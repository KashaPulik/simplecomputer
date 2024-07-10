#include "simpleassembler.h"

#include <iostream>

void
cell_number_error (code_line &line, int line_number)
{
  std::cerr << "Error in line " << line_number << ":\n"
            << line.line << std::endl;
  std::cerr << "Uncorrect address: " << line.address << std::endl;
  std::cerr << "Line must be like:" << std::endl;
  std::cerr << "<address> <command> <operand>;<comment (optional)>"
            << std::endl;
}
