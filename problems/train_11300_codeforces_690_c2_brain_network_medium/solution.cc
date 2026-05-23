#include <bits/stdc++.h>
using namespace std;
const int MAX = (int)1E5 + 10;
int n, m;
vector<int> e[MAX];
int d[MAX];
void dfs(int u, int p) {
  for (auto v : e[u])
    if (v != p) {
      d[v] = d[u] + 1;
      dfs(v, u);
    }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  d[0] = 0;
  dfs(0, -1);
  int mv = 0;
  for (int i = 1; i < n; i++)
    if (d[i] > d[mv]) mv = i;
  d[mv] = 0;
  dfs(mv, -1);
  int res = 0;
  for (int i = 0; i < n; i++) res = max(res, d[i]);
  printf("%d", res);
}
