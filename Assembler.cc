#include <string>
#include <iostream>
#include <fstream>
#include "Assembler.h"

/*
According to the instruction type, call the corresponding handler, return true is matched to a specific handler
*/

bool Assembler::common_instruction_handler_dispatcher(string* source, int &loc, int max_len, Function &f1, int &addr_offset){
    if(source[loc].find(“int”) == 0 && source[loc].find(“;”)==source[loc].length()-1){
        /*
            Code line starts with variable declaration keyword “int”
        */
        variable_offset_allocation(source, loc, f1, addr_offset);
        loc++;
    }else if{source[loc].find(“if”)==0){
        /*
            Code line starts with “if”
        */
        f1.assembly_instructions.push_back(“#” + source[loc]);
        IF_statement_handler(source, loc, mac_len, f1, addr_offset);
    }else if(source[loc.find(“for”) == 0){
        /*
            Code line starts with “for”
        */
        f1.assembly_instructions.push_back(“#” + source[loc]);
        FOR_statement_handler(source, loc, max_len, f1, addr_offset);
    }else if(source[loc].find(“return”)==0){
        /*
            Code line starts with return
        */
        f1.assembly_instructions.push_back(“#” + source[loc]);
        return_handler(source, loc, f1);
        loc++;
}else if(is_function_call(source[loc])==true){
    /*
        Code line starts with a function
    */
    f1.assembly_instructions.push_back(“#” + source[loc});
    function_call_handler(source, loc, f1);
    f1.is_leaf_function = false;
    loc++;
}else{
    // otherwise, they are arithmetic instructions
    f1.assembly_instructions.push_back(“#” + source[loc]);
    arithmetic_handler(source[loc], f1);
    loc++;
}
}

/*
    input: parse functions e.g., start “int test(int a, int b, int c){“
    return;
        none
*/

void Assembler::function_handler(string* source, int loc, int max_len) {

    /*
create a function object, get function return type and function name
*/

Function f1;
string head = source[loc];
f1.return_type = head.subtr(0, head.find(‘ ‘)); // get return type”int”
string tempstr = head.subtr(head.find(‘ ‘), head.length()); // “test (int a, int b, int c) {”
f1.function_name = tempstr(0, tempstr.find(‘(‘)); //get function name “test”
f1.assembly_instructions.push_back(f1.function_name+”: ”);
f1.assembly_instructions.push_back(“pushq %rbp”);
f1.assembly_instructions.push_back(“movq %rsp, %rbp”)
f1.is_leaf_function = true;

/*
Get parameter list and read parameter values from registers
*/

int addr offset = -4;
tempstr = tempstr.substr(tempstr.find(‘(‘) + 1, tempstr.length() - f1.function_name.length() -3); // “int a, int b, int c”
string parameter_str = tempstr.substr(tempstr.find(‘(‘) +1, tempstr.find(‘)’)));
if(parameter_str.length() > 0){
    f1.variables = varialbe_handler(parameter_str, 2, addr_offset);
    /*
        v1.1 update
    */
    int number_of_parameter = 0;
    F]for (auto & var : f1.variables) {
        number_of_parameters++;
        // first 6 parameters <- registers
        if (var.type == “int”){
    // this parameter is a 32 bits variable
    f1.assembly_instructions.push_back(add_mov_instruction(“%” + register_for_argument_32[number_of_parameter - 1], to_string(var.addr_offset) + “(%rbp)”, 32));
}else{
    //this parameter is a 64 bits variable
    f1.assembly_instructions.push_back(add_mov_instruction(“%” + register_for_argument_64[number_of_parameter - 1], to_string(var.addr_offset) + “(%rbp)”, 64));
}
//other than the first 6, the rest need to rest their offset
// 16 = return address + saved RBP
}else{
        var.addr_offset = 16 + (number_of_parameter -6 -1) *8;
}
}
}

/*
Go through each instruction
*/
loc++;     //go to next source code
bool next_function = false;
while(loc < max_len){
    if(source[loc].find(“int”) ==0 || source[loc].find(“void”) == 0 && source[loc].find(“{”) == source[loc].length()-1{
/*
    Start with a new function
*/
next_function = true;
break;
    }else if(source[loc] == “}”){
    loc++;
}else{
// send to common handler dispatcher
common_instruction_handler_dispatcher(source, loc, max_len, f1, addr_offset);
}
}


// 4 . we need to modify “RSP” at the prologue if this function is not a leaf function ad has local variables
if(f1.is_leaf function == false && f1. variables.size() > 0){
    int last_offset = 0 - f1.variables.back().addr_offset;
    // if last offset is not divisible by 16 then do 16 byte address alignment: multiples of 16
    if (last_offset %16 != 0){
        last_offset = ceil( (float)last_offset/16) * 16;
}
f1.assembly_instructions.insert(f1.assembly_instructions.begin() + 3, “subq $” + to_string(last_offset) + “,%rsp”);
}

functions.push_back(f1);
if(next_function == true){
    function_handler(source, loc, max_len);
}
