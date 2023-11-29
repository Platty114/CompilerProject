
%{
    // C code (will be placed at the begining of the scanner.c)
    // " " means empty

    // The grammar:
    // Prog -> DecList;
    // DecList -> DecList Dec | Dec
    // Dec -> VarDec | FuncDec
    // VarDec -> TypeID; | TypeID[NUM]
    // Type -> INT | VOID
    // FuncDec -> TypeID(Params)CompStmt
    // Params -> ParamList | VOID
    // ParamList -> ParamList,Param | Param
    // Param -> Type ID | Type ID[]
    // the bellow line may need to be checked
    // CompStmt -> {LocalDecs StmtList}
    // LocalDecs -> LocalDecs VarDecs | empty
    // StmtList -> StmtList Stmt | " "
    // Stmt -> ExpStmt | CompStmt | SelecStmt | IterStmt | ReturnStmt
    // ExpStmt -> Exp;
    // SelecStmt -> IF(Exp) Stmt | IF(Exp) Stmt ELSE Stmt
    // IterStmt -> WHILE(Exp) Stmt
    // ReturnStmt -> RETURN ; | RETURN Exp;
    // Exp -> Var = Exp | SimpExp
    // Var -> ID | ID[Exp] 
    // SimpExp -> AddExp RelateOp AddExp | AddExp
    // RelateOp -> LESS_EQUALS | LESS | GREATER | GREATER_EQUALS | EQUALS_EQUALS | NOT_EQUALS
    // AddExp -> AddExp AddOp Term | Term
    // AddOp -> PLUS | MINUS
    // Term -> Term MulOp Fact | Fact
    // MulOp -> MULT | DIV
    // Fact -> (Exp) | Var | Call | NUM
    // Call -> ID(Args)
    // Args -> ArgList | " "
    // ArgList -> ArgList, Exp | Exp  
    #include "parser.h"
%}

DIGIT   [0-9]
LETTER [a-z|A-Z]

%%
"+"     {return PLUS;}
"*"     {return MULT;}
"-"     {return MINUS;}
"/"     {return DIV;}
"("     {return O_PAREN;}
")"     {return C_PAREN;}
";"     {return SEMICOLON;}
"<"	    {return LESS;}
"<="	{return LESS_EQUALS;}
">"	    {return GREATER;}
">="	{return GREATER_EQUALS;}
"="	    {return EQUALS;}
"=="	{return EQUALS_EQUALS;}
"|="	{return NOT_EQUALS;}
","	    {return COMMA;}
"{"	    {return O_BRACE;}
"}"	    {return C_BRACE;}
"["	    {return O_BRACK;}
"]"	    {return C_BRACK;}
"if"      {return IF;}
"while"   {return WHILE;}
"else"  {return ELSE;}
"int"   {return INT;}
"return"    {return RETURN;}
"void"      {return VOID;}

{DIGIT}+    {yylval.num = atoi(yytext); return NUM;}
{LETTER}+   {yylval.id = strdup(yytext); return ID;}

(" "|\t|\n|"/* */")     /* skip whitespaces, and comments */

.   {return ERROR;}   
%%

// C code
// will be placed at the end of the scanner.c
int yywrap(){
    return 1;
}
