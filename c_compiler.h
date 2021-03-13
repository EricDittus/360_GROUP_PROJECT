#ifndef C_COMPILER_H
#define C_COMPILER_H

#include <iostream>
#include <string>
#include <vector>

class CTranslator{
  public:

    // Copy-constructor: Set to Default
    CTranslator(const CTranslator &rhs) = default;


    // Copy-assignment: Set to Default
    CTranslator& operator=(const CTranslator &rhs) = default;

    // Move-constructor: Set to Default
    CTranslator(CTranslator &&rhs) = default;

    // Move-assignment: Set to Default
    CTranslator& operator=(CTranslator &&rhs) = default;

    // Destructor
    ~CTranslator() = default;

	//End of Big Five


    // Two-parameter constructor// if needed
    CTranslator(const std::string &..., const std::string &...){
    }


    // Overloading < operator
    bool operator<(const CTranslator &rhs) const {

    }


    // Overloading << operator
    friend std::ostream &operator<<(std::ostream &out, const CTranslator &...){

        return out;
    }


    std::string(or whatever) return Private Variable(){
        // send back your recognition sequence.
        return privatevariable;
    }


  private:

};

#endif
