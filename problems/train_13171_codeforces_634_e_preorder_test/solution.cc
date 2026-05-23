#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int in[maxn], in1[maxn];
int dp[maxn];
int dp1[maxn];
int dp2[maxn];
int s[maxn];
int vis[maxn];
int dp3[maxn];
vector<int> g[maxn];
int a[maxn];
int k;
int flag;
void dfs(int u, int pa) {
  int p = g[u].size();
  dp1[u] = 1;
  vis[u] = 1;
  for (int i = 0; i < p; i++) {
    if (g[u][i] != pa) {
      dfs(g[u][i], u);
      dp1[u] = max(dp1[u], dp1[g[u][i]] + 1);
    }
  }
}
int pre[maxn], ou[maxn];
int nex[maxn];
void dfs1(int u, int pa) {
  s[u] = 0;
  if (in1[u] != in[u]) {
    s[u] = 1;
  }
  int p = (int)g[u].size();
  int ss = 0;
  int s1 = 0;
  int tot = 0;
  int y = 0, q = 0;
  for (int i = 0; i < p; i++) {
    if (g[u][i] != pa) {
      dfs1(g[u][i], u);
      if (flag) return;
      if (s[g[u][i]] == 0) {
        ss += dp[g[u][i]];
      } else {
        s1 = max(s1, dp[g[u][i]]);
        s[u] = 1;
        y++;
        q = g[u][i];
      }
    }
  }
  dp[u] = ss + s1 + 1;
  dp3[u] = ss;
  if (dp[u] >= k) {
    flag = 1;
  }
  if (y == 1 && in[u] == in1[u])
    nex[u] = q;
  else
    nex[u] = 0;
  dp2[u] = dp[u];
  tot = 0;
  for (int i = 0; i < p; i++) {
    if (g[u][i] != pa) {
      if (s[g[u][i]] == 0) continue;
      if (tot == 0)
        pre[tot] = dp[g[u][i]];
      else
        pre[tot] = max(pre[tot - 1], dp[g[u][i]]);
      tot++;
    }
  }
  int w = tot;
  ou[w] = 0;
  for (int i = p - 1; i >= 0; i--) {
    if (g[u][i] != pa) {
      if (s[g[u][i]] == 0) continue;
      w--;
      ou[w] = max(ou[w + 1], dp[g[u][i]]);
    }
  }
  int f = 0;
  for (int i = 0; i < p; i++) {
    if (g[u][i] != pa) {
      if (s[g[u][i]] == 0) continue;
      if (f == 0) {
        dp2[u] = max(dp2[u], dp[g[u][i]] + ou[1] + ss + 1);
      } else {
        dp2[u] = max(dp2[u], dp[g[u][i]] + max(pre[f - 1], ou[f + 1]) + ss + 1);
      }
      dp2[u] = max(dp2[u], dp[g[u][i]] + ss + 1);
      f++;
    }
  }
  if (dp2[u] >= k) {
    flag = 1;
    return;
  }
  if (pa == -1) {
    int p = u;
    int s = 0;
    while (nex[p]) {
      s += dp3[p] + 1;
      p = nex[p];
      if (s + dp2[p] >= k) {
        flag = 1;
        return;
      }
    }
  }
}
struct pi {
  int a;
  int b;
} pp[maxn];
int main() {
  int i, n;
  cin >> n >> k;
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 0; i < n - 1; i++) {
    scanf("%d%d", &pp[i].a, &pp[i].b);
    in[pp[i].a]++;
    in[pp[i].b]++;
  }
  int le = 1, ri = 1000000, mid;
  while (le <= ri) {
    mid = (le + ri) / 2;
    for (i = 1; i <= n; i++) {
      g[i].clear();
      vis[i] = 0;
      in1[i] = 0;
    }
    for (i = 0; i < n - 1; i++) {
      if (a[pp[i].a] < mid || a[pp[i].b] < mid) continue;
      g[pp[i].a].push_back(pp[i].b);
      g[pp[i].b].push_back(pp[i].a);
      in1[pp[i].a]++;
      in1[pp[i].b]++;
    }
    flag = 0;
    for (i = 1; i <= n; i++) {
      if (a[i] < mid) continue;
      if (!vis[i]) {
        dfs(i, -1);
        dfs1(i, -1);
        if (flag) {
          break;
        }
      }
    }
    if (flag)
      le = mid + 1;
    else
      ri = mid - 1;
  }
  printf("%d\n", ri);
}
