#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
long long n, m, q, l, r;
long long vis[3 * maxn], cir[3 * maxn], suff[3 * maxn];
vector<long long> G[3 * maxn];
stack<long long> path;
void dfs(long long now, long long pre) {
  path.push(now);
  vis[now] = 1;
  for (int i = 0; i < (int)G[now].size(); i++) {
    long long Next = G[now][i];
    if (Next == pre) continue;
    if (!vis[Next]) dfs(Next, now);
    if (vis[Next] == 1) {
      long long maxc = now, minc = now;
      while (!path.empty()) {
        long long temp = path.top();
        path.pop();
        maxc = max(maxc, temp), minc = min(minc, temp);
        if (temp == Next) break;
      }
      cir[minc] = maxc;
    }
  }
  if (!path.empty() && path.top() == now) path.pop();
  vis[now] = 2;
}
int main() {
  scanf("%lld %lld", &n, &m);
  for (int i = 1; i <= m; i++) {
    long long u, v;
    scanf("%lld %lld", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i <= n + 1; i++) cir[i] = n + 1;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) dfs(i, 0);
  }
  suff[n] = suff[n + 1] = 0;
  for (int i = n; i >= 1; i--) cir[i] = min(cir[i], cir[i + 1]);
  for (int i = n; i >= 1; i--) suff[i] = cir[i] - i + suff[i + 1];
  scanf("%lld", &q);
  while (q--) {
    scanf("%lld %lld", &l, &r);
    long long L = l, R = r, p;
    while (L <= R) {
      long long m = (L + R) / 2;
      if (cir[m] <= r) {
        L = m + 1;
      } else {
        p = m;
        R = m - 1;
      }
    }
    long long ans = suff[l] - suff[p] + (r - p + 1) * (r - p + 2) / 2;
    printf("%lld\n", ans);
  }
  return 0;
}
