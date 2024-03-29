#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector<string> output;
unordered_map<int, vector<int>> labels;

unsigned int imm105(unsigned int a){
    unsigned int temp1 = a<<1;
    unsigned int temp2 = temp1>>26;
    return temp2;
}

unsigned int imm20(unsigned int a){
    unsigned int temp = a>>31;
    return temp;
}

unsigned int imm12(unsigned int a){
    unsigned int temp = a>>31;
    return temp;
}

unsigned int imm41(unsigned int a){
    unsigned int temp1 = a<<20;
    unsigned int temp2 = temp1>>28;
    return temp2;
}

unsigned int imm11b(unsigned int a){
    unsigned int temp1 = a<<24;
    unsigned int temp2 = temp1>>31;
    return temp2;
}

unsigned int imm101(unsigned int a){
    unsigned int temp1 = a<<1;
    unsigned int temp2 = temp1>>22;
    return temp2;
}

unsigned int imm11j(unsigned int a){
    unsigned int temp1 = a<<11;
    unsigned int temp2 = temp1>>31;
    return temp2;
}

unsigned int imm1912(unsigned int a){
    unsigned int temp1 = a<<12;
    unsigned int temp2 = temp1>>25;
    return temp2;
}

unsigned int imm3112(unsigned int a){
    unsigned int temp = a>>12;
    return temp;
}

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

unsigned int immshift(unsigned int a){
    unsigned int temp1 = a<<6;
    unsigned int temp2 = temp1>>26;
    return temp2;
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

void reverse(string& str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - 1 - i]);
}

string convertHexa(int number)
{
    string hexa;
    while (number)
    {
        int rem = number % 16;
        if (rem < 10)
            hexa.push_back(rem + '0');
        else
            hexa.push_back(rem - 10 + 'A');

        number = number / 16;
    }
    reverse(hexa);
    return hexa;
}