#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void outputB(string temp, int i){
    unsigned int decimal = convert(temp);
    unsigned int numimm12 = imm12(decimal)<<12;
    unsigned int numimm105 = imm105(decimal)<<5;
    unsigned int numimm11 = imm11b(decimal)<<10;
    unsigned int numimm41 = imm41(decimal)<<1;
    unsigned int numrs2 = rs2(decimal);
    unsigned int numrs1 = rs1(decimal);
    unsigned int numfunct3 = funct3(decimal);
    unsigned int num = (numimm12 + numimm105 + numimm11 + numimm41)/4;
    unsigned int numrd = rd(decimal);
    string ans = "";
    if(numfunct3 == 0)ans+="beg x";
    if(numfunct3 == 1)ans+="bne x";
    if(numfunct3 == 4)ans+="blt x";
    if(numfunct3 == 5)ans+="bge x";
    if(numfunct3 == 6)ans+="bltu x";
    if(numfunct3 == 7)ans+="bgeu x";
    ans+= to_string(numrd);
    ans+= ", ";
    labels[num + i].push_back(i);
    output.push_back(ans);
}