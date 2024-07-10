#include <map>
#include <string>

using namespace std;

int
get_symbols_from_expression (map<char, int> &table, string &expression,
                             int address)
{
  for (char c : expression)
    if (isupper (c))
      if (table.count (c) == 0)
        table[c] = address--;
  return address;
}
