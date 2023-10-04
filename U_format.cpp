#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void outputU(string temp, int i){
    unsigned int decimal = convert(temp);
    unsigned int numimm3112 = imm3112(decimal);
    unsigned int numrd = rd(decimal);
    string hexnumimm = convertHexa(numimm3112);
    string ans = "";
    ans+="lui x";
    ans+=to_string(numrd);
    ans+=", 0x";
    ans+=hexnumimm;
    output.push_back(ans);
}