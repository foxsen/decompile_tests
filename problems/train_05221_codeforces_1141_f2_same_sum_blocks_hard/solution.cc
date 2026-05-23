#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
using namespace std;
int solve() {
  map<int, vector<pair<long long, long long> > > m;
  int n;
  cin >> n;
  vector<long long> a(n + 1);
  for (int i = 1; i < n + 1; i++) cin >> a[i];
  for (int i = 1; i < n + 1; i++) {
    int sum = 0;
    for (int j = i; j >= 1; j--) {
      sum += a[j];
      if (m[sum].empty() || m[sum].back().second < j) {
        m[sum].push_back(make_pair(j, i));
      }
    }
  }
  vector<pair<long long, long long> > ans;
  for (auto it : m) {
    if (it.second.size() > ans.size()) ans = it.second;
  }
  cout << ans.size() << '\n';
  for (auto& x : ans) cout << x.first << " " << x.second << '\n';
  return 0;
}
int main() {
  int t = 1;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  clock_t time_req;
  time_req = clock();
  while (t--) {
    solve();
  }
  time_req = clock() - time_req;
  return 0;
}
