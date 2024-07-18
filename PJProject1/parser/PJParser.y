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
#include <math.h>

#define SYMTABLE_SIZE 100
#define SYMTAB_VALUE_FIELD  "value"

/* delete or comment out the line below after you have a good grasp of Project 1. It will turn off all printf statements that print the grammar rules */ 
//#define PROJECT1
/*********************EXTERNAL DECLARATIONS***********************/

EXTERN(void,yyerror,(char*));
EXTERN(int,yylex,(void));

char *fileName;

extern int yylineno;
extern char *yytext;
extern FILE *yyin;

SymTable globalSymtab;

static int getValue(char *name);
static void setValue(char *name, int value);
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
  char *name;
  int value;
  bool boolean;
}


%type <boolean>  T_TRUE T_FALSE
%type <name> T_STRING Variable T_IDENTIFIER 
%type <value> WriteToken T_INTNUM T_FLOATNUM OutputFormat Factor Constant Expr AddExpr MulExpr


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
		  #ifdef PROJECT1
		  printf("IdentifierList : T_IDENTIFIER\n");		
		  #endif
		}
	       	| IdentifierList T_COMMA T_IDENTIFIER
		{
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
		  setValue($1, $3); //set value in symtable to not overwrite registers

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
		  
		  int val; //integer to be read in
		  scanf("%d", &val);
		  setValue($3, val); //set value in symtab to not overwrite other registers

		  #ifdef PROJECT1
		  printf("IOStatement : T_READ T_LPAREN Variable T_RPAREN\n");		
		  #endif
		}
		| WriteToken T_LPAREN Expr OutputFormat T_RPAREN
		{ 


		  int digits = ceil($3/10); //how many digits are in the expr (for formatting)
		  int space = 0;
		  if ($4 - digits > 0 && $4 != 0){
			space = $4 - digits; //formatting
		  }

		  if ($3 < 0){
			space -= 1;
		  }

		  char format [space]; //fill with spaces 

		  for (int i = 0; i < space; i++){ //add extra spaces onto string
			format[i] = ' ';
		  }
		  
		  format[space] = '\0'; //setting the last value in char array to /0 so no junk values are printed

		
		  
			if ($1)
				printf("%s%d\n", format, $3);
			else
				printf("%s%d", format, $3);
	
		  

		  #ifdef PROJECT1
		  printf("IOStatement : WriteToken T_LPAREN Expr OutputFormat T_RPAREN\n");		
		  #endif
		}
		| WriteToken T_LPAREN T_STRING OutputFormat T_RPAREN      
		{ 
		 
		  int size = strlen($3);
		  int altSize = size - 2; 
		  int dif  = 0;

		  if($4 - (size - 2) > 0){ //pascal disregards formatting if number of chars is greater then format value therefore only set if necessary
			altSize = $4;
			dif = $4 - (size - 2);
		  }

		  char format [dif];

		  char newstr [size - 2]; //size of string without back quotes
		  
		  for (int i = 0; i < dif; i++){ //format string 
			format[i] = ' ';
		  }
		  	format[dif] = '\0'; //setting the last value in char array to /0 so no junk values are printed

		  for (int i = 1; i < size - 1; i++){ //copy string without single quotes
			newstr[i-1] = $3[i];
		  }

		  newstr[size - 2] = '\0'; //setting the last value in char array to /0 so no junk values are printed

		  if ($1)
		  	 printf("%s%s\n", format, newstr);
		  else
		  	printf("%s%s", format, newstr);

		  #ifdef PROJECT1
		  printf("IOStatement : WriteToken T_LPAREN T_STRING OutputFormat T_RPAREN\n");		
		  #endif
		}
		;

OutputFormat 	: T_COLON T_INTNUM
        	{
		  $$ = $2; //set value of output format to the amount of space allocated
		  #ifdef PROJECT1
		  printf("OutputFormat : T_COLON T_INTNUM\n");		
		  #endif
		} 
		|
		{
		  $$ = 0;
		  #ifdef PROJECT1
		  printf("OutputFormat : \n");		
		  #endif
		}
		;

WriteToken 	: T_WRITE
             	{
		  $$ = 0; //setting T_Write to 0 in order to differentiate it from T_WriteLN
		  #ifdef PROJECT1
		  printf("WriteToken : T_WRITE\n");		
		  #endif
		}
	    	| T_WRITELN //setting T_Write to 1 in order to differentiate it from T_WriteLN
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
		  if($1 == $3){ //if eq true
			$$ = true;
		  }	
		  else{
			$$ = false;
		  }
		  #ifdef PROJECT1
		  printf("Expr : Expr T_EQ AddExpr\n");		
		  #endif
		}
                | Expr T_NE AddExpr
		{
		  if ($1 != $3){ //if ne true
			$$ = true;
		  }
		  else{
			$$=false;
		  }
		  #ifdef PROJECT1
		  printf("Expr : Expr T_NE AddExpr\n");		
		  #endif
		}
                | Expr T_LE AddExpr
		{
		  if($1 <= $3){ //if le true
			$$ = true;
		  }
		  else{
			$$ = false;
		  }
		  #ifdef PROJECT1
		  printf("Expr : Expr T_LE AddExpr\n");		
		  #endif
		}
                | Expr T_LT AddExpr
		{
		  if($1 < $3){ //if lt true
			$$ = true;
		  }
		  else{
			$$ = false;
		  }
		  #ifdef PROJECT1
		  printf("Expr : Expr T_LT AddExpr\n");		
		  #endif
		}
                | Expr T_GE AddExpr
		{
		  if($1 >= $3){ //if ge true
			$$ = true;
		  }
		  else{
			$$ = false;
		  }
		  #ifdef PROJECT1
		  printf("Expr : Expr T_GE AddExpr\n");		
		  #endif
		}
                | Expr T_GT AddExpr
		{
		  if($1 > $3){ //if gt true
			$$ = true;
		  }
		  else{
			$$ = false;
		  }
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
		  if ($1 == true || $3 == true){ //if either addepr or mulexpr or true then true
			$$ = true;
		  }
		  else{
			$$ = false;
		  }
		  #ifdef PROJECT1
		  printf("AddExpr : AddExpr T_OR MulExpr\n");		
		  #endif
		}
                | AddExpr T_PLUS MulExpr
		{
		  $$ = $1 + $3; //add registers together 
		  #ifdef PROJECT1
		  printf("AddExpr : AddExpr T_PLUS MulExpr\n");		
		  #endif
		}
                | AddExpr T_MINUS MulExpr
		{
		  $$ = $1 - $3; //subtract registers
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
		  $$ = $1 * $3; //multiply registers
		  #ifdef PROJECT1
		  printf("MulExpr : MulExpr T_TIMES Factor\n");		
		  #endif
		}
                | MulExpr T_DIV Factor
		{
	      $$ = $1 / $3; //divide registers
		  #ifdef PROJECT1
		  printf("MulExpr : MulExpr T_DIV Factor\n");		
		  #endif
		}	
		| MulExpr T_AND Factor 
		{
		  if ($1 == true && $3 == true){ //if both registers are true then tru
			$$ = true;
		  }
		  else{
			$$ = false;
		  }
		  #ifdef PROJECT1
		  printf("MulExpr : MulExpr T_AND Factor\n");		
		  #endif
		}	
                ;
		

Factor          : Variable
		{ 
		  $$ = getValue($1); // get the value of the variable set in assignment 
		  #ifdef PROJECT1
		  printf("Factor : Variable\n");		
		  #endif
		}
                | Constant
		{ 
		  $$ = $1; // set factor equal to whatever the constant was 
		  #ifdef PROJECT1
		  printf("Factor : Constant\n");		
		  #endif
		}
	    	| T_NOT Factor
		{
		  $$ = !$2;
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
		  $$ = ($2);
		  #ifdef PROJECT1
		  printf("Factor : T_LPAREN Expr T_RPAREN\n");		
		  #endif
		}
                ;  

 

Variable        : T_IDENTIFIER
		{
		  $$ = $1; //set the name of the variable = to the string value
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
		  $$ = $1;
		  #ifdef PROJECT1
		  printf("Constant : T_FLOATNUM\n");		
		  #endif
		}
		| T_MINUS T_INTNUM
		{   
		  $$ = -$2; //negative values
		  #ifdef PROJECT1
		  printf("Constant : T_MINUS T_INTNUM\n");		
		  #endif
		}
        	| T_INTNUM
		{ 
		  $$ = $1;
		  #ifdef PROJECT1
		  printf("Constant : T_INTNUM\n");		
		  #endif
		}
		| T_TRUE
		{ 
		  $$ = $1;
		  #ifdef PROJECT1
		  printf("Constant : T_TRUE\n");		
		  #endif
		}
		| T_FALSE
		{ 
		  $$ = $1;
		  #ifdef PROJECT1
		  printf("Constant : T_FALSE\n");		
		  #endif
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

	/* uncomment this section for Project 2
	char* dotChar = rindex(inputFileName,'.');
	int endIndex = strlen(inputFileName) - strlen(dotChar);
	char *outputFileName = nssave(2,substr(inputFileName,0,endIndex),".s");
	stdout = freopen(outputFileName,"w",stdout);
        if (stdout == NULL) {
          fprintf(stderr,"Error: Could not open file %s\n",outputFileName);
          exit(-1);
        }
	*/

	globalSymtab = SymInit(SYMTABLE_SIZE);
	SymInitField(globalSymtab,SYMTAB_VALUE_FIELD,(Generic)-1,NULL);	
}

static void finalize() {
    SymKillField(globalSymtab,SYMTAB_VALUE_FIELD);
    SymKill(globalSymtab);
    fclose(yyin);
    // fclose(stdout); //uncomment this line for Project 2
}

int main(int argc, char** argv)

{	
	fileName = argv[1];
	initialize(fileName);
	
	yyparse();
    
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
/******************END OF C ROUTINES**********************/
