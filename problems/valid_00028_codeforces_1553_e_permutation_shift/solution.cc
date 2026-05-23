#include <bits/stdc++.h>
using namespace std;
bool check(long long k, long long m, vector<long long>& p) {
  long long n = p.size();
  vector<vector<long long> > ed(n);
  for (long long i = 0; i < n; ++i) {
    long long to = (p[i] + k) % n;
    ed[i].push_back(to);
    ed[to].push_back(i);
  }
  long long cmp = 0;
  vector<bool> visited(n);
  for (long long i = 0; i < n; ++i) {
    if (visited[i]) continue;
    queue<long long> q;
    q.push(i);
    visited[i] = true;
    cmp++;
    while (!q.empty()) {
      long long cur = q.front();
      q.pop();
      for (auto to : ed[cur]) {
        if (visited[to]) continue;
        visited[to] = true;
        q.push(to);
      }
    }
  }
  if (n - cmp <= m)
    return true;
  else
    return false;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> p(n);
  for (long long i = 0; i < n; ++i) {
    cin >> p[i];
    p[i]--;
  }
  vector<long long> cnt(n);
  for (long long i = 0; i < n; ++i) {
    if (p[i] > i)
      cnt[i + n - p[i]]++;
    else
      cnt[i - p[i]]++;
  }
  vector<long long> ans;
  for (long long k = 0; k < n; ++k) {
    if (cnt[k] >= n - 2 * m && check(k, m, p)) ans.push_back(k);
  }
  cout << ans.size() << " ";
  for (auto k : ans) cout << k << " ";
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tst;
  tst = 1;
  cin >> tst;
  while (tst--) {
    solve();
  }
  return 0;
}
