#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <bitset>
#include <cctype>
#include <type_traits>
#include <bits/stdc++.h>

#include "Parser.h"
#include "Code.h"


using namespace std;

bool is_number(const std::string& s);



int main (int argc, char* argv[]) {
	
	string filename(argv[1]);
	string fileNameWithoutExtension = filename.substr(0, filename.find("."));
	cout << fileNameWithoutExtension << endl;
	string newFileName = fileNameWithoutExtension + "test.hack";
	ofstream outputFile(newFileName);
	Parser parser(filename);
	while(parser.hasMoreCommands()) {
		parser.advance();
		if(parser.commandType() == Parser::CommandType::C_COMMAND) {
			parser.dest();
			parser.comp();
			parser.jump();

			cout << parser.comp() << parser.dest() << parser.jump() << endl;

			outputFile << parser.comp() + parser.dest() + parser.jump() << endl;
		}
		else if(parser.commandType() == Parser::CommandType::A_COMMAND) {
			if(is_number(parser.symbol())) {
				bitset<16> b(stoi(parser.symbol()));
				cout << b << endl;
				outputFile << b << endl;
			}


		} else {
			cout << "l command yes" << endl;
		}
		 
	}
	
	
	outputFile.close();

	getchar();

}

bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}



/*
enum CommandType{A_COMMAND, C_COMMAND, L_COMMAND};
enum CommandType commandType(string x); 
bool Ignore(string x);
string ASymbol(string x);
string LSymbol(string x);
string CDest(string x);
string CComp(string x);
string CJump(string x);
map<string, bitset<3>> dest = {{"", 0b000}, {"M", 0b001}, {"D", 0b010}, {"MD", 0b011}, {"A", 0b100}, {"AM", 0b101}, {"AD", 0b110}, {"AMD", 0b111}};
map<string, bitset<10>> comp = {{"0", 0b1110101010}, {"1", 0b1110111111}, {"-1", 0b1110111010}, {"D", 0b1110001100}, {"A", 0b1110110000}, {"!D", 0b1110001101}, {"!A", 0b1110110001}, {"-D", 0b1110001111}, {"-A", 0b1110110011}, {"D+1", 0b1110011111}, {"A+1", 0b1110110111}, {"D-1", 0b1110001110}, {"A-1", 0b1110110010}, {"D+A", 0b1110000010}, {"D-A", 0b1110010011}, {"A-D", 0b1110000111}, {"D&A", 0b1110000000}, {"D|A", 0b1110010101}, {"M", 0b1111110000}, {"!M", 0b1111110001}, {"-M", 0b1111110011}, {"M+1", 0b1111110111}, {"M-1", 0b1111110010}, {"D+M", 0b1111000010}, {"D-M", 0b1111010011}, {"M-D", 0b1111000111}, {"D&M", 0b1111000000}, {"D|M", 0b1111010101}};
map<string, bitset<3>> jump ={{"", 0b000}, {"JGT", 0b001}, {"JEQ", 0b010}, {"JGE", 0b011}, {"JLT", 0b100}, {"JNE", 0b101}, {"JLE", 0b110}, {"JMP", 0b111}};

bool is_number(const std::string& s);

int main() {
	int ROMcounter = 0;
	string line;
	ifstream File("RectL.asm");
	ofstream OutputFile("RectL.hack");
	
	cout << "shut up";

	while(getline(File, line)) {
		OutputFile << "test" << '\n';
	}
	
	
	while (getline (File, line)) {
		
		if(Ignore(line)) {
			
			if(commandType(line) == A_COMMAND) {
				
				if(is_number(ASymbol(line))) {
					OutputFile << bitset<16>(stoi(ASymbol(line))).to_string() << '\n';
				}
				
			}
			if(commandType(line) == C_COMMAND) {
						
				OutputFile << comp[CComp(line)].to_string() << dest[CDest(line)].to_string() << jump[CJump(line)].to_string() << '\n';
				
			} 
			if (commandType(line) == L_COMMAND) {
				OutputFile << "L_COMMAND" << '\n';
				OutputFile << LSymbol(line) << '\n';
			}
		}
	}
	
	// Close the file
	OutputFile.close();
	File.close();
	
}

enum CommandType commandType(string x) {
	bool isA=0, isC=0, isL=0;
	for(int i = 0; i < x.length(); i++) {
		string str(1, x[i]);
		if(str == ";") {
				isC = 1;
		}
		if(str == "=") {
				isC = 1;
		}
		if(str == "(") {
				isL = 1;
		}
	}
	if(isL==0 && isC==0) {
		isA = 1;
	}
	if(isA==1) {
		return A_COMMAND;
	}
	if(isC==1) {
		return C_COMMAND;
	}
	if(isL==1) {
		return L_COMMAND;
	}
}

bool Ignore(string x){
	if(x.length() == 0) {
			return false;
	}
	
	for(int i = 0; i < x.length(); i++) {
		string str(1, x[i]);
			
		if(str=="/" ) {
			return false;
		}
	}	
	return true;
}

string ASymbol(string x){
	for(int i = 0; i < x.length(); i++) {
		string str(1, x[i]);
		if(str == "@") {
				return x.substr(i+1, -1);
		}
		
	}
	return "what";
	
}
string LSymbol(string x){
	for(int i = 0; i < x.length(); i++) {
		string str(1, x[i]);
		if(str == "(") {
				return x.substr(i+1, -2);
		}
		
	}
	
}

string CDest(string x) {
	int start = 0;
	for(int i=0; i < x.length(); i++) {
		if(!(isspace(x[i]))) {
			start = i;
			break;
		}
	}
	int end = start;
	for(int i=0; i < x.length(); i++) {
		if(x[i] == '=') {
			end = i;
			break;
		}
	}
	return x.substr(start, end);
}

string CComp(string x) {
	int start = 0;
	int end = 0;
	int equalpos = -1;
	int semicolonpos = -1;
	for(int i=0; i < x.length(); i++) {
		if(x[i]=='=') {
			equalpos = i;
		}
		if(x[i]==';') {
			semicolonpos = i;
		}
	}
	if(equalpos == -1) {
		for(int i=0; i < x.length(); i++) {
			if(!(isspace(x[i]))) {
				start = i;
				break;
			}
		}
		end = semicolonpos;
		return x.substr(start, end);
		
	} else if(semicolonpos == -1) {
		
		start=equalpos+1;
		return x.substr(start, x.length()-1);
	} else {
		return x.substr(equalpos+1, semicolonpos);
	}
	
}

string CJump(string x) {
	int semicolonpos = -1;
	for(int i=0; i < x.length(); i++) {
		if(x[i]==';') {
			semicolonpos = i;
		}
	}
	if(semicolonpos==-1) {
		return "";
	} else {
		return x.substr(semicolonpos+1, x.length());
	}
}

bool is_number(const std::string& s) {
  
	
	for(int i = 0; i < s.length(); i++) {
		if(!isdigit(s[i])) {
			return false;
		}
	}
	return true;
}

*/