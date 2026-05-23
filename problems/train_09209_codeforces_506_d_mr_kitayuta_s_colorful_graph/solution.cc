#include <bits/stdc++.h>
using namespace std;
vector<int> vec[105][105];
int visited[105], u, v, ans = 0;
void dfs(int col, int p) {
  visited[p] = 1;
  if (p == v) {
    ans++;
    return;
  }
  for (int i = 0; i < vec[p][col].size(); i++) {
    int k = vec[p][col][i];
    if (visited[k] == 0) dfs(col, k);
  }
}
int main() {
  int n, m, q, a, b, c;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    vec[a][c].push_back(b);
    vec[b][c].push_back(a);
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    ans = 0;
    cin >> u >> v;
    for (int i = 1; i <= m; i++) {
      for (int k = 0; k <= n; k++) visited[k] = 0;
      dfs(i, u);
    }
    cout << ans << endl;
  }
}
