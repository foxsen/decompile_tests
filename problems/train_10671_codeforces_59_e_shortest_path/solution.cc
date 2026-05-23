#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long n, m, k;
  cin >> n >> m >> k;
  vector<vector<long long>> a(n + 1);
  set<vector<long long>> s;
  for (long long i = 0; i < m; i++) {
    long long u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  for (long long i = 0; i < k; i++) {
    vector<long long> v(3);
    cin >> v[0] >> v[1] >> v[2];
    s.insert(v);
  }
  queue<vector<long long>> q;
  map<pair<long long, long long>, pair<long long, long long>> par;
  q.push({1, 0, 0});
  set<pair<long long, long long>> vis;
  while (!q.empty()) {
    auto tmp = q.front();
    q.pop();
    if (tmp[0] == n) {
      pair<long long, long long> start = {n, tmp[1]};
      cout << tmp[2] << endl;
      vector<long long> b;
      while (start.second) {
        b.push_back(start.first);
        start = par[start];
      }
      b.push_back(1);
      reverse(b.begin(), b.end());
      for (auto x : b) cout << x << " ";
      return 0;
    } else {
      for (auto x : a[tmp[0]]) {
        if (vis.count({x, tmp[0]}) || s.count({tmp[2], tmp[0], x})) continue;
        vis.insert({x, tmp[0]});
        q.push({x, tmp[0], tmp[2] + 1});
        par[{x, tmp[0]}] = {tmp[0], tmp[1]};
      }
    }
  }
  cout << "-1" << endl;
  return 0;
}
