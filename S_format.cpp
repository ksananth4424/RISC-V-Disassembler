#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void outputS(string temp){
    unsigned int decimal = convert(temp);
    unsigned int numimm1 = imm1(decimal);
    unsigned int numrs2 = rs2(decimal);
    unsigned int numrs1 = rs1(decimal);
    unsigned int numfunct3 = funct3(decimal);
    unsigned int numimm2 = imm2(decimal);
    if(numfunct3 == 0)cout<<"sb x"<<numrs2<<", "<<numimm1*32 + numimm2<<"(x"<<numrs1<<")"<<endl;
    if(numfunct3 == 1)cout<<"sh x"<<numrs2<<", "<<numimm1*32 + numimm2<<"(x"<<numrs1<<")"<<endl;
    if(numfunct3 == 2)cout<<"sw x"<<numrs2<<", "<<numimm1*32 + numimm2<<"(x"<<numrs1<<")"<<endl;
    if(numfunct3 == 3)cout<<"sd x"<<numrs2<<", "<<numimm1*32 + numimm2<<"(x"<<numrs1<<")"<<endl;
}