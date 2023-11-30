#include "myAST.h"
#include <glib.h>

//global name scope
GHashTable *GlobalNameScope;
//function argument hash table
GHashTable *GlobalFunctionArgs;



//Types
char* INTARRAY = "INT[]";
char* INT = "INT";
char* VOID = "VOID";
char* INTFUNCTION = "INTFUNC";
char* VOIDFUNCTION = "VOIDFUNC";

//var tracker
int varCount = 1;

//helper functions for dealing with g tables
char* getValueFromTable(GHashTable * table, char * str){
    return g_hash_table_lookup(table, str); 
}

void insertIntoTable(GHashTable * table, char * str, char* value){
    g_hash_table_insert(table, str, value);
}

void insertFunctionArg(char* var, char* value){
    //get current list, add value, re insert into table
    GList * temp = g_hash_table_lookup(
        GlobalFunctionArgs,
        var
    );

    temp = g_list_append(temp, value);

    g_hash_table_insert(
        GlobalFunctionArgs,
        var,
        temp
    );
}

char* getFunctionArg(char* var, int position){
    //get current list, get value, return it
    GList * temp = g_hash_table_lookup(
        GlobalFunctionArgs,
        var
    );

    //check if were trying to index past the list
    //THIS MIGHT THROW A ERROR
    if(g_list_length(temp) <= position ){
        //TEST this
       printf("Too many arguments for call to function %s\n", var);
       exit(0); 
    }
    
    return g_list_nth_data(temp, position);
}

bool functionHasArgs(char* var){
    //get current list, get value, return it
    GList * temp = g_hash_table_lookup(
        GlobalFunctionArgs,
        var
    );

    return (temp == NULL) ? false : true;
}


bool semanticTypeCompare(char* type1, char* type2){
    bool sameType = true;
    //if either one is a void type, then the expression is invalid
    if(
        strcmp(type1, VOID) == 0
        ||
        strcmp(type1, VOIDFUNCTION) == 0
        ||
        strcmp(type2, VOID) == 0
        ||
        strcmp(type2, VOIDFUNCTION) == 0
    ){
        sameType = false;
    }

    return sameType;
}

void checkArgsList(
    struct argsList * argsList, 
    GHashTable * scope,
    char* functionName,
    int argDepth,
    int lineNum
){
    if(argsList == NULL){
        return ;
    }
    else {
        if(argsList->argsList != NULL){
            checkArgsList(
                argsList->argsList, 
                scope,
                functionName,
                argDepth + 1,
                lineNum
            );
        }

        //now we need to check that the given args match
        char* type = checkExpr(argsList->expr, scope);
        char* argType = getFunctionArg(functionName, argDepth);

        
        if(strcmp(type, argType) != 0){
            printf(
                "Invalid argument(s) in call for function %s on line %d\nExpecing %s, recieved %s\n",
                functionName,
                lineNum,
                argType,
                type
            );
            exit(1);
        }

    }
}

void checkArgs(
    struct args * args,
    GHashTable * scope,
    char* functionName,
    int lineNum
){
    if(args == NULL){
        //need to check if function is expecting args
        if(functionHasArgs(functionName)){
            printf(
                "function call to %s on line %d missing args\n",
                functionName,
                lineNum
            );
            exit(1);
        }
        return;
    }
    checkArgsList(
        args->argsList,
        scope, 
        functionName,
        0,
        lineNum
    );
}

char* checkCall(struct call * call, GHashTable * scope){
    if(call == NULL){
        return NULL;
    }
    else {

        //need to check if function is defined
        if(
            getValueFromTable(
                GlobalNameScope,
                call->ID
            ) == NULL
        ){
            printf(
                "Use of undefined function %s on line %d\nExiting\n",
                call->ID,
                call->lineNum
            );
            exit(1);
        } 

        //now need to check that id is a function
        call->semanticType = getValueFromTable(
            GlobalNameScope,
            call->ID
        );

        if(
            strcmp(call->semanticType, INTFUNCTION) != 0
            &&
            strcmp(call->semanticType, VOIDFUNCTION) !=0    
        ){
            //id is not a func
            printf(
                "Trying to call a non function variable %s on line %d\nExiting\n",
                call->ID,
                call->lineNum
            );
            exit(1);
        }

        checkArgs(
            call->args, 
            scope,
            call->ID,
            call->lineNum
        );
        //TRHIS NEEDS TO BE CHANGED
        return call->semanticType;
    }
}

char* checkFact(struct factor * fact, GHashTable * scope){
    if(fact == NULL){
        return NULL;
    }
    else{
        switch(fact->type){
            case EXPR:
                //fact->semanticType = checkExpr(fact->expr, scope);
                //need to change this line after we change checkExpr
                fact->semanticType = checkExpr(fact->expr, scope);
                break;
            case VAR:
                fact->semanticType = checkVar(fact->var, scope);
                break;
            case CALL:
                fact->semanticType = checkCall(fact->call, scope);
                break;
            case NUMBER:
                fact->semanticType = INT;
                break;
        }

        //THIS NEEDS TO BE CHANGED
        return fact->semanticType;
    }
}

char* checkTerm(struct term * term, GHashTable * scope){
    if(term == NULL){
        return NULL;
    }
    else {
        if(term->left != NULL){
            switch(term->type){
                case MULPY:
                    term->termType = checkTerm(term->left, scope);
                    term->factorType = checkFact(term->right, scope);
                    break;
                case DIVIDE:
                    term->termType = checkTerm(term->left, scope);
                    term->factorType = checkFact(term->right, scope);
                    break;
            }

            //need to check that the types are the same here
            if(
                semanticTypeCompare(
                    term->termType,
                    term->factorType
                )
                == false
            ){
                printf(
                    "Non matching types on line %d \nExiting\n",
                    term->lineNum
                );
                exit(1);
            }
        }
        else {
            term->factorType = checkFact(term -> right, scope);
        }

        //factor and term type should be the same
        return term->factorType;
    }
}

char* checkAddExpr(struct add_expr * addExpr, GHashTable * scope){
    if(addExpr == NULL){
        return NULL;
    }
    else {
        if(addExpr->left != NULL){
            switch(addExpr->type){
                case AD:
                    addExpr->addExprType = checkAddExpr(addExpr->left, scope);
                    addExpr->termType = checkTerm(addExpr->right, scope);
                    break;
                case MIN:
                    addExpr->addExprType = checkAddExpr(addExpr->left, scope);
                    addExpr->termType = checkTerm(addExpr->right, scope);
                    break;
            }
            
            //need to check that the types are the same here
            if(
                semanticTypeCompare(
                    addExpr->addExprType,
                    addExpr->termType
                )
                == false
            ){
                printf(
                    "Non matching types on line %d \nExiting\n",
                    addExpr->lineNum
                );
                exit(1);
            }
        }
        else {
            addExpr->termType = checkTerm(addExpr -> right, scope);
        }

        return addExpr->termType;
    }
}

char* checkSimple(struct simple_expr * simple, GHashTable * scope){
    if(simple == NULL){
        return NULL;
    }
    else {
        if(simple->right != NULL){
            switch(simple->type){
                case Less:
                    simple->leftType = checkAddExpr(simple->left, scope);
                    simple->rightType = checkAddExpr(simple->right, scope);
                    break;
                case Less_EQUALS:
                    simple->leftType = checkAddExpr(simple->left, scope);
                    simple->rightType = checkAddExpr(simple->right, scope);
                    break;
                case Greater:
                    simple->leftType = checkAddExpr(simple->left, scope);
                    simple->rightType = checkAddExpr(simple->right, scope);
                    break;
                case Greater_EQUALS:
                    simple->leftType = checkAddExpr(simple->left,  scope);
                    simple->rightType = checkAddExpr(simple->right, scope);
                    break;
                case Equals_EQUALS:
                    simple->leftType = checkAddExpr(simple->left, scope);
                    simple->rightType = checkAddExpr(simple->right, scope);
                    break;
                case Not_EQUALS:
                    simple->leftType = checkAddExpr(simple->left, scope);
                    simple->rightType = checkAddExpr(simple->right, scope);
                    break;
            }

            //need to check that both types are the same
            if(
                semanticTypeCompare(
                    simple->leftType,
                    simple->rightType
                )
                == false
            ){
                printf(
                    "Non matching types on line %d \nExiting\n",
                    simple->lineNum
                );
                exit(1);
            }
        }
        else {
            simple->leftType = checkAddExpr(simple->left, scope);
        } 
        return simple->leftType;
    }
}

char* checkVar(struct var * var, GHashTable * scope){
    if(var == NULL){
        return NULL;
    }
    else {

        //need to check if var is intialized in this scope
        //or is in global scope
        if(
            getValueFromTable(
                scope,
                var->ID
            ) == NULL 
            &&
            getValueFromTable(
                GlobalNameScope,
                var->ID
            ) == NULL 
        ){
            printf(
                "Use of unitialized var %s on line %d\nExiting\n",
                var->ID,
                var->lineNum
            );
            exit(1);
        } 

        //now check if type is being used properly
        var->type =  (
            getValueFromTable(
                scope,
                var->ID
            ) != NULL
        )
        ? getValueFromTable(scope,var->ID )
        : getValueFromTable(GlobalNameScope,var->ID );

        switch(var->array){
            //Is Array
            case 1:
                //indexing is being used on non array
                if(strcmp(var->type, INTARRAY) != 0){
                    printf(
                        "array indexing on non array %s on line %d\nExiting\n",
                        var->ID,
                        var->lineNum
                    );
                    exit(1);
                }
                checkExpr(var->expr, scope);
                break;
            //regular var
            case 0:
                //need to use indexing on array
                //NEED TO FIX THIS
                // if(strcmp(var->type, INT) != 0){
                //     printf(
                //         "no indexing on array %s on line %d\nExiting\n",
                //         var->ID,
                //         var->lineNum
                //     );
                //     exit(1);
                // }
                //printf("%s", var->ID);
                break;
        }

        return var->type;
    }
}

char* checkExpr(struct expr * expr, GHashTable * scope){
    char * returnType;
    bool sameType;
    if(expr == NULL){
        return NULL;
    }
    else{
        switch(expr->type){
            case Equals:
                expr->varType = checkVar(expr->var, scope);
                expr->exprType = checkExpr(expr->expr, scope);
                returnType = expr->varType;
                sameType = semanticTypeCompare(
                    expr->exprType,
                    expr->varType
                );
                break;
            case EQUALS_EACH:
                expr->varType = checkVar(expr->var, scope);
                expr->exprType = checkExpr(expr->expr, scope);
                returnType = expr->varType;
                sameType = semanticTypeCompare(
                    expr->exprType,
                    expr->varType
                );
                break;
            case SIMPLE:
                expr->simpleType = checkSimple(expr->simple_expr, scope);
                returnType = expr->simpleType;
                sameType = true;
                break;
        }

        // need to check that both types are the same
        if(
            sameType == false
        ){
            printf(
                "Non matching types on line %d check \nExiting\n",
                expr->lineNum
            );
            exit(1);
        }

        return returnType;

    }
}

void checkParam(
    struct param * inputparams,
    GHashTable *scope,
    char* functionName
){

    if(inputparams != NULL){
       if(inputparams->next != NULL)
            checkParam(
                inputparams->next,
                scope,
                functionName
            );

        //check if name is already in use
        //(this is kinda overkill)
        if(

            getValueFromTable(
                scope,
                inputparams->ID
            ) != NULL
        ){
            printf(
                "Redeclaration of %s on line %d\nExiting\n",
                inputparams->ID,
                inputparams->lineNum
            );
            exit(1);
        } 
  
        switch(inputparams->type){
            case Int:
                if(inputparams->array){
                    
                    //track name
                    insertIntoTable(
                        scope, 
                        inputparams->ID,
                        INTARRAY
                    );

                    //insert into function args table
                    insertFunctionArg(
                        functionName,
                        INTARRAY
                    );

                }
                else{

                    //track name
                    insertIntoTable(
                        scope, 
                        inputparams->ID,
                        INT
                    );

                    insertFunctionArg(
                        functionName,
                        INT
                    );

                }
                break;
            case Void:
                //WE SHOULD NOT BE ABLE TO USE VOID ARGS
                printf(
                    "Declaration of void var %s on line %d\n",
                    inputparams->ID,
                    inputparams->lineNum
                );
                exit(1);    
                break; 
        }

    }

}

void checkStmt(
    struct stmt * stmt, 
    GHashTable * scope,
    char* parentFuncName
){
    if(stmt == NULL){
        return;
    }
    else{
        if(
            stmt->next != NULL 
            && stmt->next->type >= 0
            && stmt->next->type <= 4
        ){
            checkStmt(stmt->next, scope, parentFuncName);
        }

        switch(stmt->type){
            case EXPR_STMT:
                checkExpr(stmt->expr, scope);
                break;
            case SELEC_STMT:
                // check select stmt
                checkExpr(stmt->if_expr, scope);
                checkStmt(stmt->if_stmt, scope, parentFuncName);
                checkStmt(stmt->else_stmt, scope, parentFuncName);
                break;
            case ITER_STMT:
                // print ITER_stmt
                checkExpr(stmt->w_expr, scope);
                checkStmt(stmt->w_stmt, scope, parentFuncName);
                break;
            case RETURN_STMT:
                //print return stmt

                //need to check if we are supposed to be returning
                char * type = getValueFromTable(
                    GlobalNameScope,
                    parentFuncName
                );

                //cant return from void function
                if(strcmp(type, VOIDFUNCTION) == 0){
                    printf(
                        "return statement in void function %s on line %d\n",
                        parentFuncName,
                        stmt->lineNum
                    );
                    exit(1);   
                }

                char* expressionType = checkExpr(stmt->r_expr, scope);

                //cant have empty return in int function
                if(expressionType == NULL){
                    printf(
                        "empry return statement in int function %s on line %d\n",
                        parentFuncName,
                        stmt->lineNum
                    );
                    exit(1); 
                }
                break;
            
        }

    }

}

void checkCompStmt(
    struct comp_stmt * comp, 
    GHashTable *FunctionNameScope,
    char* parentFuncName
){
    if(comp != NULL){

        if(comp->local_decs != NULL){
            checkDecl(comp->local_decs, FunctionNameScope);
        }

        if(comp->local_stmts != NULL){
            checkStmt(
                comp->local_stmts, 
                FunctionNameScope, 
                parentFuncName
            );
        }

    } 
}

void checkDecl(struct decl * parser_result, GHashTable * scope){

    if(parser_result == NULL)
        return;
    if(parser_result->next != NULL){
        checkDecl(parser_result->next, scope);
    }

    //check if main is already defined
    if(
        getValueFromTable(
            scope,
            "main"
        ) != NULL
    ){
        printf(
            "Func declaration after main on line %d\nExiting\n",
            parser_result->lineNum
        );
        exit(1); 
    }

    //VARIABLE DECLARATION
    //could be local or global
    if(parser_result->compStmt == NULL){

        //for all types of gloabla variable, 
        //we need to check if it already is in
        //GlobalNameScope, and if not add it. IF so
        //Throw error



        //check if name is already in use
        if(

            getValueFromTable(
                scope,
                parser_result->ID
            ) != NULL
        ){
            printf(
                "Redeclaration of %s on line %d\nExiting\n",
                parser_result->ID,
                parser_result->lineNum
            );
            exit(1);
        } 

        //check if we are in function scope, 
        // if(
        //     scope != GlobalNameScope
        // ){
        //     printf("local scope\n");
        //     //check if variable is defined in global name scope
        //     if(
        //         getValueFromTable(
        //             GlobalNameScope,
        //             parser_result->ID
        //         ) != NULL
        //     ){
        //         printf("COLLISON\n %s", parser_result->ID);
        //         // we now need to rename the variable so that 
        //         // it has a unique identifier
        //         char* temp = parser_result->ID;
        //         char temp2[50];
        //         sprintf(temp2, "%d", varCount);
        //         varCount++;
        //         parser_result->ID = (char *) malloc(strlen(temp) +2); 
        //         // parser_result->ID[strlen(temp)+1] = '2';
        //         // parser_result->ID[strlen(temp) + 2] = '\0';
        //         // printf("here %s blah\n", parser_result->ID);
        //         // free(temp);
        //         strcpy(parser_result->ID, temp);
        //         strcat(parser_result->ID, temp2);
        //         printf("here %s blah\n", parser_result->ID);

        //     }
        // }

        switch(parser_result->decl_type->type){
            case Int:
                //int variable
                if(parser_result->array == -1){
                    //track name
                    insertIntoTable(
                        scope, 
                        parser_result->ID,
                        INT
                    );
                }
                // array
                else{
                    //track name
                    insertIntoTable(
                        scope, 
                        parser_result->ID,
                        INTARRAY
                    );
                }
                break;
            case Void:

                //WE SHOULD NOT BE ABLE TO USE VOID ARGS
                printf(
                    "Declaration of void var %s on line %d\n",
                    parser_result->ID,
                    parser_result->lineNum
                );
                exit(1);
        }
    }
    //GLOBAL FUNCTION DECLARATION
    else{

        //check if name is already in use
        if(
            getValueFromTable(
                scope,
                parser_result->ID
            ) != NULL
        ){
            printf(
                "Redeclaration of %s on line %d\nExiting\n",
                parser_result->ID,
                parser_result->lineNum
            );
            exit(1);
        }  
        
        

        switch(parser_result->decl_type->type){
            case Int:
                //track name
                insertIntoTable(
                    scope, 
                    parser_result->ID,
                    INTFUNCTION
                );
                break;
            case Void:

                //track name
                insertIntoTable(
                    scope, 
                    parser_result->ID,
                    VOIDFUNCTION                    
                );
                break;
        }

        // creating local scope for functions
        GHashTable *FunctionNameScope = g_hash_table_new(g_str_hash, g_str_equal);

        //now check params and stms
        if(parser_result->params != NULL){
            //adding function to args tracking table
            //only need to add to table if there are 
            //non void params (MIGHT NEEDD TO BE CHANGED)
            GList * functionArgs = NULL;
            g_hash_table_insert(
                GlobalFunctionArgs, 
                parser_result->ID,
                functionArgs
            );
            checkParam(
                parser_result->params, 
                FunctionNameScope,
                parser_result->ID
            );
        }

        if(parser_result->compStmt != NULL){
            checkCompStmt(
                parser_result->compStmt, 
                FunctionNameScope,
                parser_result->ID
            );
        }

        //destroying scope
        g_hash_table_destroy(FunctionNameScope);
    }

}

void checkTree(struct decl * parser_result){
    //intializing global name scope and function args
    GlobalNameScope = g_hash_table_new(g_str_hash, g_str_equal);
    GlobalFunctionArgs = g_hash_table_new(g_str_hash, g_str_equal);

    printf("Checking semantics\n");
    checkDecl(parser_result, GlobalNameScope);
    printf("Semantics are good!\n");

}