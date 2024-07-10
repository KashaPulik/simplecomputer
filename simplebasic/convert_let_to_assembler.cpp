#include "simplebasic.h"

string
convert_let_to_assembler (int address, string &expression,
                          string &expression_result, map<char, int> &table)
{
  int n = 0;

  string left;
  string right;
  char sign;

  string result = "";
  for (auto c : expression)
    {
      if (isalpha (c))
        n++;
    }
  if (n == 1)
    {
      result += int_to_address (address++);
      result += " LOAD   ";
      result += int_to_address (table[expression[0]]);
      result += "\n";
      result += int_to_address (address++);
      result += " STORE  ";
      result += int_to_address (table[expression_result[0]]);
      result += "\n";
      return result;
    }
  n--;
  for (int i = 0; i < n; i++)
    {
      tie (left, right, sign)
          = get_one_operation (expression, expression_result);

      result += int_to_address (address++);
      result += " LOAD   ";
      result += int_to_address (table[left[0]]);
      result += "\n";

      result += int_to_address (address++);
      switch (sign)
        {
        case ('+'):
          result += " ADD    ";
          break;
        case ('-'):
          result += " SUB    ";
          break;
        case ('*'):
          result += " MUL    ";
          break;
        case ('/'):
          result += " DIVIDE ";
          break;
        }
      result += int_to_address (table[right[0]]);
      result += "\n";

      result += int_to_address (address++);
      result += " STORE  ";
      result += int_to_address (table[expression_result[0]]);
      result += "\n";
    }
  return result;
}
