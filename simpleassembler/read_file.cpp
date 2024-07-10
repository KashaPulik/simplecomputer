#include "simpleassembler.h"

#include <fstream>
#include <string>
#include <vector>

std::vector<std::string>
read_file (char *filename)
{
  std::ifstream file (filename);
  std::vector<std::string> lines;
  std::string line;
  while (std::getline (file, line))
    {
      lines.push_back (line);
    }
  file.close ();
  return lines;
}
