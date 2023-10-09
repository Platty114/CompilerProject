
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <stack>
#include "tokenHelpers.hpp"
#include "fileHelpers.hpp" 

//takes a input file as first argument and output file name as second argument
int main(int argc, char **argv) {

    std::ifstream file;
    std::ofstream output;

    //argument checking
    if(argc < 2 || argc > 3){
        std::cout << "Invalid arguments" << std::endl;
    }

    file.open(argv[1]);
    output.open(argv[2]);

    //file checking
    if(
        file.is_open() != true
        ||
        output.is_open() != true
    ){
        std::cout << "error opening input or creating output files" << std::endl;
        return 1;
    }

    //helper regex
    std::regex identifier_keyowrd("([A-Z]|[a-z])+");
    std::regex number("[0-9]+");
    int lineNumber = 1;

    //reading in contents of given file
    std::string line;
    std::string total("");

    while(!file.eof()){
        std::getline(file, line);
        total += line + '\n';
    }

    //keeps track of comment depth
    std::stack<int> comments;

    //main state machine for processing file.
    for(int i = 0; i < total.size(); i++){
        std::string temp(1, total.at(i));

        //if we are not inside a comment, parse text
        if(comments.size() == 0)
        {
            //check if we are starting a comment
            if(total.at(i) == '/'){
                if(i < total.size() -1 && total.at(i+1) == '*'){
                    comments.push(1);
                    i++;
                    continue;
                }
            }
        
            //dealing with white space
            if(total.at(i) == ' ' || total.at(i) == '\t'){
                continue;
            }
            //dealing with new lines, taking count of line number
            if(total.at(i) == '\n'){
                lineNumber++;
                continue;
            }
            //dealing with special characters
            if(isSpecialChar(total.at(i))){
                if(
                    total.at(i) == '<' || 
                    total.at(i) == '>' || 
                    total.at(i) == '=' ||
                    total.at(i) == '!' 
                ){
                    //vaild = <= >= etc
                    if(
                        total.at(i+1) == '='
                    ){
                        temp.push_back(total.at(i+1));
                        output << specialCharToOutput(temp, lineNumber) << std::endl;
                        i++;
                    } else {
                        //throw error since ! can't exist on it's own
                        if(total.at(i) == '!'){
                            output<< lineNumber << ": ERROR:invalid token " << temp << " . moving on" <<std::endl;
                        }
                        //else just regular character
                        else {
                            output << specialCharToOutput(temp, lineNumber) << std::endl;
                        }
                    }
                } else {
                    output << specialCharToOutput(temp, lineNumber) << std::endl;
                }
                continue;
            }
            //dealing with numbers
            if(std::regex_match(temp, number)){
                int j = i;
                while(
                    isSpecialChar(total.at(j)) != true && 
                    total.at(j) != ' '
                ){
                    j++;
                }
                
                std::string num = total.substr(i, (j-i));

                if(std::regex_match(num, number)){
                    output << numToOutput(num, lineNumber) << std::endl;
                }
                else{
                    output<< lineNumber << ": ERROR:invalid token " << num << " . moving on" <<std::endl;
                }

                i = j-1;
                continue;
            }
            //dealing with indetifiers and key words
            if(std::regex_match(temp, identifier_keyowrd)){
                int j = i;
                while(
                    isSpecialChar(total.at(j)) != true && 
                    total.at(j) != ' ' &&
                    total.at(j) != '\n'
                ){
                    j++;
                }

                std::string word = total.substr(i, (j-i));

                if(isKeywordWithCasing(word)){
                    if(isKeyword(word)){
                        output << keywordToOutput(word, lineNumber) << std::endl;
                    } else {
                        output<< lineNumber <<": ERROR:invalid token " << word << " . moving on" <<std::endl;
                    }
                }
                else if(
                    std::regex_match(word, identifier_keyowrd)
                ){
                    output << idToOutput(word, lineNumber) << std::endl;
                }
                else{
                    output<< lineNumber << ": ERROR:invalid token " << word << " . moving on" <<std::endl;
                }
                i = j-1;
                continue;
            }

        }
        //currently inside a comment
        else {
            //check if we are ending the comment
            if(total.at(i) == '*'){
                if(
                    i < total.size() -1 && 
                    total.at(i+1) == '/'
                ){
                    comments.pop();
                    i++;
                    continue;
                }
            }
            //handling nested comments.
            //I know they're not allowed, but I decided to implement them just because
            else if(total.at(i) == '/'){
                if(
                    i < total.size() -1 && 
                    total.at(i+1) == '*'
                ){
                    comments.push(1);
                    output << lineNumber <<": ERROR: no nesting comments! Moving on" <<std::endl;
                    i++;
                    continue;
                }
            }
            //need to keep track of line number still
            if(total.at(i) == '\n'){
                lineNumber++;
                continue;
            }
        }

        
    
    }

    return 0;
}