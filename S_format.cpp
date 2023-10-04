#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void outputS(string temp, int i){
    unsigned int decimal = convert(temp);
    unsigned int numimm1 = imm1(decimal);
    unsigned int numrs2 = rs2(decimal);
    unsigned int numrs1 = rs1(decimal);
    unsigned int numfunct3 = funct3(decimal);
    unsigned int numimm2 = imm2(decimal);
    string ans = "";
    if(numfunct3 == 0)ans+="sb x";
    if(numfunct3 == 1)ans+="sh x";
    if(numfunct3 == 2)ans+="sw x";
    if(numfunct3 == 3)ans+="sd x";
    ans+=to_string(numrs2);
    ans+=", ";
    ans+=to_string(numimm1*32 + numimm2);
    ans+="(x";
    ans+=to_string(numrs1);
    ans+=")";
    output.push_back(ans);
}