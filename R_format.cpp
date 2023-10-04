#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void outputR(string temp, int i){
    unsigned int decimal = convert(temp);
    unsigned int numfunct7 = funct7(decimal);
    unsigned int numrs2 = rs2(decimal);
    unsigned int numrs1 = rs1(decimal);
    unsigned int numfunct3 = funct3(decimal);
    unsigned int numrd = rd(decimal);
    string ans = "";
    if(numfunct7 == 0 && numfunct3 == 0)ans += "add x";
    if(numfunct7 == 32 && numfunct3 == 0)ans += "sub x";
    if(numfunct7 == 0 && numfunct3 == 4)ans += "xor x";
    if(numfunct7 == 0 && numfunct3 == 6)ans += "or x";
    if(numfunct7 == 0 && numfunct3 == 7)ans += "and x";
    if(numfunct7 == 0 && numfunct3 == 1)ans += "sll x";
    if(numfunct7 == 0 && numfunct3 == 5)ans += "srl x";
    if(numfunct7 == 32 && numfunct3 == 5)ans += "sra x";
    ans+=to_string(numrd);
    ans+=", x";
    ans+=to_string(numrs1);
    ans+=", x";
    ans+=to_string(numrs2);
    output.push_back(ans);
}