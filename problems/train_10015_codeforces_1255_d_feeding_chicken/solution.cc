#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  string rps = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  while (t--) {
    int n, m, k, tot = 0;
    cin >> n >> m >> k;
    vector<string> s(n);
    for (int i = 0, ThxDem = n; i < ThxDem; ++i) {
      cin >> s[i];
      for (int j = 0, ThxDem = m; j < ThxDem; ++j) tot += s[i][j] == 'R';
    }
    int rem = tot % k, mn = tot / k;
    vector<vector<char>> ans(n, vector<char>(m, '-'));
    int x = 0, y = 0, id = 0, ac = 0;
    while (x < n) {
      ans[x][y] = rps[id];
      ac += s[x][y] == 'R';
      int top = mn + (rem > 0);
      if (ac == top && id + 1 < k) ac = 0, id++, rem--;
      if (x % 2 == 0)
        y++;
      else
        y--;
      if (y < 0 || y == m) y = min(m - 1, max(0, y)), x++;
    }
    for (int i = 0, ThxDem = n; i < ThxDem; ++i) {
      for (int j = 0, ThxDem = m; j < ThxDem; ++j) cout << ans[i][j];
      cout << "\n";
    }
  }
}
