#include <bits/stdc++.h>
using namespace std;
struct info {
  string currentname;
  string oldname;
};
int main() {
  vector<info> query;
  int t;
  string s1, s2;
  cin >> t;
  while (t--) {
    cin >> s1 >> s2;
    bool flag = true;
    for (int i = 0; i < query.size(); i++)
      if (query[i].currentname == s1) {
        flag = false;
        query[i].currentname = s2;
        break;
      }
    if (flag) query.push_back({s2, s1});
  }
  cout << query.size() << endl;
  for (int i = 0; i < query.size(); i++)
    cout << query[i].oldname << " " << query[i].currentname << endl;
}
