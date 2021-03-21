#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <iostream>
#include <string>
#include <vector>

class Assembler{

    public:


    // Copy-constructor: Set to Default
    Assembler(const Assembler &rhs) = default;


    // Copy-assignment: Set to Default
    Assembler& operator=(const Assembler &rhs) = default;

    // Move-constructor: Set to Default
    Assembler(Assembler &&rhs) = default;

    // Move-assignment: Set to Default
    Assembler& operator=(Assembler &&rhs) = default;

    // Destructor
    ~Assembler() = default;

    //End of Big Five

      //common_instruction_handler_dispatcher
      common_instruction_handler_dispatcher(string* source, int &loc, int max_len, Function &f1, int &addr_offset);

      //function_handler
      function_handler(string* source, int &loc, int max_len);

      variable_offset_allocation(string* source, int &loc, Funciton &f1, int &addr_offset);

      IF_statement_handler(string* source, int &loc, int max_len, Function &f1, int &addr_offset);

      FOR_statement_handler(string* source, int &loc, int max_len, Function &f1, int &addr_offset);

      return_handler(string* source, int &loc, Function &f1);

      is_function_call(string source_array_object);

      function_call_handler(string* source, int &loc, Function &f1);

      arithmetic_handler(string source_array_object, Function &f1)


    // Two-parameter constructor// if needed
    Assembler(const std::string &..., const std::string &...){
    }


    // Overloading < operator
    bool operator<(const Assembler &rhs) const {

    }


    // Overloading << operator
    friend std::ostream &operator<<(std::ostream &out, const Assembler &...){

        return out;
    }


    std::string(or whatever) return Private Variable(){
        // send back your recognition sequence.
        return privatevariable;
    }


  private:





};

#endif
