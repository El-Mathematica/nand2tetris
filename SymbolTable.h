#ifndef SYMBOLTABLE_HPP_INCLUDED
#define SYMBOLTABLE_HPP_INCLUDED

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <bitset>

using namespace std;

class SymbolTable {
    public:

       map<string, int> symbolTable = {{"SP", 0}, {"LCL", 1}, {"ARG", 2}, {"THIS", 3}, {"THAT", 4}, {"R0", 0}, {"R1", 1}, {"R2", 2}, {"R3", 3}, {"R4", 4}, {"R5", 5}, {"R6", 6}, {"R7", 7}, {"R8", 8}, {"R9", 9}, {"R10", 10}, {"R11", 11}, {"R12", 12}, {"R13", 13}, {"R14", 14}, {"R15", 15}, {"SCREEN", 16384}, {"KBD", 24576}};
       void addEntry(string symbol, int address);
       bool contains(string symbol);
       int GetAddress(string symbol);
};

#endif