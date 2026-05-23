#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int> g[N], v[N];
int d[N], dd[N], dep[N], f[N], o[N], n;
void dfs(int x, int p) {
  dep[x] = dep[p] + 1;
  for (int i = 0; i < g[x].size(); i++)
    if (g[x][i] != p) dfs(g[x][i], x);
}
bool judge(int x) {
  for (int i = 0; i <= n; i++) dep[i] = o[i] = 0;
  dfs(x, x);
  for (int i = 1; i <= n; i++)
    if (!o[dep[i]])
      o[dep[i]] = dd[i];
    else if (o[dep[i]] != dd[i])
      return false;
  return true;
}
int main() {
  scanf("%d", &n);
  if (n == 1) {
    printf("1\n");
    return 0;
  }
  for (int i = 1, x, y; i < n; i++) {
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
    d[x]++;
    d[y]++;
  }
  for (int i = 1; i <= n; i++) dd[i] = d[i];
  int root = 0;
  for (int i = 1; i <= n; i++)
    if (d[i] == 1) v[0].push_back(i), f[i] = i;
  if (v[0].size() <= 2) {
    printf("%d\n", v[0][0]);
    return 0;
  }
  int k = 0, flag = 1, lst = 0;
  while (flag && v[k].size()) {
    int u = v[k][0];
    for (auto x : v[k])
      if (dd[x] != dd[u]) {
        int root1 = f[x];
        int root2 = f[u];
        if (judge(root1))
          printf("%d\n", root1);
        else if (judge(root2))
          printf("%d\n", root2);
        else
          printf("-1\n");
        return 0;
      }
    for (auto x : v[k]) {
      for (auto y : g[x])
        if (d[y] > 1) {
          if (!f[y]) f[y] = f[x];
          d[y]--;
          if (d[y] == 1) {
            lst = y;
            v[k + 1].push_back(y);
          }
        }
    }
    k++;
  }
  if (lst && judge(lst))
    printf("%d\n", lst);
  else if (f[lst] && judge(f[lst]))
    printf("%d\n", f[lst]);
  else
    printf("-1\n");
  return 0;
}
