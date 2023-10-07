#include "tokenHelpers.hpp"

std::string specialCharToOutput(std::string & givenCharacters, int lineNumber){

    std::string outputString;

    if(
        givenCharacters.compare("+") == 0
    ){ 
        outputString = "EQUALS";
    } else if(
        givenCharacters.compare("-") == 0
    ){ 
        outputString = "MINUS";
    } else if(
        givenCharacters.compare("-") == 0
    ){ 
        outputString = "MINUS";
    } else if(
        givenCharacters.compare("*") == 0
    ){ 
        outputString = "MULTIPLY";
    } else if(
        givenCharacters.compare("/") == 0
    ){ 
        outputString = "DIVIDE";
    } else if(
        givenCharacters.compare("<") == 0
    ){ 
        outputString = "LESS";
    } else if(
        givenCharacters.compare(">") == 0
    ){ 
        outputString = "GREATER";
    } else if(
        givenCharacters.compare("<=") == 0
    ){ 
        outputString = "LESS_EQUALS";
    } else if(
        givenCharacters.compare(">=") == 0
    ){ 
        outputString = "GREATER_EQUALS";
    } else if(
        givenCharacters.compare("=") == 0
    ){ 
        outputString = "EQUALS";
    } else if(
        givenCharacters.compare("==") == 0
    ){ 
        outputString = "EQUALS_EQUALS";
    } else if(
        givenCharacters.compare("!=") == 0
    ){ 
        outputString = "NOT_EQUALS";
    } else if(
        givenCharacters.compare("||") == 0
    ){ 
        outputString = "LOGICAL_OR";
    } else if(
        givenCharacters.compare("{") == 0
    ){ 
        outputString = "O_BRACE";
    } else if(
        givenCharacters.compare("}") == 0
    ){ 
        outputString = "C_BRACE";
    } else if(
        givenCharacters.compare("(") == 0
    ){ 
        outputString = "O_PAREN";
    } else if(
        givenCharacters.compare(")") == 0
    ){ 
        outputString = "C_PAREN";
    } else if(
        givenCharacters.compare("[") == 0
    ){ 
        outputString = "O_BRACK";
    } else if(
        givenCharacters.compare("]") == 0
    ){ 
        outputString = "C_BRACK";
    } else if(
        givenCharacters.compare(",") == 0
    ){ 
        outputString = "COMMA";
    } else if(
        givenCharacters.compare(";") == 0
    ){ 
        outputString = "SEM_COL";
    } 
    else {
        outputString = "ERROR";
    }

    return std::to_string(lineNumber) + ": " + outputString;
}

std::string idToOutput(std::string & id, int lineNumber){
    return std::to_string(lineNumber) + ": " + "ID " + "\"" + id + "\"";
}

std::string numToOutput(std::string & num, int lineNumber){
    return std::to_string(lineNumber) + ": " + num;
}

std::string keywordToOutput(std::string & keyword, int lineNumber){
    std::string copy_string("");
    for(int i =0; i< keyword.size(); i++){
        copy_string.push_back(
            toupper(keyword.at(i))
        );
    }
    return std::to_string(lineNumber) + ": " + copy_string;
}
