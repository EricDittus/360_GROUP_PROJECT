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