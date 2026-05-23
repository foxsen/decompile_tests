#include <bits/stdc++.h>
using namespace std;
using LL = long long;
namespace _buff {
const size_t BUFF = 1 << 19;
char ibuf[BUFF], *ib = ibuf, *ie = ibuf;
char getc() {
  if (ib == ie) {
    ib = ibuf;
    ie = ibuf + fread(ibuf, 1, BUFF, stdin);
  }
  return ib == ie ? -1 : *ib++;
}
}  // namespace _buff
LL read() {
  using namespace _buff;
  LL ret = 0;
  bool pos = true;
  char c = getc();
  for (; (c < '0' || c > '9') && c != '-'; c = getc()) {
    assert(~c);
  }
  if (c == '-') {
    pos = false;
    c = getc();
  }
  for (; c >= '0' && c <= '9'; c = getc()) {
    ret = (ret << 3) + (ret << 1) + (c ^ 48);
  }
  return pos ? ret : -ret;
}
const int MOD = 998244353;
using uint = unsigned;
struct Z {
  uint v;
  Z(uint v = 0) : v(v) {}
  Z &operator+=(const Z &z) {
    v += z.v;
    if (v >= MOD) v -= MOD;
    return *this;
  }
  Z &operator-=(const Z &z) {
    if (v < z.v) v += MOD;
    v -= z.v;
    return *this;
  }
  Z &operator*=(const Z &z) {
    v = static_cast<uint64_t>(v) * z.v % MOD;
    return *this;
  }
};
ostream &operator<<(ostream &os, const Z &z) { return os << z.v; }
Z operator+(const Z &x, const Z &y) {
  return Z(x.v + y.v >= MOD ? x.v + y.v - MOD : x.v + y.v);
}
Z operator-(const Z &x, const Z &y) {
  return Z(x.v < y.v ? x.v + MOD - y.v : x.v - y.v);
}
Z operator*(const Z &x, const Z &y) {
  return Z(static_cast<uint64_t>(x.v) * y.v % MOD);
}
Z qpow(Z base, uint e) {
  Z ret(1);
  for (; e; e >>= 1) {
    if (e & 1) {
      ret *= base;
    }
    base *= base;
  }
  return ret;
}
const size_t L = 60;
using ull = uint64_t;
uint m;
struct LB {
  ull b[L];
  LB() { memset(b, 0, sizeof b); }
  void add(ull x) {
    for (uint i = m; i--;) {
      if (x >> i & 1) {
        if (b[i]) {
          x ^= b[i];
        } else {
          b[i] = x;
          for (uint j = i; j--;) {
            if (b[i] >> j & 1) b[i] ^= b[j];
          }
          for (uint j = i + 1; j < m; ++j) {
            if (b[j] >> i & 1) b[j] ^= b[i];
          }
          return;
        }
      }
    }
  }
};
ull b[L];
uint cnt;
int f[L];
void get_b(const LB &lb) {
  cnt = 0;
  for (uint i = 0; i < m; ++i) {
    if (lb.b[i]) {
      b[cnt++] = lb.b[i];
    }
  }
}
void dfs(ull cur = 0, uint i = 0) {
  if (i == cnt) {
    ++f[__builtin_popcountll(cur)];
    return;
  }
  dfs(cur, i + 1);
  dfs(cur ^ b[i], i + 1);
}
Z comb[L][L];
void prep_comb() {
  for (uint i = 0; i < L; ++i) {
    comb[i][0] = 1;
    for (uint j = 1; j <= i; ++j) {
      comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
    }
  }
}
int main() {
  int n = read();
  m = read();
  LB b;
  for (int i = 0; i < n; ++i) {
    b.add(read());
  }
  get_b(b);
  assert(cnt <= n);
  Z mul = qpow(2, n - cnt);
  if ((cnt << 1) <= m) {
    dfs();
    for (uint i = 0; i <= m; ++i) {
      cout << f[i] * mul << ' ';
    }
  } else {
    cnt = 0;
    for (uint i = 0; i < m; ++i) {
      ull cur = 1ull << i;
      for (uint j = 0; j < m; ++j) {
        cur ^= (b.b[j] >> i & 1) << j;
      }
      if (cur) {
        ::b[cnt++] = cur;
      }
    }
    dfs();
    mul *= qpow(2, MOD - 1 - cnt);
    prep_comb();
    for (uint i = 0; i <= m; ++i) {
      Z ans = 0;
      for (uint j = 0; j <= m; ++j) {
        for (uint k = 0; k <= i && k <= j; ++k) {
          Z cur = f[j] * comb[j][k] * comb[m - j][i - k];
          if (k & 1)
            ans -= cur;
          else
            ans += cur;
        }
      }
      cout << ans * mul << ' ';
    }
  }
  return 0;
}
