#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void outputJ(string temp, int i){
    unsigned int decimal = convert(temp);
    unsigned int numimm20 = imm20(decimal)<<20;
    unsigned int numimm101 = imm101(decimal)<<1;
    unsigned int numimm11 = imm11j(decimal)<<11;
    unsigned int numimm1912 = imm1912(decimal)<<12;
    unsigned int num = (numimm20 + numimm1912 + numimm11 + numimm101)/4;
    unsigned int numrd = rd(decimal);
    string ans = "jal x";
    ans+= to_string(numrd);
    ans+= ", ";
    labels[num + i].push_back(i);
    output.push_back(ans);
}