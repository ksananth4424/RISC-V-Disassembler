#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void outputI(string temp, int opcode, int i){
    unsigned int decimal = convert(temp);
    unsigned int numfunct7 = funct7(decimal)>>1;
    int numimm = imm(decimal);
    int numimmshift = immshift(decimal);
    unsigned int numrs1 = rs1(decimal);
    unsigned int numfunct3 = funct3(decimal);
    unsigned int numrd = rd(decimal);
    bool flag = 3;
    string ans = "";
    if(opcode == 19 && numfunct3 == 0)ans+="addi x";
    if(opcode == 19 && numfunct3 == 4)ans+="xori x";
    if(opcode == 19 && numfunct3 == 6)ans+="ori x";
    if(opcode == 19 && numfunct3 == 7)ans+="andi x";
    if(opcode == 19 && numfunct3 == 1 && numfunct7 == 0)ans+="slli x", flag=2;
    if(opcode == 19 && numfunct3 == 5 && numfunct7 == 0)ans+="srli x", flag=2;
    if(opcode == 19 && numfunct3 == 5 && numfunct7 == 32)ans+="srai x", flag=2;
    if(opcode == 3 && numfunct3 == 0)ans+="lb x", flag = 1;
    if(opcode == 3 && numfunct3 == 1)ans+="lh x", flag = 1;
    if(opcode == 3 && numfunct3 == 2)ans+="lw x", flag = 1;
    if(opcode == 3 && numfunct3 == 3)ans+="ld x", flag = 1;
    if(opcode == 3 && numfunct3 == 4)ans+="lbu x", flag = 1;
    if(opcode == 3 && numfunct3 == 5)ans+="lhu x", flag = 1;
    if(opcode == 3 && numfunct3 == 6)ans+="lwu x", flag = 1;
    if(opcode == 103 && numfunct3 == 0)ans+="jalr x", flag = 1;
    if(numimm>2047)numimm-=4096;
    if(flag == 1){
        ans+=to_string(numrd);
        ans+=", x";
        ans+=to_string(numrs1);
        ans+=", ";
        ans+=to_string(numimm);
    }else if(flag == 2){
        ans+=to_string(numrd);
        ans+=", x";
        ans+=to_string(numrs1);
        ans+=", ";
        ans+=to_string(numimmshift);
    }else{
        ans+=to_string(numrd);
        ans+=", ";
        ans+=to_string(numimm);
        ans+="(x";
        ans+=to_string(numrs1);
        ans+=")";
    }
    output.push_back(ans);
}