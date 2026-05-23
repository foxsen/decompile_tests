#include <bits/stdc++.h>
using namespace std;
long long dp[501][501];
string s;
long long fun(int l, int r) {
  if (l > r) return 0;
  if (l == r) return 1;
  if (dp[l][r] != -1) return dp[l][r];
  long long res = 0;
  res = 1 + fun(l + 1, r);
  for (long long i = l + 1; i <= r; i++) {
    if (s[l] == s[i]) res = min(res, fun(l + 1, i - 1) + fun(i, r));
  }
  return dp[l][r] = res;
}
int main() {
  long long n;
  cin >> n;
  cin >> s;
  for (int i = 0; i <= 500; i++)
    for (int j = 0; j <= 500; j++) dp[i][j] = -1;
  long long ans = fun(0, s.length() - 1);
  cout << ans;
  return 0;
}
