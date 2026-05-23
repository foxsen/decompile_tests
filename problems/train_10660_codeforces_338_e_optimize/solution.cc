#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807LL;
const int cinf = 1000000010;
const int maxn = 150010;
int tmin[maxn * 4];
int tcnt[maxn * 4];
int tadd[maxn * 4];
void push(int v, int L, int R) {
  tmin[v] += tadd[v];
  if (L != R) {
    tadd[v + v + 1] += tadd[v];
    tadd[v + v + 2] += tadd[v];
  }
  tadd[v] = 0;
}
void recalc(int v, int L, int R) {
  if (L == R) return;
  int m = (L + R) >> 1;
  push(v + v + 1, L, m);
  push(v + v + 2, m + 1, R);
  tmin[v] = min(tmin[v + v + 1], tmin[v + v + 2]);
  tcnt[v] = tcnt[v + v + 1] + tcnt[v + v + 2];
}
void build(int v, int L, int R) {
  if (L == R) {
    tmin[v] = cinf;
    tcnt[v] = 0;
    tadd[v] = 0;
  } else {
    int m = (L + R) >> 1;
    build(v + v + 1, L, m);
    build(v + v + 2, m + 1, R);
    recalc(v, L, R);
  }
}
void addcnt(int v, int L, int R, int pos, int val) {
  push(v, L, R);
  if (L == R)
    tcnt[v] += val;
  else {
    int m = (L + R) >> 1;
    if (pos <= m)
      addcnt(v + v + 1, L, m, pos, val);
    else
      addcnt(v + v + 2, m + 1, R, pos, val);
    recalc(v, L, R);
  }
}
void setval(int v, int L, int R, int pos, int val) {
  push(v, L, R);
  if (L == R)
    tmin[v] = val;
  else {
    int m = (L + R) >> 1;
    if (pos <= m)
      setval(v + v + 1, L, m, pos, val);
    else
      setval(v + v + 2, m + 1, R, pos, val);
    recalc(v, L, R);
  }
}
int calcsum(int v, int L, int R, int l, int r) {
  push(v, L, R);
  if (L > r || l > R) return 0;
  if (L >= l && R <= r) return tcnt[v];
  int m = (L + R) >> 1;
  int s1 = calcsum(v + v + 1, L, m, l, r);
  int s2 = calcsum(v + v + 2, m + 1, R, l, r);
  return s1 + s2;
}
void addval(int v, int L, int R, int l, int r, int val) {
  push(v, L, R);
  if (L > r || l > R) return;
  if (L >= l && R <= r) {
    tadd[v] += val;
    return;
  }
  int m = (L + R) >> 1;
  addval(v + v + 1, L, m, l, r, val);
  addval(v + v + 2, m + 1, R, l, r, val);
  recalc(v, L, R);
}
int getmin(int v, int L, int R, int l, int r) {
  push(v, L, R);
  if (L > r || l > R) return cinf;
  if (L >= l && R <= r) return tmin[v];
  int m = (L + R) >> 1;
  int s1 = getmin(v + v + 1, L, m, l, r);
  int s2 = getmin(v + v + 2, m + 1, R, l, r);
  return min(s1, s2);
}
int n, len, h;
vector<int> a;
vector<int> pr;
void add(int iii) {
  int pos = pr[iii];
  int ind = calcsum(0, 0, n - 1, 0, pos);
  setval(0, 0, n - 1, pos, a[iii] - ind);
  addcnt(0, 0, n - 1, pos, 1);
  if (pos < n - 1) addval(0, 0, n - 1, pos + 1, n - 1, -1);
}
void rem(int iii) {
  int pos = pr[iii];
  int ind = calcsum(0, 0, n - 1, 0, pos);
  setval(0, 0, n - 1, pos, cinf);
  addcnt(0, 0, n - 1, pos, -1);
  if (pos < n - 1) addval(0, 0, n - 1, pos + 1, n - 1, 1);
}
int calcf() {
  int curmin = getmin(0, 0, n - 1, 0, n - 1);
  return curmin >= 0;
}
int main() {
  scanf("%d%d%d", &n, &len, &h);
  vector<int> b(len);
  a.resize(n);
  for (int i = 0; i < len; ++i) scanf("%d", &b[i]), b[i] = h - b[i];
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  sort(b.begin(), b.end());
  for (int i = 0; i < n; ++i) {
    int ind = upper_bound(b.begin(), b.end(), a[i]) - b.begin() - 1;
    a[i] = ind;
  }
  vector<pair<int, int> > p(n);
  for (int i = 0; i < n; ++i) p[i] = make_pair(a[i], i);
  sort(p.begin(), p.end());
  pr.resize(n);
  for (int i = 0; i < n; ++i) pr[p[i].second] = i;
  build(0, 0, n - 1);
  for (int i = 0; i < len; ++i) add(i);
  int ans = 0;
  for (int i = 0; i + len <= n; ++i) {
    ans += calcf();
    if (i + len < n) {
      rem(i);
      add(i + len);
    }
  }
  printf("%d\n", ans);
  return 0;
}
