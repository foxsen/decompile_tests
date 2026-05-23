#include <bits/stdc++.h>
using namespace std;
set<int> d, r;
set<int> gen;
int n;
string s;
bool del[200010];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'D') {
      d.insert(i);
    }
    if (s[i] == 'R') {
      r.insert(i);
    }
    gen.insert(i);
  }
  while (1) {
    if (d.empty()) break;
    if (r.empty()) break;
    vector<int> deld;
    for (set<int>::iterator it = gen.begin(); it != gen.end(); it++) {
      int idx = *it;
      if (del[idx] == 1) continue;
      if (s[idx] == 'D') {
        set<int>::iterator t = r.upper_bound(idx);
        if (t != r.end()) {
          deld.push_back(*t);
          r.erase(*t);
          del[*t] = 1;
        } else if (r.size()) {
          t = r.begin();
          deld.push_back(*t);
          r.erase(*t);
          del[*t] = 1;
        }
      }
      if (s[idx] == 'R') {
        set<int>::iterator t = d.upper_bound(idx);
        if (t != d.end()) {
          deld.push_back(*t);
          d.erase(*t);
          del[*t] = 1;
        } else if (d.size()) {
          t = d.begin();
          deld.push_back(*t);
          d.erase(*t);
          del[*t] = 1;
        }
      }
    }
    for (int i = 0; i < deld.size(); i++) {
      gen.erase(deld[i]);
    }
  }
  if (d.size()) {
    cout << 'D' << "\n";
  } else {
    cout << "R"
         << "\n";
  }
  return 0;
}
