#ifndef CODEGEN_H_
#define CODEGEN_H_
                         
EXTERN(void, emitProcedurePrologue, (DList instList, char* name));
EXTERN(void, emitProcedureExit, (DList instList));
EXTERN(void, emitDataPrologue, (DList dataList));
EXTERN(void, emitInstructions,(DList list));
EXTERN(void, emitAssignment, (DList instList, int lhsRegIndex, int rhsRegIndex));
EXTERN(void, emitLoop, (DList instList, int loop));
EXTERN(void, emitJump, (DList instList, int loop, char*opCode));
EXTERN(void, emitTest, (DList instList, int leftOperand, int rightOperand));
EXTERN(void, emitReadVariable, (DList instList, DList dataList, int addrIndex));
EXTERN(void, emitWriteExpression, (DList instList, DList dataList, int writeType, int regIndex, char *length));
EXTERN(void, emitWriteString,(DList instList,  DList dataList, int writeType, char *str, char *length));
EXTERN(int, emitOrExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitAndExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitNotExpression, (DList instList, int operand));
EXTERN(int, emitEqualExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitNotEqualExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitLessEqualExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitLessThanExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitGreaterEqualExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitGreaterThanExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitAddExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitSubtractExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitMultiplyExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitDivideExpression, (DList instList, int leftOperand, int rightOperand));


EXTERN(int, emitComputeVariableAddress,(DList instList, int varIndex));
EXTERN(int, emitComputeArrayAddress, (DList instList, int varIndex, int expr));
EXTERN(int, emitCompute2DArrayAddress, (DList instList, int varIndex, int expr, int expr2));

EXTERN(int, emitLoadVariable,(DList instList, int varIndex));
EXTERN(int, emitLoadIntegerConstant,(DList instList, char* intConst));

EXTERN(void, initDims,(int index, int start, int end));

EXTERN(void, addIdToSymtab, (DNode node));
EXTERN(void, addArrayIdToSymtab,(DNode node));

EXTERN(void,yyerror,(char*));

#define IS_WRITE 0
#define IS_WRITELN 1
#endif /*CODEGEN_H_*/

