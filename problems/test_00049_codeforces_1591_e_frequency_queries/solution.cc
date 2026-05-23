#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int T, n, q;
int a[maxn], p[maxn], ans[maxn], ll[maxn], kk[maxn], cnt[maxn], cntcnt[maxn];
vector<int> v[maxn], g[maxn];
set<int> s[maxn];
void dfs(int x, int last) {
  if (cnt[a[x]] > 0) s[cnt[a[x]]].erase(a[x]);
  cnt[a[x]]++, cntcnt[cnt[a[x]]]++, s[cnt[a[x]]].insert(a[x]);
  for (int i = 0; i < v[x].size(); i++) {
    int q = v[x][i], L = ll[q], R = n + 1;
    if (cntcnt[ll[q]] < kk[q]) {
      ans[q] = -1;
      continue;
    }
    while (L + 1 < R) {
      int mid = (L + R) >> 1;
      if (cntcnt[ll[q]] - cntcnt[mid] < kk[q])
        L = mid;
      else
        R = mid;
    }
    ans[q] = *s[L].begin();
  }
  for (int i = 0; i < g[x].size(); i++) dfs(g[x][i], x);
  s[cnt[a[x]]].erase(a[x]), cntcnt[cnt[a[x]]]--, cnt[a[x]]--;
  if (cnt[a[x]] > 0) s[cnt[a[x]]].insert(a[x]);
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), g[i].clear(), v[i].clear();
    for (int i = 2; i <= n; i++) scanf("%d", &p[i]), g[p[i]].push_back(i);
    for (int i = 1, x; i <= q; i++)
      scanf("%d%d%d", &x, &ll[i], &kk[i]), v[x].push_back(i);
    dfs(1, 0);
    for (int i = 1; i <= q; i++) printf("%d%c", ans[i], i == q ? '\n' : ' ');
  }
  return 0;
}
