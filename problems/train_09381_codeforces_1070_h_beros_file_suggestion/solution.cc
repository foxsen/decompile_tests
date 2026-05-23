#include <bits/stdc++.h>
using namespace std;
map<string, int> nosub;
map<string, string> name;
bool comp(pair<string, int> a, pair<string, int> b) {
  if (a.first.size() < b.first.size()) return true;
  if (a.first.size() == b.first.size() && a.first.size() != 0 &&
      a.first[0] < b.first[0])
    return true;
  return false;
}
void sub(string a) {
  map<string, int> help;
  for (int i = 0; i < a.size(); i++) {
    for (int j = 1; j + i <= a.size(); j++) {
      if (help[a.substr(i, j)] == 0) {
        help[a.substr(i, j)]++;
        nosub[a.substr(i, j)]++;
        name[a.substr(i, j)] = a;
      }
    }
  }
}
int main() {
  int n, query;
  string s;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cin >> s;
    sub(s);
  }
  scanf("%d", &query);
  for (int i = 0; i < query; i++) {
    cin >> s;
    cout << nosub[s] << " ";
    if (nosub[s] == 0)
      cout << "-" << endl;
    else
      cout << name[s] << endl;
  }
  return 0;
}
