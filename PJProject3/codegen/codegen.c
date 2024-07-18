#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <util/string_utils.h>
#include <util/symtab.h>
#include <util/dlink.h>
#include "reg.h"
#include "codegen.h"
#include "symfields.h"

extern SymTable globalSymtab;
extern int globalOffset;
extern int dataSize;
extern int arrStart1;
extern int arrStart2;
extern int arrEnd1;
extern int arrEnd2;
extern int arrOffset;

static void printDataDeclaration(DNode decl);
static void printInstruction(DNode inst);
static char* makeDataDeclaration(DList dataList, char *str);
static int emitBinaryExpression(DList instList, int leftOperand, int rightOperand, char* opcode);
static int emitBinaryCompareExpression(DList instList, int leftOperand, int rightOperand,
				       char *opcode);

/**
 * Print a data declaration to stdout. This function is called by dlinkApply only.
 *
 * @param decl a DNode containing a data declaration
 */
static void printDataDeclaration(DNode decl) {
	printf("\t%s\n",(char*)dlinkNodeAtom(decl));

}

/**
 * Emit the assembly prologue for a procedure
 * @param instList a list of instructions
 * @param name procedure/function name
 */
void emitProcedurePrologue(DList instList, char* name) {
	char* inst = nssave(2,"\t.globl ",name);
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	inst = nssave(3,"\t.type ",name,",@function");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	inst = nssave(2,name,":\tnop");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	inst = ssave("\tpushq %rbp");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	inst = ssave("\tmovq %rsp, %rbp");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
}


/**
 * Print the assembly prologue that includes the data section, declare the global area and string consts 
 *
 * @param dataList a list of data declarations (strings)
 */
void emitDataPrologue(DList dataList) {

	printf("\t.section\t.rodata\n");
	if (globalOffset != 0)
		printf("\t.comm _gp, %d, 4\n",globalOffset);  
		                                               
	dlinkApply(dataList,(DLinkApplyFunc)printDataDeclaration);
	printf("\t.text\n");
}

/**
 * Print an assembly instruction to stdout. This function is only called by dlinkApply.
 *
 * @param inst a DNode containing an assembly instruction.
 */
static void printInstruction(DNode inst) {
	printf("%s\n",(char*)dlinkNodeAtom(inst));
}

/**
 * Print all of the assembly instructions for the main routine to stdout.
 *
 * @param instList a DList of assembly instructions.
 */
void emitInstructions(DList instList) {
	dlinkApply(instList,(DLinkApplyFunc)printInstruction);
}

/**
 * Add an instruction that performs an assignment.
 *
 * @param instList a DList of assembly instructions
 * @param lhsRegIndex the register index of the register for the l-value address
 * @param rhsRegIndex the register index of the register for the r-value
 */
void emitAssignment(DList instList, int lhsRegIndex, int rhsRegIndex) {
	char *inst;
	
	inst = nssave(5,  "\tmovl ", getIntegerRegisterName(rhsRegIndex),
			", (", get64bitIntegerRegisterName(lhsRegIndex), ")");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	freeIntegerRegister(lhsRegIndex);
	freeIntegerRegister(rhsRegIndex);
}
/**
 * Add an instruction that performs a test for jump statments 
 *
 * @param instList a DList of assembly instructions
 * @param leftOperand temporary 32 bit register 
 * @param rightOperand temporary 32 bit register
 */
void emitTest(DList instList, int leftOperand, int rightOperand) {
	char* rightName = getIntegerRegisterName(rightOperand);
	char* leftName = getIntegerRegisterName(leftOperand);

	
	char* inst = nssave(4, "\ttestl ", leftName, ", ", rightName); //test statment
	dlinkAppend(instList, dlinkNodeAlloc(inst));

	//free temporary registers
	freeIntegerRegister(leftOperand); 
	freeIntegerRegister(rightOperand);
}
/**
 * Add an instruction that performs a test for jump statments 
 *
 * @param instList a DList of assembly instructions
 * @param loop the loop number that is currently in use
 * @param opCode specific jump operation
 */
void emitJump(DList instList, int loop, char* opCode){
	char loopNum [2];
	sprintf(loopNum, "%d", loop);

	char* inst = nssave(4, "\t", opCode, " .L", loopNum); //jenerate the jump statment to a loop
	dlinkAppend(instList, dlinkNodeAlloc(inst));
}
/**
 * Add an instruction that performs a test for jump statments 
 *
 * @param instList a DList of assembly instructions
 * @param loop the loop number that is currently in use
 */
void emitLoop(DList instList, int loop){
	char loopNum [2];
	sprintf(loopNum, "%d", loop);

	char* inst = nssave(3, "\t.L", loopNum, ":\tnop"); //loop header
	dlinkAppend(instList, dlinkNodeAlloc(inst)); 
}


/**
 * Add the instructions needed to read a variable using the scanf system call.
 *
 * @param instList a DList of instructions
 * @param dataList a Dlist of data declarations
 * @param addrIndex the register index of the register holding the address that is to be read into
 */
void emitReadVariable(DList instList, DList dataList, int addrIndex) {
    char *inst;
    char *fmtLabel = makeDataDeclaration(dataList, "\"%d\"");
	inst = nssave(3,"\tleaq ", fmtLabel, "(%rip), %rdi");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	free(fmtLabel);
	 
	inst = nssave(3,"\tmovq ", get64bitIntegerRegisterName(addrIndex), ", %rsi");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	inst = ssave("\tmovl $0, %eax");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	inst = ssave("\tcall scanf@PLT");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	freeIntegerRegister(addrIndex);
}


/**
 * Add the instructions needed to write a value using the printf system call.
 *
 * @param instList a Dlist of instructions
 * @param dataList a Dlist of data declarations
 * @param writeType write vs writeln
 * @param regIndex the index of the register to be printed
 * @param length restricted length of the output
 */
void emitWriteExpression(DList instList, DList dataList, int writeType, int regIndex, char *length) {
	char *inst;
	char *fmtLabel;
	char *fmtStr;
	char lenStr[10];

	if (length)		
 	   strcpy(lenStr, length);
	else
	   strcpy(lenStr, "");

	if (writeType == IS_WRITE)
	  fmtStr = nssave(3, "\"%", lenStr, "d\"");  
	else
	  fmtStr = nssave(3, "\"%", lenStr, "d\\n\"");  
	
    fmtLabel = makeDataDeclaration(dataList, fmtStr);
	free(fmtStr);
	  
	inst = nssave(3, "\tleaq ", fmtLabel, "(%rip), %rdi");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
    free(fmtLabel);
	
	inst = nssave(3,"\tmovl ", getIntegerRegisterName(regIndex), ", %esi");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	inst = ssave("\tmovl $0, %eax");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	freeIntegerRegister(regIndex);
	  
	inst = ssave("\tcall printf@PLT");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
}

/**
 * Add the instructions needed to write a string using the printf system call.
 *
 * @param instList a Dlist of instructions
 * @param dataList a Dlist of data declarations
 * @param writeType write vs writeln
 * @param str the string to print
 * @param length restricted length of the output
 */
void emitWriteString(DList instList,  DList dataList, int writeType, char *str, char *length) {
    char *inst;
	char *fmtLabel;
	char *fmtStr;
	char lenStr[10];

	if (length)		
 	   strcpy(lenStr, length);
	else
	   strcpy(lenStr, "");

	if (writeType == IS_WRITE)
	  fmtStr = nssave(3, "\"%", lenStr, "s\"");  
	else
	  fmtStr = nssave(3, "\"%", lenStr, "s\\n\"");  
	
    fmtLabel = makeDataDeclaration(dataList, fmtStr);
	free(fmtStr);
	  
	inst = nssave(3, "\tleaq ", fmtLabel, "(%rip), %rdi");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
    free(fmtLabel);

	char *quotedStr = nssave(3, "\"", str, "\"");
	char *strLabel = makeDataDeclaration(dataList, quotedStr);

	inst = nssave(4,"\tleaq ", strLabel, "(%rip), ", "%rsi");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	free(strLabel);

	inst = ssave("\tcall printf@PLT");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
}

/**
 * Add an instruction that performs a binary computation.
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @param opcode the opcode of the x86 assembly instruction
 * @return
 */
static int emitBinaryExpression(DList instList, int leftOperand, int rightOperand, char* opcode) {
	char* leftName = getIntegerRegisterName(leftOperand);
	char* rightName = getIntegerRegisterName(rightOperand);

	char* inst = nssave(6,"\t",opcode," ", rightName,", ",leftName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	freeIntegerRegister(rightOperand);

	return leftOperand;
}

/**
 * Add instructions for logical or
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitOrExpression(DList instList, int leftOperand, int rightOperand) {
	return emitBinaryExpression(instList,leftOperand,rightOperand,"orl");
}

/**
 * Add instructions for logical and
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitAndExpression(DList instList, int leftOperand, int rightOperand) {
	return emitBinaryExpression(instList,leftOperand,rightOperand,"andl");
}

/**
 * Add instructions for logical not
 *
 * @param instList a DList of instructions
 * @param operand the register index of the register holding the operand
 * @return the register index for the result register
 */
int emitNotExpression(DList instList, int operand) {
 	int tmpOp = allocateIntegerRegister();
	char *tmpName = getIntegerRegisterName(tmpOp);
	
	char* inst = nssave(2, "\tmovl $1, ", tmpName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	emitBinaryExpression(instList, operand, tmpOp, "xorl");

	freeIntegerRegister(tmpOp);
	
	return operand;	
}

/**
 * Add instructions that performs a binary comparison
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @param opcode the opcode of the x86 assembly instruction
 * @return the register index for the result register
 */
static int emitBinaryCompareExpression(DList instList, int leftOperand, int rightOperand,
				       char *opcode) {
	leftOperand = emitBinaryExpression(instList,leftOperand,rightOperand,"cmpl");
	freeIntegerRegister(rightOperand);

	char *inst = nssave(2,"\tmovl $0, ", getIntegerRegisterName(leftOperand));
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	int tregIndex = allocateIntegerRegister();

	inst = nssave(2,"\tmovl $1, ", getIntegerRegisterName(tregIndex));
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	return emitBinaryExpression(instList,leftOperand,tregIndex,opcode);
}

/**
 * Add instructions that performs a == comparison
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitEqualExpression(DList instList, int leftOperand, int rightOperand) {
    return emitBinaryCompareExpression(instList,leftOperand,rightOperand,"cmove");
}
/**
 * Add instructions that performs a != comparison
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */

int emitNotEqualExpression(DList instList, int leftOperand, int rightOperand) {
  return emitBinaryCompareExpression(instList,leftOperand,rightOperand,"cmovne");
}

/**
 * Add instructions that performs a <= comparison
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitLessEqualExpression(DList instList, int leftOperand, int rightOperand) {
  return emitBinaryCompareExpression(instList,leftOperand,rightOperand,"cmovle");
}

/**
 * Add instructions that performs a < comparison
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitLessThanExpression(DList instList,int leftOperand, int rightOperand) {
  return emitBinaryCompareExpression(instList,leftOperand,rightOperand,"cmovl");
}

/**
 * Add instructions that performs a >= comparison
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 */
int emitGreaterEqualExpression(DList instList, int leftOperand, int rightOperand) {
  return emitBinaryCompareExpression(instList,leftOperand,rightOperand,"cmovge");
}

/**
 * Add instructions that performs a > comparison
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitGreaterThanExpression(DList instList, int leftOperand, int rightOperand) {
  return emitBinaryCompareExpression(instList,leftOperand,rightOperand,"cmovg");
}


/**
 * Add instructions that performs addtion
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitAddExpression(DList instList, int leftOperand, int rightOperand) {
	return emitBinaryExpression(instList,leftOperand,rightOperand,"addl");
}

/**
 * Add instructions that performs substruction
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitSubtractExpression(DList instList, int leftOperand, int rightOperand) {
	return emitBinaryExpression(instList,leftOperand,rightOperand,"subl");
}

/**
 * Add instructions that performs multiplication
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitMultiplyExpression(DList instList, int leftOperand, int rightOperand) {
	return emitBinaryExpression(instList,leftOperand,rightOperand,"imull");
}

/**
 * Add instructions that performs division
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitDivideExpression(DList instList, int leftOperand, int rightOperand) {
        char *inst;
	
	    inst = nssave(3,"\tmovl ", getIntegerRegisterName(leftOperand), ", %eax");
	    dlinkAppend(instList,dlinkNodeAlloc(inst));


		inst = ssave("\tcdq");
		dlinkAppend(instList,dlinkNodeAlloc(inst));

		inst = nssave(2,"\tidivl ", getIntegerRegisterName(rightOperand));
		dlinkAppend(instList,dlinkNodeAlloc(inst));

	    inst = nssave(2,"\tmovl %eax, ", getIntegerRegisterName(leftOperand)); 
		dlinkAppend(instList,dlinkNodeAlloc(inst));


	    freeIntegerRegister(rightOperand);

		return leftOperand;
}

/**
 * Add an instruction to compute the address of a variable.
 *
 * @param instList a Dlist of instructions
 * @param varIndex the register index for a variable
 * @return the register index of the address register
 */
int emitComputeVariableAddress(DList instList, int varIndex) {
	
  int addrRegIndex = allocateIntegerRegister();   
  char* addrRegName = (char*)get64bitIntegerRegisterName(addrRegIndex);

  int offset = (int)SymGetFieldByIndex(globalSymtab,varIndex,SYMTAB_OFFSET_FIELD);
  char offsetStr[10];
  snprintf(offsetStr,9,"%d",offset);

  char *inst; 
  inst = nssave(2,"\tleaq _gp(%rip), ", addrRegName);
  dlinkAppend(instList,dlinkNodeAlloc(inst));
  inst = nssave(4,"\taddq $", offsetStr, ", ", addrRegName);
  dlinkAppend(instList,dlinkNodeAlloc(inst));
  
  return addrRegIndex;
}
/**
 * All the neccessary actions in order to compute a specific address in a 1D Array
 *
 * @param instList a DList of assembly instructions
 * @param varIndex the index given from the symtable to access sybol table values
 * @param expr the index of the register being used as the expression
 */
int emitComputeArrayAddress(DList instList, int varIndex, int expr){
  
  //allocating necassary registers
  int addrRegIndex = allocateIntegerRegister();   
  char* addrRegName = (char*)get64bitIntegerRegisterName(addrRegIndex);

  char* subScrRegName = (char*) getIntegerRegisterName(expr);
  char* subScr64RegName = (char*) get64bitIntegerRegisterName(expr);
  
  //initializing offset and starting offset in the array ie a[1..0] 1 is the value
  int offset = (int)SymGetFieldByIndex(globalSymtab,varIndex,SYMTAB_OFFSET_FIELD);
  char offsetStr[10];
  snprintf(offsetStr,9,"%d",offset);

  int strt = (int)SymGetFieldByIndex(globalSymtab,varIndex,SYMTAB_START_FIELD);
  char arrStrtStr[10];
  snprintf(arrStrtStr,9,"%d", strt);


  char *inst; 

  //load instructions 
  inst = nssave(2,"\tleaq _gp(%rip), ", addrRegName);
  dlinkAppend(instList,dlinkNodeAlloc(inst));
  
  inst = nssave(4,"\taddq $", offsetStr, ", ", addrRegName);
  dlinkAppend(instList,dlinkNodeAlloc(inst));
  
  inst = nssave(4,"\tmovslq ", subScrRegName, ", ", subScr64RegName);
  dlinkAppend(instList,dlinkNodeAlloc(inst));

   inst = nssave(4,"\tsubq $", arrStrtStr, ", ", subScr64RegName);
  dlinkAppend(instList,dlinkNodeAlloc(inst));

  inst = nssave(2,"\timulq $4, ", subScr64RegName);
  dlinkAppend(instList,dlinkNodeAlloc(inst));
  
  inst = nssave(4,"\taddq ", subScr64RegName, ", ", addrRegName);
  dlinkAppend(instList,dlinkNodeAlloc(inst));	

  //free registers
  freeIntegerRegister(expr);

  return addrRegIndex;
}

/**
 * all the neccassary actions inorder to compute the specific adress for a 2d array
 *
 * @param instList a DList of assembly instructions
 * @param varIndex the index given from the symtable to access sybol table values
 * @param expr1 the index of the register being used as the expression
 * @param expr2 the index of the register being used as the expression
 */
int emitCompute2DArrayAddress(DList instList, int varIndex, int expr1, int expr2){
  //allocate registers being used in instructions
  int addrRegIndex = allocateIntegerRegister();   
  char* addrRegName = (char*)get64bitIntegerRegisterName(addrRegIndex);

  char* subScrRegName1 = (char*) getIntegerRegisterName(expr1);
  char* subScr64RegName1 = (char*) get64bitIntegerRegisterName(expr1);

  char* subScrRegName2 = (char*) getIntegerRegisterName(expr2);
  char* subScr64RegName2 = (char*) get64bitIntegerRegisterName(expr2);

  int extra64Reg = allocateIntegerRegister();
  char* extra64RegName = (char*) get64bitIntegerRegisterName(extra64Reg);
  
  //initialize offset starting point in both ranges and ending point in second range
  int offset = (int)SymGetFieldByIndex(globalSymtab,varIndex,SYMTAB_OFFSET_FIELD);
  char offsetStr[10];
  snprintf(offsetStr,9,"%d",offset);

  int strt = (int)SymGetFieldByIndex(globalSymtab,varIndex,SYMTAB_START_FIELD);
  char arrStrtStr[10];
  snprintf(arrStrtStr,9,"%d", strt);

  int end = (int)SymGetFieldByIndex(globalSymtab,varIndex,SYMTAB_END2_FIELD);
  char arrEndStr[10];
  snprintf(arrEndStr,9,"%d", end);

  int strt2 = (int)SymGetFieldByIndex(globalSymtab,varIndex, SYMTAB_START2_FIELD);
  char arrStrtStr2[10];
  snprintf(arrStrtStr2,9,"%d", strt2);


  char *inst; 
  
  //load instructions
  inst = nssave(2,"\tleaq _gp(%rip), ", addrRegName);
  dlinkAppend(instList,dlinkNodeAlloc(inst));
  
  inst = nssave(4,"\taddq $", offsetStr, ", ", addrRegName);
  dlinkAppend(instList,dlinkNodeAlloc(inst));
  
  inst = nssave(4,"\tmovslq ", subScrRegName1, ", ", subScr64RegName1);
  dlinkAppend(instList,dlinkNodeAlloc(inst));

  inst = nssave(4,"\tsubq $", arrStrtStr, ", ", subScr64RegName1);
  dlinkAppend(instList,dlinkNodeAlloc(inst));

  inst = nssave(4,"\tmovq $", arrEndStr, ", ", extra64RegName);
  dlinkAppend(instList,dlinkNodeAlloc(inst));  

  inst = nssave(4,"\timulq ", extra64RegName, ", ", subScr64RegName1);
  dlinkAppend(instList,dlinkNodeAlloc(inst));

  inst = nssave(4,"\tmovslq ", subScrRegName2, ", ", subScr64RegName2);
  dlinkAppend(instList,dlinkNodeAlloc(inst));

  inst = nssave(4,"\taddq ", subScr64RegName2, ", ", subScr64RegName1);
  dlinkAppend(instList,dlinkNodeAlloc(inst));

  inst = nssave(4,"\tsubq $", arrStrtStr2, ", ", subScr64RegName1);
  dlinkAppend(instList,dlinkNodeAlloc(inst));

  inst = nssave(2,"\timulq $4, ", subScr64RegName1);
  dlinkAppend(instList,dlinkNodeAlloc(inst));
  
  inst = nssave(4,"\taddq ", subScr64RegName1, ", ", addrRegName);
  dlinkAppend(instList,dlinkNodeAlloc(inst));	

  //free registers no longer being used
  freeIntegerRegister(expr1);
  freeIntegerRegister(expr2);
  freeIntegerRegister(extra64Reg);

  return addrRegIndex;
}

/**
 * add symtable values for start and end asswell as the size of the array 
 *
 * @param index symbtable index being used
 * @param end the ending point in the range 
 * @param start the starting point in the range 
 */
void initDims (int index, int end, int start) {
	int offset = (end - start) + 4;
	SymPutFieldByIndex(globalSymtab, index, SYMTAB_START_FIELD, (Generic)start);
	SymPutFieldByIndex(globalSymtab, index, SYMTAB_END_FIELD, (Generic)end);
	SymPutFieldByIndex(globalSymtab, index, SYMTAB_ARROFFSET_FIELD, (Generic)offset);
} 




/**
 * Add an instruction to load a variable from memory.
 *
 * @param instList a Dlist of instructions
 * @param regIndex the register index for the address of a variable
 * @return the register index of the result register
 */
int emitLoadVariable(DList instList, int regIndex) {
	int dstRegIndex = allocateIntegerRegister();
	char* dstRegName = getIntegerRegisterName(dstRegIndex);

	char* srcAddrRegName = get64bitIntegerRegisterName(regIndex);

	char *inst = nssave(4,"\tmovl (",srcAddrRegName,"), ", dstRegName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	freeIntegerRegister(regIndex);

	return dstRegIndex;
}

/**
 * Add an instruction to load an integer constant
 *
 * @param instList a Dlist of instructions
 * @param intConst the const string of an integer constant
 * @return the register index of the result register holding the const
 */
int emitLoadIntegerConstant(DList instList, char * intConst) {
	int regIndex = allocateIntegerRegister();
	char* regName = (char*)getIntegerRegisterName(regIndex);
	
	char *inst = nssave(4,"\tmovl $", intConst, ", ", regName);

	dlinkAppend(instList,dlinkNodeAlloc(inst));

	return regIndex;
}

/**
 * Add a .asciiz declaration for a string constant if it hasn't been declared
 *
 * @param dataList a DList of data declarations
 * @param str string constant to put into data section
 * @return the label of the string constant
 */
static char* makeDataDeclaration(DList dataList, char* str) {
	static int stringNum = 0;
	int symIndex = SymQueryIndex(globalSymtab, str);
	int labelcount;
	char* strLabel = (char*)malloc(sizeof(char)*15);
		
	if (symIndex == SYM_INVALID_INDEX) {
	   symIndex = SymIndex(globalSymtab, str);
	   labelcount = stringNum++;
           SymPutFieldByIndex(globalSymtab,symIndex,SYMTAB_OFFSET_FIELD, (Generic)labelcount);

	   snprintf(strLabel, 17, ".string_const%d",labelcount);

	   char* decl = nssave(3, strLabel, ": .string ", str);
 	   dlinkAppend(dataList,dlinkNodeAlloc(decl));
	} else {
	   labelcount = (int)SymGetFieldByIndex(globalSymtab,symIndex,SYMTAB_OFFSET_FIELD);
	   snprintf(strLabel,15,".string_const%d",labelcount);
	}
	
	return strLabel;
}


/**
 * Add an identifier to the symbol table and store its offset in the activation record.
 * This function is called by dlinkApply1.
 *
 * @param node a node on a linked list containing the symbol table index of a variable
 *                delcared in a program
 */
void addIdToSymtab(DNode node) {
	int symIndex = (int)dlinkNodeAtom(node);
	SymPutFieldByIndex(globalSymtab, symIndex, SYMTAB_OFFSET_FIELD, (Generic)(globalOffset));
	globalOffset += 4;
}

/**
 * Add an identifier to the symbol table and store its offset, start value for first and second dim, and end on second dim in the activation record.
 * This function is called by dlinkApply1.
 *
 * @param node a node on a linked list containing the symbol table index of a variable
 *                delcared in a program
 */
void addArrayIdToSymtab(DNode node) {
	int symIndex = (int)dlinkNodeAtom(node);
	SymPutFieldByIndex(globalSymtab, symIndex, SYMTAB_OFFSET_FIELD, (Generic)(globalOffset));
	SymPutFieldByIndex(globalSymtab, symIndex, SYMTAB_START_FIELD, (Generic)(arrStart1));
	SymPutFieldByIndex(globalSymtab, symIndex, SYMTAB_START2_FIELD, (Generic)(arrStart2));
	SymPutFieldByIndex(globalSymtab, symIndex, SYMTAB_END2_FIELD, (Generic)(arrEnd2));
	globalOffset += arrOffset;
}


/**
 * Print out the procedure exit instructios
 *
 * @param instList a DList of instructions
 */
void emitProcedureExit(DList instList) {
	char *inst = ssave("\tleave");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	inst = ssave("\tret");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
}
