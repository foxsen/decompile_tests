#include <bits/stdc++.h>
using namespace std;
long long dp[26][26];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m, l = 0, p = 0, i, flag = 0, k, t, d = 0, q = 0, r = 0;
  cin >> n;
  string s;
  for (long long i = 0; i < n; i++) {
    cin >> s;
    long long start, last;
    k = (long long)s.size();
    start = s[0] - 'a';
    last = s[k - 1] - 'a';
    for (long long j = 0; j < 26; j++) {
      if (dp[j][start] == 0) continue;
      dp[j][last] = max(dp[j][last], dp[j][start] + k);
    }
    dp[start][last] = max(dp[start][last], k);
  }
  for (long long i = 0; i < 26; i++) {
    p = max(p, dp[i][i]);
  }
  cout << p;
  return 0;
}
