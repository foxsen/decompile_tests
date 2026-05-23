#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
int Q, n, r, d[N][21];
int notp[N], p[N];
void sieve(int n) {
  for (int i = 2; i <= n; i++) {
    if (!notp[i]) p[++p[0]] = i;
    for (int j = 1; j <= p[0] && i * p[j] <= n; j++) {
      notp[i * p[j]] = 1;
      if (i % p[j] == 0) break;
    }
  }
}
void dp() {
  for (int i = 1; i <= 20; i++) d[0][i] = 2;
  for (int i = 1; i < N; i++) {
    d[i][0] = 1;
    for (int j = 1; j <= 20; j++) d[i][j] = (d[i - 1][j] + d[i][j - 1]) % MOD;
  }
}
void solve(int r, int n) {
  long long ans = 1;
  int m = sqrt(n);
  for (int i = 1; i <= p[0] && p[i] <= m; i++)
    if (n % p[i] == 0) {
      int e = 0;
      while (n % p[i] == 0) e++, n /= p[i];
      ans = (ans * d[r][e]) % MOD;
    }
  if (n != 1) ans = (ans * d[r][1]) % MOD;
  printf("%I64d\n", ans);
}
int main() {
  sieve(N - 1);
  dp();
  Q = read();
  while (Q--) {
    r = read();
    n = read();
    solve(r, n);
  }
}
