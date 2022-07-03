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

string Parser::dest() {
    if(currentCommand.find("=") != string::npos) {
        string mnemonic = currentCommand.substr(0, currentCommand.find("="));
        return codeModule.dest(mnemonic);
    } else {
        return "000";
    }
    
}

string Parser::comp() {
    if(currentCommand.find("=") != string::npos && currentCommand.find(";") != string::npos) {
        string mnemonic = currentCommand.substr(currentCommand.find("="), currentCommand.find(";") - currentCommand.find("="));

        return codeModule.comp(mnemonic);
    } else if(currentCommand.find("=") != string::npos) {
        string mnemonic = currentCommand.substr(currentCommand.find("=") + 1);

        return codeModule.comp(mnemonic);
    } else if(currentCommand.find(";") != string::npos) {
        string mnemonic = currentCommand.substr(0, currentCommand.find(";"));

        return codeModule.comp(mnemonic);
    }
    
} 

string Parser::jump() {
    if(currentCommand.find(";") != string::npos) {
        string mnemonic = currentCommand.substr(currentCommand.find(";") + 1);
        return codeModule.jump(mnemonic);
        
    } else {
        return "000";
    }
}

string Parser::symbol() {
    return currentCommand.substr(currentCommand.find("@") != string::npos);
}

