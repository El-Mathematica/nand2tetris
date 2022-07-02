#ifndef CODE_HPP_INCLUDED
#define CODE_HPP_INCLUDED
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <bitset>

using namespace std;

class Code {
    //make sure to private appropriate commands
    public:
        map<string, bitset<3>> destMap = {{"", 0b000}, {"M", 0b001}, {"D", 0b010}, {"MD", 0b011}, {"A", 0b100}, {"AM", 0b101}, {"AD", 0b110}, {"AMD", 0b111}};
        map<string, bitset<10>> compMap = {{"0", 0b1110101010}, {"1", 0b1110111111}, {"-1", 0b1110111010}, {"D", 0b1110001100}, {"A", 0b1110110000}, {"!D", 0b1110001101}, {"!A", 0b1110110001}, {"-D", 0b1110001111}, {"-A", 0b1110110011}, {"D+1", 0b1110011111}, {"A+1", 0b1110110111}, {"D-1", 0b1110001110}, {"A-1", 0b1110110010}, {"D+A", 0b1110000010}, {"D-A", 0b1110010011}, {"A-D", 0b1110000111}, {"D&A", 0b1110000000}, {"D|A", 0b1110010101}, {"M", 0b1111110000}, {"!M", 0b1111110001}, {"-M", 0b1111110011}, {"M+1", 0b1111110111}, {"M-1", 0b1111110010}, {"D+M", 0b1111000010}, {"D-M", 0b1111010011}, {"M-D", 0b1111000111}, {"D&M", 0b1111000000}, {"D|M", 0b1111010101}};
        map<string, bitset<3>> jumpMap ={{"", 0b000}, {"JGT", 0b001}, {"JEQ", 0b010}, {"JGE", 0b011}, {"JLT", 0b100}, {"JNE", 0b101}, {"JLE", 0b110}, {"JMP", 0b111}};
        string dest(string mnemonic);
        string comp(string mnemonic);
        string jump(string mnemonic);

};

#endif