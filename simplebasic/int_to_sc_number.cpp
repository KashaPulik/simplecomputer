#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

string
int_to_sc_number (int value)
{
  stringstream stream;
  stream << hex << uppercase << setfill ('0') << setw (4) << value;
  if (value < 0)
    {
      return '-' + stream.str ();
    }
  return '+' + stream.str ();
}
