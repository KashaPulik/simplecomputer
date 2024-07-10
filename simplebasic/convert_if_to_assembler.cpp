#include "simplebasic.h"

string
convert_if_to_assembler (code_line &cl, map<char, int> &table,
                         map<int, int> &addresses)
{
  string result = "";
  int address = cl.assembler_line_number;
  int left;
  int right;
  char left_operand;
  char right_operand;
  char sign;
  int jump_to;
  for (auto &ad : addresses)
    {
      if (ad.second > address)
        {
          jump_to = ad.second;
          break;
        }
    }
  tie (left, right) = is_there_numbers_in_if (cl.first_expression);
  if (left != 100000)
    {
      result += int_to_address (address++);
      result += " =   ";
      result += int_to_sc_number (left);
    }
  if (right != 100000)
    {
      result += int_to_address (address++);
      result += " =   ";
      result += int_to_sc_number (right);
    }

  result += int_to_address (address++);
  result += " LOAD   ";
  if (left != 100000)
    {
      if (right != 100000)
        result += int_to_address (address - 3);
      else
        result += int_to_address (address - 2);
    }
  else
    {
      left_operand += cl.first_expression[0];
      result += int_to_address (table[left_operand]);
    }
  result += "\n";

  result += int_to_address (address++);
  result += " SUB    ";
  if (right != 100000)
    result += int_to_address (address - 3);
  else
    {
      right_operand
          = cl.first_expression[cl.first_expression.find_first_of ("<>=") + 1];
      result += int_to_address (table[right_operand]);
    }
  result += "\n";
  sign = cl.first_expression[cl.first_expression.find_first_of ("<>=")];
  switch (sign)
    {
    case ('<'):
      result += int_to_address (address++);
      result += " JZ     ";
      result += int_to_address (jump_to);
      result += "\n";
      result += int_to_address (address++);
      result += " JNS    ";
      result += int_to_address (jump_to);
      result += "\n";
      break;
    case ('>'):
      result += int_to_address (address++);
      result += " JZ     ";
      result += int_to_address (jump_to);
      result += "\n";
      result += int_to_address (address++);
      result += " JNEG   ";
      result += int_to_address (jump_to);
      result += "\n";
      break;
    case ('='):
      result += int_to_address (address++);
      result += " JNEG   ";
      result += int_to_address (jump_to);
      result += "\n";
      result += int_to_address (address++);
      result += " JNS    ";
      result += int_to_address (jump_to);
      result += "\n";
      break;
    }
  if (cl.second_command == "LET")
    {
      result += convert_let_to_assembler (address, cl.postfix_expression,
                                          cl.expression_result, table);
    }
  else if (cl.second_command == "INPUT")
    {
      result += int_to_address (address);
      result += " READ   ";
      result += int_to_address (table[cl.operand[0]]);
      result += '\n';
    }
  else if (cl.second_command == "OUTPUT")
    {
      result += int_to_address (address);
      result += " WRITE  ";
      result += int_to_address (table[cl.operand[0]]);
      result += '\n';
    }
  else if (cl.second_command == "GOTO")
    {
      result += int_to_address (address);
      result += " JUMP   ";
      result += int_to_address (addresses[stoi (cl.operand)]);
      result += '\n';
    }
  return result;
}
