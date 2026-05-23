#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int inf = 1e9 + 5;
vector<int> a(2005);
int dp[2005][2005];
int n, h, l, r;
int fun(int idx, int hr) {
  int c1, c2, t1, t2;
  if (idx == n) return 0;
  if (dp[idx][hr] != -1) return dp[idx][hr];
  t1 = hr + a[idx];
  t1 %= h;
  t2 = hr + a[idx] - 1;
  t2 %= h;
  if (t1 >= l && t1 <= r)
    c1 = 1 + fun(idx + 1, t1);
  else
    c1 = fun(idx + 1, t1);
  if (t2 >= l && t2 <= r)
    c2 = 1 + fun(idx + 1, t2);
  else
    c2 = fun(idx + 1, t2);
  return dp[idx][hr] = max(c1, c2);
}
void solve() {
  cin >> n >> h >> l >> r;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  memset(dp, -1, sizeof(dp));
  cout << fun(0, 0);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  cout << "\n";
  return 0;
}
