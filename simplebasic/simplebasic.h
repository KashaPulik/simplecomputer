#pragma once

#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class code_line
{
public:
  string basic_code;
  string first_command;
  string second_command;
  string first_expression;
  string second_expression;
  string operand;
  string postfix_expression;
  string expression_result;
  int line_number;
  int assembler_line_number;

  code_line ()
  {
    basic_code = "";
    first_command = "";
    second_command = "";
    first_expression = "";
    second_expression = "";
    operand = "";
    postfix_expression = "";
    expression_result = "";
    line_number = 0;
    assembler_line_number = 0;
  }

  bool
  is_empty ()
  {
    return basic_code.empty ();
  }

  bool
  is_there_any_spaces ()
  {
    return basic_code.find (' ') != string::npos;
  }

  bool
  token_is_command (string token)
  {
    return token == "REM" || token == "INPUT" || token == "OUTPUT"
           || token == "GOTO" || token == "IF" || token == "LET"
           || token == "END";
  }

  int
  split ()
  {
    istringstream iss (basic_code);
    string token;
    iss >> token;
    if (token.empty ())
      return 1;
    line_number = stoi (token);

    iss >> token;
    if (!token_is_command (token))
      return 1;
    first_command = token;
    if (first_command == "REM")
      {
        return 0;
      }
    else if (first_command == "INPUT" || first_command == "OUTPUT"
             || first_command == "GOTO")
      {
        iss >> token;
        if (token.empty ())
          return 1;
        operand = token;
        return 0;
      }
    else if (first_command == "IF")
      {
        iss >> token;
        while (!token_is_command (token))
          {
            first_expression += token;
            iss >> token;
          }
        second_command = token;
        if (second_command == "INPUT" || second_command == "OUTPUT"
            || second_command == "GOTO")
          {
            iss >> token;
            if (token.empty ())
              return 1;
            operand = token;
            return 0;
          }
        else if (second_command == "LET")
          {
            token = "";
            iss >> token;
            while (!token.empty ())
              {
                second_expression += token;
                token = "";
                iss >> token;
              }
            return 0;
          }
      }
    else if (first_command == "LET")
      {
        token = "";
        iss >> token;
        while (!token.empty ())
          {
            first_expression += token;
            token = "";
            iss >> token;
          }
        return 0;
      }
    else if (first_command == "END")
      {
        return 0;
      }
    return 1;
  }

  void
  split_expression ()
  {
    if (first_command == "LET")
      {
        expression_result += first_expression[0];
        first_expression.erase (0, 2);
      }
    if (second_command == "LET")
      {
        expression_result += second_expression[0];
        second_expression.erase (0, 2);
      }
  }
};

vector<code_line> read_file (string filename);
int check_code_lines_empty (vector<code_line> &code_lines);
int check_code_lines_spaces (vector<code_line> &code_lines);
int code_lines_to_tokens (vector<code_line> &code_lines);
int get_symbols_from_expression (map<char, int> &table, string &expression,
                                 int address);
map<char, int> make_symbolic_table (vector<code_line> &code_lines);
int precedence (char op);
string infix_to_postfix (string &expression,
                         map<char, pair<int, int> > &constants);
void convert_infix_to_postfix (vector<code_line> &code_lines,
                               map<char, pair<int, int> > &constants);
void give_addresses_to_constants (map<char, int> &table,
                                  map<char, pair<int, int> > &constants);
int count_commands (string &command, string &expression);
map<int, int>
convert_basic_code_lines_adresses_to_assembler (vector<code_line> &code_lines);
string int_to_address (int address);
string take_operand (string &expression);
tuple<string, string, char> get_one_operation (string &expression,
                                               string &expression_result);
void merge_tables (map<char, int> &table,
                   map<char, pair<int, int> > &constants);
string convert_let_to_assembler (int address, string &expression,
                                 string &expression_result,
                                 map<char, int> &table);
pair<int, int> is_there_numbers_in_if (string &expression);
string int_to_sc_number (int value);
string convert_if_to_assembler (code_line &cl, map<char, int> &table,
                                map<int, int> &addresses);
string convert_basic_code_line_to_assembler (code_line &cl,
                                             map<char, int> &table,
                                             map<int, int> &addresses);
string convert_basic_code_lines_to_assembler (
    vector<code_line> &code_lines, map<char, int> &table,
    map<int, int> &addresses, map<char, pair<int, int> > &constants);