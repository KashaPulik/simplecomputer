#include "simplebasic.h"

map<int, int>
convert_basic_code_lines_adresses_to_assembler (vector<code_line> &code_lines)
{
  map<int, int> addresses;
  int address = 0;
  for (auto &cl : code_lines)
    {
      addresses[cl.line_number] = address;
      cl.assembler_line_number = address;
      if (cl.first_command == "LET")
        {
          address += count_commands (cl.first_command, cl.postfix_expression);
          continue;
        }
      if (cl.first_command == "LET")
        {
          address += count_commands (cl.second_command, cl.postfix_expression);
          continue;
        }
      if (cl.first_command == "IF")
        {
          address += count_commands (cl.first_command, cl.first_expression);
          address += count_commands (cl.second_command, cl.second_expression);
          continue;
        }
      address += count_commands (cl.first_command, cl.first_expression);
    }
  return addresses;
}
