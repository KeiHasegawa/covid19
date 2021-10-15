#include <map>
#include <vector>
#include <string>
using namespace std;

struct info_t {
  map<int, int> tm;
  vector<pair<int, int> > gn;
  tuple<int, int, int> pl;
};

map<string, map<pair<double, double>, info_t> > g_crow_data;
