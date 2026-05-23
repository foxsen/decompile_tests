#include <bits/stdc++.h>
using namespace std;
const int maxn = 200050;
int n, m, k, mx;
int a[maxn], ans;
int l, r, fa[maxn], siz[maxn];
vector<int> G[maxn];
map<int, int> mp;
int f(int x) { return fa[x] == x ? x : fa[x] = f(fa[x]); }
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), fa[i] = i;
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &l, &r);
    if (f(l) != f(r)) fa[f(l)] = f(r);
  }
  for (int i = 1; i <= n; ++i) siz[f(i)]++, G[f(i)].push_back(a[i]);
  for (int i = 1; i <= n; ++i)
    if (siz[i]) {
      mp.clear();
      mx = 0;
      for (int j = 0; j <= G[i].size() - 1; ++j)
        mp[G[i][j]]++, mx = max(mx, mp[G[i][j]]);
      ans += siz[i] - mx;
    }
  printf("%d", ans);
  return 0;
}
