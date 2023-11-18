/*
defining all enumerations 
mostly used to make printing and keeping track of state
easier.
*/

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

typedef enum {
    Int,
    Void
} type_spec;

typedef enum{
    EXPR_STMT,
    COMP_STMT,
    SELEC_STMT,
    ITER_STMT,
    RETURN_STMT
} stmt_type;

typedef enum{
    Equals,
    EQUALS_EACH,
    SIMPLE
} expr_type;

typedef enum{
    Less,
    Less_EQUALS,
    Greater,
    Greater_EQUALS,
    Equals_EQUALS,
    Not_EQUALS
} relateOp_type;

typedef enum {
    AD,
    MIN
} add_type;

typedef enum {
    MULPY,
    DIVIDE
} mult_type;

typedef enum{
    EXPR,
    VAR,
    CALL,
    NUMBER
} factor_type;

/*
defining all struct types, there are about 20 total.
*/

struct argsList {
    struct argsList* argsList;
    struct expr* expr;
};

struct args{
    struct argsList* argsList;
};

struct call{
    char* ID;
    struct args* args;
};

struct factor {
    struct expr* expr;
    struct var* var;
    struct call* call;
    int NUM;
    factor_type type;
};

struct term {
    struct term* left;
    struct factor* right;
    mult_type type;
};

struct add_expr {
    struct add_expr* left;
    struct term* right;
    add_type type;
};

struct simple_expr{
    struct add_expr* left;
    struct add_expr* right;
    relateOp_type type;
};

struct var {
    char* ID;
    int array;
    struct expr* expr;
};

struct expr {
    expr_type type;
    struct var* var;
    struct expr* expr;
    struct simple_expr* simple_expr;
};

struct stmt {
    struct expr* expr;
    struct expr* if_expr;
    struct stmt* if_stmt;
    struct stmt* else_stmt;
    struct expr* w_expr;
    struct stmt* w_stmt;
    struct expr* r_expr;
    stmt_type type;
    struct stmt* next;
};

struct comp_stmt{
    struct decl* local_decs;
    struct stmt* local_stmts;
};

struct type {
    type_spec type;
};

struct param {
    type_spec type;
    char* ID;
    bool array;
    struct param* next;
};

struct decl {
    struct type * decl_type;
    char* ID;
    int array;
    struct param* params;
    struct comp_stmt* compStmt;
    struct decl* next;
};


// create functions

struct args * createArgs(
    struct argsList * argsList
){
    struct args * newArgs = (struct args * ) malloc(sizeof(struct args));
    newArgs->argsList = argsList;

    return newArgs;
}

struct argsList * createArgsList(
    struct argsList * next,
    struct expr * inExpr
){  
    struct argsList * newArgsList = (struct argsList *) malloc(sizeof(struct argsList));
    newArgsList->argsList = next;
    newArgsList->expr = inExpr;

    return newArgsList;
}

struct call * createCall(
    char * ID,
    struct args * inArgs
){
    struct call * newCall = (struct call *) malloc(sizeof(struct call));
    newCall->ID = (char *) malloc(strlen(ID) +1);
    strcpy(newCall->ID, ID);

    newCall->args = inArgs;

    return newCall;
}

struct factor * createFact(
    struct expr * inexpr,
    struct var * inVar,
    struct call * inCall,
    int inNUM,
    int typeNum
){
    struct factor * newFactor = (struct factor *) malloc(sizeof(struct factor));
    newFactor->expr = inexpr;
    newFactor->call = inCall;
    newFactor->var = inVar;
    newFactor->NUM = inNUM;

    switch(typeNum){
        case 1:
            newFactor->type = EXPR;
            break;
        case 2:
            newFactor->type = VAR;
            break;
        case 3:
            newFactor->type = CALL;
            break;
        case 4:
            newFactor->type = NUMBER;
            break;
    }

    return newFactor;
}

struct term * createTerm(
    struct term * inLeft,
    mult_type type,
    struct factor * inRight
){
    struct term * newTerm = (struct term *) malloc(sizeof(struct term));
    newTerm->left = inLeft;
    newTerm->right = inRight;
    newTerm->type = type;

    return newTerm;
}

struct add_expr * createAddExp(
    struct add_expr * inLeft,
    add_type type,
    struct term * inRight
){
    struct add_expr * newAddExpr = (struct add_expr *) malloc(sizeof(struct add_expr));
    newAddExpr->left = inLeft;
    newAddExpr->right = inRight;
    newAddExpr->type = type;

    return newAddExpr;
}

struct simple_expr * createSimpleExpr(
    struct add_expr * inLeft,
    relateOp_type type,
    struct add_expr * inRight
){
    struct simple_expr * newSimple = (struct simple_expr * ) malloc(sizeof(struct simple_expr));
    newSimple->left = inLeft;
    newSimple->right = inRight;
    newSimple->type = type;

    return newSimple;
}

struct var* createVar(
    char* ID, 
    struct expr* inExpr
){
    struct var * newVar = (struct var *) malloc(sizeof(struct var));
    newVar->ID = (char *) malloc(strlen(ID) +1);
    strcpy(newVar->ID, ID);
    newVar->expr = inExpr;
    if(inExpr != NULL){
        newVar->array = 1;
    }
    else{
        newVar->array = 0;
    }

    return newVar;

}


struct expr * createExpr(
    int numType, 
    struct var* var,
    struct expr* inExpr,
    struct simple_expr* simple_expr
){
    struct expr* newExpr = (struct expr *) malloc(sizeof(struct expr));
    newExpr->var = var;
    newExpr->expr = inExpr;
    newExpr->simple_expr = simple_expr;

    switch(numType){
        case 1:
            newExpr->type = EQUALS_EACH;
            break;
        case 2:
            newExpr->type = Equals;
            break;
        case 3:
            newExpr->type = SIMPLE;
            break;
    }

    return newExpr;
}

struct stmt* createStmt(
    struct expr * expression,
    struct expr * ifExpr,
    struct stmt * ifStmt,
    struct stmt * elseStmt,
    struct expr* w_expr,
    struct stmt* w_stmt,
    struct expr* r_expr,
    int numType
){
    struct stmt * newStmt = (struct stmt * ) malloc(sizeof(struct stmt));
    newStmt->expr = expression;
    newStmt->if_expr = ifExpr;
    newStmt->if_stmt = ifStmt;
    newStmt->else_stmt = elseStmt;
    newStmt->w_expr = w_expr;
    newStmt->w_stmt = w_stmt;
    newStmt->r_expr = r_expr;
    newStmt->next = NULL;
    switch(numType){
        case 1:
            newStmt->type = EXPR_STMT;
            break;
        case 2:
            newStmt->type = COMP_STMT;
            break; 
        case 3:
            newStmt->type = SELEC_STMT;
            break;
        case 4:
            newStmt->type = ITER_STMT;
            break;
        case 5:
            newStmt->type = RETURN_STMT;
            break;  
    }

    return newStmt;
}

struct comp_stmt * createCompStmt(
    struct decl * localDecs,
    struct stmt* localStmt
){
    struct comp_stmt * newComp = (struct comp_stmt *) malloc(sizeof(struct comp_stmt));
    newComp->local_decs = localDecs;
    newComp->local_stmts = localStmt;

    return newComp;
}

struct param * createParam(
    type_spec type,
    char* ID,
    int array
){
    struct param * newParam = (struct param*) malloc(sizeof(struct param));
    newParam->ID = (char *) malloc(strlen(ID) +1); 
    newParam->ID = strcpy(newParam->ID, ID);
    newParam->array = array == 1 ? true : false;
    newParam->type = type;

    return newParam;
}

struct decl * createDecl(
    type_spec type, 
    char* ID, 
    int arraySize, 
    struct param* params, 
    struct comp_stmt* comp_stmt
    ){
        struct decl *newDecl = (struct decl *) malloc(sizeof(struct decl));
        newDecl->ID = (char *) malloc(strlen(ID) +1);
        newDecl->ID = strcpy(newDecl->ID, ID);
        newDecl->array = arraySize;
        newDecl->params = params;
        newDecl->compStmt = comp_stmt;
        struct type * temp = (struct type*) malloc(sizeof(struct type));
        temp->type = type;
        newDecl->decl_type = temp;

        return newDecl;
    }

// printing functions

int line = 0;

void printParam(struct param* inputParams);
void printCompStmt(struct comp_stmt * comp);
void printDecl(struct decl * parser_result);
void printStmt(struct stmt * stmt);
void printExpr(struct expr * expr);
void printVar(struct var * var);
void printSimple(struct simple_expr * simple);
void printAddExpr(struct add_expr * addExpr);
void printTerm(struct term * term);
void printFact(struct factor * fact);
void printCall(struct call * call);
void printArgs(struct args * args);
void printArgsList(struct argsList * argsList);

void printArgsList(struct argsList * argsList){
    if(argsList == NULL){
        return ;
    }
    else {
        if(argsList->argsList != NULL){
            printArgsList(argsList->argsList);
            printf(",");
        }
        printExpr(argsList->expr);
    }
}

void printArgs(struct args * args){
    if(args == NULL){
        return;
    }
    printArgsList(args->argsList);
}

void printCall(struct call * call){
    if(call == NULL){
        return;
    }
    else {
        printf("%s(", call->ID);
        printArgs(call->args);
        printf(")");
    }
}

void printFact(struct factor * fact){
    if(fact == NULL){
        return;
    }
    else{
        switch(fact->type){
            case EXPR:
                printf("(");
                printExpr(fact->expr);
                printf(")");
                break;
            case VAR:
                printVar(fact->var);
                break;
            case CALL:
                printCall(fact->call);
                break;
            case NUMBER:
                printf("%d", fact->NUM);
                break;
        }
    }
}

void printTerm(struct term * term){
    if(term == NULL){
        return;
    }
    else {
        if(term->left != NULL){
            switch(term->type){
                case MULPY:
                    printTerm(term->left);
                    printf(" * ");
                    printFact(term->right);
                    break;
                case DIVIDE:
                    printTerm(term->left);
                    printf(" / ");
                    printFact(term->right);
                    break;
            }
        }
        else {
            printFact(term -> right);
        }
    }
}

void printAddExpr(struct add_expr * addExpr){
    if(addExpr == NULL){
        return;
    }
    else {
        if(addExpr->left != NULL){
            switch(addExpr->type){
                case AD:
                    printAddExpr(addExpr->left);
                    printf(" + ");
                    printTerm(addExpr->right);
                    break;
                case MIN:
                    printAddExpr(addExpr->left);
                    printf(" - ");
                    printTerm(addExpr->right);
                    break;
            }
        }
        else {
            printTerm(addExpr -> right);
        }
    }
}

void printSimple(struct simple_expr * simple){
    if(simple == NULL){
        return ;
    }
    else {
        if(simple->right != NULL){
            switch(simple->type){
                case Less:
                    printAddExpr(simple->left);
                    printf(" < ");
                    printAddExpr(simple->right);
                    break;
                case Less_EQUALS:
                    printAddExpr(simple->left);
                    printf(" <= ");
                    printAddExpr(simple->right);
                    break;
                case Greater:
                    printAddExpr(simple->left);
                    printf(" > ");
                    printAddExpr(simple->right);
                    break;
                case Greater_EQUALS:
                    printAddExpr(simple->left);
                    printf(" >= ");
                    printAddExpr(simple->right);
                    break;
                case Equals_EQUALS:
                    printAddExpr(simple->left);
                    printf(" == ");
                    printAddExpr(simple->right);
                    break;
                case Not_EQUALS:
                    printAddExpr(simple->left);
                    printf(" != ");
                    printAddExpr(simple->right);
                    break;
            }
        }
        else {
            printAddExpr(simple->left);
        } 
    }
}

void printVar(struct var * var){
    if(var == NULL){
        return;
    }
    else {
        switch(var->array){
            //Is Array
            case 1:
                printf("%s[", var->ID);
                printExpr(var->expr);
                printf("]");
                break;
            case 0:
                printf("%s", var->ID);
                break;
        }
    }
}

void printExpr(struct expr * expr){
    if(expr == NULL){
        return;
    }
    else{
        switch(expr->type){
            case Equals:
                printf("Var : ");
                printVar(expr->var);
                printf(" = ");
                printExpr(expr->expr);
                break;
            case Equals_EQUALS:
                printf("Var : ");
                printVar(expr->var);
                printf(" == ");
                printExpr(expr->expr);
                break;
            case SIMPLE:
                printSimple(expr->simple_expr);
            
        }
    }
}

void printParam(struct param * inputparams){

    if(inputparams->next != NULL)
        printParam(inputparams->next);
    if(inputparams != NULL){
        switch(inputparams->type){
            case Int:
                if(inputparams->array)
                    printf("\tInt[] Param %s\n", inputparams->ID);
                else
                    printf("\tInt Param %s\n", inputparams->ID);
                break;
            case Void:
                if(inputparams->array)
                    printf("\tvoid[] Param %s\n", inputparams->ID);
                else
                    printf("\tvoid Param %s\n", inputparams->ID);
                break; 
        }

    }

}

void printStmt(struct stmt * stmt){
    if(stmt == NULL){
        return;
    }
    else{

        if(
            stmt->next != NULL 
            && stmt->next->type >= 0
            && stmt->next->type <= 4
        ){

            printStmt(stmt->next);
            printf("\n");
        }
        switch(stmt->type){
            case EXPR_STMT:
                printf("Expression : ");
                printExpr(stmt->expr);
                break;
            case SELEC_STMT:
                // print select stmt
                printf("If Expression: ");
                printExpr(stmt->if_expr);
                printf("\n\tif statment : ");
                printStmt(stmt->if_stmt);
                if(stmt->else_stmt != NULL)
                    printf("\n\t\telse statement : ");
                printStmt(stmt->else_stmt);
                break;
            case ITER_STMT:
                // print ITER_stmt
                printf("While expression : ");
                printExpr(stmt->w_expr);
                printf("\n\tWhile Statement : ");
                printStmt(stmt->w_stmt);
                break;
            case RETURN_STMT:
                //print return stmt
                printf("Return Expression : ");
                printExpr(stmt->r_expr);
                break;
            
        }

    }

}

void printCompStmt(struct comp_stmt * comp){
    if(comp != NULL){
        if(comp->local_decs != NULL){
            printDecl(comp->local_decs);
        }
        if(comp->local_stmts != NULL){
            printStmt(comp->local_stmts);
        }
    } 
}

void printDecl(struct decl * parser_result){
    //print everything in this declaration
    //var declaration
    if(parser_result == NULL)
        return;
        
    //print the next one till null
    if(parser_result->next != NULL){
        printDecl(parser_result->next);
    }
    //variable declaration
    if(parser_result->compStmt == NULL){
        switch(parser_result->decl_type->type){
            case Int:
                if(parser_result->array == -1)
                    printf("Var Int %s\n", parser_result->ID);
                else
                    printf(
                        "Var Int[%d] %s\n", 
                        parser_result->array, 
                        parser_result->ID
                    );
                break;
            case Void:
                if(parser_result->array == -1)
                    printf("Var Void %s\n", parser_result->ID);
                else
                    printf(
                        "Var Void[%d] %s\n", 
                        parser_result->array, 
                        parser_result->ID
                    ); 
                break;
        }
    }
    else{
        switch(parser_result->decl_type->type){
            case Int:
                printf("Func Int %s\n", parser_result->ID); 
                break;
            case Void:
                printf("Func Void %s\n", parser_result->ID);
                break;
        }
        if(parser_result->params != NULL)
            printParam(parser_result->params);
        if(parser_result->compStmt != NULL){
            printCompStmt(parser_result->compStmt);
        }
        printf("\n");
    }

}

void printTree(struct decl * parser_result){
    printf("Program \n");
    printDecl(parser_result);

}