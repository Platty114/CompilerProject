
#include <string>
#include <string>
#include <cstring>

//takes a given special character and returns
//english uppercase notation
//ie givenChar = ';', output = 'SEM_COL'
std::string specialCharToOutput(std::string & givenCharacters, int lineNumber);

//converts a given id to proper output 
std::string idToOutput(std::string & id, int lineNumber);

//converts a given num to proper output 
std::string numToOutput(std::string & num, int lineNumber);

//converts a given num to proper output 
std::string keywordToOutput(std::string & num, int lineNumber);