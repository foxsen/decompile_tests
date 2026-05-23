#include <bits/stdc++.h>
using namespace std;
vector<int long long> vis;
vector<vector<int long long> > a;
int long long ans = 0;
void dfs(int long long i, int long long step, int long long father) {
  if (step == 2) {
    vis[i]++;
    if (vis[i] >= 2) ans += vis[i] - 1;
    return;
  }
  for (long long j = 0; j < a[i].size(); j++) {
    if (father != a[i][j]) dfs(a[i][j], step + 1, i);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  ;
  int long long n, m, x, y;
  cin >> n >> m;
  a.resize(n);
  vis.resize(n);
  for (long long i = 0; i < m; i++) {
    cin >> x >> y;
    x--;
    y--;
    a[x].push_back(y);
  }
  for (long long i = 0; i < n; i++) {
    for (long long i = 0; i < n; i++) vis[i] = 0;
    dfs(i, 0, -1);
  }
  cout << ans << endl;
}
