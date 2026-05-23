#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3fll;
char __wzp[1 << 15 | 1], *__S = __wzp + 32768;
inline int read() {
  register int x = 0, dp = 1;
  register char c =
      (__S >= __wzp + 32768
       ? (__wzp[fread(__wzp, sizeof(char), 1 << 15, stdin)] = EOF),
       *((__S = __wzp)++) : *(__S++));
  for (; !isdigit(c);
       c = (__S >= __wzp + 32768
            ? (__wzp[fread(__wzp, sizeof(char), 1 << 15, stdin)] = EOF),
            *((__S = __wzp)++) : *(__S++)))
    if (c == '-') dp = -1;
  for (; isdigit(c);
       c = (__S >= __wzp + 32768
            ? (__wzp[fread(__wzp, sizeof(char), 1 << 15, stdin)] = EOF),
            *((__S = __wzp)++) : *(__S++)))
    x = (x << 1) + (x << 3) + (c ^ 48);
  return x * dp;
}
void write(int x) {
  if (x < 0) x = -x, putchar('-');
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
void writeln(int x) {
  write(x);
  puts("");
}
const int maxn = 262144;
struct seg {
  int n, mx[maxn];
  int f[maxn];
  inline void modify(int x, int v) {
    for (mx[x += n] = v, x >>= 1; x; x >>= 1)
      mx[x] = mx[x << 1] < mx[x << 1 | 1] ? mx[x << 1 | 1] : mx[x << 1];
  }
  inline int query(int l, int r) {
    int ans = 0;
    for (l += n - 1, r += n + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
      if (~l & 1)
        if (mx[l ^ 1] > ans) ans = mx[l ^ 1];
      if (r & 1)
        if (mx[r ^ 1] > ans) ans = mx[r ^ 1];
    }
    return ans;
  }
  inline void ins(int x) { modify(x, f[x] = query(1, x - 1) + 1); }
  void build(int _n) {
    for (n = 1; n < _n + 2; n <<= 1)
      ;
  }
} T0, T1;
int h[maxn], pos[maxn];
int n, m;
set<int> s;
set<int>::iterator it;
int ans;
signed main() {
  n = read(), m = read();
  T0.build(m + 10), T1.build(n);
  for (register int i = (1); i <= int(m); ++i) {
    if (read() == 1) {
      int k = n + 1 - read();
      h[k] = i + 10 - read();
      pos[h[k]] = k;
      s.insert(k);
      for (register int j = (h[k]); j <= int(h[k] + 9); ++j)
        if (pos[j]) {
          T1.modify(pos[j], 0);
        }
      for (register int j = (h[k]); j <= int(h[k] + 9); ++j)
        if (pos[j]) {
          T1.ins(pos[j]);
          T0.f[j] = T1.f[pos[j]];
          T0.modify(j, T0.f[j]);
        }
    } else {
      int k = read();
      for (it = s.end(); k; k--) {
        it--;
        T0.modify(h[*it], 0);
      }
      T1.modify(*it, 0);
      pos[h[*it]] = 0;
      for (s.erase(it++); it != s.end(); it++) {
        T0.ins(h[*it]);
        T1.f[*it] = T0.f[h[*it]];
        T1.modify(*it, T1.f[*it]);
      }
    }
    writeln(T0.mx[1]);
  }
  return 0;
}
