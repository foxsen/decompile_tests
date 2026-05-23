#include <bits/stdc++.h>
using namespace std;
const long long maxn = 85;
const long long maxk = 11;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
mt19937 rng(time(0));
long long n, m, c[maxn][maxn], dp[maxk][maxn], ans;
vector<long long> a, b;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      cin >> c[i][j];
    }
  }
  ans = inf;
  for (long long o = 0; o < 5000; o++) {
    a.clear();
    b.clear();
    a.push_back(0);
    for (long long i = 1; i < n; i++) {
      if (rng() % 2)
        a.push_back(i);
      else
        b.push_back(i);
    }
    fill(dp[0] + 1, dp[0] + n, inf);
    for (long long i = 0; i < m / 2; i++) {
      fill(dp[i + 1], dp[i + 1] + n, inf);
      for (long long j : a) {
        for (long long k : b) {
          dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + c[j][k]);
        }
      }
      for (long long j : b) {
        for (long long k : a) {
          dp[i + 1][k] = min(dp[i + 1][k], dp[i + 1][j] + c[j][k]);
        }
      }
    }
    ans = min(ans, dp[m / 2][0]);
  }
  cout << ans;
  return 0;
}
