#ifndef CODE_HPP_INCLUDED
#define CODE_HPP_INCLUDED
#include <string>

using namespace std;

class Code {
    //make sure to private appropriate commands
    public:
        string dest(string mnemonic);
        string comp(string mnemonic);
        string jump(string mnemonic);

};

#endif