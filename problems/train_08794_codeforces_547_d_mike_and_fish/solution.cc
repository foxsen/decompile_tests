#include <bits/stdc++.h>
using namespace std;
int col[200005], las[200005], x[200005], y[200005], n, i;
vector<int> to[200005];
void dfs(int now, int v) {
  col[now] = v;
  for (int T, i = 0; i < to[now].size(); ++i)
    if (col[T = to[now][i]] == -1) dfs(T, v ^ 1);
}
int main() {
  cin >> n;
  for (i = 1; i <= n; ++i) cin >> x[i] >> y[i];
  for (i = 1; i <= n; ++i) {
    if (las[x[i]]) {
      to[i].push_back(las[x[i]]);
      to[las[x[i]]].push_back(i);
      las[x[i]] = 0;
    } else
      las[x[i]] = i;
  }
  memset(las, 0, sizeof(las));
  for (i = 1; i <= n; ++i) {
    if (las[y[i]]) {
      to[i].push_back(las[y[i]]);
      to[las[y[i]]].push_back(i);
      las[y[i]] = 0;
    } else
      las[y[i]] = i;
  }
  memset(col, -1, sizeof(col));
  for (i = 1; i <= n; ++i)
    if (col[i] == -1) dfs(i, 0);
  memset(las, 0, sizeof(las));
  for (i = 1; i <= n; ++i) cout << (col[i] ? "r" : "b");
}
