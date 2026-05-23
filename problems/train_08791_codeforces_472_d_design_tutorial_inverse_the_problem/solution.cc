#include <bits/stdc++.h>
using namespace std;
int n;
struct node {
  int t, nxt;
} edge[2000000];
int headline[2100], E;
inline void add(int f, int t) {
  edge[E].t = t;
  edge[E].nxt = headline[f];
  headline[f] = E++;
}
int puzzle[2100][2100];
int lca[2100][2100];
bool visit[2100], flag;
int fsu[2100];
int ans[2100][2100];
int findfa(int x) {
  if (fsu[x] != x) fsu[x] = findfa(fsu[x]);
  return fsu[x];
}
void tarjan(int u) {
  visit[u] = true;
  for (int i = (1); i <= (n); i++) {
    if (i == u) continue;
    if (visit[i]) {
      lca[u][i] = lca[i][u] = findfa(i);
    }
  }
  for (int i = headline[u]; ~i; i = edge[i].nxt) {
    int v = edge[i].t;
    if (!visit[v]) {
      tarjan(v);
      fsu[v] = u;
    }
  }
}
vector<int> pool;
vector<int>::iterator it, fuck;
void dfs(int u, int fa) {
  while (true) {
    if (pool.empty()) break;
    int id, minr = INT_MAX;
    for (it = pool.begin(); it != pool.end(); it++) {
      int tt = (*it);
      if (puzzle[tt][fa] == puzzle[tt][u] + puzzle[u][fa]) {
        if (puzzle[tt][u] < minr) {
          minr = puzzle[tt][u];
          id = tt;
          fuck = it;
        }
      }
    }
    if (minr != INT_MAX) {
      pool.erase(fuck);
      add(id, u);
      add(u, id);
      dfs(id, u);
    } else
      break;
  }
}
void solve(void) {
  pool.clear();
  memset(headline, -1, sizeof(headline));
  E = 0;
  memset(visit, false, sizeof(visit));
  for (int i = (1); i <= (n); i++) fsu[i] = i;
  for (int i = (2); i <= (n); i++) pool.push_back(i);
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++) scanf("%d", puzzle[i] + j);
  flag = true;
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++) {
      if (i == j && puzzle[i][j]) flag = false;
      if (i != j) {
        if (puzzle[i][j] == 0 || puzzle[i][j] != puzzle[j][i]) flag = false;
      }
    }
  if (!flag) {
    printf("NO\n");
    return;
  }
  while (!pool.empty()) {
    int id, minr = INT_MAX;
    for (it = pool.begin(); it != pool.end(); it++) {
      int tt = (*it);
      if (minr > puzzle[1][tt]) {
        minr = puzzle[1][tt];
        id = tt;
        fuck = it;
      }
    }
    pool.erase(fuck);
    add(1, id);
    add(id, 1);
    dfs(id, 1);
  }
  if (E != 2 * n - 2) {
    printf("NO\n");
    return;
  }
  tarjan(1);
  memset(ans, 0, sizeof(ans));
  for (int i = (1); i <= (n); i++) {
    for (int j = (i + 1); j <= (n); j++) {
      int fff = lca[i][j];
      ans[i][j] = ans[j][i] = puzzle[i][1] + puzzle[j][1] - 2 * puzzle[fff][1];
    }
  }
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++)
      if (ans[i][j] != puzzle[i][j]) {
        printf("NO\n");
        return;
      }
  printf("YES\n");
}
int main(void) {
  while (EOF != scanf("%d", &n)) solve();
  return 0;
}
