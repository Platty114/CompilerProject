
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "tokenHelpers.hpp"
#include "fileHelpers.hpp" 


int main(int argc, char **argv) {

    //read in eahc line from the text file,
    //then break the read line into tokens 
    //via deliniating with white spaces,
    //then process each token as we come across them.

    std::ifstream file("file.txt");

    std::string line;
    std::string total("");

    std::regex identifier_keyowrd("([A-Z]|[a-z])+");
    std::regex number("[0-9]+");
    int lineNumber = 1;

    while(!file.eof()){
        std::getline(file, line);
        total += line + '\n';
    }

    std::cout << total;
    
    bool insideComment = false;

    for(int i = 0; i < total.size(); i++){
        std::string temp(1, total.at(i));

        //if we are not inside a comment, parse text
        if(insideComment == false)
        {
            //check if we are starting a comment
            if(total.at(i) == '/'){
                if(i < total.size() -1 && total.at(i+1) == '*'){
                    insideComment = true;
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
                    total.at(i) == '!' ||
                    total.at(i) == '|'
                ){
                    if(i < total.size() -1 && total.at(i+1) == '='){
                        temp.push_back(total.at(i+1));
                        std::cout << specialCharToOutput(temp, lineNumber) << std::endl;
                        // std::cout << "special char! On Line: " << lineNumber << std::endl;
                        i++;
                    } else {
                        //handle logical or
                        if(total.at(i) == '|'){
                            temp.push_back(total.at(i+1));
                            std::cout << specialCharToOutput(temp, lineNumber) << std::endl;
                            // std::cout << "special char! On Line: " << lineNumber << std::endl;
                            i++;
                        }
                        //throw error since ! can't exist on it's own
                        else if(total.at(i) == '!'){
                            
                        }
                        //else just regular character
                        else {
                            std::cout << specialCharToOutput(temp, lineNumber) << std::endl;
                            // std::cout << "special char! On Line: " << lineNumber << std::endl;
                        }
                    }
                } else {
                    std::cout << specialCharToOutput(temp, lineNumber) << std::endl;
                    // std::cout << "special char! On Line: " << lineNumber << std::endl;
                }
                continue;
            }
            //dealing with numbers
            if(std::regex_match(temp, number)){
                int j = i;
                while(isSpecialChar(total.at(j)) != true && total.at(j) != ' '){
                    j++;
                }
                
                std::string num = total.substr(i, (j-i));

                if(std::regex_match(num, number)){
                    std::cout << numToOutput(num, lineNumber) << std::endl;
                    // std::cout << "Number! on line:" << lineNumber << std::endl;
                }
                else{
                    std::cout << num << std::endl;
                    std::cout << "error: invalid token found. moving on" <<std::endl;
                }

                i = j-1;
                continue;
            }
            //dealing with indetifiers and key words
            if(std::regex_match(temp, identifier_keyowrd)){
                int j = i;
                while(isSpecialChar(total.at(j)) != true && total.at(j) != ' '){
                    j++;
                }

                std::string word = total.substr(i, (j-i));

                if(isKeywordWithCasing(word)){
                    if(isKeyword(word)){
                        std::cout << keywordToOutput(word, lineNumber) << std::endl;
                        // std::cout << "key word! on line:" << lineNumber << std::endl;
                    } else {
                        std::cout << word << std::endl;
                        std::cout << "error: invalid token found. moving on" <<std::endl;
                    }
                }
                else if(
                    std::regex_match(word, identifier_keyowrd)
                ){
                    std::cout << idToOutput(word, lineNumber) << std::endl;
                    // std::cout << "identifier! On line" << lineNumber <<  std::endl;
                }
                else{
                    std::cout << word << std::endl;
                    std::cout << "error: invalid token found. moving on" <<std::endl;
                }
                i = j-1;
                continue;
            }

        }
        //currently inside a comment
        else {
            //check if we are ending the comment
            if(total.at(i) == '*'){
                if(i < total.size() -1 && total.at(i+1) == '/'){
                    insideComment = false;
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