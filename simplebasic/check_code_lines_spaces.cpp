#include "simplebasic.h"

#include <iostream>
#include <vector>

int
check_code_lines_spaces (vector<code_line> &code_lines)
{
  int i = 0;
  for (auto &cl : code_lines)
    {
      i++;
      if (!cl.is_there_any_spaces ())
        {
          cerr << "Error in " << i << " line" << endl;
          cerr << "Code line must have at least line number and command"
               << endl;
          cerr << "This is an empty line" << endl;
          return 1;
        }
    }
  return 0;
}
