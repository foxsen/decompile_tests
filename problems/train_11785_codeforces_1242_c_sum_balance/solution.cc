#include <bits/stdc++.h>
using namespace std;
const int maxn = 15 * 5000 + 5;
int k, v[20], vis[maxn];
long long a[20][5050], ss[20], tot, sum;
struct node {
  int val, bel;
} x[maxn];
map<long long, int> mp;
vector<int> g[maxn], rec[1 << 15 + 5], tmp;
int pre[1 << 15 + 5], dp[1 << 15 + 5], ok[1 << 15 + 5], l[20], r[20];
void getans(int y) {
  int sz = rec[y].size();
  for (int i = 0; i < sz; i++) {
    int now = rec[y][i];
    int nxt;
    if (i == sz - 1)
      nxt = rec[y][0];
    else
      nxt = rec[y][i + 1];
    l[x[now].bel + 1] = x[now].val;
    r[x[now].bel + 1] = x[nxt].bel + 1;
  }
}
void dfs(int u, int st) {
  if (vis[u]) {
    int num = tmp.size();
    int now = 0;
    for (int i = num - 1; i >= 0; i--) {
      now = now | (1 << x[tmp[i]].bel);
      if (tmp[i] == u) break;
    }
    if (!ok[now]) {
      ok[now] = 1;
      for (int i = num - 1; i >= 0; i--) {
        rec[now].push_back(tmp[i]);
        if (tmp[i] == u) break;
      }
    }
    return;
  }
  if (st & (1 << x[u].bel)) {
    return;
  }
  vis[u] = 1;
  tmp.push_back(u);
  for (int i = 0; i < g[u].size(); i++) {
    dfs(g[u][i], (st | (1 << x[u].bel)));
  }
  vis[u] = 0;
  tmp.pop_back();
}
int main() {
  scanf("%d", &k);
  sum = tot = 0;
  for (int i = 1; i <= k; i++) {
    scanf("%d", &v[i]);
    for (int j = 1; j <= v[i]; j++) {
      scanf("%lld", &a[i][j]);
      ss[i] += a[i][j];
      sum += a[i][j];
      mp[a[i][j]] = ++tot;
      x[tot].val = a[i][j];
      x[tot].bel = i - 1;
    }
  }
  if (sum % k) {
    printf("No\n");
    return 0;
  }
  sum /= k;
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= v[i]; j++) {
      if (mp.count(a[i][j] - ss[i] + sum)) {
        g[mp[a[i][j]]].push_back(mp[a[i][j] - ss[i] + sum]);
      }
    }
  }
  int mx = (1 << k) - 1;
  for (int i = 0; i <= mx; i++) dp[i] = 0, ok[i] = 0;
  dp[0] = 1;
  for (int i = 1; i <= tot; i++) {
    tmp.clear();
    dfs(i, 0);
  }
  for (int i = 0; i <= mx; i++) {
    if (dp[i]) {
      int S = mx ^ i;
      for (int j = S; j; j = ((j - 1) & S)) {
        if (ok[j]) {
          dp[i | j] = 1;
          pre[i | j] = i;
        }
      }
    }
  }
  if (!dp[mx]) {
    printf("No\n");
    return 0;
  }
  int now = mx;
  while (now) {
    int y = now ^ pre[now];
    getans(y);
    now = pre[now];
  }
  printf("Yes\n");
  for (int i = 1; i <= k; i++) {
    printf("%d %d\n", l[i], r[i]);
  }
}
