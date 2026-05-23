#include <bits/stdc++.h>
using namespace std;
const int MX = 1e6 + 100, Mx = 4 * 1e3 + 100;
int a[Mx], dp[Mx][Mx], an[MX], ann[MX], n;
void input() {
  cin >> n;
  int num = 1;
  for (int i = 1; i <= n; ++i) {
    int e;
    cin >> e;
    if (ann[e] == 0) {
      a[i] = num;
      ann[e] = num;
      an[e]++;
      num++;
    } else {
      a[i] = ann[e];
      an[e]++;
    }
  }
}
void solve() {
  for (int i = 1; i <= n; ++i) {
    dp[a[i]][0] = 1;
    for (int j = i - 1; j > 0; --j) {
      if (a[i] == a[j]) continue;
      dp[a[i]][a[j]] = max(dp[a[j]][a[i]] + 1, 2);
    }
  }
  int ans = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) ans = max(ans, dp[i][j]);
  }
  for (int i = 1; i < MX; ++i) ans = max(ans, an[i]);
  cout << ans << endl;
}
int main() {
  input();
  solve();
}
