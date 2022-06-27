#include "Parser.h"
#include <iostream>
#include <limits>

using namespace std;

Parser::Parser(string filename) {
        file.open(filename);
        for(string line; getline(file, line); ) {
            cout << boolalpha << hasMoreCommands();
            cout << line << endl;
    }
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