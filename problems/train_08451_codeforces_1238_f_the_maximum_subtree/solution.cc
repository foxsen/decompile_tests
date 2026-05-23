#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 3e5 + 15;
int q, n, ans;
bool mark[MAX_N];
int d[MAX_N];
vector<int> G[MAX_N];
int dfs(int v, int p = -1) {
  int res1 = 0, res2 = 0, ct = 0;
  for (int u : G[v])
    if (u != p && !mark[u]) {
      ct++;
      int tmp = dfs(u, v);
      if (res1 < tmp) {
        res2 = res1;
        res1 = tmp;
      } else
        res2 = max(res2, tmp);
    }
  ans = max(ans, d[v] + res1 + res2 + ct - 2 + (p != -1));
  ans = max(ans, d[v] + res1 + max(0, ct - 1 + (p != -1)));
  ans = max(ans, d[v] + ct + (p != -1));
  return d[v] + max(res1 + max(0, ct - 1), ct);
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  fill(d, d + MAX_N, 1);
  cin >> q;
  while (q--) {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
      int v, u;
      cin >> v >> u;
      v--, u--;
      G[v].push_back(u);
      G[u].push_back(v);
    }
    if (n == 2) {
      cout << 2 << "\n";
      for (int i = 0; i < n; i++) G[i].clear();
      continue;
    }
    for (int i = 0; i < n; i++)
      if (G[i].size() == 1) {
        mark[i] = true;
        d[G[i][0]]++;
      }
    int V = 0;
    for (int i = 0; i < n; i++)
      if (!mark[i]) V = i;
    dfs(V);
    cout << ans << "\n";
    fill(mark, mark + n, 0);
    fill(d, d + n, 1);
    ans = 0;
    for (int i = 0; i < n; i++) G[i].clear();
  }
  return 0;
}
