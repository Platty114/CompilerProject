%{
    // C code
    #include<stdio.h>
    #include"scanner.h"
    #include"myAST.h"
    struct decl *parser_result = 0;
    int yyerror(char *msg);
%}

%define parse.error verbose

%token PLUS MULT MINUS DIV O_PAREN C_PAREN SEMICOLON LESS LESS_EQUALS GREATER GREATER_EQUALS EQUALS EQUALS_EQUALS NOT_EQUALS COMMA O_BRACE C_BRACE O_BRACK C_BRACK IF WHILE ELSE INT RETURN VOID NUM ID ERROR
%union {
    struct decl *decl;
    struct param * param;
    struct comp_stmt * compStmt;
    struct stmt * stmt;
    struct expr *expr;
    struct var * var;
    struct simple_expr * simple_expr;
    struct add_expr * add_expr;
    struct term * term;
    struct factor * factor;
    struct call * call;
    struct argsList * argsList;
    struct args * args;

    char *id;
    int num;
}

%type<decl> prog decList dec varDec funcDec localDecs
%type<param> params paramList param
%type<compStmt> compStmt
%type<stmt> stmt stmtList expStmt selecStmt iterStmt returnStmt
%type<expr> exp
%type<var> var
%type<simple_expr> simpExp
%type<add_expr> addExp
%type<term> term
%type<factor> fact
%type<call> call
%type<args> args
%type<argsList> argList

%type<id> ID
%type<num> NUM relateOp addOp mulOp type
%%
// grammar rules

prog: decList 
        {parser_result = $1;};

decList: decList dec {$$ = $2; $2->next = $1;}| dec {$$ = $1;};

dec: varDec 
        {$$ = $1;}
    | funcDec 
        {$$ = $1;};

varDec: type ID SEMICOLON 
        {$$ = createDecl($1, $2, -1, 0, 0);}
    | type ID O_BRACK NUM C_BRACK SEMICOLON 
        {$$ = createDecl($1, $2, $4, 0, 0);};

type: INT 
        {$$ = Int;}
    | VOID 
        {$$ = Void;};

funcDec: 
    type ID O_PAREN params C_PAREN compStmt 
        {$$ = createDecl($1, $2, -1, $4, $6);};

params: paramList {$$ = $1;} | VOID {$$ = 0;};

paramList: paramList COMMA param 
        {$$ = $3; $3->next = $1;}
    | param 
        {$$ = $1; $1->next = 0;};

param: type ID 
        {$$ = createParam($1, $2, 0);}
    | type ID O_BRACK C_BRACK 
        {$$ = createParam($1, $2, 1);};

compStmt: O_BRACE localDecs stmtList C_BRACE 
    {$$ = createCompStmt($2, $3);};

localDecs: localDecs varDec 
        {$$ = $2; $2->next = $1;}
    | {$$ = 0;};

stmtList: stmtList stmt  
        {$$ = $2; $2->next = $1;}
    | ;

stmt: expStmt SEMICOLON
        {$$ = $1;}
    | selecStmt 
        {$$ = $1;}
    | iterStmt
        {$$ = $1;}
    | returnStmt 
        {$$ = $1;};

expStmt: exp {$$ = createStmt($1,0,0,0,0,0,0, 1);};

selecStmt: IF O_PAREN exp C_PAREN stmt
        {$$ = createStmt(0, $3, $5, 0,0,0,0,3);}
    | IF O_PAREN exp C_PAREN stmt ELSE stmt
        {$$ = createStmt(0, $3, $5, $7,0,0,0,3);};

iterStmt: WHILE O_PAREN exp C_PAREN stmt
    {$$ = createStmt(0, 0, 0, 0,$3,$5,0,4);};

returnStmt: RETURN SEMICOLON
        {$$ = createStmt(0,0,0,0,0,0,0,5);}
    | RETURN exp SEMICOLON
        {$$ = createStmt(0, 0, 0, 0,0,0,$2,5);}; 

exp: var EQUALS_EQUALS exp
        {$$ = createExpr(1, $1, $3, 0);}
    | var EQUALS exp 
        {$$ = createExpr(2, $1, $3, 0);}
    | simpExp
        {$$ = createExpr(3, 0, 0, $1);};

var: ID
        {$$ = createVar($1, 0);}
    | ID O_BRACK exp C_BRACK
        {$$ = createVar($1, $3);};

simpExp: addExp relateOp addExp 
        {$$ = createSimpleExpr($1, $2, $3);}
    | addExp
        {$$ = createSimpleExpr($1, 0, 0);};

relateOp: LESS_EQUALS
        {$$ = Less_EQUALS;}
    | LESS
        {$$ = Less;} 
    | GREATER
        {$$ = Greater;}
    | GREATER_EQUALS
        {$$ = Greater_EQUALS;} 
    | EQUALS_EQUALS
        {$$ = Equals_EQUALS;} 
    | NOT_EQUALS
       {$$ = Not_EQUALS;}; 

addExp: addExp addOp term 
        {$$ = createAddExp($1, $2, $3);}
    | term
        {$$ = createAddExp(0, 0, $1);};

addOp: PLUS
        {$$ = AD;}
    | MINUS
        {$$ = MIN;};

term: term mulOp fact
        {$$ = createTerm($1, $2, $3);}
    | fact
        {$$ = createTerm(0, 0, $1);};

mulOp: MULT
        {$$ = MULPY;}
    | DIV
        {$$ = DIVIDE;};

fact: O_PAREN exp C_PAREN 
        {$$ = createFact($2, 0, 0, 0, 1);}
    | var
        {$$ = createFact(0, $1, 0, 0, 2);} 
    | call
        {$$ = createFact(0, 0, $1, 0, 3);} 
    | NUM
        {$$ = createFact(0, 0, 0, $1, 4);};

call: ID O_PAREN args C_PAREN
    {$$ = createCall($1, $3);}; 

args: argList {$$ = createArgs($1);}| {$$ = 0;};

argList: argList COMMA exp 
        {$$ = createArgsList($1, $3);}
    | exp
        {$$ = createArgsList(0, $1);};



%%

// C code 

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


int main(int argc, char **argv){
   /*

    if(argc > 1){
        yyin = fopen(argv[1], "r");
        if(!yyin){
            printf("error reading the file: %s\n", argv[1]);
            return 1;
        }
    }else {
        printf("usage: ./parser <filename>");
        return 1;
    }

    int result = yyparse();


    if(result == 0){
        printExpr(parser_result);
        printf("\nparsing successful");
    }else {
        printf("parsing failed");
    }

   */

    if(argc > 1){
        yyin = fopen(argv[1], "r");
        if(!yyin){
            printf("error reading the file: %s\n", argv[1]);
            return 1;
        }
    }else {
        printf("usage: ./parser <filename>");
        return 1;
    }

    int result = yyparse();

    if(result == 0){
        printf("pring the tree!\n");
        printTree(parser_result);
        printf("\nparsing successful");
    }else {
        printf("parsing failed");
    }

    return result;

}

int yyerror(char *msg){
    printf("parsing failed: %s\n", msg);
    return 1;
}
