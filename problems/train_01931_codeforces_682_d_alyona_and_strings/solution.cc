#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int n, m;
int dp[1001][1001][11][2];
int solve(int a, int b, int c, int d) {
  if (a == n || b == m || c == 0) return 0;
  if (dp[a][b][c][d] != -1) return dp[a][b][c][d];
  int &r = dp[a][b][c][d];
  if (d) {
    if (s1[a] == s2[b]) {
      r = max(r, 1 + solve(a + 1, b + 1, c, d));
      r = max(r, 1 + solve(a + 1, b + 1, c - 1, d));
    } else
      r = max(r, solve(a, b, c - 1, 0));
  }
  if (!d) {
    if (s1[a] == s2[b]) r = max(r, 1 + solve(a + 1, b + 1, c, 1));
    r = max(r, solve(a + 1, b, c, 0));
    r = max(r, solve(a, b + 1, c, 0));
  }
  return r;
}
int main() {
  int k;
  cin >> n >> m >> k >> s1 >> s2;
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0, k, 0);
  return 0;
}
