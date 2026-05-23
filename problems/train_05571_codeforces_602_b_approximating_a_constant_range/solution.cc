#include <bits/stdc++.h>
#pragma GCC optimize("O3")
const int N = 100000 + 5;
const int OO = 1e9;
const long long MOD = 1000000007;
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  int a[n + 5];
  for (long long i = 0; i < n; i++) cin >> a[i];
  int ans = 0;
  for (long long i = 0; i < n; i++) {
    int mx = a[i], mn = a[i], cnt = 0;
    for (long long j = i + 1; j < n; j++) {
      mx = max(mx, a[j]);
      mn = min(mn, a[j]);
      if (mx - mn > 1) break;
      cnt++;
    }
    ans = max(ans, cnt + 1);
    if (n - i <= ans) break;
  }
  cout << ans << '\n';
  return 0;
}
