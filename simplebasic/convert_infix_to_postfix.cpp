#include "simplebasic.h"

void
convert_infix_to_postfix (vector<code_line> &code_lines,
                          map<char, pair<int, int> > &constants)
{
  for (auto &cl : code_lines)
    {
      if (cl.first_command == "LET")
        {
          cl.split_expression ();
          cl.postfix_expression
              = infix_to_postfix (cl.first_expression, constants);
        }
      if (cl.second_command == "LET")
        {
          cl.split_expression ();
          cl.postfix_expression
              = infix_to_postfix (cl.second_expression, constants);
        }
    }
}