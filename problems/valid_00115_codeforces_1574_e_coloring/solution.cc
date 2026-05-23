#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + ch - '0', ch = getchar();
  return s * f;
}
const int N = 1e6 + 5, mod = 998244353, inv2 = (mod + 1) >> 1;
inline void Add(int &a, int b) { a += (a + b >= mod) ? b - mod : b; }
inline int dec(int a, int b) { return (a - b < 0) ? a - b + mod : a - b; }
inline int add(int a, int b) { return (a + b >= mod) ? a + b - mod : a + b; }
inline int quick_pow(int a, int b) {
  int ret = 1;
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) ret = 1ll * ret * a % mod;
  return ret;
}
int col[3], coltp[N][2], row[3], rowtp[N][2], n, m, k, s[2];
inline int calc() {
  int ret =
      add(col[0] ? 0 : quick_pow(2, col[2]), row[0] ? 0 : quick_pow(2, row[2]));
  if (!s[0]) ret = dec(ret, 1);
  if (!s[1]) ret = dec(ret, 1);
  return ret;
}
inline void work(int x, int y, int val) {
  if (!coltp[y][0] && !coltp[y][1])
    col[2] += val;
  else if (coltp[y][0] && coltp[y][1])
    col[0] += val;
  else
    col[1] += val;
  if (!rowtp[x][0] && !rowtp[x][1])
    row[2] += val;
  else if (rowtp[x][0] && rowtp[x][1])
    row[0] += val;
  else
    row[1] += val;
}
inline void ADD(int x, int y, int v) {
  work(x, y, -1);
  int a = x & 1, b = y & 1;
  ++s[a ^ b ^ v];
  ++coltp[y][a ^ v];
  ++rowtp[x][b ^ v];
  work(x, y, 1);
}
inline void DEC(int x, int y, int v) {
  work(x, y, -1);
  int a = x & 1, b = y & 1;
  --s[a ^ b ^ v];
  --coltp[y][a ^ v];
  --rowtp[x][b ^ v];
  work(x, y, 1);
}
map<pair<int, int>, int> g;
int main() {
  n = read();
  m = read();
  k = read();
  col[2] = m;
  row[2] = n;
  int x, y, opt;
  while (k--) {
    x = read();
    y = read();
    opt = read();
    if (g.count(make_pair(x, y))) {
      int u = g[make_pair(x, y)];
      if (u) {
        DEC(x, y, u - 1);
      }
      if (opt == -1) {
        g[make_pair(x, y)] = 0;
      }
    }
    if (opt == 0) {
      g[make_pair(x, y)] = 1;
      ADD(x, y, 0);
    } else if (opt == 1) {
      g[make_pair(x, y)] = 2;
      ADD(x, y, 1);
    }
    printf("%d\n", calc());
  }
  return 0;
}
