#ifndef STRUCTS_H
#define STRUCTS_H

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
    int lineNum;
};

struct call{
    char* ID;
    struct args* args;
    char* semanticType;
    int lineNum;
};

struct factor {
    struct expr* expr;
    struct var* var;
    struct call* call;
    int NUM;
    factor_type type;
    int lineNum;
    char* semanticType;
};

struct term {
    struct term* left;
    char* termType;
    struct factor* right;
    char* factorType;
    mult_type type;
    int lineNum;
};

struct add_expr {
    struct add_expr* left;
    char* addExprType;
    struct term* right;
    char* termType;
    add_type type;
    int lineNum;
};

struct simple_expr{
    struct add_expr* left;
    char* leftType;
    struct add_expr* right;
    char* rightType;
    relateOp_type type;
    int lineNum;
};

struct var {
    char* ID;
    int array;
    struct expr* expr;
    int lineNum;
    char* type;
};

struct expr {
    expr_type type;
    struct var* var;
    char* varType;
    struct expr* expr;
    char* exprType;
    struct simple_expr* simple_expr;
    char* simpleType;
    int lineNum;
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
    int lineNum;
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
    int lineNum;
};

struct decl {
    struct type * decl_type;
    char* ID;
    int array;
    struct param* params;
    struct comp_stmt* compStmt;
    struct decl* next;
    int lineNum;
};

#endif