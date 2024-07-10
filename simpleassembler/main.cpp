#include "simpleassembler.h"

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int code_line::counter = 0;

int
main (int argc, char *argv[])
{
  if (argc != 3)
    {
      std::cerr << "Usage: " << argv[0] << " <input file> <output file>"
                << std::endl;
      return 1;
    }
  char input_file_name[256];
  char *input_file_name_p;
  strcpy (input_file_name, argv[1]);
  input_file_name_p = strtok (input_file_name, ".");
  input_file_name_p = strtok (NULL, ".");
  if (strcmp (input_file_name_p, "sa") != 0)
    {
      std::cerr << "Uncorrect input file extension!" << std::endl;
      std::cerr << "It must be like: <filename>.sa" << std::endl;
      return 1;
    }
  std::vector<std::string> lines = read_file (argv[1]);
  code_line *code_lines = convert_strings_to_code_line (lines);
  int *memory = convert_code_lines_to_memory (code_lines);
  delete[] code_lines;
  if (memory == NULL)
    return 1;
  if (write_memory_to_file (memory, 128, argv[2]))
    {
      delete[] memory;
      return 1;
    }
  return 0;
}