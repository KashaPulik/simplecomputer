int
precedence (char op)
{
  if (op == '+' || op == '-')
    return 1;
  if (op == '*' || op == '/')
    return 2;
  if (op == '(')
    return 3;
  if (op == ')')
    return 4;
  return 0;
}
