#include "SymbolTable.h"

void SymbolTable::addEntry(string symbol, int address) {
    symbolTable.insert(pair<string, int>(symbol, address));
}

bool SymbolTable::contains(string symbol) {
    if(symbolTable.count(symbol)) {
        return true;
    } else {
        return false;
    }
}

int SymbolTable::GetAddress(string symbol) {
    return symbolTable[symbol];
}
