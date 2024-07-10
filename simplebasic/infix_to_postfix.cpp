#include "simplebasic.h"

#include <map>
#include <stack>
#include <string>
#include <utility>

using namespace std;

string
infix_to_postfix (string &expression, map<char, pair<int, int> > &constants)
{
  std::stack<char> s;
  std::stack<int> s_prec;
  int increment = 0;
  int prec = 0;
  string result;
  char constant = 'a';
  int exist = false;
  int int_number;
  string number = "";
  if (constants.size () != 0)
    {
      auto last_constant = constants.end ();
      --last_constant;
      constant = last_constant->first + 1;
    }
  for (char c : expression)
    {
      if (isdigit (c))
        {
          number += c;
          continue;
        }
      if (number != "")
        {
          int_number = stoi (number);
          for (auto &c : constants)
            {
              if (c.second.second == int_number)
                {
                  constant = c.first;
                  exist = true;
                }
            }
          if (!exist)
            {
              if (constants.size () != 0)
                {
                  auto last_constant = constants.end ();
                  --last_constant;
                  constant = last_constant->first + 1;
                }
              constants[constant] = make_pair (0, int_number);
            }
          result += constant;

          exist = false;
          number = "";
        }
      prec = precedence (c);
      switch (prec)
        {
        case 0:
          result += c;
          break;
        case 3:
          increment += 2;
          break;
        case 4:
          increment -= 2;
          break;
        default:
          prec += increment;
          if (s.size () == 0)
            {
              s.push (c);
              s_prec.push (prec);
            }
          else if (s_prec.top () >= prec)
            {
              while (s.size () > 0)
                {
                  result += s.top ();
                  s.pop ();
                  s_prec.pop ();
                }
              s.push (c);
              s_prec.push (prec);
            }
          else
            {
              s.push (c);
              s_prec.push (prec);
            }
          break;
        }
    }

  if (number != "")
    {
      int_number = stoi (number);
      for (auto &c : constants)
        {
          if (c.second.second == int_number)
            {
              constant = c.first;
              exist = true;
            }
        }
      if (!exist)
        {
          if (constants.size () != 0)
            {
              auto last_constant = constants.end ();
              --last_constant;
              constant = last_constant->first + 1;
            }
          constants[constant] = make_pair (0, int_number);
        }
      result += constant++;

      exist = false;
      number = "";
    }

  while (s.size () > 0)
    {
      result += s.top ();
      s.pop ();
      s_prec.pop ();
    }
  return result;
}