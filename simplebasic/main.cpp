#include "simplebasic.h"

#include <fstream>
#include <iostream>

int
main (int argc, char *argv[])
{
  if (argc != 3)
    {
      std::cerr << "Usage: " << argv[0] << " <input file> <output file>"
                << std::endl;
      return 1;
    }

  vector<code_line> code_lines = read_file (argv[1]);

  if (check_code_lines_empty (code_lines))
    return 1;
  if (check_code_lines_spaces (code_lines))
    return 1;

  if (code_lines_to_tokens (code_lines))
    return 1;

  map<char, int> table = make_symbolic_table (code_lines);

  map<char, pair<int, int> > constants;

  convert_infix_to_postfix (code_lines, constants);

  give_addresses_to_constants (table, constants);

  map<int, int> addresses
      = convert_basic_code_lines_adresses_to_assembler (code_lines);

  merge_tables (table, constants);

  string result = convert_basic_code_lines_to_assembler (code_lines, table,
                                                         addresses, constants);

  ofstream out (argv[2]);
  if (!out.is_open ())
    {
      cerr << "Can't open file \"" << argv[2] << "\"" << endl;
      return 1;
    }
  out << result;
  out.close ();
  cout << "Success!" << endl;
}