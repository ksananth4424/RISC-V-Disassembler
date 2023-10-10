# RISC-V-Disassembler

This is a program coded in C++. This program is capable of disassembling RISC - V assembly code. 
The program covers all the instruction set present in RISC - V which are R, I, U, B, S and J type.

In order to compile and run the program run the following command:

        $ g++ main.cpp -o main

To run the program:

        $ ./main <file_name>
        
        for example: $ ./main input.txt

Input: The input is of hexadecimal machine level code listed line by line.

    If want to try a custom input then make a new .txt file with hexadecimal machine level code with each input seperated with a newline.
    Refer input.txt for reference.

Implementation: The program has been implemented by first converting the hexadecimal inout into decimal then bit shifting to get the 
    desired part of the instruct set we are trying to disassemble. Then we do a bunch of comparisions to reach the final conclusion of the code and print them in order.

Output: The output is of RISC - V assembly code where the code for the respective machine level code is printed in the terminal.

Happy Coding :)