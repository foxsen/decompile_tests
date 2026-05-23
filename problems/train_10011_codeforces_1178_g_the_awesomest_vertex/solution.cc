#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
using namespace std;
const int MN = 1000005, inf = 1000000005, mod = 1000000007;
const long long INF = 1000000000000000005LL;
const int __BS = 4096;
static char __bur[__BS + 16], *__er = __bur + __BS, *__ir = __er;
template <class T = int>
T readInt() {
  auto c = [&]() {
    if (__ir == __er)
      std::fill(__bur, __bur + __BS, 0), cin.read(__bur, __BS), __ir = __bur;
  };
  c();
  while (*__ir && (*__ir < '0' || *__ir > '9') && *__ir != '-') ++__ir;
  c();
  bool m = false;
  if (*__ir == '-') ++__ir, c(), m = true;
  T r = 0;
  while (*__ir >= '0' && *__ir <= '9') r = r * 10 + *__ir - '0', ++__ir, c();
  ++__ir;
  return m ? -r : r;
}
string readString() {
  auto c = [&]() {
    if (__ir == __er)
      std::fill(__bur, __bur + __BS, 0), cin.read(__bur, __BS), __ir = __bur;
  };
  string r;
  c();
  while (*__ir && isspace(*__ir)) ++__ir, c();
  while (!isspace(*__ir)) r.push_back(*__ir), ++__ir, c();
  ++__ir;
  return r;
}
char readChar() {
  auto c = [&]() {
    if (__ir == __er)
      std::fill(__bur, __bur + __BS, 0), cin.read(__bur, __BS), __ir = __bur;
  };
  c();
  while (*__ir && isspace(*__ir)) ++__ir, c();
  return *__ir++;
}
static char __buw[__BS + 20], *__iw = __buw, *__ew = __buw + __BS;
template <class T>
void writeInt(T x, char endc = '\n') {
  if (x < 0) *__iw++ = '-', x = -x;
  if (x == 0) *__iw++ = '0';
  char *s = __iw;
  while (x) {
    T t = x / 10;
    char c = x - 10 * t + '0';
    *__iw++ = c;
    x = t;
  }
  char *f = __iw - 1;
  while (s < f) swap(*s, *f), ++s, --f;
  if (__iw > __ew) cout.write(__buw, __iw - __buw), __iw = __buw;
  if (endc) {
    *__iw++ = endc;
  }
}
template <class T>
void writeStr(const T &str) {
  int i = 0;
  while (str[i]) {
    *__iw++ = str[i++];
    if (__iw > __ew) cout.write(__buw, __iw - __buw), __iw = __buw;
  }
}
struct __FL__ {
  ~__FL__() {
    if (__iw != __buw) cout.write(__buw, __iw - __buw);
  }
};
static __FL__ __flushVar__;
inline int mo(int &a) { return (a > 0 ? a : -a); }
int pocz[MN], kon[MN], A[MN], B[MN], sa[MN], sb[MN];
vector<int> G[MN];
int czas;
void dfs(int x, int a, int b) {
  pocz[x] = ++czas;
  kon[x] = pocz[x];
  a += A[x];
  b += B[x];
  sa[pocz[x]] = a, sb[pocz[x]] = b;
  for (auto v : G[x])
    if (!pocz[v]) {
      dfs(v, a, b);
      kon[x] = kon[v];
    }
}
void add(int *t, int n, int x) {
  for (int i = 0; i < n; ++i) t[i] += x;
}
long long ask(int *t, int *u, int n) {
  long long ans1 = 0LL, ans2 = 0LL;
  for (int i = 0; i < n; ++i) {
    long long r = t[i] * 1LL * u[i];
    ans1 = ans1 < r ? r : ans1;
    ans2 = ans2 > r ? r : ans2;
  }
  return max(ans1, -ans2);
}
int main() {
  int n, q;
  n = readInt();
  q = readInt();
  for (int i = 2; i <= n; ++i) {
    int p;
    p = readInt();
    G[p].push_back(i);
  }
  for (int i = 1; i <= n; ++i) A[i] = readInt();
  for (int i = 1; i <= n; ++i) B[i] = readInt();
  dfs(1, 0, 0);
  while (q--) {
    int typ, v, x, a, b;
    typ = readInt();
    if (typ == 1) {
      v = readInt();
      x = readInt();
      a = pocz[v], b = kon[v];
      add(sa + a, b - a + 1, x);
    } else {
      v = readInt();
      a = pocz[v], b = kon[v];
      long long ans = ask(sa + a, sb + a, b - a + 1);
      writeInt(ans);
    }
  }
}
