#include "simpleassembler.h"

#include <cstring>
#include <string>

int
convert_string_to_cell_value (std::string str)
{
  char buf[128];
  int value;
  strcpy (buf, str.c_str ());

  int sign = buf[0] == '+' ? 0 : 1;
  int right_value = strtol (&buf[3], NULL, 16);
  buf[3] = '\0';
  int left_value = strtol (&buf[1], NULL, 16);
  if (sign && right_value > 127 && left_value > 126)
    {
      value = 0b100000000000000;
      return value;
    }
  right_value = right_value > 127 ? 127 : right_value;
  left_value = left_value > 127 ? 127 << 7 : left_value << 7;
  value = 0;
  value |= (sign << 14) | right_value | left_value;
  if (sign)
    value = ((~(value - 1) & 0x3FFF) | (sign << 14));
  if (sign && !right_value && !left_value)
    value = 0;
  return value;
}
