#include <bits/stdc++.h>
using namespace std;
int solve(int n, vector<int> a) {
  int sz = a.size();
  int pos = 1;
  for (int i = 1; i < sz; i++) {
    a[i] += a[i - 1];
  }
  int mx = 0;
  for (int i = 0; i < sz; i++) {
    int possible_right = n - pos;
    if (a[i] > possible_right) break;
    mx = max(mx, a[i]);
    if (a[i] < 0) {
      if (pos - 1 >= -a[i]) continue;
      int margin = (n - mx - pos);
      pos += min(margin, -a[i] - (pos - 1));
      if (-a[i] > pos - 1) break;
    }
  }
  return pos;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int len = s.length();
    vector<int> height, width;
    for (auto &u : s) {
      if (u == 'L')
        width.push_back(-1);
      else if (u == 'R')
        width.push_back(1);
      else if (u == 'U')
        height.push_back(-1);
      else
        height.push_back(1);
    }
    int x, y;
    x = solve(n, height);
    y = solve(m, width);
    cout << x << " " << y << "\n";
  }
  return 0;
}
