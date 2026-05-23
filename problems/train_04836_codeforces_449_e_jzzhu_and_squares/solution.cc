#include <bits/stdc++.h>
const int max = 1E6;
using AI = int[max + 1];
int F[max + 2];
bool S[max + 1];
AI P, G, H;
const int mod = 1E9 + 7;
inline void reduce(int& x) { x += x >> 31 & mod; }
inline void add(int& x, int y) { reduce(x += y - mod); }
inline int mul(int a, int b) { return static_cast<long long>(a) * b % mod; }
namespace IO {
const int in_len = 2E6, out_len = 2E6;
char pool[in_len], *in = pool - 1;
class istream {
 public:
  inline istream() { std::cin.rdbuf()->sgetn(pool, in_len); }
  inline istream& operator>>(int& RHS) {
    RHS = 0;
    while (std::isspace(*++in))
      ;
    do RHS = 10 * RHS + (*in ^ 48);
    while (std::isdigit(*++in));
    return *this;
  }
} cin;
char pool_[out_len], *out = pool_ - 1;
class ostream {
 public:
  inline ostream& operator<<(int RHS) {
    static char pool[10], *buf = pool;
    do *buf++ = RHS % 10 | 48;
    while (RHS /= 10);
    while (buf > pool) *++out = *--buf;
    return *this;
  }
  inline void operator<<(char RHS) { *++out = 10; }
  inline ~ostream() { std::cout.rdbuf()->sputn(pool_, out - pool_ + 1); }
} cout;
}  // namespace IO
int main() {
  F[1] = 1;
  for (int *PE = P, i = 2; i <= max; ++i) {
    if (!S[i]) *PE++ = i, G[i] = 1, H[i] = i, F[i] = (i << 1) - 1;
    for (int k, *j = P; (k = *j * i) <= max; ++j) {
      S[k] = 1;
      if (!(i % *j)) {
        G[k] = G[i] + 1;
        if (i == H[i])
          H[k] = k, F[k] = k + G[k] * (k - i);
        else
          H[k] = H[i] * *j, F[k] = F[k / H[k]] * F[H[k]];
        break;
      }
      G[k] = 1, H[k] = *j, F[k] = ((*j << 1) - 1) * F[i];
    }
  }
  for (int *F = ::F + 1, __ = -1, _ = -1, i = 1; i <= max;
       ++i, ++F, add(__, i - 2 << 2), add(_, __)) {
    reduce(*F = (*F << 1) - mod), add(*F, _), G[i] = mul(*F, i),
                                              H[i] = mul(G[i], i);
    add(*F, ::F[i - 1]), add(G[i], G[i - 1]), add(H[i], H[i - 1]);
  }
  int t;
  for (IO::cin >> t; t--;) {
    int n, m;
    IO::cin >> n >> m;
    int _ = std::min(n, m), res = H[_];
    ++n, ++m, reduce(res -= mul(n + m, G[_])), add(res, mul(mul(n, m), F[_]));
    IO::cout << res << '\n';
  }
}
