#include <bits/stdc++.h>
using namespace std;
int n;
long long a[3][100011], sum[3][100011];
void solve() {
  cin >> n;
  for (int i = 1; i <= 2; i++)
    for (int j = 1; j <= n; j++) cin >> a[i][j], sum[i][j] = 0;
  sum[2][1] = a[2][1];
  sum[1][1] = a[1][1];
  for (int i = 2; i <= n; i++)
    sum[1][i] = sum[1][i - 1] + a[1][i], sum[2][i] = sum[2][i - 1] + a[2][i];
  long long ans = 1e18;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, max(sum[1][n] - sum[1][i], sum[2][i - 1]));
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
