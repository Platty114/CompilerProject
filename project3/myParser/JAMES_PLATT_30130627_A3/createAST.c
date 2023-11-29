#include "myAST.h"

// create functions

struct args * createArgs(
    struct argsList * argsList,
    int lineNum
){
    struct args * newArgs = (struct args * ) malloc(sizeof(struct args));
    newArgs->argsList = argsList;
    newArgs->lineNum = lineNum;

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
    struct args * inArgs,
    int lineNum
){
    struct call * newCall = (struct call *) malloc(sizeof(struct call));
    newCall->ID = (char *) malloc(strlen(ID) +1);
    strcpy(newCall->ID, ID);
    newCall->lineNum = lineNum;
    newCall->args = inArgs;

    return newCall;
}

struct factor * createFact(
    struct expr * inexpr,
    struct var * inVar,
    struct call * inCall,
    int inNUM,
    int typeNum,
    int lineNum
){
    struct factor * newFactor = (struct factor *) malloc(sizeof(struct factor));
    newFactor->expr = inexpr;
    newFactor->call = inCall;
    newFactor->var = inVar;
    newFactor->NUM = inNUM;
    newFactor->lineNum = lineNum;

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
    struct factor * inRight,
    int lineNum
){
    struct term * newTerm = (struct term *) malloc(sizeof(struct term));
    newTerm->left = inLeft;
    newTerm->right = inRight;
    newTerm->type = type;
    newTerm->lineNum = lineNum;

    return newTerm;
}

struct add_expr * createAddExp(
    struct add_expr * inLeft,
    add_type type,
    struct term * inRight,
    int lineNum
){
    struct add_expr * newAddExpr = (struct add_expr *) malloc(sizeof(struct add_expr));
    newAddExpr->left = inLeft;
    newAddExpr->right = inRight;
    newAddExpr->type = type;
    newAddExpr->lineNum = lineNum;

    return newAddExpr;
}

struct simple_expr * createSimpleExpr(
    struct add_expr * inLeft,
    relateOp_type type,
    struct add_expr * inRight,
    int lineNum
){
    struct simple_expr * newSimple = (struct simple_expr * ) malloc(sizeof(struct simple_expr));
    newSimple->left = inLeft;
    newSimple->right = inRight;
    newSimple->type = type;
    newSimple->lineNum = lineNum;

    return newSimple;
}

struct var* createVar(
    char* ID, 
    struct expr* inExpr, 
    int lineNum
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

    newVar->lineNum = lineNum;

    return newVar;

}


struct expr * createExpr(
    int numType, 
    struct var* var,
    struct expr* inExpr,
    struct simple_expr* simple_expr,
    int lineNum
){
    struct expr* newExpr = (struct expr *) malloc(sizeof(struct expr));
    newExpr->var = var;
    newExpr->expr = inExpr;
    newExpr->simple_expr = simple_expr;
    newExpr->lineNum = lineNum;

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
    int numType,
    int lineNum
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
    newStmt->lineNum = lineNum;
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
    int array,
    int lineNum
){
    struct param * newParam = (struct param*) malloc(sizeof(struct param));
    newParam->ID = (char *) malloc(strlen(ID) +1); 
    newParam->ID = strcpy(newParam->ID, ID);
    newParam->array = array == 1 ? true : false;
    newParam->type = type;
    newParam->lineNum = lineNum;

    return newParam;
}

struct decl * createDecl(
    type_spec type, 
    char* ID, 
    int arraySize, 
    struct param* params, 
    struct comp_stmt* comp_stmt,
    int lineNum
    ){
        struct decl *newDecl = (struct decl *) malloc(sizeof(struct decl));
        newDecl->ID = (char *) malloc(strlen(ID) +1);
        newDecl->ID = strcpy(newDecl->ID, ID);
        newDecl->array = arraySize;
        newDecl->params = params;
        newDecl->compStmt = comp_stmt;
        newDecl->lineNum = lineNum;
        struct type * temp = (struct type*) malloc(sizeof(struct type));
        temp->type = type;
        newDecl->decl_type = temp;

        return newDecl;
    }