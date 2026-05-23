#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int M = N;
const int inf = 1e9 + 9;
const long long base = 1e18;
const double pi = acos(-1);
const double ep = 1e-9;
int low[N], num[N], pa[N];
int n, m, cnt;
vector<int> adj[N];
bool check[N];
void DFS(int u) {
  low[u] = num[u] = ++cnt;
  for (int j = 0; j < adj[u].size(); j++) {
    int v = adj[u][j];
    if (num[v] == 0) {
      pa[v] = u;
      DFS(v);
      low[u] = min(low[u], low[v]);
    } else {
      if (v != pa[u]) {
        low[u] = min(low[u], num[v]);
      }
    }
  }
}
void findBridge() {
  pa[1] = -1;
  DFS(1);
  for (int i = 1; i < n + 1; i++)
    if (pa[i] != -1) {
      if (low[i] >= num[i]) {
        check[i] = true;
      }
    }
}
int tp[N];
int cs = 0;
vector<int> rev[N];
int pre[N][20];
int d[N];
void makeTree(int u) {
  for (int j = 0; j < adj[u].size(); j++) {
    int v = adj[u][j];
    if (pa[v] == u) {
      if (tp[v] == 0) {
        if (check[v]) {
          tp[v] = ++cs;
          rev[tp[u]].push_back(tp[v]);
          pre[tp[v]][0] = tp[u];
          d[tp[v]] = d[tp[u]] + 1;
          for (int t = 1; t < 20; t++)
            if (pre[tp[v]][t - 1] == -1)
              pre[tp[v]][t] = -1;
            else
              pre[tp[v]][t] = pre[pre[tp[v]][t - 1]][t - 1];
        } else
          tp[v] = tp[u];
        makeTree(v);
      }
    }
  }
}
int lca(int u, int v) {
  if (d[u] < d[v]) swap(u, v);
  while (d[u] > d[v]) {
    int k = log(d[u] - d[v]) / log(2);
    u = pre[u][k];
  }
  if (u == v) return u;
  for (int j = 19; j > -1; j--) {
    if (pre[u][j] != -1 && pre[u][j] != pre[v][j]) {
      u = pre[u][j];
      v = pre[v][j];
    }
  }
  return pre[u][0];
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  findBridge();
  cs = 1;
  for (int i = 0; i < 20; i++) pre[1][i] = -1;
  tp[1] = 1;
  makeTree(1);
  int k;
  cin >> k;
  for (int j = 0; j < k; j++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u = tp[u];
    v = tp[v];
    int g = lca(u, v);
    printf("%d\n", d[u] - d[g] + d[v] - d[g]);
  }
}
