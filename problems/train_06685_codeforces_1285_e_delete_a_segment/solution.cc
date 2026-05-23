#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<tuple<int, int, int>> v;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    v.emplace_back(l, 1, i);
    v.emplace_back(r + 1, -1, i);
  }
  sort(v.begin(), v.end());
  set<int> s;
  int seg = 0, inf = 1000000001, m0 = inf;
  map<int, int> m;
  bool dbl = false;
  for (auto t : v) {
    int x = get<0>(t), d = get<1>(t), i = get<2>(t);
    if (d == 1) {
      if (s.empty()) {
        seg++;
      } else {
        dbl = true;
      }
      if (s.size() == 1 && *s.begin() == m0) m[m0]++;
      s.insert(i);
    } else {
      s.erase(i);
      if (s.size() == 1) m0 = *s.begin();
      if (s.empty()) m0 = inf;
    }
  }
  int mmax = 0;
  for (auto x : m) {
    mmax = max(mmax, x.second);
  }
  if (!dbl) seg--;
  cout << seg + mmax << endl;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) solve();
}
