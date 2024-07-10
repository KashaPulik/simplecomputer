#include "simplebasic.h"

#include <iostream>
#include <vector>

int
check_code_lines_empty (vector<code_line> &code_lines)
{
  int i = 0;
  for (auto &cl : code_lines)
    {
      i++;
      if (cl.is_empty ())
        {
          cerr << "Error in " << i << " line" << endl;
          cerr << "This is an empty line" << endl;
          return 1;
        }
    }
  return 0;
}
