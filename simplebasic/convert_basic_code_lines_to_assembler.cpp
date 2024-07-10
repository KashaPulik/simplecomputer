#include "simplebasic.h"

string
convert_basic_code_lines_to_assembler (vector<code_line> &code_lines,
                                       map<char, int> &table,
                                       map<int, int> &addresses,
                                       map<char, pair<int, int> > &constants)
{
  string result = "";
  for (auto &cl : code_lines)
    {
      result += convert_basic_code_line_to_assembler (cl, table, addresses);
    }
  for (auto c = constants.rbegin (); c != constants.rend (); ++c)
    {
      result += int_to_address (c->second.first);
      result += " =   ";
      result += int_to_sc_number (c->second.second);
      result += "\n";
    }
  return result;
}
