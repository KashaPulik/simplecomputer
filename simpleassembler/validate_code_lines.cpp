#include "simpleassembler.h"

bool
validate_code_lines (code_line *code_lines)
{
  for (int i = 0; i < code_line::counter; i++)
    {
      if (code_lines[i].error_line)
        return true;
    }
  return false;
}
