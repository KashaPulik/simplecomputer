#pragma once

#include <string>
#include <vector>

enum commands
{
  NOP = 0x00,
  CPUINFO = 0x01,
  READ = 0x0A,
  WRITE = 0x0B,
  LOAD = 0x14,
  STORE = 0x15,
  ADD = 0x1E,
  SUB = 0x1F,
  DIVIDE = 0x20,
  MUL = 0x21,
  JUMP = 0x28,
  JNEG = 0x29,
  JZ = 0x2A,
  HALT = 0x2B,
  NOT = 0x33,
  AND = 0x34,
  OR = 0x35,
  XOR = 0x36,
  JNS = 0x37,
  JC = 0x38,
  JNC = 0x39,
  JP = 0x3A,
  JNP = 0x3B,
  CHL = 0x3C,
  SHR = 0x3D,
  RCL = 0x3E,
  RCR = 0x3F,
  NEG = 0x40,
  ADDC = 0x41,
  SUBC = 0x42,
  LOGLC = 0x43,
  LOGRC = 0x44,
  RCCL = 0x45,
  RCCR = 0x46,
  MOVA = 0x47,
  MOVR = 0x48,
  MOVCA = 0x49,
  MOVCR = 0x4A,
  ADDC2 = 0x4B,
  SUBC2 = 0x4C,
  EQ = 0x4D
};

class code_line
{
public:
  static int counter;
  bool empty_line;
  bool error_line;
  std::string line;
  std::string address;
  std::string command;
  std::string operand;
  std::string comment;
};

std::vector<std::string> read_file (char *filename);
code_line *convert_strings_to_code_line (std::vector<std::string> lines);
bool validate_code_lines (code_line *code_lines);
void default_error_output (code_line &line, int line_number);
void unknownown_command_error (code_line &line, int line_number);
void cell_number_error (code_line &line, int line_number);
void cell_value_error (code_line &line, int line_number);
int convert_string_to_command (std::string command);
int convert_string_to_cell_value (std::string str);
int *convert_code_lines_to_memory (code_line *code_lines);
int write_memory_to_file (int *memory, int size, std::string filename);