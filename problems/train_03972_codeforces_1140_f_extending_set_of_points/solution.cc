#include <bits/stdc++.h>
using namespace std;
const int maxn = 600005;
int q, tot;
long long ans;
struct Opt {
  int x, y, l, r;
} opt[maxn];
vector<pair<int, int> > vec[maxn * 4];
int cnt, fa[maxn], siz1[maxn], siz2[maxn], mx[maxn], my[maxn];
inline int gi() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int sum = 0;
  while ('0' <= c && c <= '9') sum = sum * 10 + c - 48, c = getchar();
  return sum;
}
void insert(int s, int l, int r, int ql, int qr, int x, int y) {
  if (ql <= l && r <= qr) return vec[s].push_back(make_pair(x, y)), void();
  if (ql <= ((l + r) >> 1)) insert((s << 1), l, ((l + r) >> 1), ql, qr, x, y);
  if (qr >= ((l + r) >> 1) + 1)
    insert((s << 1 | 1), ((l + r) >> 1) + 1, r, ql, qr, x, y);
}
inline int find(int x) {
  if (fa[x] == x) return x;
  return find(fa[x]);
}
inline void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  ans -= (long long)siz1[x] * siz2[x] + (long long)siz1[y] * siz2[y];
  if (siz1[x] + siz2[x] < siz1[y] + siz2[y]) swap(x, y);
  fa[y] = x;
  siz1[x] += siz1[y];
  siz2[x] += siz2[y];
  ans += (long long)siz1[x] * siz2[x];
  ++cnt;
  mx[cnt] = x;
  my[cnt] = y;
}
inline void clear(int top) {
  while (cnt > top) {
    fa[my[cnt]] = my[cnt];
    siz1[mx[cnt]] -= siz1[my[cnt]];
    siz2[mx[cnt]] -= siz2[my[cnt]];
    --cnt;
  }
}
void solve(int s, int l, int r) {
  int tmp = cnt;
  long long lstans = ans;
  for (auto e : vec[s]) merge(e.first, e.second + 300000);
  if (l == r)
    printf("%lld ", ans);
  else
    solve((s << 1), l, ((l + r) >> 1)),
        solve((s << 1 | 1), ((l + r) >> 1) + 1, r);
  clear(tmp);
  ans = lstans;
}
int main() {
  q = gi();
  map<pair<int, int>, int> S;
  for (int x, y, i = 1; i <= q; ++i) {
    x = gi();
    y = gi();
    if (S.count(make_pair(x, y)))
      opt[S[make_pair(x, y)]].r = i - 1, S.erase(make_pair(x, y));
    else
      ++tot, S[make_pair(x, y)] = tot, opt[tot] = (Opt){x, y, i, q + 1};
  }
  for (int i = 1; i <= tot; ++i)
    insert(1, 1, q, opt[i].l, opt[i].r, opt[i].x, opt[i].y);
  for (int i = 1; i <= 300000; ++i) siz1[fa[i] = i] = 1;
  for (int i = 300001; i <= 600000; ++i) siz2[fa[i] = i] = 1;
  solve(1, 1, q);
  return 0;
}
