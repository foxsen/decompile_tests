#include <bits/stdc++.h>
using namespace std;
int get() {
  char ch;
  while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-')
    ;
  if (ch == '-') {
    int s = 0;
    while (ch = getchar(), ch >= '0' && ch <= '9') s = s * 10 + ch - '0';
    return -s;
  }
  int s = ch - '0';
  while (ch = getchar(), ch >= '0' && ch <= '9') s = s * 10 + ch - '0';
  return s;
}
const int N = 1e5 + 5;
const int mo = 998244353;
long long add(long long x, long long y) {
  return x + y >= mo ? x + y - mo : x + y;
}
long long dec(long long x, long long y) { return x < y ? x - y + mo : x - y; }
long long quickmi(long long x, long long tim) {
  long long ret = 1;
  for (; tim; tim /= 2, x = x * x % mo)
    if (tim & 1) ret = ret * x % mo;
  return ret;
}
long long inv[N * 2], js[N * 2];
void prepare() {
  js[0] = js[1] = 1;
  for (int i = 2; i <= 2e5; i++) js[i] = js[i - 1] * i % mo;
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= 2e5; i++)
    inv[i] = 1ll * (mo - mo / i) * inv[mo % i] % mo;
}
int n, m, q;
int a[N];
struct Query {
  int l, r, k;
  int id;
} qry[N];
long long ans[N];
map<int, int> id;
int v[105];
int k;
long long val[105][N];
int blk;
int be[N];
long long nv[105];
int cnt[N];
int all[N];
bool cmp(Query a, Query b) {
  return be[a.l] != be[b.l] ? be[a.l] < be[b.l] : a.r < b.r;
}
void add(int i, int c) {
  cnt[c]++;
  nv[i] = nv[i] * (v[i] + all[c] - cnt[c] + 1) % mo;
}
void del(int i, int c) {
  nv[i] = nv[i] * inv[v[i] + all[c] - cnt[c] + 1] % mo;
  cnt[c]--;
}
void add(int c) {
  cnt[c]++;
  for (int i = 1; i <= k; i++)
    nv[i] = nv[i] * (v[i] + all[c] - cnt[c] + 1) % mo;
}
int main() {
  prepare();
  n = get();
  m = get();
  q = get();
  for (int i = 1; i <= n; i++) {
    a[i] = get();
    all[a[i]]++;
  }
  for (int i = 1; i <= q; i++) {
    qry[i].l = get(), qry[i].r = get(), qry[i].k = get();
    qry[i].id = i;
    if (!id[qry[i].k]) {
      id[qry[i].k] = ++k;
      v[k] = qry[i].k;
    }
  }
  for (int i = 1; i <= k; i++) {
    long long now = v[i];
    val[i][0] = 1;
    for (int x = 1; x <= n; x++)
      val[i][x] = val[i][x - 1] * (now * m % mo + x) % mo;
  }
  blk = sqrt(1.0 * n * n * k / q) + 1;
  for (int i = 1; i <= n; i++) be[i] = (i - 1) / blk + 1;
  sort(qry + 1, qry + 1 + q, cmp);
  int w = 1;
  for (int L = 1; L <= n; L += blk) {
    for (int i = 1; i <= m; i++) cnt[i] = 0;
    for (int i = 1; i <= k; i++) nv[i] = 1;
    while (w <= q && be[qry[w].l] == be[L] && be[qry[w].r] == be[L]) {
      int tk = id[qry[w].k];
      for (int i = qry[w].l; i <= qry[w].r; i++) add(tk, a[i]);
      ans[qry[w].id] = nv[tk] * val[tk][n - (qry[w].r - qry[w].l + 1)] % mo;
      for (int i = qry[w].l; i <= qry[w].r; i++) del(tk, a[i]);
      w++;
    }
    for (int R = L + blk; R <= n; R++) {
      add(a[R]);
      while (w <= q && be[qry[w].l] == be[L] && qry[w].r == R) {
        int tk = id[qry[w].k];
        for (int i = L + blk - 1; i >= qry[w].l; i--) add(tk, a[i]);
        ans[qry[w].id] = nv[tk] * val[tk][n - (qry[w].r - qry[w].l + 1)] % mo;
        for (int i = qry[w].l; i <= L + blk - 1; i++) del(tk, a[i]);
        w++;
      }
    }
  }
  for (int i = 1; i <= q; i++) printf("%I64d\n", ans[i]);
  return 0;
}
