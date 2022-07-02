#include "Code.h"

using namespace std;

string Code::dest(string mnemonic) {
    return destMap[mnemonic].to_string();
}

string Code::comp(string mnemonic) {
    return compMap[mnemonic].to_string();
}

string Code::jump(string mnemonic) {
    return jumpMap[mnemonic].to_string();
}