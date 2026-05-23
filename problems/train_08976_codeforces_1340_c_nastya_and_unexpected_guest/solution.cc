#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const long long int INF = 1e14;
long long int n, m;
vector<long long int> d;
long long int g, r;
vector<vector<long long int>> dist;
vector<vector<bool>> vis;
void solve() {
  cin >> n >> m;
  d.resize(m);
  for (int i = 0; i < m; i++) {
    cin >> d[i];
  }
  sort(d.begin(), d.end());
  cin >> g >> r;
  dist.resize(m, vector<long long int>(g + 1, 0));
  vis.resize(m, vector<bool>(g + 1, false));
  deque<pair<long long int, long long int>> q;
  vis[0][0] = true;
  dist[0][0] = 0;
  q.push_back({0, 0});
  long long int ans = -1;
  while (!q.empty()) {
    long long int v = q.front().first;
    long long int t = q.front().second;
    q.pop_front();
    if (t == 0) {
      long long int time = n - d[v];
      if (time <= g) {
        long long int tans = (r + g) * dist[v][t] + time;
        if (ans == -1 || ans > tans) {
          ans = tans;
        }
      }
    }
    if (t == g) {
      if (!vis[v][0]) {
        dist[v][0] = dist[v][t] + 1;
        q.push_back({v, 0});
        vis[v][0] = true;
      }
      continue;
    }
    if (v > 0) {
      long long int time = t + d[v] - d[v - 1];
      if (time <= g && (!vis[v - 1][time])) {
        vis[v - 1][time] = true;
        dist[v - 1][time] = dist[v][t];
        q.push_front({v - 1, time});
      }
    }
    if (v < m - 1) {
      long long int time = t + d[v + 1] - d[v];
      if (time <= g && (!vis[v + 1][time])) {
        vis[v + 1][time] = true;
        dist[v + 1][time] = dist[v][t];
        q.push_front({v + 1, time});
      }
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
