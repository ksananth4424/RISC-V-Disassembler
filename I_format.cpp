#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void outputI(string temp, int opcode){
    unsigned int decimal = convert(temp);
    unsigned int numfunct7 = funct7(decimal);
    unsigned int numimm = imm(decimal);
    unsigned int numrs1 = rs1(decimal);
    unsigned int numfunct3 = funct3(decimal);
    unsigned int numrd = rd(decimal);
    if(opcode == 38 && numfunct3 == 0)cout<<"addi x"<<numrd<<", "<<numrs1<<", "<<numimm<<endl;
    if(opcode == 38 && numfunct3 == 4)cout<<"xori x"<<numrd<<", "<<numrs1<<", "<<numimm<<endl;
    if(opcode == 38 && numfunct3 == 5)cout<<"ori x"<<numrd<<", "<<numrs1<<", "<<numimm<<endl;
    if(opcode == 38 && numfunct3 == 7)cout<<"andi x"<<numrd<<", "<<numrs1<<", "<<numimm<<endl;
    if(opcode == 38 && numfunct3 == 1 && numfunct7 == 0)cout<<"slli x"<<numrd<<", "<<numrs1<<", "<<numimm<<endl;
    if(opcode == 38 && numfunct3 == 5 && numfunct7 == 0)cout<<"srli x"<<numrd<<", "<<numrs1<<", "<<numimm<<endl;
    if(opcode == 38 && numfunct3 == 5 && numfunct7 == 32)cout<<"srai x"<<numrd<<", "<<numrs1<<", "<<numimm<<endl;
    if(opcode == 3 && numfunct3 == 0)cout<<"lb x"<<numrd<<", "<<numrs1<<", "<<numimm<<endl;
    if(opcode == 3 && numfunct3 == 1)cout<<"lh x"<<numrd<<", "<<numrs1<<", "<<numimm<<endl;
    if(opcode == 3 && numfunct3 == 2)cout<<"lw x"<<numrd<<", "<<numrs1<<", "<<numimm<<endl;
    if(opcode == 3 && numfunct3 == 3)cout<<"ld x"<<numrd<<", "<<numrs1<<", "<<numimm<<endl;
    if(opcode == 3 && numfunct3 == 4)cout<<"lbu x"<<numrd<<", "<<numrs1<<", "<<numimm<<endl;
    if(opcode == 3 && numfunct3 == 5)cout<<"lhu x"<<numrd<<", "<<numrs1<<", "<<numimm<<endl;
    if(opcode == 3 && numfunct3 == 6)cout<<"lwu x"<<numrd<<", "<<numrs1<<", "<<numimm<<endl;
    if(opcode == 103 && numfunct3 == 0)cout<<"jalr x"<<numrd<<", "<<numrs1<<", "<<numimm<<endl;
}