#include "tokenHelpers.hpp"

//returns true if given string is a key word in the
//c- language
bool isKeyword(std::string & string_to_compare){
    if(
        string_to_compare.compare("else") == 0
    ){
        return true;
    }
    else if(
        string_to_compare.compare("if") == 0
    ){
        return true;
    }
    else if(
        string_to_compare.compare("int") == 0
    ){
        return true;
    }
    else if(
        string_to_compare.compare("return") == 0
    ){
        return true;
    }
    else if(
        string_to_compare.compare("void") == 0
    ){
        return true;
    }
    else if(
        string_to_compare.compare("while") == 0
    ){
        return true;
    }
    else{
        return false;
    }
}

//returns true if given string is a keyword, ignoring casing
bool isKeywordWithCasing(std::string & string_to_compare){
    std::string copy_string("");
    for(int i =0; i< string_to_compare.size(); i++){
        copy_string.push_back(
            tolower(string_to_compare.at(i))
        );
    }
    return isKeyword(copy_string);
}

//reutrns true if the given character is a special character in the c- language.
bool isSpecialChar(char & character){
    bool returnValue = false;
    switch(character){
        case '+':
            returnValue = true;
            break;
        case '-':
            returnValue = true;
            break;
        case '*':
            returnValue = true;
            break;
        case '/':
            returnValue = true;
            break;
        case '<':
            returnValue = true;
            break;
        case '>':
            returnValue = true;
            break;
        case '=':
            returnValue = true;
            break;
        case '|':
            returnValue = true;
            break;
        case '{':
            returnValue = true;
            break;
        case '}':
            returnValue = true;
            break;
        case '[':
            returnValue = true;
            break;
        case ']':
            returnValue = true;
            break;
        case '(':
            returnValue = true;
            break;
        case ')':
            returnValue = true;
            break;
        case ',':
            returnValue = true;
            break;
        case ';':
            returnValue = true;
            break;
    }
    return returnValue;
}
