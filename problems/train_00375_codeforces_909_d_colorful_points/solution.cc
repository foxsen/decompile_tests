#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
list<pair<char, int>> L;
int solve() {
  int res = 0;
  while (L.size() > 1) {
    int mini = INF;
    for (auto it = L.begin(); it != L.end(); ++it) {
      int x = it->second;
      if (it == L.begin() || next(it) == L.end()) {
        mini = min(mini, x);
      } else {
        mini = min(mini, (x + 1) / 2);
      }
    }
    res += mini;
    for (auto it = L.begin(); it != L.end(); ++it) {
      if (it == L.begin() || next(it) == L.end()) {
        it->second -= mini;
      } else {
        it->second -= 2 * mini;
      }
    }
    for (auto it = L.begin(); it != L.end();) {
      auto cur = it++;
      if (cur->second <= 0) {
        L.erase(cur);
        continue;
      }
      if (cur != L.begin()) {
        auto pre = prev(cur);
        if (pre->first == cur->first) {
          pre->second += cur->second;
          L.erase(cur);
        }
      }
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  char last = s[0];
  int cnt = 0;
  s.push_back('$');
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == last) {
      cnt++;
    } else {
      L.emplace_back(last, cnt);
      last = s[i];
      cnt = 1;
    }
  }
  {};
  cout << solve() << endl;
}
