#include <bits/stdc++.h>
const long long MOD = 1e9 + 7;
const long long INF = 1011111111;
const long long LLINF = 1000111000111000111LL;
const long double EPS = 1e-10;
const long double PI = 3.14159265358979323;
using namespace std;
long long powm(long long base, long long exp, long long mod = MOD) {
  long long ans = 1;
  while (exp) {
    if (exp & 1) ans = (ans * base) % mod;
    exp >>= 1, base = (base * base) % mod;
  }
  return ans;
}
const long long N = 505;
long long a[N][N], dp[4][N][N], pref[8][N][N], val[8][N][N];
vector<pair<long long, pair<long long, long long>>> v;
long long dist(long long x1, long long y1, long long x2, long long y2) {
  return min(abs(x1 - x2), abs(y1 - y2)) + 1;
}
long long get(long long k, long long x1, long long y1, long long x2,
              long long y2) {
  if (x1 > x2 or y1 > y2) return 0;
  return pref[k][x2][y2] - pref[k][x2][y1 - 1] - pref[k][x1 - 1][y2] +
         pref[k][x1 - 1][y1 - 1];
}
bool check(long long x, long long y, long long r1, long long c1, long long r2,
           long long c2) {
  return (x >= r1 and x <= r2 and y >= c1 and y <= c2);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, q;
  cin >> n >> m >> q;
  for (long long i = 0; i < n + 2; i++)
    for (long long j = 0; j < m + 2; j++) a[i][j] = 5;
  for (long long i = 1; i < n + 1; i++)
    for (long long j = 1; j < m + 1; j++) {
      char x;
      cin >> x;
      if (x == 'R') a[i][j] = 0;
      if (x == 'G') a[i][j] = 1;
      if (x == 'Y') a[i][j] = 2;
      if (x == 'B') a[i][j] = 3;
    }
  for (long long i = 1; i < n + 1; i++)
    for (long long j = 1; j < m + 1; j++)
      if (a[i][j] == 0)
        dp[0][i][j] =
            1 + min(dp[0][i - 1][j - 1], min(dp[0][i - 1][j], dp[0][i][j - 1]));
  for (long long i = 1; i < n + 1; i++)
    for (long long j = m; j >= 1; j--)
      if (a[i][j] == 1)
        dp[1][i][j] =
            1 + min(dp[1][i - 1][j + 1], min(dp[1][i - 1][j], dp[1][i][j + 1]));
  for (long long i = n; i >= 1; i--)
    for (long long j = 1; j < m + 1; j++)
      if (a[i][j] == 2)
        dp[2][i][j] =
            1 + min(dp[2][i + 1][j - 1], min(dp[2][i + 1][j], dp[2][i][j - 1]));
  for (long long i = n; i >= 1; i--)
    for (long long j = m; j >= 1; j--)
      if (a[i][j] == 3)
        dp[3][i][j] =
            1 + min(dp[3][i + 1][j + 1], min(dp[3][i + 1][j], dp[3][i][j + 1]));
  for (long long i = 1; i < n + 1; i++)
    for (long long j = 1; j < m + 1; j++) {
      long long minm = LLINF;
      minm = min(minm, dp[0][i][j]);
      minm = min(minm, dp[1][i][j + 1]);
      minm = min(minm, dp[2][i + 1][j]);
      minm = min(minm, dp[3][i + 1][j + 1]);
      if (minm == 0) continue;
      if (minm >= 8)
        v.push_back(make_pair(minm, make_pair(i, j)));
      else
        for (long long k = 1; k < minm + 1; k++) val[k][i][j]++;
    }
  sort((v).begin(), (v).end()), reverse((v).begin(), (v).end());
  for (long long k = 1; k < 8; k++)
    for (long long i = 1; i < n + 1; i++)
      for (long long j = 1; j < m + 1; j++)
        pref[k][i][j] = val[k][i][j] + pref[k][i][j - 1] + pref[k][i - 1][j] -
                        pref[k][i - 1][j - 1];
  while (q--) {
    long long r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    long long ans = 0;
    for (auto i : v) {
      long long x = i.second.first, y = i.second.second;
      if (check(x, y, r1, c1, r2, c2) && check(x + 1, y + 1, r1, c1, r2, c2) &&
          check(x + 1, y, r1, c1, r2, c2) && check(x, y + 1, r1, c1, r2, c2)) {
        long long border = i.first;
        border = min(border, dist(x, y, r1, c1));
        border = min(border, dist(x, y + 1, r1, c2));
        border = min(border, dist(x + 1, y, r2, c1));
        border = min(border, dist(x + 1, y + 1, r2, c2));
        ans = max(ans, border);
      } else
        continue;
    }
    for (long long i = 1; i < 8; i++) {
      long long tmp = get(i, r1 + i - 1, c1 + i - 1, r2 - i, c2 - i);
      if (tmp) ans = max(ans, i);
    }
    cout << (4 * ans * ans) << '\n';
  }
  return 0;
}
