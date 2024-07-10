#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

string
int_to_address (int address)
{
  ostringstream oss;
  oss << setfill ('0') << setw (2) << address;
  return oss.str ();
}
