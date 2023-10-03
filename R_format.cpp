#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void outputR(string temp){
    unsigned int decimal = convert(temp);
    unsigned int numfunct7 = funct7(decimal);
    unsigned int numrs2 = rs2(decimal);
    unsigned int numrs1 = rs1(decimal);
    unsigned int numfunct3 = funct3(decimal);
    unsigned int numrd = rd(decimal);
    if(numfunct7 == 0 && numfunct3 == 0)cout<<"add x"<<numrd<<", x"<<numrs1<<", x"<<numrs2<<endl;
    if(numfunct7 == 32 && numfunct3 == 0)cout<<"sub x"<<numrd<<", x"<<numrs1<<", x"<<numrs2<<endl;
    if(numfunct7 == 0 && numfunct3 == 4)cout<<"xor x"<<numrd<<", x"<<numrs1<<", x"<<numrs2<<endl;
    if(numfunct7 == 0 && numfunct3 == 6)cout<<"or x"<<numrd<<", x"<<numrs1<<", x"<<numrs2<<endl;
    if(numfunct7 == 0 && numfunct3 == 7)cout<<"and x"<<numrd<<", x"<<numrs1<<", x"<<numrs2<<endl;
    if(numfunct7 == 0 && numfunct3 == 1)cout<<"sll x"<<numrd<<", x"<<numrs1<<", x"<<numrs2<<endl;
    if(numfunct7 == 0 && numfunct3 == 5)cout<<"srl x"<<numrd<<", x"<<numrs1<<", x"<<numrs2<<endl;
    if(numfunct7 == 32 && numfunct3 == 5)cout<<"sra x"<<numrd<<", x"<<numrs1<<", x"<<numrs2<<endl;
}