#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long ar[300001];
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  sort(ar, ar + n);
  long long dp[300001];
  int was = 1;
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] + abs(i - ar[i - 1]);
    was++;
  }
  cout << dp[n];
  return 0;
}
