#include <bits/stdc++.h>
const long long MXN = 5e1 + 5, md = 1e9 + 7, inf = 1e9, zero = 0;
using namespace std;
long long n;
long long dp[MXN][MXN][MXN];
long long game(long long x, long long y, long long k) {
  if (dp[x][y][k] || x * y == k || !k) return dp[x][y][k];
  long long res = 1e12;
  for (long long i = 1; i * 2 <= x; i++)
    for (long long j = 0; j <= k; j++)
      res = min(res, y * y + game(i, y, k - j) + game(x - i, y, j));
  for (long long i = 1; i * 2 <= y; i++)
    for (long long j = 0; j <= k; j++)
      res = min(res, x * x + game(x, y - i, k - j) + game(x, i, j));
  dp[x][y][k] = res;
  return res;
}
int main() {
  long long q;
  cin >> q;
  for (long long i = 0; i < q; i++) {
    long long x, y, k;
    cin >> x >> y >> k;
    cout << game(x, y, k) << endl;
  }
}
