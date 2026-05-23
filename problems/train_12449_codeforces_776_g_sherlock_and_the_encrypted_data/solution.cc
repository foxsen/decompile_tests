#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int sum = 0;
  char c = getchar();
  bool f = 0;
  while (c < '0' || c > '9') {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  if (f) return -sum;
  return sum;
}
const int Z = 65535;
long long f[17][Z + 1][16];
bool vis[17][Z + 1][16];
inline long long dp(int p, int l, int K) {
  if (vis[p][l][K]) return f[p][l][K];
  vis[p][l][K] = 1;
  if (!p) return f[p][l][K] = ((l >> K) & 1);
  int i;
  long long r = 0;
  for (i = 0; i <= 15; i++) r += dp(p - 1, ((l << 4) | i) & Z, max(K, i));
  return f[p][l][K] = r;
}
char s[20];
inline long long _gets() {
  int i, x, y;
  long long r = 0;
  scanf("%s", s + 1);
  for (x = strlen(s + 1), i = 1; i <= x; i++) {
    if (s[i] >= '0' && s[i] <= '9')
      y = s[i] - '0';
    else
      y = s[i] - 'a' + 10;
    r = (r << 4) | y;
  }
  return r;
}
int n, S[20];
inline long long ask(long long v) {
  if (v <= 0) return 0;
  int i, j, K = 0, l = 0;
  long long r = 0;
  for (n = 0; v; v >>= 4) S[++n] = v & 15;
  for (i = n; i >= 1; i--) {
    for (j = 0; j < S[i]; j++) r += f[i - 1][((l << 4) | j) & Z][max(K, j)];
    l <<= 4;
    l |= S[i];
    l &= Z;
    K = max(K, S[i]);
  }
  return r + f[0][l][K];
}
inline void work() {
  int T = read();
  long long l, r;
  while (T--) {
    l = _gets();
    r = _gets();
    printf("%I64d\n", ask(r) - ask(l - 1));
  }
}
int main() {
  dp(16, 0, 0);
  work();
  return 0;
}
