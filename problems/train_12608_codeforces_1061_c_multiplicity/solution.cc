#include <bits/stdc++.h>
using namespace std;
inline bool isvowel(char c) {
  c = tolower(c);
  if (c == 'a' || c == 'e' || c == 'i' || c == 'y' || c == 'o' || c == 'u')
    return 1;
  return 0;
}
const double eps = 0.000001;
const long double pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 7;
const long long MOD = 1e18 + 9;
const long long INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 6e5 + 123;
const int M = 22;
const int pri = 997;
const int Magic = 2101;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int n, m, k;
int a[N];
int dp[mxn];
int main() {
  cin >> n;
  dp[0] = 1;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    vector<int> v;
    for (int j = 1; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        v.push_back(j);
        if (a[i] / j != j) v.push_back(a[i] / j);
      }
    }
    sort(v.begin(), v.end());
    for (int i = (int)(v.size()) - 1; i >= 0; i--) {
      dp[v[i]] += dp[v[i] - 1];
      if (dp[v[i]] >= mod) dp[v[i]] -= mod;
    }
  }
  int ans = 0;
  for (int i = 1; i < mxn; i++) {
    ans += dp[i];
    if (ans >= mod) ans -= mod;
  }
  cout << ans;
  return 0;
}
