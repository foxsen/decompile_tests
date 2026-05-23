#include <bits/stdc++.h>
using namespace std;
long long M = 1e9 + 7;
const long long N = 1e6 + 7;
long long n;
long long a[N];
vector<long long> ad[N];
long long dp[N][2];
bool isl[N];
void solve(long long v, long long p) {
  if (ad[v].size() == 1 && v != 1) {
    isl[v] = 1;
    dp[v][0] = a[v];
    return;
  }
  vector<long long> dif, x, y;
  long long s = 0;
  for (auto u : ad[v])
    if (u != p) {
      solve(u, v);
      if (isl[u])
        x.push_back(dp[u][0] - dp[u][1]);
      else
        y.push_back(dp[u][0] - dp[u][1]);
      dif.push_back(dp[u][0] - dp[u][1]);
      s += dp[u][0];
    }
  sort(dif.begin(), dif.end());
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  dp[v][0] = min(s, s - dif.back() + a[v]);
  dp[v][1] = s - dif.back();
}
bool mrk[N][2];
set<long long> res;
void get(long long v, long long knd, long long p) {
  if (mrk[v][knd]) return;
  mrk[v][knd] = 1;
  if (ad[v].size() == 1 && v != 1) {
    if (knd == 0) res.insert(v);
    return;
  }
  vector<pair<long long, long long> > dif, x, y;
  long long s = 0;
  for (auto u : ad[v])
    if (u != p) {
      s += dp[u][0];
      dif.push_back({dp[u][0] - dp[u][1], u});
      if (isl[u])
        x.push_back({dp[u][0] - dp[u][1], u});
      else
        y.push_back({dp[u][0] - dp[u][1], u});
    }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  sort(dif.begin(), dif.end());
  if (knd == 0) {
    if (dif.back().first <= a[v]) {
      for (auto u : ad[v])
        if (u != p) get(u, 0, v);
    }
    if (dif.back().first >= a[v]) {
      res.insert(v);
      if (dif.size() > 1 && dif[dif.size() - 2].first == dif.back().first) {
        for (auto pr : dif) {
          if (pr.first == dif.back().first)
            get(pr.second, 0, v), get(pr.second, 1, v);
          else
            get(pr.second, 0, v);
        }
      } else
        for (auto pr : dif)
          if (pr.first == dif.back().first)
            get(pr.second, 1, v);
          else
            get(pr.second, 0, v);
    }
  } else {
    long long f = s - dif.back().first;
    long long o = 1e18, t = 1e18;
    if (f <= min(o, t)) {
      if (dif.size() > 1 && dif[dif.size() - 2].first == dif.back().first) {
        for (auto pr : dif)
          if (pr.first == dif.back().first)
            get(pr.second, 0, v), get(pr.second, 1, v);
          else
            get(pr.second, 0, v);
      } else
        for (auto pr : dif)
          if (pr.first == dif.back().first)
            get(pr.second, 1, v);
          else
            get(pr.second, 0, v);
    }
    if (t <= min(o, f)) {
      res.insert(v);
      if (y.size() > 2 && y[y.size() - 3].first == y.back().first) {
        for (auto pr : y)
          if (pr.first == y.back().first)
            get(pr.second, 0, v), get(pr.second, 1, v);
          else
            get(pr.second, 0, v);
      } else
        for (auto pr : y)
          if (pr.first == y.back().first)
            get(pr.second, 1, v);
          else
            get(pr.second, 0, v);
    }
    if (o <= min(t, f)) {
      res.insert(v);
      if (x.size() > 1 && x[x.size() - 2].first == x.back().first) {
        for (auto pr : x)
          if (pr.first == x.back().first)
            get(pr.second, 0, v), get(pr.second, 1, v);
          else
            get(pr.second, 0, v);
      } else
        for (auto pr : x)
          if (pr.first == x.back().first)
            get(pr.second, 1, v);
          else
            get(pr.second, 0, v);
      if (y.size() > 1 && y[y.size() - 2].first == y.back().first) {
        for (auto pr : y)
          if (pr.first == y.back().first)
            get(pr.second, 0, v), get(pr.second, 1, v);
          else
            get(pr.second, 0, v);
      } else
        for (auto pr : y)
          if (pr.first == y.back().first)
            get(pr.second, 1, v);
          else
            get(pr.second, 0, v);
    }
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i < n; i++) {
    long long v, u;
    cin >> v >> u;
    ad[v].push_back(u);
    ad[u].push_back(v);
  }
  solve(1, 0);
  get(1, 0, 0);
  long long sm = 0;
  cout << dp[1][0] << " " << res.size() << '\n';
  for (auto v : res) {
    cout << v << ' ';
    sm += a[v];
  }
}
