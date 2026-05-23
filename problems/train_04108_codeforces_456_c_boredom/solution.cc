#include <bits/stdc++.h>
using namespace std;
long long a[200000];
long long dp[200000][2];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    a[x]++;
  }
  long long ans = 0;
  for (long long i = 1; i <= 1e5; i++) {
    dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + i * a[i]);
    dp[i][0] = dp[i - 1][1];
    ans = max(max(dp[i][1], dp[i][0]), ans);
  }
  cout << ans;
}
