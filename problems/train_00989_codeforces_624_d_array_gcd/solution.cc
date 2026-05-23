#include <bits/stdc++.h>
using namespace std;
const long long INF = 3000000000000000000LL;
long long dp[1000001][3];
void pf(long a, set<long long> &s) {
  long long i;
  for (i = 2; i * i <= a; ++i) {
    if (a % i == 0) {
      s.insert(i);
      while (a % i == 0) a /= i;
    }
  }
  if (a > 1) s.insert(a);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long i, j;
  long long n;
  long long A, B;
  cin >> n >> A >> B;
  vector<long long> a(n);
  for (i = 0; i < n; ++i) cin >> a[i];
  set<long long> p;
  pf(a[0] - 1, p);
  pf(a[0], p);
  pf(a[0] + 1, p);
  pf(a[n - 1] - 1, p);
  pf(a[n - 1], p);
  pf(a[n - 1] + 1, p);
  long long ans = INF;
  for (__typeof(p.begin()) it = p.begin(); it != p.end(); it++) {
    int d = *it;
    for (i = 0; i < 3; ++i) dp[0][i] = 0;
    for (i = 0; i < n; ++i) {
      long x = a[i] % d;
      if (x == 0) {
        dp[i + 1][0] = dp[i][0];
        dp[i + 1][1] = min(dp[i][0], dp[i][1] + A);
        dp[i + 1][2] = min(dp[i][1], dp[i][2]);
      } else if (x == 1 || x == d - 1) {
        dp[i + 1][0] = dp[i][0] + B;
        dp[i + 1][1] = min(dp[i][0] + B, dp[i][1] + A);
        dp[i + 1][2] = min(dp[i][1] + B, dp[i][2] + B);
      } else {
        dp[i + 1][0] = INF;
        dp[i + 1][1] = min(dp[i][0], dp[i][1]) + A;
        dp[i + 1][2] = dp[i + 1][1];
      }
    }
    long long tmp = INF;
    for (i = 0; i < 3; ++i) tmp = min(tmp, dp[n][i]);
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}
