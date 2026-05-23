#include <bits/stdc++.h>
using namespace std;
int vis[200009];
int main() {
  int n, m;
  cin >> n >> m;
  int i;
  long long l[n], r[n];
  for (i = 0; i < n; ++i) cin >> l[i] >> r[i];
  vector<pair<pair<long long, long long>, int> > diff;
  for (i = 0; i < n - 1; ++i) {
    diff.push_back(make_pair(make_pair(r[i + 1] - l[i], l[i + 1] - r[i]), i));
  }
  set<pair<long long, long long> > bridge;
  for (i = 0; i < m; ++i) {
    long long x;
    cin >> x;
    bridge.insert({x, i + 1});
  }
  vector<int> ans(n);
  if (m < n - 1) {
    cout << "No";
    return 0;
  }
  sort(diff.begin(), diff.end());
  for (auto p : diff) {
    long long le = p.first.first, ri = p.first.second, x = p.second;
    auto it = bridge.upper_bound(make_pair(ri, -1));
    if (it == bridge.end() || it->first > le) {
      cout << "No";
      return 0;
    }
    ans[x] = it->second;
    bridge.erase(it);
  }
  cout << "Yes\n";
  for (int i = 0; i < n - 1; ++i) cout << ans[i] << " ";
  return 0;
}
