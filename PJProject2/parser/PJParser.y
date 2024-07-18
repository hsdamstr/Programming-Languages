/*******************************************************/
/*                     PascalJunior Parser             */
/*                                                     */
/*******************************************************/

/*********************DEFINITIONS***********************/
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <util/general.h>
#include <util/symtab.h>
#include <util/string_utils.h>

#define SYMTABLE_SIZE 100
#define SYMTAB_VALUE_FIELD  "value"
#define SYMTAB_NAME_FIELD  "name"
#define SYMTAB_OFFSET_FIELD  "offset"


/* delete or comment out the line below after you have a good grasp of Project 1. It will turn off all printf statements that print the grammar rules */
//#define PROJECT1
/*********************EXTERNAL DECLARATIONS***********************/

EXTERN(void,yyerror,(char*));
EXTERN(int,yylex,(void));

int offset = 0; //set global offset for assingling and using variables 
int curWord = 0; //current word for string constants
int instNumHead = 0; //number of instructions in the head of the assembly code used for printing 
int instNumBody = 0; //number of instructions in the body of the assembly code used for printing
int curOffset = 0;




char* fileName;
char buffer[1000];  //buffer used to temporarily store asslembl y code before getting moved to its propper section
char header[1000][1000];// assebly header code storage
char body[2000][1000]; // assembly body code storage

typedef struct Registers { //storing registers to be used and not over written 
	int used;
	char* reg32;
	char* reg64;
}Register;


char* reg64[]= {"%r8", "%r9", "%r10", "%r11", "%r12", "%r13", "%r14", "%r15", "%rax", "%rbx", "%rcx", "%rdx", "%rsi", "%rdi"};
char* reg32[]= {"%r8d", "%r9d", "%r10d", "%r11d", "%r12d", "%r13d", "%r14d", "%r15d", "%eax", "%ebx", "%ecx", "%edx", "%esi", "%edi"};

Register registers[14];	

extern int yylineno;
extern char *yytext;
extern FILE *yyin;


SymTable globalSymtab;

static int getValue(char *name);
static void setValue(char *name, int value);
static void setName(char *name, char* str);
//static int getName(char *name);
static void x86String(int newLine, char* string, char* reg);
static void x86PrintNum(int newLine, char* frmt, char* reg);
static void x86Assign(int offset, int num, char* reg);
static int findAvailableReg();
static void x86PrintVar(int newLine, char* frmt, char* reg, int offset);
static void x86Read();

%}

%defines

%start Program

%token T_AND
%token T_ELSE
%token T_FLOAT
%token T_FOR
%token T_IF 		
%token T_LONGINT
%token T_BOOLEAN
%token T_PROGRAM	 
%token T_FUNCTION
%token T_NOT 		
%token T_OR 		
%token T_READ
%token T_WHILE
%token T_WRITE
%token T_WRITELN
%token T_BEGIN
%token T_END
%token T_VAR
%token T_DO
%token T_ARRAY
%token T_EXIT
%token T_THEN
%token T_LE
%token T_LT
%token T_GE
%token T_GT
%token T_EQ
%token T_NE
%token T_ASSIGN
%token T_COMMA
%token T_SEMICOLON
%token T_COLON
%token T_LBRACKET
%token T_RBRACKET
%token T_LPAREN
%token T_RPAREN
%token T_PLUS
%token T_TIMES
%token T_IDENTIFIER
%token T_DIV
%token T_STRING	
%token T_INTNUM
%token T_FLOATNUM
%token T_MINUS
%token T_DOT
%token T_DOTDOT
%token T_OF
%token T_TRUE
%token T_FALSE


%left T_LT T_LE T_GT T_GE T_NE T_EQ
%left T_PLUS T_MINUS T_OR
%left T_TIMES T_DIV T_AND
%left T_NOT

%union {
	char*	name;
	int     val;
}
%type <val> WriteToken Expr AddExpr MulExpr Factor Constant T_TRUE T_FALSE DeclList
%type <name> OutputFormat Variable T_STRING T_IDENTIFIER T_INTNUM IdentifierList Decls

%%
/***********************PRODUCTIONS****************************/

Program 	: ProgramHeadAndProcedures CompoundStatement T_DOT
	  	{
		  
		  #ifdef PROJECT1
		  printf("Program : ProgramHeadAndProcedures CompoundStatement T_DOT\n");		
		  #endif
          	}
		;

ProgramHeadAndProcedures : ProgramHead Procedures 
		{
		  #ifdef PROJECT1
		  printf("ProgramHeadAndProcedures : ProgramHead Procedure\n");		
		  #endif
		}
		;

ProgramHead 	: T_PROGRAM T_IDENTIFIER T_SEMICOLON Decls 
		{
		  
		  #ifdef PROJECT1
		  printf("ProgramHead : T_PROGRAM T_IDENTIFIER T_SEMICOLON Decls \n");		
		  #endif
		}
	    	;

       
Decls 		: T_VAR DeclList
		{
		  #ifdef PROJECT1
		  printf("Decls : T_VAR DeclList\n");		
		  #endif
		}
      		|
    		{
		  #ifdef PROJECT1
		  printf("Decls : \n");		
		  #endif
		}
	  	;
	  
DeclList 	: IdentifierList T_COLON Type T_SEMICOLON
		{   
		  $$ = offset;
		  #ifdef PROJECT1
		  printf("DeclList : IdentifierList T_COLON Type T_SEMICOLON\n");		
		  #endif
		}
		| DeclList IdentifierList T_COLON Type T_SEMICOLON
		{
		  #ifdef PROJECT1
		  printf("DeclList : DeclList IdentifierList T_COLON Type T_SEMICOLON\n");		
		  #endif
		}
		;
		 
IdentifierList 	: T_IDENTIFIER
		{
		  
		  SymPutField(globalSymtab, $1, SYMTAB_OFFSET_FIELD, (Generic)offset); //setting the off set in syboltable so it wont be overwritten 
		  offset += 4; //increasing offset for one var
		  $$ = $1;
		  #ifdef PROJECT1
		  printf("IdentifierList : T_IDENTIFIER\n");		
		  #endif
		}
	       	| IdentifierList T_COMMA T_IDENTIFIER
		{
		  SymPutField(globalSymtab, $3, SYMTAB_OFFSET_FIELD, (Generic)offset);
		  $$ = $3;
		  offset += 4; //for multiple vars
		  #ifdef PROJECT1
		  printf("IdentifierList : IdentifierList T_COMMA T_IDENTIFIER\n");		
		  #endif
		}
	
Type 		: StandardType
		{
		  #ifdef PROJECT1
		  printf("Type : StandardType\n");		
		  #endif
		}
	 	| ArrayType
	 	{
		  #ifdef PROJECT1
		  printf("Type : ArrayType\n");		
		  #endif
	 	}
	 	;

StandardType 	: T_LONGINT
		{
		  #ifdef PROJECT1
		  printf("StandardType : T_LONGINT\n");		
		  #endif
		} 
		| T_BOOLEAN
		{
		  #ifdef PROJECT1
		  printf("StandardType : T_BOOLEAN\n");		
		  #endif
		}
		| T_FLOAT
		{
		  #ifdef PROJECT1
		  printf("StandardType : T_FLOAT\n");		
		  #endif
		}
		;
			
ArrayType 	: T_ARRAY T_LBRACKET Dim T_RBRACKET T_OF StandardType
		{
		  #ifdef PROJECT1
		  printf("ArrayType : T_ARRAY T_LBRACKET Dim T_RBRACKET T_OF StandardType\n");		
		  #endif
		}
		| T_ARRAY T_LBRACKET Dim T_COMMA Dim T_RBRACKET T_OF StandardType
		{
		  #ifdef PROJECT1
		  printf("ArrayType : T_ARRAY T_LBRACKET Dim T_COMMA Dim T_RBRACKET T_OF StandardType\n");		
		  #endif
		}
		;

Dim 		: T_INTNUM T_DOTDOT T_INTNUM
		{
		  #ifdef PROJECT1
		  printf("Dim : T_INTNUM T_DOTDOT T_INTNUM\n");		
		  #endif
		}
		;

Procedures 	: Procedures ProcedureDecl
		{
		  #ifdef PROJECT1
		  printf("Procedures : Procedures ProcedureDecl\n");		
		  #endif
		}
	   	| 
		{
		  #ifdef PROJECT1
		  printf("Procedures :\n");		
		  #endif
		}
	   	;

ProcedureDecl 	: ProcedureHead ProcedureBody
		{
		  #ifdef PROJECT1
		  printf("ProcedureDecl : ProcedureHead ProcedureBody\n");
		  #endif
		}
              	;

ProcedureHead 	: FunctionDecl Decls 
		{
		  #ifdef PROJECT1
		  printf("ProcedureHead : FunctionDecl Decls\n");		
		  #endif
		}
              	;

FunctionDecl 	: T_FUNCTION T_IDENTIFIER T_COLON StandardType T_SEMICOLON
		{
		  #ifdef PROJECT1
		  printf("FunctionDecl : T_FUNCTION T_IDENTIFIER T_COLON StandardType T_SEMICOLON\n");		
		  #endif
		}
   	     	;
	      
ProcedureBody 	: CompoundStatement T_SEMICOLON
		{
		  #ifdef PROJECT1
		  printf("ProcedureBody : CompoundStatement T_SEMICOLON\n");		
		  #endif
		}
	      	;

Statement 	: Assignment
		{
		  #ifdef PROJECT1
		  printf("Statement : Assignment\n");		
		  #endif
		}
          	| IfStatement
		{
		  #ifdef PROJECT1
		  printf("Statement : IfStatement\n");		
		  #endif
		}
	  	| WhileStatement
		{
		  #ifdef PROJECT1
		  printf("Statement : WhileStatement\n");		
		  #endif
		}
          	| IOStatement 
		{
		  #ifdef PROJECT1
		  printf("Statement : IOStatement\n");		
		  #endif
		}
	  	| ExitStatement
		{
		  #ifdef PROJECT1
		  printf("Statement : ExitStatement\n");		
		  #endif
		}
	  	| CompoundStatement
		{
		  #ifdef PROJECT1
		  printf("Statement : CompoundStatement\n");		
		  #endif
		}
          	;

Assignment 	: Variable T_ASSIGN Expr
		{ 
		  //curOffset = getValue($1);
		  
		  char* src = registers[$3].reg32; //these should be switched but pulling value from variable register
		  char* dst = registers[getValue($1)].reg64; //source of variable register 

		  //printf("%s %s", src, dst);
		  sprintf(buffer, "\tmovl %s, (%s)\n", src, dst);
		  strcat(body[instNumBody], buffer);
		  instNumBody++;

		  registers[$3].used = 0; //set both registers as not used as values have been moved out and they are free
		  registers[getValue($1)].used = 0;

		
		  
		  #ifdef PROJECT1
		  printf("Assignment : Variable T_ASSIGN Expr\n");		
		  #endif
		}
		;
 
IfStatement 	: T_IF TestAndThen T_ELSE Statement
		{
		  #ifdef PROJECT1
		  printf("IfStatement : T_IF TestAndThen T_ELSE Statement\n");		
		  #endif
		}
	    	| T_IF TestAndThen
		{
		  #ifdef PROJECT1
		  printf("IfStatement : T_IF TestAndThen\n");		
		  #endif
		}
  	    	;
				
TestAndThen	: Test T_THEN Statement
	   	{
		  #ifdef PROJECT1
		  printf("TestAndThen : Test T_THEN Statement\n");		
		  #endif
	    	}
		;
				
Test 		: Expr 
		{
		  #ifdef PROJECT1
		  printf("Test : Expr \n");		
		  #endif
		}
	 	;

WhileStatement 	: WhileToken WhileExpr T_DO Statement
		{
		  #ifdef PROJECT1
		  printf("WhileStatement : WhileToken WhileExpr T_DO Statement\n");		
		  #endif
		}
                ;
                
WhileExpr : 	Expr 
		{
		  #ifdef PROJECT1
		  printf("WhileExpr : Expr \n");		
		  #endif
		}
		;
				
WhileToken	: T_WHILE
		{
		  #ifdef PROJECT1
		  printf("WhileToken : T_WHILE\n");		
		  #endif
		}
		;

IOStatement 	: T_READ T_LPAREN Variable T_RPAREN
		{ 


		  x86Read(registers[getValue($3)].reg64); //this function completes all necessary calls for reading variables in assembly
		  
		  sprintf(buffer, "\tcall scanf@PLT\n"); //final call for read clears registers
		  strcat(body[instNumBody], buffer);
		  instNumBody++;

		  registers[getValue($3)].used = 0; //set registers to free so they can be used again 
		  #ifdef PROJECT1
		  printf("IOStatement : T_READ T_LPAREN Variable T_RPAREN\n");		
		  #endif
		}
		| WriteToken T_LPAREN Expr OutputFormat T_RPAREN
		{ 
		  char fmtStr[10];
		  
		  strcpy(fmtStr, "%");

		  if ($4 != NULL) {
			strcat(fmtStr, $4);
		  }

		  strcat(fmtStr, "d");
		  	
		  if ($1 == 1) {
				x86PrintNum(1, fmtStr, registers[$3].reg32); //this function copletes all necassary processes for printing numbers in assembly
		  }
		  else{
				x86PrintNum(0, fmtStr, registers[$3].reg32);
		  }

		  strcat(body[instNumBody], "\tcall printf@PLT\n");
		  instNumBody++;

		  registers[$3].used = 0;

		  #ifdef PROJECT1
		  printf("IOStatement : WriteToken T_LPAREN Expr OutputFormat T_RPAREN\n");		
		  #endif
		}
		| WriteToken T_LPAREN T_STRING OutputFormat T_RPAREN      
		{ 
		  char fmtStr[10];
		  
		  strcpy(fmtStr, "%");

		  if ($4 != NULL) {
			strcat(fmtStr, $4);
		  }

		  strcat(fmtStr, "s");

		  x86String(0,fmtStr,"%rdi"); //this funtion takes care of all processes necassary to print strings in assembly

		  
		  if ($1 == 1) { //for printing with new line
			x86String(1,$3,"%rsi");
		  }
		  else{
			x86String(0,$3,"%rsi");
		  }

		  strcat(body[instNumBody], "\tcall printf@PLT\n");
		  instNumBody++; //increase instruction number for printing accuratly
		 
		  #ifdef PROJECT1
		  printf("IOStatement : WriteToken T_LPAREN T_STRING OutputFormat T_RPAREN\n");		
		  #endif
		}
		;

OutputFormat 	: T_COLON T_INTNUM
        {
		  $$ = $2;	
		  #ifdef PROJECT1
		  printf("OutputFormat : T_COLON T_INTNUM\n");		
		  #endif
		} 
		|
		{
		  $$ = NULL;	
		  #ifdef PROJECT1
		  printf("OutputFormat : \n");		
		  #endif
		}
		;

WriteToken 	: T_WRITE
             	{
		  $$ =  0;			
		  #ifdef PROJECT1
		  printf("WriteToken : T_WRITE\n");		
		  #endif
		}
	    	| T_WRITELN
            	{
		  $$ = 1;			
		  #ifdef PROJECT1
		  printf("WriteToken : T_WRITELN\n");		
		  #endif
		}
                ;
			 
ExitStatement 	: T_EXIT T_LPAREN Expr T_RPAREN 
		{
		  #ifdef PROJECT1
		  printf("ExitStatement : T_EXIT T_LPAREN Expr T_RPAREN\n");		
		  #endif
		}
                ;

CompoundStatement : T_BEGIN StatementList T_END
		{
		  #ifdef PROJECT1
		  printf("CompoundStatement : T_BEGIN StatementList T_END\n");		
		  #endif
		}
                ;
                  
StatementList 	: StatementList T_SEMICOLON Statement
		{
		  #ifdef PROJECT1
		  printf("StatementList : StatementList T_SEMICOLON Statement\n");		
		  #endif
		}
		| Statement
		{
		  #ifdef PROJECT1
		  printf("StatementList : Statement\n");		
		  #endif
		}
		;

 
Expr		: AddExpr
		{
		  $$ = $1;

		  #ifdef PROJECT1
		  printf("Expr : AddExpr\n");		
		  #endif
		}
                | Expr T_EQ AddExpr
		{
		  int nindex = findAvailableReg(); //find nre register 
		  char* nreg = registers[nindex].reg32;// assign new register for comparison 

		  char* tgt = registers[$1].reg32;
		  char* src = registers[$3].reg32;

		  //as explained in slide 8

		  /*
		  #assume that a is loaded to %ecx
		  #and b is loaded to %r8d
		  cmpl %r8d, %ecx
		  movl $0, %ecx
		  movl $1, %ebx
		  cmovg %ebx, %ecx
		  #%ecx now holds the result of a>b 
		  */

		  //this applies for all comparisons
		  
		  
		  sprintf(buffer, "\tcmpl %s, %s\n", src, tgt);
		  strcat(body[instNumBody],buffer);
		  instNumBody++;	

		  registers[$3].used = 0;	

		  sprintf(buffer, "\tmovl $0, %s\n", tgt);
		  strcat(body[instNumBody],buffer);
		  instNumBody++;

		  sprintf(buffer, "\tmovl $1, %s\n", nreg);
		  strcat(body[instNumBody],buffer);
		  instNumBody++;	

		  sprintf(buffer, "\tcmove %s, %s\n", nreg, tgt);
		  strcat(body[instNumBody],buffer);
		  instNumBody++;	
		  
		  registers[nindex].used = 0;

		 
		  $$ = $1; //set expr equal to the currrent expr register which contains the comparrison results

		  #ifdef PROJECT1
		  printf("Expr : Expr T_EQ AddExpr\n");		
		  #endif
		}
                | Expr T_NE AddExpr
		{

		  //explained above 
		  int nindex = findAvailableReg();
		  char* nreg = registers[nindex].reg32;

		  char* tgt = registers[$1].reg32;
		  char* src = registers[$3].reg32;

		  sprintf(buffer, "\tcmpl %s, %s\n", src, tgt);
		  strcat(body[instNumBody],buffer);
		  instNumBody++;	

		  registers[$3].used = 0;	

		  sprintf(buffer, "\tmovl $0, %s\n", tgt);
		  strcat(body[instNumBody],buffer);
		  instNumBody++;

		  sprintf(buffer, "\tmovl $1, %s\n", nreg);
		  strcat(body[instNumBody],buffer);
		  instNumBody++;	

		  sprintf(buffer, "\tcmovne %s, %s\n", nreg, tgt);
		  strcat(body[instNumBody],buffer);
		  instNumBody++;	
		  
		  registers[nindex].used = 0;

		  $$ = $1;
		  #ifdef PROJECT1
		  printf("Expr : Expr T_NE AddExpr\n");		
		  #endif
		}
                | Expr T_LE AddExpr
		{
		  //explained above 
		  int nindex = findAvailableReg();
		  char* nreg = registers[nindex].reg32;

		  char* tgt = registers[$1].reg32;
		  char* src = registers[$3].reg32;

		  sprintf(buffer, "\tcmpl %s, %s\n", src, tgt);
		  strcat(body[instNumBody],buffer);
		  instNumBody++;

		  registers[$3].used = 0;	

		  sprintf(buffer, "\tmovl $0, %s\n", tgt);
		  strcat(body[instNumBody],buffer);
		  instNumBody++;

		  sprintf(buffer, "\tmovl $1, %s\n", nreg);
		  strcat(body[instNumBody],buffer);
		  instNumBody++;	

		  sprintf(buffer, "\tcmovle %s, %s\n", nreg, tgt);
		  strcat(body[instNumBody],buffer);
		  instNumBody++;	
		  
		  registers[nindex].used = 0;

		  $$ = $1;	
		  #ifdef PROJECT1
		  printf("Expr : Expr T_LE AddExpr\n");		
		  #endif
		}
                | Expr T_LT AddExpr
		{
		   //explained above 
		   int nindex = findAvailableReg();
		  char* nreg = registers[nindex].reg32;

		  char* tgt = registers[$1].reg32;
		  char* src = registers[$3].reg32;

		  sprintf(buffer, "\tcmpl %s, %s\n", src, tgt);
		  strcat(body[instNumBody],buffer);
		  instNumBody++;	

		  registers[$3].used = 0;	

		  sprintf(buffer, "\tmovl $0, %s\n", tgt);
		  strcat(body[instNumBody],buffer);
		  instNumBody++;

		  sprintf(buffer, "\tmovl $1, %s\n", nreg);
		  strcat(body[instNumBody],buffer);
		  instNumBody++;	

		  sprintf(buffer, "\tcmovl %s, %s\n", nreg, tgt);
		  strcat(body[instNumBody],buffer);
		  instNumBody++;	
		  
		  registers[nindex].used = 0;

		  $$ = $1;	
		  #ifdef PROJECT1
		  printf("Expr : Expr T_LT AddExpr\n");		
		  #endif
		}
                | Expr T_GE AddExpr
		{
		  //explained above 
		   int nindex = findAvailableReg();
		  char* nreg = registers[nindex].reg32;

		  char* tgt = registers[$1].reg32;
		  char* src = registers[$3].reg32;

		  sprintf(buffer, "\tcmpl %s, %s\n", src, tgt);
		  strcat(body[instNumBody],buffer);
		  instNumBody++;	

		  registers[$3].used = 0;	

		  sprintf(buffer, "\tmovl $0, %s\n", tgt);
		  strcat(body[instNumBody],buffer);
		  instNumBody++;

		  sprintf(buffer, "\tmovl $1, %s\n", nreg);
		  strcat(body[instNumBody],buffer);
		  instNumBody++;	

		  sprintf(buffer, "\tcmovge %s, %s\n", nreg, tgt);
		  strcat(body[instNumBody],buffer);
		  instNumBody++;	
		  
		  registers[nindex].used = 0;

		  $$ = $1;	
		  #ifdef PROJECT1
		  printf("Expr : Expr T_GE AddExpr\n");		
		  #endif
		}
                | Expr T_GT AddExpr
		{
		  //explained above 
		   int nindex = findAvailableReg();
		  char* nreg = registers[nindex].reg32;

		  char* tgt = registers[$1].reg32;
		  char* src = registers[$3].reg32;

		  sprintf(buffer, "\tcmpl %s, %s\n", src, tgt);
		  strcat(body[instNumBody],buffer);
		  instNumBody++;	

		  registers[$3].used = 0;	

		  sprintf(buffer, "\tmovl $0, %s\n", tgt);
		  strcat(body[instNumBody],buffer);
		  instNumBody++;

		  sprintf(buffer, "\tmovl $1, %s\n", nreg);
		  strcat(body[instNumBody],buffer);
		  instNumBody++;	

		  sprintf(buffer, "\tcmovg %s, %s\n", nreg, tgt);
		  strcat(body[instNumBody],buffer);
		  instNumBody++;	
		  
		  registers[nindex].used = 0;

		  $$ = $1;
		  #ifdef PROJECT1
		  printf("Expr : Expr T_GT AddExpr\n");		
		  #endif
		}
                ;

AddExpr		: MulExpr            
		{
		  $$ = $1;

		  #ifdef PROJECT1
		  printf("AddExpr : MulExpr\n");		
		  #endif
		}
		| AddExpr T_OR MulExpr 
		{ 

		  // as explained in slide 7

		  /*andl %eax, %ebx
		   orl %eax, %ebx this is being used in this case	
		   xorl %eax, %ebx
		   notl %eax
		  */

		  //registers are different as my code is set up differently
		  char* tgt = registers[$1].reg32;
		  char* src = registers[$3].reg32;

		  sprintf(buffer,"\torl %s, %s\n", src, tgt);
		  strcat(body[instNumBody],buffer);
		  
		  registers[$3].used = 0;

		  instNumBody++;	
		 
		  $$ = $1; 	
		  #ifdef PROJECT1
		  printf("AddExpr : AddExpr T_OR MulExpr\n");		
		  #endif
		}
        | AddExpr T_PLUS MulExpr
		{
		  
		  
		  char* tgt = registers[$1].reg32;
		  char* src = registers[$3].reg32;

		  //as explained in slide 6 add expression
		  

		  sprintf(buffer,"\taddl %s, %s\n", src, tgt);
		  strcat(body[instNumBody],buffer);
		  registers[$3].used = 0;
		  
		  instNumBody++;

		  $$ = $1;
		  #ifdef PROJECT1
		  printf("AddExpr : AddExpr T_PLUS MulExpr\n");		
		  #endif
		}
                | AddExpr T_MINUS MulExpr
		{
		   
		   //also explained in slide 6
		  char* tgt = registers[$1].reg32;
		  char* src = registers[$3].reg32;

		  sprintf(buffer,"\tsubl %s, %s\n", src, tgt);
		  strcat(body[instNumBody],buffer);
		  
		  registers[$3].used = 0;

		  instNumBody++;	

		  $$ = $1;	
		  #ifdef PROJECT1
		  printf("AddExpr : AddExpr T_MINUS MulExpr\n");		
		  #endif
		}
                ;

MulExpr		:  Factor
        	{
		  $$ = $1;
		  #ifdef PROJECT1
		  printf("MulExpr : Factor\n");		
		  #endif
                }
	    	| MulExpr T_TIMES Factor
		{
		  
		 //explained in slide 6

		  char* tgt = registers[$1].reg32;
		  char* src = registers[$3].reg32;

		  sprintf(buffer,"\timull %s, %s\n", src, tgt);
		  strcat(body[instNumBody],buffer);
		  instNumBody++;

		  registers[$3].used = 0;
		  
		  $$ = $1;
		  #ifdef PROJECT1
		  printf("MulExpr : MulExpr T_TIMES Factor\n");		
		  #endif
		}
                | MulExpr T_DIV Factor
		{


		  char* tgt = registers[$1].reg32;
		  char* src = registers[$3].reg32;


		  //for multiple divisions ie. i div j div k div l it is easier to only use on register for storage puposes as well as memory allocation 
		  sprintf(buffer, "\tmovl %s, %%eax\n", tgt); 
		  strcat(body[instNumBody],buffer);
		  instNumBody++;
		  
		  sprintf(buffer, "\tcdq\n"); 
		  strcat(body[instNumBody],buffer);
		  instNumBody++;
		  
		  sprintf(buffer, "\tidivl %s\n", src);
          strcat(body[instNumBody],buffer);
		  instNumBody++;

		  sprintf(buffer, "\tmovl %%eax, %s\n", tgt);
          strcat(body[instNumBody],buffer);
		  instNumBody++;


		 registers[$3].used = 0;


		  $$ = $1;
		  #ifdef PROJECT1
		  printf("MulExpr : MulExpr T_DIV Factor\n");		
		  #endif
		}	
		| MulExpr T_AND Factor 
		{
		    

		  //explained in slide 7	
		  char* tgt = registers[$1].reg32;
		  char* src = registers[$3].reg32;


		  sprintf(buffer,"\tandl %s, %s\n", src, tgt);
		  strcat(body[instNumBody],buffer);
		  
		  registers[$3].used = 0;

		  instNumBody++;	
		  
		  $$ = $1; 		
		  #ifdef PROJECT1
		  printf("MulExpr : MulExpr T_AND Factor\n");		
		  #endif
		}	
                ;
		

Factor          : Variable
		{ 
		  int nindex = findAvailableReg(); //find a new register to fill in memory location in 64 bit register
		  char* nreg = registers[nindex].reg32; 
		  int index = getValue($1); //old register 
		  char* reg = registers[index].reg64;

		  sprintf(buffer, "\tmovl (%s), %s\n", reg, nreg);// move value in 32 bit register to 64 bit register
		  strcat(body[instNumBody], buffer);
		  instNumBody++;
		
		  //setValue($1, nindex);
		  $$ = nindex; //set factor equal to the new index as that is what will be used 
		  
		  registers[getValue($1)].used = 0; //free the old register 

		  #ifdef PROJECT1
		  printf("Factor : Variable\n");		
		  #endif
		}
                | Constant
		{ 
		  $$ = $1;	
		  #ifdef PROJECT1
		  printf("Factor : Constant\n");		
		  #endif
		}
	    	| T_NOT Factor
		{
		  char* reg = registers[$2].reg32;
		  sprintf(buffer, "\txorl $1, %s\n", reg); //not dose not work so by doing an exlusive or and comparing the register with the value stored in the register results in
		  //both values being both the same resulting in the opposite of what we stated with inturn not
		  strcat(body[instNumBody], buffer);
		  instNumBody++;

		  $$ = $2;	
		  #ifdef PROJECT1
		  printf("Factor : T_NOT Factor\n");		
		  #endif
		}
                | T_IDENTIFIER T_LPAREN T_RPAREN
       		{					
		  #ifdef PROJECT1
		  printf("Factor : T_IDENTIFIER T_LPAREN T_RPAREN\n");		
		  #endif
		}
         	| T_LPAREN Expr T_RPAREN
		{
		  $$ = $2;	
		  #ifdef PROJECT1
		  printf("Factor : T_LPAREN Expr T_RPAREN\n");		
		  #endif
		}
                ;  

 

Variable        : T_IDENTIFIER
		{
		  
		  //if(curOffset < offset){
			int index = findAvailableReg(); //set register equal to constant value to be stored later or printed
			char* reg = registers[index].reg64;
			int indoff = (int)SymGetField(globalSymtab, $1, SYMTAB_OFFSET_FIELD);
			
			
			sprintf(buffer, "\tleaq _gp(%%rip), %s\n\taddq $%d, %s\n", reg , indoff, reg);
			strcat(body[instNumBody],buffer);
			instNumBody++; 
			
			
			setValue($$, index);
			curOffset = getValue($1);
		  //}
		  #ifdef PROJECT1
		  printf("Variable : T_IDENTIFIER\n");		
		  #endif
		}
                | T_IDENTIFIER T_LBRACKET Expr T_RBRACKET    
               	{
		  #ifdef PROJECT1
		  printf("Variable : T_IDENTIFIER T_LBRACKET Expr T_RBRACKET\n");		
		  #endif
               	}
		| T_IDENTIFIER T_LBRACKET Expr T_COMMA Expr T_RBRACKET   
               	{
		  #ifdef PROJECT1
		  printf("Variable  : T_IDENTIFIER T_LBRACKET Expr T_COMMA Expr T_RBRACKET\n");		
		  #endif
               	}
                ;			       

        		       
Constant        : T_FLOATNUM    
		{ 
		  #ifdef PROJECT1
		  printf("Constant : T_FLOATNUM\n");		
		  #endif
		}
		| T_MINUS T_INTNUM
		{ 
		  int index = findAvailableReg();
		  char* reg = registers[index].reg32;
	 	  
		  sprintf(buffer, "\tmovl $%d, %s\n", -atoi($2), reg); //move negative constant into 32 bit register
		  strcat(body[instNumBody],buffer);
		  instNumBody++; 

		  $$ = index;
		  #ifdef PROJECT1
		  printf("Constant : T_MINUS T_INTNUM\n");		
		  #endif
		}
        	| T_INTNUM
		{ 
		  int index = findAvailableReg();
		  char* reg = registers[index].reg32;
	 	  
		  sprintf(buffer, "\tmovl $%d, %s\n", atoi($1), reg); //move positive constant into a 32 bit register
		  strcat(body[instNumBody],buffer);
		  instNumBody++; 

		  $$ = index;

		  #ifdef PROJECT1
		  printf("Constant : T_INTNUM\n");		
		  #endif
		}
		| T_TRUE
		{ 
		 
		  int index = findAvailableReg();
		  char* reg = registers[index].reg32;
	 	  
		  sprintf(buffer, "\tmovl $%d, %s\n", 1, reg); //move the value 1 into a 32 bit regiter 
		  strcat(body[instNumBody],buffer);
		  instNumBody++; 

		  $$ = index;	
		  #ifdef PROJECT1
		  printf("Constant : T_TRUE\n");		
		  #endif
		}
		| T_FALSE
		{ 
		  int index = findAvailableReg();
		  char* reg = registers[index].reg32;
	 	  
		  sprintf(buffer, "\tmovl $%d, %s\n", 0, reg); //move the value 0 into a 32 bit register
		  strcat(body[instNumBody],buffer);
		  instNumBody++; 

		  $$ = index;	
		  #ifdef PROJECT1
		  printf("Constant : T_FALSE\n");		
		  #endif
		}
                ;

%%


/********************C ROUTINES *********************************/
static int findAvailableReg(){
	for(int i = 0; i < 15; i++){
		if(registers[i].used == 0){
			registers[i].used = 1;
			return i;
		}
	}
	printf("No available");
	return -1;
}


static void x86String (int newLine, char* string, char* reg){
	if(newLine){ //for writeln 
		sprintf(buffer,"\t.string_const%d: .string \"%s\\n\"\n",curWord, string); //print string constant in header 
		strcat(header[instNumHead], buffer);
		instNumHead++;

		sprintf(buffer,"\tleaq .string_const%d(%%rip), %s\n",curWord, reg); //call string constant in body
	  	strcat(body[instNumBody], buffer);
		instNumBody++;
	}

	else{ //for write
		sprintf(buffer,"\t.string_const%d: .string \"%s\"\n",curWord, string);
		strcat(header[instNumHead], buffer);
		instNumHead++;
			
		sprintf(buffer,"\tleaq .string_const%d(%%rip), %s\n",curWord, reg);
		strcat(body[instNumBody], buffer);
		instNumBody++;
	}
	curWord++;
}

static void x86PrintNum(int newLine, char* frmt, char* reg){
	if(newLine){//for writeln
		sprintf(buffer,"\t.string_const%d: .string \"%s\\n\"\n",curWord, frmt); //place string constant in header
		strcat(header[instNumHead], buffer);
		instNumHead++;

		sprintf(buffer,"\tleaq .string_const%d(%%rip), %%rdi\n",curWord);
	  	strcat(body[instNumBody], buffer);
		instNumBody++;
	}

	else{ //for write
		sprintf(buffer,"\t.string_const%d: .string \"%s\"\n",curWord, frmt);
		strcat(header[instNumHead], buffer);
		instNumHead++;
			
		sprintf(buffer,"\tleaq .string_const%d(%%rip), %s\n",curWord, reg);
		strcat(body[instNumBody], buffer);
		instNumBody++;
	}

	sprintf(buffer, "\tmovl %s, %%esi\n", reg);
	strcat(body[instNumBody], buffer);
	instNumBody++;

	curWord++;
}

static void x86Read(char* reg){
	sprintf(buffer,"\t.string_const%d: .string \"%%d\"\n",curWord); //place string constant in header 
	strcat(header[instNumHead], buffer);
	instNumHead++;

	sprintf(buffer,"\tleaq .string_const%d(%%rip), %%rdi\n\tmovq %s, %%rsi\n",curWord , reg);
	strcat(body[instNumBody], buffer);
	instNumBody++;

	curWord++;
}

void yyerror(char *s)
{
  fprintf(stderr,"%s: line %d, found %s: %s\n",fileName,yylineno,yytext,s);
}

int yywrap() {
	return 1;
}

static void initialize(char* inputFileName) {
	yyin = fopen(inputFileName,"r");
    if (yyin == NULL) {
        fprintf(stderr,"Error: Could not open file %s\n",inputFileName);
        exit(-1);
    }


	char* dotChar = rindex(inputFileName,'.');
	int endIndex = strlen(inputFileName) - strlen(dotChar);
	char *outputFileName = nssave(2,substr(inputFileName,0,endIndex),".s");
	stdout = freopen(outputFileName,"w",stdout);
        if (stdout == NULL) {
          fprintf(stderr,"Error: Could not open file %s\n",outputFileName);
          exit(-1);
        }
	

	globalSymtab = SymInit(SYMTABLE_SIZE);
	SymInitField(globalSymtab,SYMTAB_VALUE_FIELD,(Generic)-1,NULL);
	SymInitField(globalSymtab,SYMTAB_NAME_FIELD,(Generic)-1,NULL);
	SymInitField(globalSymtab,SYMTAB_OFFSET_FIELD,(Generic)-1,NULL);
}

static void finalize() {
	SymKillField(globalSymtab,SYMTAB_VALUE_FIELD);
    SymKill(globalSymtab);
    fclose(yyin);
    fclose(stdout); //uncomment this line for Project 2
}

int main(int argc, char** argv){	
		//initialize usable registers
	for (int i = 0; i < 14; i++){ //initialize registers
		registers[i].used = 0;
		registers[i].reg32 = reg32[i];
		registers[i].reg64 = reg64[i];
	}

	fileName = argv[1];
	initialize(fileName);
	
	printf("\t.section\t.rodata \n"); //essential x86_64 code
	yyparse();

	if(offset != 0){
		printf("\t.comm _gp, %d, 4\n", offset);
	}
	
	for(int i=0; i<instNumHead; i++){ //prints all declarations in header 
		printf("%s",header[i]);
	}
	
	printf("\t.text\n\t.globl main\n\t.type main,@function\nmain:\tnop\n\tpushq %%rbp\n\tmovq %%rsp, %%rbp\n"); //essential x86_64 code
	
	for(int i=0; i<instNumBody; i++){ //prints all declarations in body
		if(i == instNumBody-1){
			printf("\tmovl $0, %%eax\n");
		}
		printf("%s",body[i]);
	}

	printf("\tleave\n\tret\n"); //essential x86_64 code
	
    
	finalize();
  
	return 0;
}

/**
 *
 * retrieve the value of a key
 *
 * @param name a C character string which is a key
 * @return the value of the key
 */
static int getValue(char *name)
{
  return (int)SymGetField(globalSymtab, name, SYMTAB_VALUE_FIELD); 
}

/**
 *
 * Set the value for a key
 *
 * @param name a C character string which is a key
 * @param value the value of the key
 */
static void setValue(char *name, int value)
{
  SymPutField(globalSymtab, name, SYMTAB_VALUE_FIELD, (Generic)value); 
}


static void setName(char *name, char* str)
{
  SymPutField(globalSymtab, name, SYMTAB_VALUE_FIELD, (Generic)str); 
}


//static char getName(char *name)
//{
  //return (int)SymGetField(globalSymtab, name, SYMTAB_NAME_FIELD); 
//}

/******************END OF C ROUTINES**********************/
