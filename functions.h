#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

unsigned int imm1(unsigned int a){
    unsigned int temp = a>>25;
    return temp;
}

unsigned int rs2(unsigned int a){
    unsigned int temp1 = a<<7;
    unsigned int temp2 = temp1>>27;
    return temp2;
}

unsigned int rs1(unsigned int a){
    unsigned int temp1 = a<<12;
    unsigned int temp2 = temp1>>27;
    return temp2;
}

unsigned int funct3(unsigned int a){
    unsigned int temp1 = a<<17;
    unsigned int temp2 = temp1>>29;
    return temp2;
}

unsigned int imm2(unsigned int a){
    unsigned int temp1 = a<<20;
    unsigned int temp2 = temp1>>27;
    return temp2;
}

unsigned int funct7(unsigned int a){
    unsigned int temp = a>>25;
    return temp;
}

unsigned int imm(unsigned int a){
    unsigned int temp = a>>20;
    return temp;
}

unsigned int rd(unsigned int a){
    unsigned int temp1 = a<<20;
    unsigned int temp2 = temp1>>27;
    return temp2;
}

unsigned int immupper(unsigned int a){
    unsigned int temp = a>>11;
    return temp;
}

int convert(string s) {
   int len = s.size();
   int base = 1;
   int temp = 0;
    for (int i=len-1; i>=0; i--) {
        if (s[i]>='0' && s[i]<='9') {
            temp += (s[i] - '0')*base;
        }
        else if (s[i]>='a' && s[i]<='f') {
            temp += (s[i] - 'a' + 10)*base;
        }
        base = base*16;
    }
   return temp;
}