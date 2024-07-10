#include <string>
#include <utility>

using namespace std;

pair<int, int>
is_there_numbers_in_if (string &expression)
{
  int left = 100000;
  int right = 100000;
  int index = 0;
  string expression_copy = expression;

  if (expression_copy[0] == '-' || isdigit (expression_copy[0]))
    {
      left = stoi (expression_copy);
    }

  index = expression_copy.find_first_of ("><=");
  expression_copy.erase (0, index);

  if (expression[0] == '-' || isdigit (expression[0]))
    {
      left = stoi (expression_copy);
    }
  return make_pair (left, right);
}
