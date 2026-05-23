#include <bits/stdc++.h>
using namespace std;
int T, t, n, k, a, m, maxn;
int tree[200010], x[200010];
bool vis[200010];
int lowbit(int x) { return x & (-x); }
void update(int x, int num) {
  for (; x <= n; x += lowbit(x)) tree[x] += num;
}
int query(int x) {
  int ret = 0;
  for (; x > 0; x -= lowbit(x)) ret += tree[x];
  return ret;
}
int fen1(int pos) {
  int i, j, k, l, r, mi;
  l = 1;
  r = pos;
  while (l < r) {
    mi = (l + r) / 2;
    if (query(pos) - query(mi - 1) == pos - mi + 1)
      r = mi;
    else
      l = mi + 1;
  }
  return l;
}
int fen2(int pos) {
  int i, j, k, l, r, mi;
  l = pos;
  r = n;
  while (l < r) {
    mi = (l + r + 1) / 2;
    if (query(mi) - query(pos - 1) == mi - pos + 1)
      l = mi;
    else
      r = mi - 1;
  }
  return l;
}
void solve() {
  int i, j, l, r, len, len1, len2;
  scanf("%d%d%d", &n, &k, &a);
  maxn = (n + 1) / (a + 1);
  scanf("%d", &m);
  for (i = 1; i <= m; i++) scanf("%d", &x[i]);
  for (i = 1; i <= n; i++) update(i, 1);
  for (i = 1; i <= m; i++) {
    if (vis[x[i]]) continue;
    vis[x[i]] = 1;
    l = fen1(x[i]);
    r = fen2(x[i]);
    update(x[i], -1);
    len = r - l + 1;
    len1 = x[i] - l;
    len2 = r - x[i];
    maxn = maxn - (len + 1) / (a + 1) + (len1 + 1) / (a + 1) +
           (len2 + 1) / (a + 1);
    if (maxn >= k)
      continue;
    else {
      printf("%d\n", i);
      return;
    }
  }
  printf("-1\n");
}
int main() { solve(); }
