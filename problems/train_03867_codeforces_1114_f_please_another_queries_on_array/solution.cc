#include <bits/stdc++.h>
using namespace std;
template <typename T>
void maxtt(T &t1, T t2) {
  t1 = max(t1, t2);
}
template <typename T>
void mintt(T &t1, T t2) {
  t1 = min(t1, t2);
}
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "URDL";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int &x, int y, int mod = 1000000007) {
  assert(y >= 0);
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et(int x = -1) {
  printf("%d\n", x);
  exit(0);
}
long long fastPow(long long x, long long y, int mod = 1000000007) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = (x * ans) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long gcd1(long long x, long long y) { return y ? gcd1(y, x % y) : x; }
vector<int> ps;
long long fp[303], invp[66];
bool isp(int x) {
  for (int i = 2; i < x; i++)
    if (x % i == 0) return 0;
  return 1;
}
void init() {
  for (int i = 2; i < 300; i++)
    if (isp(i)) ps.push_back(i);
  for (int i = 2; i <= 300; i++) {
    for (int(j) = 0; (j) < (int)(62); (j)++)
      if (i % ps[j] == 0) fp[i] |= 1LL << j;
  }
  for (int(j) = 0; (j) < (int)(62); (j)++) {
    invp[j] =
        (long long)(ps[j] - 1) * fastPow(ps[j], 1000000007 - 2) % 1000000007;
  }
}
struct nd {
  int ss;
  long long bs;
  nd() {
    ss = 1;
    bs = 0;
  }
  friend nd operator+(const nd &x, const nd &y) {
    nd res = nd();
    res.ss = (long long)x.ss * y.ss % 1000000007;
    res.bs = x.bs | y.bs;
    return res;
  }
} T[400135 << 2];
int lz[400135 << 2];
long long lzb[400135 << 2];
int a[400135];
void Up(int rt, int l, int r) { T[rt] = T[(rt << 1)] + T[(rt << 1 | 1)]; }
void Down(int rt, int l, int r) {
  if (l + 1 == r) return;
  int mid = (l + r) / 2;
  if (lz[rt] != 1) {
    T[(rt << 1)].ss =
        (long long)T[(rt << 1)].ss * fastPow(lz[rt], mid - l) % 1000000007;
    lz[(rt << 1)] = (long long)lz[(rt << 1)] * lz[rt] % 1000000007;
    T[(rt << 1 | 1)].ss =
        (long long)T[(rt << 1 | 1)].ss * fastPow(lz[rt], r - mid) % 1000000007;
    lz[(rt << 1 | 1)] = (long long)lz[(rt << 1 | 1)] * lz[rt] % 1000000007;
    lz[rt] = 1;
  }
  if (lzb[rt] != 0) {
    T[(rt << 1)].bs |= lzb[rt];
    lzb[(rt << 1)] |= lzb[rt];
    T[(rt << 1 | 1)].bs |= lzb[rt];
    lzb[(rt << 1 | 1)] |= lzb[rt];
    lzb[rt] = 0;
  }
}
void upt(int rt, int l, int r, int L, int R, int val) {
  if (R <= l || r <= L) return;
  if (L <= l && r <= R) {
    T[rt].ss = (long long)T[rt].ss * fastPow(val, r - l) % 1000000007;
    lz[rt] = (long long)lz[rt] * val % 1000000007;
    T[rt].bs |= fp[val];
    lzb[rt] |= fp[val];
    return;
  }
  Down(rt, l, r);
  int mid = (l + r) / 2;
  upt((rt << 1), l, mid, L, R, val);
  upt((rt << 1 | 1), mid, r, L, R, val);
  Up(rt, l, r);
}
nd qy(int rt, int l, int r, int L, int R) {
  if (L <= l && r <= R) {
    return T[rt];
  }
  Down(rt, l, r);
  int mid = (l + r) / 2;
  if (R <= mid)
    return qy((rt << 1), l, mid, L, R);
  else if (L >= mid)
    return qy((rt << 1 | 1), mid, r, L, R);
  else
    return qy((rt << 1), l, mid, L, mid) + qy((rt << 1 | 1), mid, r, mid, R);
}
void build(int rt, int l, int r) {
  if (l + 1 == r) {
    T[rt].ss = a[r];
    T[rt].bs = fp[a[r]];
    return;
  }
  int mid = (l + r) / 2;
  build((rt << 1), l, mid);
  build((rt << 1 | 1), mid, r);
  Up(rt, l, r);
}
void fmain(int tid) {
  scanf("%d%d", &n, &m);
  init();
  for (int(i) = 1; (i) <= (int)(n); (i)++) scanf("%d", a + i);
  for (int(i) = 0; (i) < (int)(400135 * 4); (i)++) lz[i] = 1;
  build(1, 0, n);
  char s[20];
  for (int(i) = 1; (i) <= (int)(m); (i)++) {
    int l, r, x;
    scanf("%s%d%d", s, &l, &r);
    if (s[0] == 'M') {
      scanf("%d", &x);
      upt(1, 0, n, l - 1, r, x);
    } else {
      nd z = qy(1, 0, n, l - 1, r);
      int ans = z.ss;
      for (int(j) = 0; (j) < (int)(62); (j)++)
        if (z.bs & (1LL << j)) {
          ans = (long long)ans * invp[j] % 1000000007;
        }
      printf("%d\n", ans);
    }
  }
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
