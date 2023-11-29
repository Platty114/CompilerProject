/*
James Platt 30130627 CPSC 411 Assignment 3 
myAST.h
*/
#ifndef MY_AST_H
#define MY_AST_H

#include "structs.h"
#include <glib.h>

//CREATE FUNCTIONS
/*
all of these construct a struct of their
respective types and return them.
used in constructing the tree
*/
struct args *createArgs(
    struct argsList *argsList,
    int lineNum
);
struct argsList *createArgsList(
    struct argsList *next, 
    struct expr *inExpr
);
struct call *createCall(
    char *ID, 
    struct args *inArgs,
    int lineNum
);
struct factor *createFact(
    struct expr *inexpr, 
    struct var *inVar, 
    struct call *inCall, 
    int inNUM, 
    int typeNum, 
    int lineNum
);
struct term *createTerm(
    struct term *inLeft, 
    mult_type type, 
    struct factor *inRight,
    int lineNum
);
struct add_expr *createAddExp(
    struct add_expr *inLeft, 
    add_type type, 
    struct term *inRight, 
    int lineNum
);
struct simple_expr *createSimpleExpr(
    struct add_expr *inLeft,
    relateOp_type type, 
    struct add_expr *inRight,
    int lineNum
);
struct var *createVar(
    char *ID, 
    struct expr *inExpr,
    int lineNum
);
struct expr *createExpr(
    int numType, struct var *var, 
    struct expr *inExpr,
    struct simple_expr *simple_expr, 
    int lineNum
);
struct stmt *createStmt(
    struct expr *expression, 
    struct expr *ifExpr, 
    struct stmt *ifStmt, 
    struct stmt *elseStmt,
    struct expr *w_expr, 
    struct stmt *w_stmt, 
    struct expr *r_expr, 
    int numType, 
    int lineNum
);
struct comp_stmt *createCompStmt(
    struct decl *localDecs, 
    struct stmt *localStmt
);
struct param *createParam(
    type_spec type, 
    char *ID, 
    int array, 
    int lineNum
);
struct decl *createDecl(
    type_spec type, 
    char *ID, 
    int arraySize, 
    struct param *params, 
    struct comp_stmt *comp_stmt,
    int lineNum
);

//AST PRINTING FUNCTIONS
/*
used to travel through the tree, printing
all the information of the nodes. Used after
the tree has been traveled through to gain semantic information
*/
void printParam(struct param* inputParams);
void printCompStmt(struct comp_stmt * comp);
void printDecl(struct decl * parser_result);
void printStmt(struct stmt * stmt, int depth);
void printExpr(struct expr * expr);
void printVar(struct var * var);
void printSimple(struct simple_expr * simple);
void printAddExpr(struct add_expr * addExpr);
void printTerm(struct term * term);
void printFact(struct factor * fact);
void printCall(struct call * call);
void printArgs(struct args * args);
void printArgsList(struct argsList * argsList);
void printTree(struct decl * parser_result);

//SEMANTIC ANALYSIS FUNCTIONS
/*
travels through the tree in the same patern as
the printing functions, but determines any
semantic errors (if there are any) and 
adds information to the nodes about type info
*/
void checkParam(
    struct param* inputParams, 
    GHashTable *scope,
    char* functionName
);
void checkCompStmt(
    struct comp_stmt * comp, 
    GHashTable *FunctionNameScope,
    char* parentFuncName
);
void checkDecl(
    struct decl * parser_result,
    GHashTable * scope
);
void checkStmt(
    struct stmt * stmt,
    GHashTable * scope,
    char* parentFuncName
);
char* checkExpr(
    struct expr * expr,
    GHashTable * scope
);
char* checkVar(
    struct var * var,
    GHashTable * scope
);
char* checkSimple(
    struct simple_expr * simple,
    GHashTable * scope    
);
char* checkAddExpr(
    struct add_expr * addExpr,
    GHashTable * scope    
);
char* checkTerm(
    struct term * term,
    GHashTable * scope    
);
char* checkFact(
    struct factor * fact,
    GHashTable * scope    
);
char* checkCall(
    struct call * call,
    GHashTable * scope   
);
void checkArgs(
    struct args * args,
    GHashTable * scope,
    char* functionID,
    int lineNum    
);
void checkArgsList(
    struct argsList * argsList,
    GHashTable * scope,
    char* functionID,
    int argDepth,
    int lineNum
);
void checkTree(struct decl * parser_result);



#endif