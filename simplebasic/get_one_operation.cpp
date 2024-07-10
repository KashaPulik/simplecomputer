#include "simplebasic.h"

#include <string>
#include <tuple>

using namespace std;

tuple<string, string, char>
get_one_operation (string &expression, string &expression_result)
{
  bool there_is_expression = false;
  for (char c : expression)
    {
      if (c == '+' || c == '-' || c == '*' || c == '/')
        {
          there_is_expression = true;
          break;
        }
    }
  if (!there_is_expression)
    return make_tuple ("", "", 0);

  size_t position = expression.find_first_of ("+-*/");
  char sign = expression[position];
  string right_operand = take_operand (expression);
  string left_operand = take_operand (expression);
  position = expression.find_first_of ("+-*/");
  expression[position] = expression_result[0];
  return make_tuple (left_operand, right_operand, sign);
}
