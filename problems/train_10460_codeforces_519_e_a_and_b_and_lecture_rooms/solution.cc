#include <bits/stdc++.h>
using namespace std;
template <class T1>
void deb(T1 e1) {
  cout << e1 << endl;
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cout << e1 << " " << e2 << endl;
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cout << e1 << " " << e2 << " " << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
const int LN = 19;
vector<int> graph[100000 + 7];
int par[100000 + 7][LN + 1], depth[100000 + 7], room[100000 + 7], n;
void dfs(int cur = 1, int pr = -1, int dep = 0) {
  par[cur][0] = pr;
  depth[cur] = dep;
  int v;
  room[cur] = 1;
  for (int i = 0; i < graph[cur].size(); i++) {
    v = graph[cur][i];
    if (v == pr) continue;
    dfs(v, cur, dep + 1);
    room[cur] += room[v];
  }
}
void build_lca() {
  for (int i = 1; i <= LN; i++) {
    for (int j = 1; j <= n; j++) {
      if (par[j][i - 1] != -1) par[j][i] = par[par[j][i - 1]][i - 1];
    }
  }
}
int solve(int u, int v) {
  int ans = 0, node = 0, su = u, sv = v, temp;
  if (depth[v] > depth[u]) swap(u, v);
  su = u;
  sv = v;
  for (int i = LN; i >= 0; i--) {
    if (depth[u] - (1 << i) >= depth[v]) {
      node += (1 << i);
      u = par[u][i];
    }
  }
  if (u == v) {
    if (node & 1) return -1;
    node = node / 2;
    temp = depth[v] + node;
    ans = -room[su];
    for (int i = LN; i >= 0; i--) {
      if (depth[su] - (1 << i) > temp) su = par[su][i];
    }
    ans = room[par[su][0]] - room[su];
    return ans;
  }
  for (int i = LN; i >= 0; i--) {
    if (par[u][i] != par[v][i]) {
      u = par[u][i];
      v = par[v][i];
      node += (1 << (i + 1));
    }
  }
  node += 2;
  if (node & 1) return -1;
  if (depth[su] == depth[sv]) {
    ans = n - room[u] - room[v];
    return ans;
  }
  u = su;
  temp = node / 2;
  temp = depth[u] - temp;
  for (int i = LN; i >= 0; i--) {
    if (depth[u] - (1 << i) > temp) u = par[u][i];
  }
  ans = room[par[u][0]] - room[u];
  return ans;
}
int main() {
  int u, v, q, ans;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d %d", &u, &v);
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  memset(par, -1, sizeof(par));
  dfs();
  build_lca();
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d %d", &u, &v);
    if (u == v) {
      printf("%d\n", n);
      continue;
    }
    ans = solve(u, v);
    if (ans == -1)
      printf("0\n");
    else
      printf("%d\n", ans);
  }
  return 0;
}
