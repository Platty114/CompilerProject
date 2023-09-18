
#include <iostream>
#include <fstream>
#include <string>
#include "tokens.h"


int main(int argc, char **argv) {

    //read in eahc line from the text file,
    //then break the read line into tokens 
    //via deliniating with white spaces,
    //then process each token as we come across them.

    std::ifstream file("file.txt");

    std::string line;

    while(std::getline(file,line)){
        // break line done into tokens

        std::string token;

        for(int i = 0; i < line.size(); i++){

            //std::cout << line.at(i) << std::endl;
            // std::cout << token << std::endl;

            if(line.at(i) == ' '){

                // std::cout << "here" << std::endl;

                if(token.length() != 0){
                    //this is where we call some sort of process token function
                    std::cout << "found a token! " << token << std::endl;
                    token = "";
                }

            } 
            else if(line.at(i) == ';'){
                
                if(token.length() != 0){
                    //call the process token function
                    std::cout << "found a token! " << token << std::endl;
                    token = "";
                }
                else {
                    break;
                }

            }
            else {
                token.push_back(line.at(i));
            }

        }
    }

    std::cout << "this is a message" << std::endl;

    return 0;
}