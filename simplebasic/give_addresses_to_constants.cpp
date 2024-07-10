#include <map>
#include <utility>

using namespace std;

void
give_addresses_to_constants (map<char, int> &table,
                             map<char, pair<int, int> > &constants)
{
  auto last_address = table.end ();
  --last_address;
  int address = last_address->second - 1;
  for (auto &c : constants)
    c.second.first = address--;
}
