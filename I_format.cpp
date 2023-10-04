#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void outputI(string temp, int opcode, int i){
    unsigned int decimal = convert(temp);
    unsigned int numfunct7 = funct7(decimal);
    unsigned int numimm = imm(decimal);
    unsigned int numrs1 = rs1(decimal);
    unsigned int numfunct3 = funct3(decimal);
    unsigned int numrd = rd(decimal);
    string ans = "";
    if(opcode == 19 && numfunct3 == 0)ans+="addi x";
    if(opcode == 19 && numfunct3 == 4)ans+="xori x";
    if(opcode == 19 && numfunct3 == 5)ans+="ori x";
    if(opcode == 19 && numfunct3 == 7)ans+="andi x";
    if(opcode == 19 && numfunct3 == 1 && numfunct7 == 0)ans+="slli x";
    if(opcode == 19 && numfunct3 == 5 && numfunct7 == 0)ans+="srli x";
    if(opcode == 19 && numfunct3 == 5 && numfunct7 == 32)ans+="srai x";
    if(opcode == 3 && numfunct3 == 0)ans+="lb x";
    if(opcode == 3 && numfunct3 == 1)ans+="lh x";
    if(opcode == 3 && numfunct3 == 2)ans+="lw x";
    if(opcode == 3 && numfunct3 == 3)ans+="ld x";
    if(opcode == 3 && numfunct3 == 4)ans+="lbu x";
    if(opcode == 3 && numfunct3 == 5)ans+="lhu x";
    if(opcode == 3 && numfunct3 == 6)ans+="lwu x";
    if(opcode == 103 && numfunct3 == 0)ans+="jalr x";
    ans+=to_string(numrd);
    ans+=", x";
    ans+=to_string(numrs1);
    ans+=", ";
    ans+=to_string(numimm);
    output.push_back(ans);
}