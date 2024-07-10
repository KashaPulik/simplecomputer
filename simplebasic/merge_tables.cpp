#include <map>
#include <utility>

using namespace std;

void
merge_tables (map<char, int> &table, map<char, pair<int, int> > &constants)
{
  for (auto &c : constants)
    {
      table[c.first] = c.second.first;
    }
}
