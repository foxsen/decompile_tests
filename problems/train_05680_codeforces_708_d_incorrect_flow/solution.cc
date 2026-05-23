#include <bits/stdc++.h>
using namespace std;
namespace io {
const int SI = 1 << 21 | 1;
char IB[SI], *IS, *IT, OB[SI], *OS = OB, *OT = OS + SI - 1, c, ch[100];
int f, t;
inline void flush() { fwrite(OB, 1, OS - OB, stdout), OS = OB; }
inline void pc(char x) {
  *OS++ = x;
  if (OS == OT) flush();
}
template <class I>
inline void rd(I &x) {
  for (f = 1, c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                              IS == IT ? EOF : *IS++)
                            : *IS++);
       c < '0' || c > '9';
       c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                       IS == IT ? EOF : *IS++)
                     : *IS++))
    if (c == '-') f = -1;
  for (x = 0; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + (c & 15),
      c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                      IS == IT ? EOF : *IS++)
                    : *IS++))
    ;
  x *= f;
}
template <class I>
inline void rda(I *a, int &n) {
  for (int i = 1; i <= n; i++) rd(a[i]);
}
inline void rds(char *s, int &x) {
  for (c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                       IS == IT ? EOF : *IS++)
                     : *IS++);
       c < 33 || c > 126;
       c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                       IS == IT ? EOF : *IS++)
                     : *IS++))
    ;
  for (x = 0; c >= 33 && c <= 126;
       s[++x] = c, c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                                   IS == IT ? EOF : *IS++)
                                 : *IS++))
    ;
  s[x + 1] = '\0';
}
template <class I>
inline void print(I x, char k = '\n') {
  if (!x) pc('0');
  if (x < 0) pc('-'), x = -x;
  while (x) ch[++t] = x % 10 + '0', x /= 10;
  while (t) pc(ch[t--]);
  pc(k);
}
inline void prints(string s) {
  int x = s.length();
  while (t < x) pc(s[t++]);
  pc('\n'), t = 0;
}
struct Flush {
  ~Flush() { flush(); }
} flusher;
}  // namespace io
using io::print;
using io::prints;
using io::rd;
using io::rda;
using io::rds;
namespace EK {
const int N = 1e4 + 7, M = 1e5 + 7;
const long long inf = 1e18;
int n, S, T, h[N], e[M], t[M], tot, pre[N], v[N];
long long mxf, ans, f[M], c[M], d[N], now[N];
inline void add(int x, int y, long long z, long long w, int o = 1) {
  e[++tot] = y, f[tot] = z, c[tot] = w, t[tot] = h[x], h[x] = tot;
  if (o) add(y, x, 0, -w, 0);
}
inline bool spfa() {
  for (int i = 1; i <= n; i++) v[i] = 0, d[i] = inf;
  queue<int> q;
  q.push(S), v[S] = 1, d[S] = 0, now[S] = inf;
  while (q.size()) {
    int x = q.front();
    q.pop(), v[x] = 0;
    for (int i = h[x]; i; i = t[i]) {
      int y = e[i];
      long long z = f[i], w = c[i];
      if (!z || d[y] <= d[x] + w) continue;
      d[y] = d[x] + w, now[y] = min(now[x], z), pre[y] = i;
      if (!v[y]) q.push(y), v[y] = 1;
    }
  }
  return d[T] != inf;
}
inline void upd() {
  mxf += now[T], ans += d[T] * now[T];
  int x = T;
  while (x != S)
    f[pre[x]] -= now[T], f[pre[x] ^ 1] += now[T], x = e[pre[x] ^ 1];
}
inline void main() {
  while (spfa()) upd();
}
inline void init(int _n, int _S, int _T) {
  n = _n, S = _S, T = _T, tot = 1, mxf = ans = 0;
  for (int i = 1; i <= n; i++) h[i] = 0;
}
}  // namespace EK
namespace no_min_cost_flow {
const int N = 1e5 + 7;
int n, S, T;
long long d[N], s;
inline void add(int x, int y, long long l, long long r, long long w) {
  EK::add(x, y, r - l, w), d[y] += l, d[x] -= l;
}
inline bool main() {
  for (int i = 1; i <= n; i++)
    if (d[i] > 0)
      EK::add(S, i, d[i], 0), s += d[i];
    else if (d[i] < 0)
      EK::add(i, T, -d[i], 0);
  EK::main();
  return EK::mxf == s;
}
inline void init(int _n) {
  n = _n, s = 0, S = n + 1, T = n + 2;
  EK::init(n + 2, S, T);
  for (int i = 1; i <= n; i++) d[i] = 0;
}
}  // namespace no_min_cost_flow
const long long inf = 1e18;
long long ans;
int main() {
  int n, m, S, T;
  rd(n), rd(m), S = 1, T = n;
  no_min_cost_flow::init(n);
  no_min_cost_flow::add(T, S, 0, inf, 0);
  for (int i = 1, u, v, c, f; i <= m; i++) {
    rd(u), rd(v), rd(c), rd(f);
    no_min_cost_flow::add(u, v, f, f, 0);
    if (c >= f) {
      no_min_cost_flow::add(v, u, 0, f, 1);
      no_min_cost_flow::add(u, v, 0, c - f, 1);
      no_min_cost_flow::add(u, v, 0, inf, 2);
    } else {
      ans += f - c;
      no_min_cost_flow::add(v, u, 0, c, 1);
      no_min_cost_flow::add(v, u, 0, f - c, 0);
      no_min_cost_flow::add(u, v, 0, inf, 2);
    }
  }
  no_min_cost_flow::main();
  print(EK::ans + ans);
  return 0;
}
