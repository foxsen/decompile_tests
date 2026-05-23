#include <bits/stdc++.h>
using namespace std;
vector<int> v[102];
bool par[102][102];
bool vis[102];
int cyc = 0;
void dfs(int nd, int p) {
  vis[nd] = true;
  int z = v[nd].size();
  int nx;
  for (int i = 0; i < z; i++) {
    nx = v[nd][i];
    if (vis[nx]) {
      if (nx != p && p != 0) {
        if (par[nx][nd] || par[nd][nx]) continue;
        par[nx][nd] = par[nd][nx] = true;
        cyc++;
      }
    } else
      dfs(nx, nd);
  }
  return;
}
int main() {
  int n, m;
  cin >> n >> m;
  int x, y;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(1, 0);
  bool complete = true;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      complete = false;
    }
  }
  if (cyc == 1 && complete) {
    cout << "FHTAGN!";
  } else
    cout << "NO";
  return 0;
}
