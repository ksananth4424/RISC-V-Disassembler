#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void outputU(string temp){
    unsigned int decimal = convert(temp);
    unsigned int numimm3112 = imm3112(decimal);
    unsigned int numrd = rd(decimal);
    string hexnumimm = convertHexa(numimm3112);
    cout<<"lui x"<<numrd<<", 0x"<<hexnumimm<<endl;
}