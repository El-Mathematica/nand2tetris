#include "Parser.h"
#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

Parser::Parser(string filename) {
        file.open(filename);
        
}


bool Parser::hasMoreCommands() {
    int c = file.peek();
    if (c == EOF) {
        if (file.eof()) {
            return 0;
        }
        else {
        // error
            return 1;
        }
        return 1;
    }
}

void Parser::advance() {
    string line;
    getline(file, line);

    line.erase(remove(line.begin(), line.end(), ' '), line.end());
    
    //remove(line.begin(), line.end(), ' ');

    if(!(line.empty() || line.substr(0, 2) == "//" )) {
        cout << line << endl;
        currentCommand = line;
    } else {
        advance();
    }
}

enum Parser::CommandType Parser::commandType() {

    if(currentCommand.find(";") != -1 || currentCommand.find("=") != -1) {
        return C_COMMAND;
    }
    else if(currentCommand.find("(") != -1) {
        return L_COMMAND;
    } else {
        return A_COMMAND;
    }
}