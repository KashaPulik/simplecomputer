#include "simplebasic.h"

#include <map>
#include <string>
#include <vector>

map<char, int>
make_symbolic_table (vector<code_line> &code_lines)
{
  int address = 127;
  map<char, int> table;
  string first_expression;
  string second_expression;
  for (auto &cl : code_lines)
    {
      if (cl.first_command == "REM" || cl.first_command == "GOTO"
          || cl.first_command == "OUTPUT")
        continue;
      if (cl.first_command == "INPUT" || cl.second_command == "INPUT")
        {
          table[cl.operand[0]] = address--;
          continue;
        }
      if (cl.first_command == "IF")
        {
          address = get_symbols_from_expression (table, cl.first_expression,
                                                 address);
        }
      if (cl.first_command == "LET")
        address = get_symbols_from_expression (table, cl.first_expression,
                                               address);
      if (cl.second_command == "LET")
        address = get_symbols_from_expression (table, cl.second_expression,
                                               address);
    }
  return table;
}
