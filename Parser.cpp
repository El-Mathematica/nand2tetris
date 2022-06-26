#include "Parser.h"
#include <iostream>

using namespace std;

Parser::Parser(string filename) {
        file.open(filename);
        for(string line; getline(file, line); ) {
        cout << line << endl;
    }
}

bool Parser::hasMoreCommands() {
    cout << "running hasMoreCommands" << endl;
    return true;
}