#ifndef PARSER_HPP_INCLUDED
#define PARSER_HPP_INCLUDED

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Parser {
    public:
       
        enum CommandType{A_COMMAND, C_COMMAND, L_COMMAND};
        string currentCommand;
        ifstream file;

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