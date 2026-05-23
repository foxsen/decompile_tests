#include <bits/stdc++.h>
using namespace std;
struct edge {
  int x, w;
  edge() {}
  edge(int x, int w) : x(x), w(w) {}
};
inline void read(int &x) {
  char ch;
  int f = 1;
  x = 0;
  do {
    ch = getchar();
    if (ch == '-') f = -f;
  } while (ch < '0' || ch > '9');
  do {
    x = (x << 3) + (x << 1) + (ch & 15);
    ch = getchar();
  } while (ch >= '0' && ch <= '9');
  x *= f;
}
const int maxs = 1000010;
const long long M = 998244353;
struct node {
  long long x, y;
  int w;
} blk[maxs];
long long inv[maxs], f[maxs], Sfp2[maxs], Sx[maxs], Sy[maxs];
int main() {
  int n, m, s, sx, sy;
  read(n);
  read(m);
  s = n * m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      int pls = (i - 1) * m + j;
      read(blk[pls].w);
      blk[pls].x = i;
      blk[pls].y = j;
    }
  read(sx);
  read(sy);
  sort(blk + 1, blk + s + 1, [&](node &x, node &y) { return x.w < y.w; });
  inv[1] = 1;
  for (int i = 2; i <= s; ++i) inv[i] = (-M / i * inv[M % i] % M) % M;
  int l;
  for (l = 1; blk[l + 1].w == blk[l].w; ++l) {
    Sx[l] = (Sx[l - 1] + blk[l].x) % M;
    Sy[l] = (Sy[l - 1] + blk[l].y) % M;
    Sfp2[l] =
        (Sfp2[l - 1] + blk[l].x * blk[l].x % M + blk[l].y * blk[l].y % M) % M;
  }
  Sx[l] = (Sx[l - 1] + blk[l].x) % M;
  Sy[l] = (Sy[l - 1] + blk[l].y) % M;
  Sfp2[l] = Sfp2[l - 1] + blk[l].x * blk[l].x + blk[l].y * blk[l].y;
  for (int i = 1; i <= l; ++i)
    if (sx == blk[i].x && sy == blk[i].y) {
      printf("0\n");
      return 0;
    }
  for (int i = l + 1; i <= s; ++i) {
    while (blk[l + 1].w != blk[i].w) ++l;
    long long p2 = (blk[i].x * blk[i].x % M + blk[i].y * blk[i].y % M) % M;
    f[i] =
        (inv[l] *
             (Sfp2[l] - 2 * (Sx[l] * blk[i].x % M + Sy[l] * blk[i].y % M)) % M +
         p2) %
        M;
    if (blk[i].x == sx && blk[i].y == sy) {
      printf("%lld\n", (f[i] % M + M) % M);
      break;
    }
    Sfp2[i] = (Sfp2[i - 1] + p2 + f[i]) % M;
    Sx[i] = (Sx[i - 1] + blk[i].x) % M;
    Sy[i] = (Sy[i - 1] + blk[i].y) % M;
  }
  return 0;
}
