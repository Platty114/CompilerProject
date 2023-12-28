#include "myAST.h"

void printTabs(int tabCount){
    while(tabCount > 0){
        printf("\t");
        tabCount--;
    }
}

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
                printf("%s: ", expr->varType);
                printVar(expr->var);
                printf(" = ");
                printExpr(expr->expr);
                break;
            case EQUALS_EACH:
                printf("%s: ", expr->varType);
                printVar(expr->var);
                printf(" == ");
                printExpr(expr->expr);
                break;
            case SIMPLE:
                printf("%s: ", expr->simpleType);
                printSimple(expr->simple_expr);
            
        }
    }
}

void printParam(struct param * inputparams){

    if(inputparams != NULL){
       if(inputparams->next != NULL)
            printParam(inputparams->next);
  
        switch(inputparams->type){
            case Int:
                if(inputparams->array)
                    printf(
                        "\tInt[] Param %s @%d\n", 
                        inputparams->ID,
                        inputparams->lineNum
                    );
                else
                    printf(
                        "\tInt Param %s @%d\n", 
                        inputparams->ID,
                        inputparams->lineNum
                    );
                break;
            case Void:
                if(inputparams->array)
                    printf(
                        "\tvoid[] Param %s @%d\n", 
                        inputparams->ID,
                        inputparams->lineNum
                    );
                else
                    printf(
                        "\tvoid Param %s @%d\n", 
                        inputparams->ID,
                        inputparams->lineNum
                    );
                break; 
        }

    }

}

void printStmt(struct stmt * stmt, int depth){
    if(stmt == NULL){
        return;
    }
    else{
        if(
            stmt->next != NULL 
            && stmt->next->type >= 0
            && stmt->next->type <= 4
        ){
            printStmt(stmt->next, depth);
            printf("\n");
        }

        switch(stmt->type){
            case EXPR_STMT:
                printTabs(depth);
                printf(
                    "Expression @%d of type ",
                    stmt->lineNum
                );
                printExpr(stmt->expr);
                break;
            case SELEC_STMT:
                // print select stmt
                printTabs(depth);
                printf("If Expression @%d: ", stmt->lineNum);
                printExpr(stmt->if_expr);
                printf("\n");
                printTabs(depth + 1);
                printf("if statment @%d: ", stmt->if_stmt->lineNum);
                printf("\n");
                printStmt(stmt->if_stmt, depth + 2);
                if(stmt->else_stmt != NULL){
                    printf("\n");
                    printTabs(depth + 1);
                    printf("else statement @%d: ", stmt->else_stmt->lineNum);
                    printf("\n");
                }
                printStmt(stmt->else_stmt, depth + 2);
                break;
            case ITER_STMT:
                // print ITER_stmt
                printTabs(depth);
                printf("While expression @%d: ", stmt->w_expr->lineNum);
                printExpr(stmt->w_expr);
                printf("\n");
                printTabs(depth + 1);
                printf("While Statement @%d:", stmt->w_stmt->lineNum);
                printf("\n");
                printStmt(stmt->w_stmt, depth + 2);
                break;
            case RETURN_STMT:
                //print return stmt
                printTabs(depth);
                printf("Return Expression @%d: ", stmt->r_expr->lineNum);
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
            printStmt(comp->local_stmts, 1);
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
                    printf(
                        "\tVar Int %s @%d\n", 
                        parser_result->ID,
                        parser_result->lineNum
                    );
                else
                    printf(
                        "\tVar Int[%d] %s @%d\n", 
                        parser_result->array, 
                        parser_result->ID,
                        parser_result->lineNum
                    );
                break;
            case Void:
                if(parser_result->array == -1)
                    printf(
                        "\tVar Void %s @%d\n", 
                        parser_result->ID,
                        parser_result->lineNum
                    );
                else
                    printf(
                        "\tVar Void[%d] %s @%d\n", 
                        parser_result->array, 
                        parser_result->ID,
                        parser_result->lineNum
                    ); 
                break;
        }
    }
    else{
        switch(parser_result->decl_type->type){
            case Int:
                printf(
                    "Func Int %s @%d\n", 
                    parser_result->ID,
                    parser_result->lineNum
                    ); 
                break;
            case Void:
                printf(
                    "Func Void %s @%d\n ",
                    parser_result->ID,
                    parser_result->lineNum
                );
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