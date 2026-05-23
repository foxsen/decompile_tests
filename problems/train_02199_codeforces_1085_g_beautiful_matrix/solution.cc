#include <bits/stdc++.h>
using namespace std;
long long n, mat[2021][2021], dp[2021], f[2021][2021];
long long fac[2021], sum[2][2021], vis[2021], vis2[2021];
void read(long long& x) {
  x = 0;
  char c = getchar();
  for (; c > '9' || c < '0'; c = getchar())
    ;
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - '0';
}
long long mul(long long x, long long y) {
  long long ans = 1;
  for (; y; y >>= 1) {
    if (y & 1) ans = ans * x % 998244353ll;
    x = x * x % 998244353ll;
  }
  return ans;
}
void update(long long x, long long add, long long pos) {
  for (; x <= n; x += x & (-x)) sum[pos][x] += add;
}
long long query(long long x, long long pos) {
  long long ans = 0;
  for (; x > 0; x -= x & (-x)) ans += sum[pos][x];
  return ans;
}
int main() {
  read(n);
  if (n == 1) {
    puts("0");
    return 0;
  }
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= n; j++) read(mat[i][j]);
  dp[2] = fac[0] = 1;
  for (long long i = 3; i <= n; i++)
    dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % 998244353ll;
  for (long long i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % 998244353ll;
  for (long long i = 0; i <= n; i++) f[i][0] = fac[i];
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= i; j++) {
      f[i][j] = (f[i][j - 1] - f[i - 1][j - 1] + 998244353ll) % 998244353ll;
    }
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) update(i, 1, 0);
  for (long long i = 1; i <= n; i++) {
    update(mat[1][i], -1, 0);
    ans = (ans + fac[n - i] * query(mat[1][i], 0)) % 998244353ll;
  }
  ans = ans * mul(dp[n], n - 1) % 998244353ll;
  for (long long a, b, c, bk, i = 2; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      vis[j] = vis2[j] = 0;
      update(j, 1, 0);
      update(j, 1, 1);
    }
    long long tmp = 0;
    for (long long j = 1; j <= n; j++) {
      if (!vis[mat[i - 1][j]]) {
        vis[mat[i - 1][j]] = 1;
        update(mat[i - 1][j], -1, 1);
      }
      bk = !vis[mat[i][j]];
      if (bk) {
        vis[mat[i][j]] = 1;
        update(mat[i][j], -1, 1);
      }
      update(mat[i][j], -1, 0);
      vis2[mat[i][j]] = 1;
      a = query(mat[i][j], 0);
      b = query(mat[i][j], 1);
      c = query(n, 1) - query(mat[i][j], 1);
      a -= b;
      tmp = (tmp + f[n - j][b - 1 + bk + c] * b % 998244353ll +
             f[n - j][b + bk + c] * a % 998244353ll) %
            998244353ll;
      if (mat[i][j] > mat[i - 1][j] && !vis2[mat[i - 1][j]]) {
        tmp = (tmp - f[n - j][b + bk + c] + 998244353ll) % 998244353ll;
      }
    }
    ans = (ans + tmp * mul(dp[n], n - i)) % 998244353ll;
  }
  cout << ans;
  return 0;
}
