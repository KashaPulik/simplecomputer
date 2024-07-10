#include "simpleassembler.h"

#include <iostream>

int *
convert_code_lines_to_memory (code_line *code_lines)
{
  int *memory = new int[128];
  for (int i = 0; i < 128; i++)
    memory[i] = 0;

  int cell_number;
  int command;
  int operand;
  for (int i = 0; i < code_line::counter; i++)
    {
      if (code_lines[i].empty_line)
        {
          std::cout << code_lines[i].line << std::endl;
          continue;
        }
      if (code_lines[i].error_line)
        {
          default_error_output (code_lines[i], i + 1);
          return NULL;
        }
      try
        {
          cell_number = std::stoi (code_lines[i].address);
        }
      catch (const std::invalid_argument &e)
        {
          default_error_output (code_lines[i], i + 1);
          return NULL;
        }
      if (cell_number < 0 || cell_number > 127)
        {
          cell_number_error (code_lines[i], i + 1);
          return NULL;
        }
      command = convert_string_to_command (code_lines[i].command);
      if (command == -1)
        {
          unknownown_command_error (code_lines[i], i + 1);
          return NULL;
        }

      try
        {
          operand = std::stoi (code_lines[i].operand);
        }
      catch (const std::invalid_argument &e)
        {
          default_error_output (code_lines[i], i + 1);
          return NULL;
        }

      if (command == EQ)
        {
          if (operand < -0x7F80 || operand > 0x7F7F)
            {
              cell_value_error (code_lines[i], i + 1);
              return NULL;
            }
          if (code_lines[i].operand.length () != 5)
            {
              cell_value_error (code_lines[i], i + 1);
              return NULL;
            }
          memory[cell_number]
              = convert_string_to_cell_value (code_lines[i].operand);
          continue;
        }
      else
        {
          if (operand < 0 || operand > 127)
            {
              default_error_output (code_lines[i], i + 1);
              return NULL;
            }
        }
      memory[cell_number] = 0;
      memory[cell_number] |= (command << 7) | operand;
    }
  return memory;
}
