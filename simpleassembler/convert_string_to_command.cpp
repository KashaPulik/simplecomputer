#include "simpleassembler.h"

#include <string>

int
convert_string_to_command (std::string command)
{
  if (command == "NOP")
    return NOP;
  else if (command == "CPUINFO")
    return CPUINFO;
  else if (command == "READ")
    return READ;
  else if (command == "WRITE")
    return WRITE;
  else if (command == "LOAD")
    return LOAD;
  else if (command == "STORE")
    return STORE;
  else if (command == "ADD")
    return ADD;
  else if (command == "SUB")
    return SUB;
  else if (command == "DIVIDE")
    return DIVIDE;
  else if (command == "MUL")
    return MUL;
  else if (command == "JUMP")
    return JUMP;
  else if (command == "JNEG")
    return JNEG;
  else if (command == "JZ")
    return JZ;
  else if (command == "HALT")
    return HALT;
  else if (command == "NOT")
    return NOT;
  else if (command == "AND")
    return AND;
  else if (command == "OR")
    return OR;
  else if (command == "XOR")
    return XOR;
  else if (command == "JNS")
    return JNS;
  else if (command == "JC")
    return JC;
  else if (command == "JNC")
    return JNC;
  else if (command == "JP")
    return JP;
  else if (command == "JNP")
    return JNP;
  else if (command == "CHL")
    return CHL;
  else if (command == "SHR")
    return SHR;
  else if (command == "RCL")
    return RCL;
  else if (command == "RCR")
    return RCR;
  else if (command == "NEG")
    return NEG;
  else if (command == "ADDC")
    return ADDC;
  else if (command == "SUBC")
    return SUBC;
  else if (command == "LOGLC")
    return LOGLC;
  else if (command == "LOGRC")
    return LOGRC;
  else if (command == "=")
    return EQ;
  return -1;
}
