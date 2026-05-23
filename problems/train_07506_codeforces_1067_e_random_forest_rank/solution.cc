#include <bits/stdc++.h>
using i64 = long long;
constexpr int maxn = 500000;
constexpr int p = 998244353;
template <class x_tp, class y_tp>
inline void inc(x_tp &x, const y_tp y) {
  x += y;
  (p <= x) && (x -= p);
}
template <class _Tp>
inline _Tp div2(const _Tp &v) {
  return ((v & 1) ? v + p : v) >> 1;
}
template <class _Tp>
inline int fpow(_Tp v, int n) {
  _Tp pw = 1;
  for (; n; n >>= 1, v = (i64)v * v % p)
    if (n & 1) pw = (i64)pw * v % p;
  return pw;
}
namespace IOManager {
constexpr int FILESZ = 131072;
char buf[FILESZ];
const char *ibuf = buf, *tbuf = buf;
struct IOManager {
  inline char gc() {
    return (ibuf == tbuf) &&
                   (tbuf = (ibuf = buf) + fread(buf, 1, FILESZ, stdin),
                    ibuf == tbuf)
               ? EOF
               : *ibuf++;
  }
  template <class _Tp>
  inline operator _Tp() {
    _Tp s = 0u;
    char c = gc();
    for (; c < 48; c = gc())
      ;
    for (; c > 47; c = gc()) s = (_Tp)(s * 10u + c - 48u);
    return s;
  }
};
}  // namespace IOManager
IOManager::IOManager io;
struct Edge {
  int v;
  Edge *las;
  inline Edge *init(const int to, Edge *const ls) {
    return v = to, las = ls, this;
  }
} * las[maxn + 1];
inline void lnk(const int u, const int v) {
  static Edge pool[maxn << 1], *alc = pool - 1;
  las[u] = (++alc)->init(v, las[u]);
  las[v] = (++alc)->init(u, las[v]);
}
i64 ans;
int calc(const int u, const int fa) {
  int val = 1;
  for (Edge *o = las[u]; o; o = o->las)
    if (o->v != fa) val = (i64)val * (1ll - div2(calc(o->v, u)) + p) % p;
  ans += 1 - val;
  return val;
}
int main() {
  const int n = io;
  for (int i = n - 1; i != 0; --i) lnk(io, io);
  calc(1, 0);
  printf("%lld", ((ans % p) + p) * fpow(2, n) % p);
  return 0;
}
