#include <bits/stdc++.h>
using namespace std;
int arr[300105];
int _next[300105];
map<int, int> mp[300105];
int dp[300105];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      _next[i] = -1;
      mp[i].clear();
      dp[i] = 0;
    }
    dp[n] = 0;
    mp[n].clear();
    mp[n - 1][arr[n - 1]] = n - 1;
    for (int i = n - 1; i >= 0; i--) {
      if (mp[i + 1].count(arr[i])) {
        _next[i] = mp[i + 1][arr[i]];
        swap(mp[i], mp[_next[i] + 1]);
        if (_next[i] < n - 1) {
          mp[i][arr[_next[i] + 1]] = _next[i] + 1;
        }
      }
      mp[i][arr[i]] = i;
    }
    long long ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (_next[i] == -1) continue;
      dp[i] = dp[_next[i] + 1] + 1;
    }
    for (int i = 0; i < n; i++) {
      ans += dp[i];
    }
    cout << ans << '\n';
  }
}
