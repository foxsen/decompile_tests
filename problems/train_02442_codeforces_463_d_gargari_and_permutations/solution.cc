#include <bits/stdc++.h>
using namespace std;
const long long md = 1e9 + 7;
int n, k, ans, mx, edg[1010][1010], dis[1001];
vector<int> v, gr[100000];
bool vis[1001];
void dfs(int x, int l) {
  vis[x] = true;
  dis[x] = 0;
  for (int i = 0; i < gr[x].size(); i++) {
    int u = gr[x][i];
    if (vis[u] == false) {
      dfs(u, l + 1);
    }
    dis[x] = max(dis[x], dis[u] + 1);
    mx = max(mx, dis[x]);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  int kk = k;
  while (k--) {
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      edg[x][k] = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      bool t = false;
      for (int z = 0; z < kk; z++) {
        if (edg[i][z] > edg[j][z]) t = true;
      }
      if (t == false) gr[i].push_back(j);
    }
  }
  for (int i = 1; i <= n; i++) {
    dfs(i, 1);
    memset(vis, 0, sizeof vis);
  }
  cout << mx + 1;
}
