#include "simplebasic.h"

string
convert_basic_code_line_to_assembler (code_line &cl, map<char, int> &table,
                                      map<int, int> &addresses)
{
  string result = "";
  int address = cl.assembler_line_number;
  if (cl.first_command == "INPUT")
    {
      result += int_to_address (address);
      result += " READ   ";
      result += int_to_address (table[cl.operand[0]]);
      result += '\n';
    }
  else if (cl.first_command == "OUTPUT")
    {
      result += int_to_address (address);
      result += " WRITE  ";
      result += int_to_address (table[cl.operand[0]]);
      result += '\n';
    }
  else if (cl.first_command == "GOTO")
    {
      result += int_to_address (address);
      result += " JUMP   ";
      result += int_to_address (addresses[stoi (cl.operand)]);
      result += '\n';
    }
  else if (cl.first_command == "LET")
    {
      result += convert_let_to_assembler (address, cl.postfix_expression,
                                          cl.expression_result, table);
    }
  else if (cl.first_command == "IF")
    {
      result += convert_if_to_assembler (cl, table, addresses);
    }
  else if (cl.first_command == "END")
    {
      result += int_to_address (address);
      result += " HALT   ";
      result += "00\n";
    }
  return result;
}
