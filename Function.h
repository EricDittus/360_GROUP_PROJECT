#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <string>
#include <vector>

class Function{
public:
  // Copy-constructor: Set to Default
  Function(const Function &rhs) = default;


  // Copy-assignment: Set to Default
  Function& operator=(const Function &rhs) = default;

  // Move-constructor: Set to Default
  Function(Function &&rhs) = default;

  // Move-assignment: Set to Default
  Function& operator=(Function &&rhs) = default;

  // Destructor
  ~Function() = default;

    //End of Big Five
private:
  std::vector<string> assembly_instructions;
  bool is_leaf_function;
  std::string type;
  std::string return_type;
  std::string function_name;
  variables (not sure on the type yet)
  int addr_offset;
}
