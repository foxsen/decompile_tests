#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const long long MOD = 1e9 + 7;
long long dp[MAXN];
int main() {
  dp[0] = 0LL;
  dp[1] = 1LL;
  for (int(i) = (2); (i) < (MAXN); (i)++) {
    dp[i] = (dp[i - 1] * 2LL + 1LL) % MOD;
  }
  string s;
  cin >> s;
  int a_ctr = 0, b_ctr = 0;
  long long res = 0;
  for (int(i) = (0); (i) < (s.length()); (i)++) {
    if (s[i] == 'a') {
      ++a_ctr;
    } else {
      res = (res + dp[a_ctr]) % MOD;
    }
  }
  cout << res;
  return 0;
}
