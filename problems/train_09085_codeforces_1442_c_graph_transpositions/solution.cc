#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 2e5 + 10;
const int K = 20;
const int INF = 1e9;
const int MOD = 998244353;
int n;
vector<pair<int, int> > adj[2][N];
int trans[2][N], lvl_dist[2][N], dist[2][K][N];
struct elem {
  int rev, tr, u, d;
  bool operator<(const elem &o) const { return d > o.d; }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m;
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[0][u].emplace_back(0, v);
    adj[1][v].emplace_back(1, u);
  }
  vector<int> pot2(max(K, n + 2));
  pot2[0] = 1;
  for (int i = (int)(1); i < ((int)((int)(pot2).size())); i++)
    pot2[i] = 2 * pot2[i - 1] % MOD;
  int ans = INF;
  {
    for (int i = 0; i < (int)(2); i++)
      for (int j = 0; j < (int)(K); j++)
        for (int k = 0; k < (int)(n); k++) dist[i][j][k] = INF;
    dist[0][0][0] = 0;
    priority_queue<elem> q;
    q.push({0, 0, 0, 0});
    while (!q.empty()) {
      auto el = q.top();
      q.pop();
      if (el.u == n - 1) ans = min(ans, el.d);
      if (dist[el.rev][el.tr][el.u] < el.d) continue;
      for (auto [tv, v] : adj[el.rev][el.u]) {
        if (el.d + 1 < dist[tv][el.tr][v]) {
          dist[tv][el.tr][v] = el.d + 1;
          q.push({tv, el.tr, v, el.d + 1});
        }
      }
      if (el.tr + 1 < K) {
        auto cand = el.d + pot2[el.tr];
        if (cand < dist[1 - el.rev][el.tr + 1][el.u]) {
          dist[1 - el.rev][el.tr + 1][el.u] = cand;
          q.push({1 - el.rev, el.tr + 1, el.u, cand});
        }
      }
    }
  }
  if (ans < INF) return cout << ans, 0;
  {
    for (int i = 0; i < (int)(2); i++)
      for (int j = 0; j < (int)(n); j++) trans[i][j] = INF;
    trans[0][0] = 0;
    deque<pair<int, int> > q;
    q.emplace_back(0, 0);
    while (!q.empty()) {
      auto [tu, u] = q.front();
      q.pop_front();
      for (auto [tv, v] : adj[tu][u]) {
        if (trans[tu][u] < trans[tv][v]) {
          trans[tv][v] = trans[tu][u];
          q.emplace_front(tv, v);
        }
      }
      if (trans[tu][u] + 1 < trans[1 - tu][u]) {
        trans[1 - tu][u] = 1 + trans[tu][u];
        q.emplace_back(1 - tu, u);
      }
    }
  }
  int need = min(trans[0][n - 1], trans[1][n - 1]);
  {
    deque<pair<int, int> > q;
    for (int i = 0; i < (int)(2); i++)
      for (int j = 0; j < (int)(n); j++) lvl_dist[i][j] = INF;
    lvl_dist[0][0] = 0;
    q.emplace_back(0, 0);
    while (!q.empty()) {
      auto [tu, u] = q.front();
      q.pop_front();
      bool lvl = trans[tu][u] + 1 == trans[1 - tu][u];
      if (lvl && lvl_dist[tu][u] < lvl_dist[1 - tu][u]) {
        lvl_dist[1 - tu][u] = lvl_dist[tu][u];
        q.emplace_front(1 - tu, u);
      }
      for (auto [tv, v] : adj[tu][u]) {
        if (trans[tu][u] > trans[tv][v]) continue;
        if (lvl_dist[tu][u] + 1 < lvl_dist[tv][v]) {
          lvl_dist[tv][v] = lvl_dist[tu][u] + 1;
          q.emplace_back(tv, v);
        }
      }
    }
  }
  {
    int ans = INF;
    for (int i = 0; i < (int)(2); i++)
      if (trans[i][n - 1] == need) ans = min(ans, lvl_dist[i][n - 1]);
    for (int i = 0; i < (int)(need); i++) ans = (ans + pot2[i]) % MOD;
    cout << ans << endl;
  }
  return 0;
}
