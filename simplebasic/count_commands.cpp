#include <string>

using namespace std;

int
count_commands (string &command, string &expression)
{
  bool inNumber = false;
  int count = 0;
  bool there_is_expression = false;
  if (command == "REM")
    return 0;
  if (command == "GOTO" || command == "INPUT" || command == "OUTPUT"
      || command == "END")
    return 1;
  if (command == "IF")
    {
      for (char c : expression)
        {
          if (isdigit (c))
            {
              if (!inNumber)
                {
                  inNumber = true;
                  count++;
                }
            }
          else
            {
              inNumber = false;
            }
        }
      return count + 4;
    }
  if (command == "LET")
    {
      for (char c : expression)
        {
          if (isalpha (c))
            count += 3;
          if (c == '+' || c == '-' || c == '*' || c == '/')
            there_is_expression = true;
        }
      if (there_is_expression)
        return count - 3;
      else
        return 2;
    }
  return 0;
}
