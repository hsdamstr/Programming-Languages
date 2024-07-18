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
#include <util/dlink.h>
#include <util/string_utils.h>
#include <codegen/codegen.h>
#include <codegen/codegen.h>
#include <codegen/reg.h>
#include <codegen/symfields.h>
  
#define SYMTABLE_SIZE 100

/*********************EXTERNAL DECLARATIONS***********************/

EXTERN(void,yyerror,(char*));
EXTERN(int,yylex,(void));

SymTable globalSymtab;

static DList instList;
static DList dataList;
char *fileName;

int globalOffset = 0;
int curLoop = 1; //loop counter to keep track of current loop
int arrStart1 = 0; //starting point of first dim
int arrEnd1 = 0; //ending point of first dim
int arrStart2 = 0; //starting point of second dim
int arrEnd2 = 0; //ending point of second dim
int arrOffset = 0; //size of a given array 
extern int yylineno;
extern char *yytext;
extern FILE *yyin;
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
	int     regIndex;
	int	typeId;
	DList	idList;
	char	*name;
	int 	offset;
}

%type <idList> IdentifierList
%type <typeId> WriteToken
%type <regIndex> Expr AddExpr MulExpr Factor Variable Constant Test TestAndThen WhileToken WhileExpr StandardType ArrayType Type
%type <name> T_STRING T_INTNUM  ProgramHead T_IDENTIFIER OutputFormat Dim

%%
/***********************PRODUCTIONS****************************/

Program : ProgramHeadAndProcedures CompoundStatement T_DOT
		{
			emitProcedureExit(instList);
			emitDataPrologue(dataList);
			emitInstructions(instList);
		}
		;

ProgramHeadAndProcedures : ProgramHead Procedures 
		{
			emitProcedurePrologue(instList,$1);
		}
;

ProgramHead : T_PROGRAM T_IDENTIFIER T_SEMICOLON Decls 
		{
			$$ = "main";
		}
	    ;

       
Decls : T_VAR DeclList
		|
	  	;
	  
DeclList : IdentifierList T_COLON Type T_SEMICOLON
		{   //if type is array then use the other addtosymtab function
			if($3 == 1){
				dlinkApply($1,(DLinkApplyFunc)addArrayIdToSymtab);
			}
			else{
				dlinkApply($1,(DLinkApplyFunc)addIdToSymtab);
			}
			dlinkFreeNodes($1);
		}
		| DeclList IdentifierList T_COLON Type T_SEMICOLON
		{
			if($4 == 1){
				
				dlinkApply($2,(DLinkApplyFunc)addArrayIdToSymtab);
			}
			else{
				dlinkApply($2,(DLinkApplyFunc)addIdToSymtab);
			}
			dlinkFreeNodes($2);
		}
		;
		 
IdentifierList : T_IDENTIFIER
		{
			int symTabIndex = SymIndex(globalSymtab,$1);
			$$ = dlinkListAlloc(NULL);
			dlinkAppend($$,dlinkNodeAlloc((Generic)symTabIndex));
		}
	       | IdentifierList T_COMMA T_IDENTIFIER
		{
			int symTabIndex = SymIndex(globalSymtab,$3);
			dlinkAppend($1,dlinkNodeAlloc((Generic)symTabIndex));
			$$ = $1;
		}
	
Type : StandardType{
		$$ = -1;

		}
		| ArrayType{
			$$ = 1;
		}
	 	;

StandardType 	: T_LONGINT{
		}
		
		| T_BOOLEAN{
		}
		| T_FLOAT{

		}
		;
			
ArrayType : T_ARRAY T_LBRACKET Dim T_RBRACKET T_OF StandardType{
			int symIndex = SymIndex(globalSymtab, $3);
			
			//set global variables to be added to symbol table later
			arrOffset = ((int)SymGetFieldByIndex(globalSymtab, symIndex, SYMTAB_ARROFFSET_FIELD) * 4);
			arrStart1 = (int)SymGetFieldByIndex(globalSymtab, symIndex, SYMTAB_START_FIELD);
			arrEnd1 = (int)SymGetFieldByIndex(globalSymtab, symIndex, SYMTAB_END_FIELD);


		
		}

		| T_ARRAY T_LBRACKET Dim T_COMMA Dim T_RBRACKET T_OF StandardType{
			int symIndex1 = SymIndex(globalSymtab, $3);
			int symIndex2 = SymIndex(globalSymtab, $5);
			
			//set global variables to be added to symbol table later
			arrOffset = ((int)SymGetFieldByIndex(globalSymtab, symIndex1, SYMTAB_ARROFFSET_FIELD) * (int)SymGetFieldByIndex(globalSymtab, symIndex2, SYMTAB_ARROFFSET_FIELD) * 4);
			arrStart1 = (int)SymGetFieldByIndex(globalSymtab, symIndex1, SYMTAB_START_FIELD);
			arrEnd1 = (int)SymGetFieldByIndex(globalSymtab, symIndex1, SYMTAB_END_FIELD);
			arrStart2 = (int)SymGetFieldByIndex(globalSymtab, symIndex2, SYMTAB_START_FIELD);
			arrEnd2 = (int)SymGetFieldByIndex(globalSymtab, symIndex2, SYMTAB_END_FIELD);

		}
		;

Dim : T_INTNUM T_DOTDOT T_INTNUM{
		//index to be accesed in symboltable
		int symIndex = SymIndex(globalSymtab, $$);
		initDims(symIndex,atoi($3), atoi($1));	
		}
	| T_MINUS T_INTNUM T_DOTDOT T_INTNUM{
		
		int symIndex = SymIndex(globalSymtab, $$);
		initDims(symIndex,atoi($4), -atoi($2));	
	}

	|  T_MINUS T_INTNUM T_DOTDOT T_MINUS T_INTNUM{
		int symIndex = SymIndex(globalSymtab, $$);
		initDims(symIndex,-atoi($5), -atoi($2));	
	}
		;

Procedures : Procedures ProcedureDecl
	   | 
	   ;

ProcedureDecl : ProcedureHead ProcedureBody
       ;

ProcedureHead : FunctionDecl Decls 
    	;

FunctionDecl : T_FUNCTION T_IDENTIFIER T_COLON StandardType T_SEMICOLON
   	     ;
	      
ProcedureBody : CompoundStatement T_SEMICOLON
	      ;

Statement : Assignment{
		}
		| IfStatement{
		}
		| WhileStatement{
		
		}
		| IOStatement{
		
		}
		| ExitStatement{
		
		}
	  	| CompoundStatement{
		
		}
		;

Assignment : Variable T_ASSIGN Expr
		{ 
			emitAssignment(instList,$1,$3);
		}
		;
 
IfStatement : T_IF TestAndThen T_ELSE Statement{
			emitLoop(instList, $2); //create a loop header
		}
	    | T_IF TestAndThen{
			emitLoop(instList, $2); //create a loop header 
		}
  	    ;
				
TestAndThen	: Test T_THEN Statement{
			emitJump(instList, curLoop, "jmp"); //jmp to the front of loop
			emitLoop(instList, $1);
			$$ = curLoop;
			curLoop++; //increase loop counter 
		}
		;
				
Test : Expr {
			int leftOperand = emitLoadIntegerConstant(instList, "-1");
			emitTest(instList, leftOperand, $1);
			emitJump(instList, curLoop, "je"); //jump out of loop if test passes
			$$ = curLoop;
			curLoop++; //ncrease loop counter
		}
	 	;

WhileStatement : WhileToken WhileExpr T_DO Statement{
		emitJump(instList, $1, "jmp"); //jmp to front of loop
		emitLoop(instList, $2);
	}
     	;
                
WhileExpr : Expr{
		int leftOperand = emitLoadIntegerConstant(instList, "-1"); //for tests always compare with -1
		emitTest(instList, leftOperand, $1);
		$$ = curLoop;
		emitJump(instList, curLoop++, "je");//jump out of loop
	}
		;
				
WhileToken	: T_WHILE{
		emitLoop(instList, curLoop); //create loop header 
		$$ = curLoop;
		curLoop++;
	}
		;

IOStatement : T_READ T_LPAREN Variable T_RPAREN
		{ 
			emitReadVariable(instList,dataList,  $3);
		}
            | WriteToken T_LPAREN Expr OutputFormat T_RPAREN
		{ 
			emitWriteExpression(instList, dataList, $1, $3, $4);
		}
            | WriteToken T_LPAREN T_STRING OutputFormat T_RPAREN      
		{ 
			emitWriteString(instList, dataList, $1, $3, $4);
		}
            ;

OutputFormat : T_COLON T_INTNUM
        	{
		   $$ = $2;
		} |
		{
		   $$ = NULL;
		}
		;

WriteToken : T_WRITE
		{$$ = IS_WRITE;}
	    | T_WRITELN
		{$$ = IS_WRITELN;}
		;
			 
ExitStatement : T_EXIT T_LPAREN Expr T_RPAREN 
		;

CompoundStatement : T_BEGIN StatementList T_END
		;
                  
StatementList : StatementList T_SEMICOLON Statement
			  | Statement
              ;

 
Expr	: AddExpr
		{
			$$ = $1; 
		}
                | Expr T_EQ AddExpr
		{
			$$ = emitEqualExpression(instList,$1,$3);
		}
                | Expr T_NE AddExpr
		{
			$$ = emitNotEqualExpression(instList,$1,$3);
		}
                | Expr T_LE AddExpr
		{
			$$ = emitLessEqualExpression(instList,$1,$3);
		}
                | Expr T_LT AddExpr
		{
			$$ = emitLessThanExpression(instList,$1,$3);
		}
                | Expr T_GE AddExpr
		{
			$$ = emitGreaterEqualExpression(instList,$1,$3);
		}
                | Expr T_GT AddExpr
		{
			$$ = emitGreaterThanExpression(instList,$1,$3);
		}
                ;

AddExpr		:  MulExpr            
		{
			$$ = $1; 
		}
		| AddExpr T_OR MulExpr 
		{
			$$ = emitOrExpression(instList,$1,$3);
		}
                |  AddExpr T_PLUS MulExpr
		{
			$$ = emitAddExpression(instList,$1,$3);
		}
                |  AddExpr T_MINUS MulExpr
		{
			$$ = emitSubtractExpression(instList,$1,$3);
		}
                ;

MulExpr		:  Factor
        	{$$ =$1;}
	    	| MulExpr T_TIMES Factor
		{
			$$ = emitMultiplyExpression(instList,$1,$3);
		}
                |  MulExpr T_DIV Factor
		{
			$$ = emitDivideExpression(instList,$1,$3);
		}	
		     | MulExpr T_AND Factor 
		{
			$$ = emitAndExpression(instList,$1,$3);
		}	
                ;
		

Factor          : Variable
		{ 
			$$ = emitLoadVariable(instList, $1);
		}
                | Constant
		{ 
			$$ = $1;
		}
		|  T_NOT Factor
		{
			$$ = emitNotExpression(instList,$2);
		}
		| T_IDENTIFIER T_LPAREN T_RPAREN
		| T_LPAREN Expr T_RPAREN
		{
			$$ = $2;
		}
                ;  

 

Variable        : T_IDENTIFIER
		{
			int symIndex = SymQueryIndex(globalSymtab,$1);
			$$ = emitComputeVariableAddress(instList, symIndex);
		}
        | T_IDENTIFIER T_LBRACKET Expr T_RBRACKET {
			int symIndex = SymQueryIndex(globalSymtab,$1);
			$$ = emitComputeArrayAddress(instList, symIndex, $3); //find array adress

		}   
		| T_IDENTIFIER T_LBRACKET Expr T_COMMA Expr T_RBRACKET {
			int symIndex = SymQueryIndex(globalSymtab,$1);
			$$ = emitCompute2DArrayAddress(instList, symIndex, $3, $5); //find 2d array adress


			
		}  
                ;			       

        		       
Constant        : T_FLOATNUM    
		| T_MINUS T_INTNUM
		{   
			char *negstr = nssave(2, "-", $2);
			$$ = emitLoadIntegerConstant(instList,negstr); 
		}
        	| T_INTNUM
		{ 
			$$ = emitLoadIntegerConstant(instList,$1); 
		}
		| T_TRUE
		{ 
			$$ = emitLoadIntegerConstant(instList,"1"); 
		}
		| T_FALSE
		{ 
			$$ = emitLoadIntegerConstant(instList,"0"); 
		}
                ;

%%


/********************C ROUTINES *********************************/
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
	SymInitField(globalSymtab,SYMTAB_OFFSET_FIELD,(Generic)-1,NULL);
	initRegisters();
	
	instList = dlinkListAlloc(NULL);
	dataList = dlinkListAlloc(NULL);
}

static void finalize() {

    fclose(stdin);
    fclose(stdout);
    
    SymKillField(globalSymtab,SYMTAB_OFFSET_FIELD);
    SymKill(globalSymtab);
 
    cleanupRegisters();
    
    dlinkFreeNodesAndAtoms(instList);
    dlinkFreeNodesAndAtoms(dataList);

}

int main(int argc, char** argv)

{	
	fileName = argv[1];
	initialize(fileName);
	
	yyparse();
    
	finalize();
  
	return 0;
}
/******************END OF C ROUTINES**********************/
