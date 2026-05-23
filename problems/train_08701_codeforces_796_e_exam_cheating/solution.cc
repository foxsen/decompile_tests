#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char now[1 << 16], *S, *T;
  if (T == S) {
    T = (S = now) + fread(now, 1, 1 << 16, stdin);
    if (T == S) return EOF;
  }
  return *S++;
}
inline long long read() {
  register long long x = 0, f = 1;
  char ch = gc();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = gc();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = gc();
  }
  return (f == 1) ? x : -x;
}
int dp[2][1010][51][51], dpm[2][1010];
int n, P, K, la, lb, ha[10101], hb[10101];
inline void chkmax(int &a, const int &b) { return (void)(a < b ? a = b : 0); }
inline void chkmax(int &a, const int &b, const int &c) {
  chkmax(a, b);
  chkmax(a, c);
}
signed main() {
  n = read(), P = read(), K = read();
  la = read();
  for (int i = 1; i <= la; i++) {
    int x = read();
    ha[x] = 1;
  }
  lb = read();
  for (int i = 1; i <= lb; i++) {
    int x = read();
    hb[x] = 1;
  }
  if (P * K >= 2 * n) {
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += (ha[i] | hb[i]);
    }
    cout << ans;
    return 0;
  }
  bool cur = 0;
  memset(dp, 0x80, sizeof dp);
  dp[cur][0][0][0] = 0;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cur ^= 1;
    memset(dpm[cur], 0x80, sizeof dpm[cur]);
    memset(dp[cur], 0x80, sizeof dp[cur]);
    for (int j = 0; j <= P; j++) {
      for (int a = 0; a < K; a++) {
        for (int b = 0; b < K; b++) {
          long long las = dp[cur ^ 1][j][a][b];
          chkmax(dp[cur][j][max(a - 1, 0)][max(b - 1, 0)],
                 las + ((a ? ha[i] : 0) | (b ? hb[i] : 0)));
          if (j + 1 <= P) {
            chkmax(dp[cur][j + 1][K - 1][max(b - 1, 0)],
                   las + ((ha[i]) | (b ? hb[i] : 0)));
            chkmax(dp[cur][j + 1][max(a - 1, 0)][K - 1],
                   las + ((a ? ha[i] : 0) | (hb[i])));
            if (j + 2 <= P) {
              chkmax(dp[cur][j + 2][K - 1][K - 1], las + ((ha[i]) | (hb[i])));
            }
          }
        }
      }
      for (int a = 0; a < K; a++) {
        for (int b = 0; b < K; b++) {
          ans = max(ans, dp[cur][j][a][b]);
        }
      }
    }
  }
  cout << ans;
  return 0;
}
