#include <bits/stdc++.h>
using namespace std;
int dist(pair<int, int> a, pair<int, int> b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}
int const N = 2000, K = 10;
int vis[K];
pair<int, int> sla[K][4];
vector<vector<int>> tans = vector<vector<int>>(K, vector<int>(K));
void solvetask() {
  int n, m, k, s;
  cin >> n >> m >> k >> s;
  pair<int, int> aux[] = {{0, 0}, {n - 1, 0}, {n - 1, m - 1}, {0, m - 1}};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int num;
      cin >> num;
      if (!vis[num]) {
        for (int y = 0; y < 4; y++) sla[num][y] = {i, j};
        vis[num] = 1;
        continue;
      }
      for (int y = 0; y < 4; y++) {
        if (dist(sla[num][y], aux[y]) > dist({i, j}, aux[y])) {
          sla[num][y] = {i, j};
        }
      }
    }
  }
  for (int n1 = 1; n1 <= k; n1++) {
    for (int n2 = n1; n2 <= k; n2++) {
      if (!vis[n1] || !vis[n2]) continue;
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          tans[n1][n2] = max(tans[n1][n2], dist(sla[n1][i], sla[n2][j]));
          tans[n2][n1] = max(tans[n2][n1], tans[n1][n2]);
        }
      }
    }
  }
  int ans = 0, ant, cur;
  cin >> ant;
  for (int y = 1; y < s; y++) {
    cin >> cur;
    ans = max(ans, tans[ant][cur]);
    ant = cur;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) solvetask();
}
