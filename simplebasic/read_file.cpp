#include "simplebasic.h"

#include <fstream>
#include <iostream>
#include <vector>

vector<code_line>
read_file (string filename)
{
  ifstream file (filename);
  if (!file.is_open ())
    {
      cerr << "Can't open file \"" << filename << "\"" << endl;
      exit (1);
    }
  string line;
  vector<code_line> code_lines;
  while (getline (file, line))
    {
      code_line cl;
      cl.basic_code = line;
      code_lines.push_back (cl);
    }
  file.close ();
  return code_lines;
}
