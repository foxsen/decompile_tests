#include <bits/stdc++.h>
using namespace std;
const int maxS = 1 << 21;
const int maxn = 50;
long long ans, con[maxn];
int n, m, fa[maxn], col[maxn], num[maxS];
int nl, nr, cnt1, cnt2 = 1;
vector<int> G[maxn];
int find(int a) { return fa[a] == a ? a : fa[a] = find(fa[a]); }
int check(int u) {
  for (int v : G[u]) {
    if (col[v] == col[u]) return 0;
    if (!col[v]) {
      col[v] = col[u] ^ 1;
      if (!check(v)) return 0;
    }
  }
  return 1;
}
void add(int a, int b) {
  G[a].push_back(b);
  con[a] |= 1ll << (b - 1);
}
int main() {
  scanf("%d%d", &n, &m);
  ans = 1ll << n;
  if (!m) ans -= (1ll << n);
  cnt1 = n;
  nl = n / 2;
  nr = n - nl;
  for (int i = 1; i <= n; ++i) fa[i] = i;
  for (int i = 1, u, v; i <= m; ++i) {
    scanf("%d%d", &u, &v);
    add(u, v);
    add(v, u);
    if (find(u) != find(v)) {
      fa[find(u)] = find(v);
      --cnt1;
    }
  }
  for (int i = 1; i <= n; ++i)
    if (!G[i].size()) ++cnt2;
  ans += (1ll << cnt2) + (1ll << cnt1);
  for (int i = 1; i <= n; ++i)
    if (!col[i]) {
      col[i] = 2;
      if (!check(i)) {
        ans -= (1ll << cnt1);
        break;
      }
    }
  ans -= (1ll << cnt1);
  for (int i = 0; i < (1 << nl); ++i) {
    long long cons = 0ll;
    for (int j = 0; j < nl; ++j)
      if ((i >> j) & 1) cons |= con[j + 1];
    if ((cons & i) == 0) {
      ++num[cons >> nl];
    }
  }
  for (int i = 0; i < nr; ++i)
    for (int j = 0; j < (1 << nr); ++j)
      if ((j >> i) & 1) num[j] += num[j ^ (1 << i)];
  for (int i = 0; i < (1 << nr); ++i) {
    long long cons = 0ll;
    for (int j = 0; j < nr; ++j)
      if ((i >> j) & 1) cons |= con[j + nl + 1];
    if (((cons >> nl) & i) == 0) {
      ans -= (num[i ^ ((1 << nr) - 1)] << 1);
    }
  }
  cout << ans << endl;
  return 0;
}
