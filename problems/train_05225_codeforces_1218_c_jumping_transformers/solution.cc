#include <bits/stdc++.h>
using namespace std;
const int N = 505;
long long dp_hor[2][N][N], dp_vert[2][N][N];
vector<pair<int, int>> cost_hor[N][N], cost_vert[N][N];
long long inf = 1e18;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) {
    int x, y, d, t, e;
    cin >> x >> y >> d >> t >> e;
    if (x + y >= t && ((x + y) % 4) == (t % 4))
      cost_hor[x][y].push_back({1e9, e}), cost_vert[x][y].push_back({1e9, e});
    if (x + y >= t + 1 && ((x + y) % 4) == ((t + 1) % 4))
      cost_hor[x + d][y - d].push_back({1e9, e}),
          cost_vert[x + d][y - d].push_back({1e9, e});
    if (x + y + d >= t + 2 && ((x + y + d) % 4) == ((t + 2) % 4)) {
      if (x + y >= t + 1 && ((x + y) % 4) == ((t + 1) % 4))
        cost_hor[x + d][y].push_back({d, e});
      else
        cost_hor[x + d][y].push_back({1e9, e});
      if (x + y >= t && ((x + y) % 4) == (t % 4))
        cost_vert[x + d][y].push_back({d, e});
      else
        cost_vert[x + d][y].push_back({1e9, e});
    }
    if (x + y + d >= t + 3 && ((x + y + d) % 4) == ((t + 3) % 4)) {
      if (x + y >= t && ((x + y) % 4) == (t % 4))
        cost_hor[x][y + d].push_back({d, e});
      else
        cost_hor[x][y + d].push_back({1e9, e});
      cost_vert[x][y + d].push_back({1e9, e});
    }
  }
  for (int x = 0; x < 2; x++)
    for (int y = 0; y < N; y++)
      for (int z = 0; z < N; z++) dp_hor[x][y][z] = dp_vert[x][y][z] = inf;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      int f = x & 1;
      for (int z = 0; z < N; z++) dp_hor[f][y][z] = dp_vert[f][y][z] = inf;
      if (x == 0 && y == 0) {
        dp_hor[f][y][0] = dp_vert[f][y][0] = 0;
      }
      sort(cost_hor[x][y].begin(), cost_hor[x][y].end());
      sort(cost_vert[x][y].begin(), cost_vert[x][y].end());
      long long cost = 0;
      for (int z = y; z >= 1; z--) {
        while (cost_hor[x][y].size() > 0 && cost_hor[x][y].back().first > z) {
          pair<int, int> t = cost_hor[x][y].back();
          cost_hor[x][y].pop_back();
          cost += t.second;
        }
        dp_hor[f][y][z] = dp_hor[f][y - 1][z - 1] + cost;
      }
      cost = 0;
      for (int z = x; z >= 1; z--) {
        while (cost_vert[x][y].size() > 0 && cost_vert[x][y].back().first > z) {
          pair<int, int> t = cost_vert[x][y].back();
          cost_vert[x][y].pop_back();
          cost += t.second;
        }
        dp_vert[f][y][z] = dp_vert[f ^ 1][y][z - 1] + cost;
      }
      for (int z = 1; z <= x; z++) {
        dp_hor[f][y][0] = min(dp_hor[f][y][0], dp_vert[f][y][z]);
      }
      for (int z = 1; z <= y; z++) {
        dp_vert[f][y][0] = min(dp_vert[f][y][0], dp_hor[f][y][z]);
      }
    }
  }
  long long ans = inf;
  for (int z = 1; z < m; z++) {
    ans = min(ans, dp_hor[(n - 1) & 1][m - 1][z]);
  }
  for (int z = 1; z < n; z++) {
    ans = min(ans, dp_vert[(n - 1) & 1][m - 1][z]);
  }
  if (ans == inf) ans = 0;
  cout << ans << endl;
}
