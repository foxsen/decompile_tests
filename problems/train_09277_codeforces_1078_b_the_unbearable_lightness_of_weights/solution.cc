#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e17 + 10;
const int N = 1e4 + 10;
const long long mod = 998244353;
map<string, int> ml;
int c[N], vis[N], a[N], t, n, m, x, y, k, dp[N][105];
char s[N];
int ex, ey, cnt;
long long dist[N];
vector<pair<int, int> > v;
map<int, int> mp;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  for (auto p : mp) v.push_back(p);
  if (v.size() == 2) return cout << n << endl, 0;
  dp[0][0] = 1;
  for (auto p : v) {
    int cost = p.first;
    int k = p.second;
    for (int i = N; i >= 0; i--)
      for (int j = 1; j <= n; j++)
        for (int t = 1; t <= k && t <= j && t * cost <= i; t++)
          dp[i][j] += dp[i - t * cost][j - t];
  }
  int ans = 1;
  for (auto p : v) {
    int cost = p.first;
    int k = p.second;
    for (int i = 1; i <= k; i++) {
      if (dp[i * cost][i] == 1) ans = max(ans, i);
    }
  }
  cout << ans << endl;
}
