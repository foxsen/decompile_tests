#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y) {
  long long int res = 1;
  x = x;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long int logtwo(long long int n) {
  if (n == 1) return 0;
  return logtwo(n / 2) + 1;
}
vector<long long int> adj[105][105];
long long int vis[105][105];
void dfs(int par, long long int col) {
  for (auto child : adj[par][col]) {
    if (vis[child][col]) continue;
    vis[child][col] = vis[par][col];
    dfs(child, col);
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    long long int N, M;
    cin >> N >> M;
    for (long long int i = 0; i < M; i++) {
      long long int a, b, c;
      cin >> a >> b >> c;
      a--;
      b--;
      adj[a][c].push_back(b);
      adj[b][c].push_back(a);
    }
    for (long long int i = 0; i < 105; i++) {
      long long int c = 1;
      for (long long int j = 0; j < N; j++) {
        if (vis[j][i]) continue;
        vis[j][i] = c++;
        dfs(j, i);
      }
    }
    long long int Q;
    cin >> Q;
    while (Q--) {
      long long int x, y;
      cin >> x >> y;
      long long int ans = 0;
      x--;
      y--;
      for (long long int i = 0; i < 105; i++) {
        if (vis[x][i] && vis[x][i] == vis[y][i]) ans++;
      }
      cout << ans << "\n";
    }
  }
  cerr << "Time : " << 1000 * (long double)clock() / (long double)CLOCKS_PER_SEC
       << "ms\n";
  ;
}
