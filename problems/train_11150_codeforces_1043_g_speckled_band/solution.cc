#include <bits/stdc++.h>
using std::max;
using std::min;
using std::reverse;
using std::swap;
const int INF = 1e9;
const int N = 200010;
const int C = 26;
int n, sqrtn;
char str[N];
int csum[N][C];
namespace SA {
int n;
int reala[N], realb[N], *a = reala, *b = realb;
int sa[N], rk[N], h[N];
int c[N], m;
int st[19][N];
void Sort() {
  for (int i = 1; i <= m; i++) c[i] = 0;
  for (int i = 1; i <= n; i++) c[a[b[i]]]++;
  for (int i = 2; i <= m; i++) c[i] += c[i - 1];
  for (int i = n; i >= 1; i--) sa[c[a[b[i]]]--] = b[i];
}
void Calc(int _n, char *str) {
  n = _n;
  m = 0;
  for (int i = 1; i <= n; i++) {
    a[i] = str[i] - 'a' + 1;
    b[i] = i;
    m = max(m, a[i]);
  }
  Sort();
  int all = -1;
  for (int l = 1; all < n; l <<= 1) {
    all = 0;
    for (int i = n - l + 1; i <= n; i++) b[++all] = i;
    for (int i = 1; i <= n; i++)
      if (sa[i] > l) b[++all] = sa[i] - l;
    Sort();
    swap(a, b);
    a[sa[1]] = all = 1;
    for (int i = 2; i <= n; i++) {
      if (!(b[sa[i]] == b[sa[i - 1]] && b[sa[i] + l] == b[sa[i - 1] + l]))
        all++;
      a[sa[i]] = all;
    }
    m = all;
  }
  for (int i = 1; i <= n; i++) rk[i] = a[i];
  for (int i = 1, j = 0; i <= n; i++) {
    if (j) j--;
    while (str[i + j] == str[sa[rk[i] - 1] + j]) j++;
    h[rk[i]] = j;
  }
  for (int i = 1; i < n; i++) st[0][i] = h[i + 1];
  for (int j = 1; j <= 18; j++)
    for (int i = 1; i < n; i++) {
      st[j][i] = st[j - 1][i];
      if (i + (1 << (j - 1)) < n)
        st[j][i] = min(st[j][i], st[j - 1][i + (1 << (j - 1))]);
    }
}
int GetLCP(int a, int b) {
  if (a == b) return -1;
  a = rk[a];
  b = rk[b];
  if (a > b) swap(a, b);
  b--;
  int j = (int)log2(b - a + 1);
  return min(st[j][a], st[j][b - (1 << j) + 1]);
}
bool Same(int a, int b, int len) { return GetLCP(a, b) >= len; }
bool Query(int l, int r) {
  int lcp;
  int x = rk[l];
  lcp = h[x];
  for (int i = x - 1; i >= 1 && x - i + 1 <= sqrtn; lcp = min(lcp, h[i]), i--)
    if ((l < sa[i] && sa[i] <= r) && sa[i] + lcp - 1 >= r) return true;
  lcp = h[x + 1];
  for (int i = x + 1; i <= n && i - x + 1 <= sqrtn; i++, lcp = min(lcp, h[i]))
    if ((l < sa[i] && sa[i] <= r) && sa[i] + lcp - 1 >= r) return true;
  return false;
}
}  // namespace SA
namespace HASH {
const unsigned long long BAS = 133333;
unsigned long long bas[N];
unsigned long long h[N];
void Calc(int n, char *str) {
  bas[0] = 1;
  for (int i = 1; i <= n; i++) bas[i] = bas[i - 1] * BAS;
  for (int i = 1; i <= n; i++) h[i] = h[i - 1] + bas[i] * (str[i] - 'a' + 1);
}
bool Same(int x, int y, int len) {
  if (x > y) swap(x, y);
  return (h[x + len - 1] - h[x - 1]) * bas[y - x] ==
         (h[y + len - 1] - h[y - 1]);
}
}  // namespace HASH
namespace MATH {
bool vis[N];
int p[N], pcnt;
int minp[N];
void Sieve(int n) {
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) {
      p[++pcnt] = i;
      minp[i] = i;
    }
    for (int j = 1; j <= pcnt && i * p[j] <= n; j++) {
      vis[i * p[j]] = true;
      minp[i * p[j]] = p[j];
      if (i % p[j] == 0) break;
    }
  }
}
void GetP(int x, int *a, int &acnt) {
  acnt = 0;
  while (x != 1) {
    int curp = minp[x];
    a[++acnt] = curp;
    while (x % curp == 0) x /= curp;
  }
}
}  // namespace MATH
namespace DIV {
struct Seg {
  int rt, sz;
  int ch[N * 2][2];
  int tag[N * 2];
  void Reset() { rt = sz = 0; }
  inline void MakeTag(int u, int x) { tag[u] = min(tag[u], x); }
  void Build(int &u, int l, int r) {
    u = ++sz;
    tag[u] = INF;
    if (l == r) return;
    int mid = (l + r) >> 1;
    Build(ch[u][0], l, mid);
    Build(ch[u][1], mid + 1, r);
  }
  void SegMin(int u, int l, int r, int ml, int mr, int x) {
    if (ml > mr) return;
    if (ml <= l && r <= mr) {
      MakeTag(u, x);
      return;
    }
    int mid = (l + r) >> 1;
    if (mr <= mid)
      SegMin(ch[u][0], l, mid, ml, mr, x);
    else if (mid < ml)
      SegMin(ch[u][1], mid + 1, r, ml, mr, x);
    else {
      SegMin(ch[u][0], l, mid, ml, mid, x);
      SegMin(ch[u][1], mid + 1, r, mid + 1, mr, x);
    }
  }
  void Extract(int u, int l, int r, int *arr, int tagSum = INF) {
    tagSum = min(tagSum, tag[u]);
    if (l == r) {
      arr[l] = tagSum;
      return;
    }
    int mid = (l + r) >> 1;
    Extract(ch[u][0], l, mid, arr, tagSum);
    Extract(ch[u][1], mid + 1, r, arr, tagSum);
  }
} sl, sr;
int f[2][N];
int st[2][19][N];
void GetNext(int n, char *str, int *nex) {
  int i = 0, j, p;
  nex[0] = n;
  while (i < n - 1 && str[i] == str[i + 1]) i++;
  nex[1] = i;
  p = 1;
  for (int i = 2; i < n; i++)
    if (nex[i - p] + i < nex[p] + p)
      nex[i] = nex[i - p];
    else {
      j = max(0, p + nex[p] - i);
      while (i + j < n && str[j] == str[i + j]) j++;
      nex[i] = j;
      p = i;
    }
}
void GetExt(int n, char *s, int m, char *t, int *nex, int *ext) {
  int i = 0, j, p;
  while (i < n && i < m && s[i] == t[i]) i++;
  ext[0] = i;
  p = 0;
  for (int i = 1; i < n; i++)
    if (nex[i - p] + i < ext[p] + p)
      ext[i] = nex[i - p];
    else {
      j = max(0, p + ext[p] - i);
      while (i + j < n && j < m && s[i + j] == t[j]) j++;
      ext[i] = j;
      p = i;
    }
}
void Proceed(int l, int mid, int r, int *lp, int *ls) {
  int lenl = mid - l + 1, lenr = r - mid;
  static int nex[N];
  GetNext(lenr, str + mid + 1, lp + 1);
  lp[lenr + 1] = 0;
  reverse(str + l, str + mid + 1);
  reverse(str + mid + 1, str + r + 1);
  GetNext(lenl, str + l, nex);
  GetExt(lenr, str + mid + 1, lenl, str + l, nex, ls + 1);
  reverse(ls + 1, ls + 1 + lenr);
  reverse(str + l, str + mid + 1);
  reverse(str + mid + 1, str + r + 1);
}
void Divide(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  Divide(l, mid);
  Divide(mid + 1, r);
  static int lp[N], ls[N];
  Proceed(l, mid, r, lp, ls);
  for (int x = 1; x <= r - mid; x++) {
    int tl = mid + max(1, 2 * x - ls[x]),
        tr = mid + min(r - mid, min(2 * x - 1, x + lp[x + 1]));
    sl.SegMin(sl.rt, 1, n, tl, tr, 2 * x);
    sr.SegMin(sr.rt, 1, n, tl - 2 * x + 1, tr - 2 * x + 1, 2 * x);
  }
  reverse(str + l, str + r + 1);
  mid = l + (r - mid) - 1;
  Proceed(l, mid, r, lp, ls);
  for (int x = 1; x <= r - mid; x++) {
    int tl = mid + max(1, 2 * x - ls[x]),
        tr = mid + min(r - mid, min(2 * x - 1, x + lp[x + 1]));
    tl = l + (r - tl);
    tr = l + (r - tr);
    sr.SegMin(sr.rt, 1, n, tr, tl, 2 * x);
    sl.SegMin(sr.rt, 1, n, tr + 2 * x - 1, tl + 2 * x - 1, 2 * x);
  }
  reverse(str + l, str + r + 1);
}
void InitST() {
  for (int i = 1; i <= n; i++) st[0][0][i] = f[0][i];
  for (int j = 1; j <= 18; j++)
    for (int i = 1; i <= n; i++) {
      st[0][j][i] = st[0][j - 1][i];
      if (i + (1 << (j - 1)) <= n)
        st[0][j][i] = max(st[0][j][i], st[0][j - 1][i + (1 << (j - 1))]);
    }
  for (int i = 1; i <= n; i++) st[1][0][i] = f[1][i];
  for (int j = 1; j <= 18; j++)
    for (int i = 1; i <= n; i++) {
      st[1][j][i] = st[1][j - 1][i];
      if (i + (1 << (j - 1)) <= n)
        st[1][j][i] = min(st[1][j][i], st[1][j - 1][i + (1 << (j - 1))]);
    }
}
int Query(int k, int l, int r) {
  int j = (int)log2(r - l + 1);
  if (!k)
    return max(st[0][j][l], st[0][j][r - (1 << j) + 1]);
  else
    return min(st[1][j][l], st[1][j][r - (1 << j) + 1]);
}
void Calc() {
  sl.Build(sl.rt, 1, n);
  sr.Build(sr.rt, 1, n);
  Divide(1, n);
  sl.Extract(sl.rt, 1, n, f[0]);
  sr.Extract(sr.rt, 1, n, f[1]);
  for (int i = 1; i <= n; i++) {
    f[0][i] = max(0, i - f[0][i] + 1);
    f[1][i] = min(n + 1, i + f[1][i] - 1);
  }
  InitST();
}
}  // namespace DIV
void ReadData() {
  scanf("%d", &n);
  sqrtn = ((int)sqrt(n)) + 1;
  scanf("%s", str + 1);
}
void InitStr() {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < C; j++) csum[i][j] = csum[i - 1][j];
    csum[i][str[i] - 'a']++;
  }
}
bool AllSingle(int l, int r) {
  if (r - l + 1 > 26) return false;
  bool exist = false;
  for (int j = 0; j < C; j++)
    if (csum[r][j] - csum[l - 1][j] >= 2) {
      exist = true;
      break;
    }
  return !exist;
}
bool Loop(int l, int r) {
  int len = r - l + 1;
  static int p[20], pcnt;
  MATH::GetP(len, p, pcnt);
  for (int i = 1; i <= pcnt; i++) {
    int orz = len / p[i];
    if (SA::Same(l, l + orz, len - orz)) return true;
  }
  return false;
}
bool ExistBorder(int l, int r) {
  int len = r - l + 1;
  for (int i = 1; i < len && i <= sqrtn; i++)
    if (SA::Same(l, r - i + 1, i)) return true;
  return SA::Query(l, r);
}
bool SideAdjTwo(int l, int r) { return DIV::f[1][l] <= r || l <= DIV::f[0][r]; }
bool AdjTwo(int l, int r) {
  return DIV::Query(0, l, r) >= l || DIV::Query(1, l, r) <= r;
}
bool TwoCha(int l, int r) {
  int lc = str[l] - 'a', rc = str[r] - 'a';
  return csum[r][lc] - csum[l - 1][lc] > 1 || csum[r][rc] - csum[l - 1][rc] > 1;
}
int Solve(int l, int r) {
  if (AllSingle(l, r)) return -1;
  if (Loop(l, r)) return 1;
  if (ExistBorder(l, r)) return 2;
  if (SideAdjTwo(l, r)) return 2;
  if (AdjTwo(l, r)) return 3;
  if (TwoCha(l, r)) return 3;
  return 4;
}
void AnswerQuery() {
  int q, l, r;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &l, &r);
    printf("%d\n", Solve(l, r));
  }
}
int main() {
  ReadData();
  InitStr();
  SA::Calc(n, str);
  HASH::Calc(n, str);
  MATH::Sieve(n);
  DIV::Calc();
  AnswerQuery();
  return 0;
}
