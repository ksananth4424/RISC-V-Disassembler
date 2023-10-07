#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "functions.h"
#include "B_format.cpp"
#include "J_format.cpp"
#include "U_format.cpp"
#include "R_format.cpp"
#include "I_format.cpp"
#include "S_format.cpp"

using namespace std;

unsigned int opcode(unsigned int a){
    unsigned int temp1 = a<<25;
    unsigned int temp2 = temp1>>25;
    return temp2;
}

int main(int argc, char *argv[]){
    fstream file;
    std::vector<string> input;
    file.open(argv[1], ios::in);
    if(file.is_open()){
        string temp;
        while(getline(file, temp)){
            input.push_back(temp);
        }
    }else{
        cout<<"Error: No file found."<<endl;
        return 0;
    }
    for(int i=0; i<input.size(); i++){
        unsigned int numopcode = opcode(convert(input[i]));
        if(numopcode==51){
            outputR(input[i], i);
        }else if(numopcode==35){
            outputS(input[i], i);
        }else if(numopcode == 19 || numopcode == 3 || numopcode == 103){
            outputI(input[i], numopcode, i);
        }else if(numopcode == 99){
            outputB(input[i], i);
        }else if(numopcode == 111){
            outputJ(input[i], i);
        }else if(numopcode == 55){
            outputU(input[i], i);
        }
    }
    int temp = 1;
    for(auto x: labels){
        output[x.first] = "\nL" + to_string(temp) + ": " + output[x.first];
        for(int i=0; i<x.second.size(); i++){
            output[x.second[i]] += "L" + to_string(temp);
        }
        temp++;
    }
    for(int i=0; i<output.size(); i++){
        cout<<output[i]<<endl;
    }
}