#include "simplebasic.h"

#include <iostream>
#include <vector>

int
code_lines_to_tokens (vector<code_line> &code_lines)
{
  int i = 0;
  for (auto &cl : code_lines)
    {
      i++;
      if (cl.split ())
        {
          cerr << "Error in " << i << " line" << endl;
          cerr << cl.basic_code << endl;
          cerr << "This is an invalid code line" << endl;
          return 1;
        }
    }
  return 0;
}
