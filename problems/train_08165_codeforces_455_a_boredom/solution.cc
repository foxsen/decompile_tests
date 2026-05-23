#include <bits/stdc++.h>
using namespace std;
long long int cnt[100005] = {0}, n, dp[100005] = {0}, Ti = 0, t;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t;
    cnt[t]++;
    Ti = max(t, Ti);
  }
  dp[1] = cnt[1];
  for (int i = 2; i <= Ti; i++) {
    dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);
  }
  cout << dp[Ti] << endl;
  return 0;
}
