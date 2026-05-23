#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10, N = 2e4 + 10;
const int n = 1e5;
long long ans, s[M];
int gcd(int x, int y) {
  int i = 0, j = 0;
  if (x == 0) return y;
  if (y == 0) return x;
  for (; 0 == (x & 1); i++) x >>= 1;
  for (; 0 == (y & 1); j++) y >>= 1;
  if (i > j) i = j;
  while (1) {
    if (x < y) x ^= y, y ^= x, x ^= y;
    if (0 == (x -= y)) return y << i;
    while (0 == (x & 1)) x >>= 1;
  }
}
int T, A, B, C;
int prime[N], cc[M], cnt;
bool vis[M];
void init() {
  s[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) {
      prime[++cnt] = i;
      s[i] = 2;
      cc[i] = 1;
    }
    for (int j = 1, v; j <= cnt && i * prime[j] <= n; j++) {
      v = i * prime[j];
      vis[v] = 1;
      if (!(i % prime[j])) {
        s[v] = s[i] / (cc[i] + 1) * (cc[i] + 2);
        cc[v] = cc[i] + 1;
        break;
      }
      s[v] = s[i] * s[prime[j]];
      cc[v] = 1;
    }
  }
}
long long all(int a, int b, int c) { return s[a] * s[b] * s[c]; }
long long S(long long a) { return (a * (a - 1ll)) / 2ll; }
long long S2(long long a) { return (a * (a - 1ll) * (a - 2ll)) / 6ll * 4ll; }
long long calc1(int ab, int c) { return S(s[ab]) * s[c]; }
long long calc2(int a, int bc) { return s[a] * S(s[bc]); }
long long calc3(int abc) { return S(s[abc]) * 2ll + S2(s[abc]); }
long long calc4(int ab, int abc) { return (s[ab] - s[abc]) * S(s[abc]); }
long long calc5(int ab, int bc, int ac, int abc) {
  return (s[ab] - s[abc]) * (s[bc] - s[abc]) * (s[ac] - s[abc]);
}
int ab, bc, ac, abc;
long long solve() {
  return all(A, B, C) - calc1(ab, C) - calc2(A, bc) - calc2(B, ac) +
         calc4(ab, abc) + calc4(bc, abc) + calc4(ac, abc) -
         calc5(ab, bc, ac, abc) + calc3(abc);
}
int main() {
  init();
  for (scanf("%d", &T); T--;) {
    scanf("%d%d%d", &A, &B, &C);
    ab = gcd(A, B), bc = gcd(B, C), ac = gcd(A, C);
    abc = gcd(A, bc);
    printf("%I64d\n", solve());
  }
  return 0;
}
