#include <bits/stdc++.h>
using namespace std;
char BB[1 << 16], *SB = BB, *TB = BB;
template <typename T>
void read(T &n) {
  T w = 1;
  n = 0;
  char ch =
      (SB == TB && (TB = (SB = BB) + fread(BB, 1, 1 << 15, stdin), SB == TB)
           ? EOF
           : *SB++);
  while (!isdigit(ch)) {
    if (ch == '-') w = -1;
    ch = (SB == TB && (TB = (SB = BB) + fread(BB, 1, 1 << 15, stdin), SB == TB)
              ? EOF
              : *SB++);
  }
  while (isdigit(ch)) {
    n = (n << 3) + (n << 1) + (ch & 15);
    ch = (SB == TB && (TB = (SB = BB) + fread(BB, 1, 1 << 15, stdin), SB == TB)
              ? EOF
              : *SB++);
  }
  n *= w;
}
template <typename T>
inline void exg(T &a, T &b) {
  a ^= b ^= a ^= b;
}
template <typename T>
inline void chkmn(T &a, const T &b) {
  (a > b) && (a = b);
}
template <typename T>
inline void chkmx(T &a, const T &b) {
  (a < b) && (a = b);
}
inline int min(const int &a, const int &b) { return a < b ? a : b; }
inline int max(const int &a, const int &b) { return a > b ? a : b; }
inline long long min(const long long &a, const long long &b) {
  return a < b ? a : b;
}
inline long long max(const long long &a, const long long &b) {
  return a > b ? a : b;
}
int MOD;
inline int adt(const int &a) { return (a % MOD + MOD) % MOD; }
inline int inc(const int &a, const int &b) {
  return a + b >= MOD ? a + b - MOD : a + b;
}
inline int dec(const int &a, const int &b) {
  return a - b < 0 ? a - b + MOD : a - b;
}
inline int mul(const int &a, const int &b) { return 1LL * a * b % MOD; }
inline int sqr(const int &a) { return 1LL * a * a % MOD; }
inline int cub(const int &a) { return 1LL * a * a % MOD * a % MOD; }
inline void Adt(int &a) { a = (a % MOD + MOD) % MOD; }
inline void Inc(int &a, const int &b) { ((a += b) >= MOD) && (a -= MOD); }
inline void Dec(int &a, const int &b) { ((a -= b) < 0) && (a += MOD); }
inline void Mul(int &a, const int &b) { a = 1LL * a * b % MOD; }
inline void Sqr(int &a) { a = 1LL * a * a % MOD; }
inline void Cub(int &a) { a = 1LL * a * a % MOD * a % MOD; }
inline int fsp(int a, int x = MOD - 2) {
  int res = 1;
  while (x) {
    if (x & 1) Mul(res, a);
    Sqr(a), x >>= 1;
  }
  return res;
}
const int maxn = 4e5 + 5;
int T, n, k, tot;
int pa[maxn], rk[maxn], mn[maxn], r[maxn];
vector<int> h[maxn], g[maxn];
map<int, int> pp;
struct bomb {
  int x, y, t;
} b[maxn];
inline bool Cmp_1(int x, int y) { return b[x].y < b[y].y; }
inline bool Cmp_2(int x, int y) { return b[x].x < b[y].x; }
inline int Find(int x) { return (pa[x] ^ x) ? pa[x] = Find(pa[x]) : x; }
inline bool Judge(int x, int y) { return Find(x) == Find(y); }
inline void Merge(int x, int y) {
  x = Find(x), y = Find(y);
  if (rk[x] > rk[y]) exg(x, y);
  pa[x] = y, chkmn(mn[y], mn[x]);
  if (rk[x] == rk[y]) ++rk[y];
}
int main() {
  read(T);
  while (T--) {
    read(n), read(k);
    tot = 0, pp.clear();
    for (int i = (1); i <= (n); ++i) {
      read(b[i].x), read(b[i].y), read(b[i].t), pa[i] = i, rk[i] = 0,
                                                mn[i] = b[i].t;
      if (!pp.count(b[i].x)) pp[b[i].x] = ++tot;
      if (!pp.count(b[i].y)) pp[b[i].y] = ++tot;
      h[pp[b[i].x]].emplace_back(i), g[pp[b[i].y]].emplace_back(i);
    }
    for (int i = (1); i <= (tot); ++i) {
      sort(h[i].begin(), h[i].end(), Cmp_1);
      sort(g[i].begin(), g[i].end(), Cmp_2);
      for (int j = (1); j <= ((int)h[i].size() - 1); ++j)
        if (b[h[i][j]].y - b[h[i][j - 1]].y <= k &&
            !Judge(h[i][j], h[i][j - 1]))
          Merge(h[i][j], h[i][j - 1]);
      for (int j = (1); j <= ((int)g[i].size() - 1); ++j)
        if (b[g[i][j]].x - b[g[i][j - 1]].x <= k &&
            !Judge(g[i][j], g[i][j - 1]))
          Merge(g[i][j], g[i][j - 1]);
      h[i].clear(), g[i].clear();
    }
    tot = 0;
    for (int i = (1); i <= (n); ++i)
      if (Find(i) == i) r[++tot] = mn[i];
    sort(r + 1, r + tot + 1);
    int L = 1, R = tot, t = 0;
    while (L <= R) {
      --R;
      while (L <= R && r[L] == t) ++L;
      if (L > R) printf("%d\n", t);
      ++t;
    }
  }
  return 0;
}
