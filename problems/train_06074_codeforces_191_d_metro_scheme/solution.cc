#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
vector<int> adj[maxn];
int deg[maxn];
int n, m, ret;
void init() {
  scanf("%d%d", &n, &m);
  int u, v;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    if (deg[u] < 2) adj[u].push_back(v);
    if (deg[v] < 2) adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
}
void work() {
  for (int i = 1; i <= n; i++) ret += deg[i] & 1;
  ret >>= 1;
  for (int i = 1; i <= n; i++)
    if (deg[i] == 2) {
      int x = adj[i][0], y = adj[i][1];
      if (x == y) {
        deg[x] = 0;
        ret++;
        continue;
      }
      adj[x][adj[x][0] != i] = y;
      adj[y][adj[y][0] != i] = x;
    }
}
void print() { printf("%d %d\n", ret, m); }
int main() {
  init();
  work();
  print();
  return 0;
}
