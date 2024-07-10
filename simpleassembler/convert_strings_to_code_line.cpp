#include "simpleassembler.h"

#include <cstring>
#include <string>
#include <vector>

code_line *
convert_strings_to_code_line (std::vector<std::string> lines)
{
  code_line *code_lines = new code_line[lines.size ()];
  code_line::counter = lines.size ();
  char char_string_for_line[128];
  char *char_string_for_token;
  for (size_t i = 0; i < lines.size (); i++)
    {
      code_lines[i].line = lines[i];
      code_lines[i].empty_line = false;
      code_lines[i].error_line = false;
      strcpy (char_string_for_line, lines[i].c_str ());

      char_string_for_token = strtok (char_string_for_line, " ");
      if (char_string_for_token == NULL)
        {
          code_lines[i].empty_line = true;
          continue;
        }
      code_lines[i].address = char_string_for_token;
      char_string_for_token = NULL;

      char_string_for_token = strtok (NULL, " ");
      if (char_string_for_token == NULL)
        {
          code_lines[i].error_line = true;
          continue;
        }
      code_lines[i].command = char_string_for_token;
      char_string_for_token = NULL;

      char_string_for_token = strtok (NULL, " ");
      if (char_string_for_token == NULL)
        {
          code_lines[i].error_line = true;
          continue;
        }
      code_lines[i].operand = char_string_for_token;
      char_string_for_token = NULL;

      strtok (NULL, " ");
      char_string_for_token = strtok (NULL, ";");
      if (char_string_for_token == NULL)
        continue;
      code_lines[i].comment = char_string_for_token;
    }
  return code_lines;
}
