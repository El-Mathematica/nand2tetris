#ifndef PARSER_HPP_INCLUDED
#define PARSER_HPP_INCLUDED

#include <string>
#include <fstream>
#include <iostream>

#include "Code.h"

using namespace std;

class Parser {
    public:

        int ROMCounter = 0;
        int RAMCounter = 16;
       
        enum CommandType{A_COMMAND, C_COMMAND, L_COMMAND};
        string currentCommand;
        ifstream file;
        Code codeModule;
        Parser(string filename);
        

        bool hasMoreCommands();
        void advance();
        CommandType commandType();
        string symbol();
        string dest();
        string comp();
        string jump();
};

#endif