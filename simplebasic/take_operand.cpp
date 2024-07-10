#include <string>

using namespace std;

string
take_operand (string &expression)
{
  size_t right_position = expression.find_first_of ("+-*/");
  size_t left_position = right_position - 1;
  string operand
      = expression.substr (left_position, right_position - left_position);
  expression.erase (left_position, right_position - left_position);
  return operand;
}
