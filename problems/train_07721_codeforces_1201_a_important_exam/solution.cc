#include <bits/stdc++.h>
using namespace std;
map<char, int> mp;
string s[1005];
int a[1005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> s[i];
  for (int i = 0; i < m; ++i) cin >> a[i];
  long long ans = 0;
  int mx = -1;
  for (int i = 0; i < m; ++i) {
    mx = -1;
    mp.clear();
    for (int j = 0; j < n; ++j) {
      ++mp[s[j][i]];
    }
    for (auto nx : mp)
      if (nx.second > mx) mx = nx.second;
    ans += a[i] * mx;
  }
  cout << ans;
  return 0;
}
