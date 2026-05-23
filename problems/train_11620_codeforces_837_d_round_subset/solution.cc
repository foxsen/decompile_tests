#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
const long long MAX = INT_MAX;
const long long inf = 1e18 + 5;
const double pi = 3.14159265358979323846;
long long dirX[] = {1, -1, 0, 0};
long long dirY[] = {0, 0, 1, -1};
using namespace std;
int32_t main() {
  long long n;
  cin >> n;
  long long k;
  cin >> k;
  long long A[n];
  long long pow2[n];
  long long pow5[n];
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> A[i];
    long long count = 0;
    long long temp = A[i];
    while (temp % 2 == 0) {
      temp /= 2;
      count++;
    }
    pow2[i] = count;
    temp = A[i];
    count = 0;
    while (temp % 5 == 0) {
      temp /= 5;
      count++;
    }
    pow5[i] = count;
    sum += count;
  }
  long long dp[k + 1][sum + 1];
  for (long long j = 0; j <= k; j++)
    for (long long ki = 0; ki <= sum; ki++) dp[j][ki] = -1;
  dp[0][0] = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = k - 1; j >= 0; j--) {
      for (long long ki = 0; ki <= sum; ki++) {
        if (dp[j][ki] >= 0) {
          dp[j + 1][ki + pow5[i]] =
              max(dp[j][ki] + pow2[i], dp[j + 1][ki + pow5[i]]);
        }
      }
    }
  }
  long long ans = 0;
  for (long long i = 0; i <= sum; i++) {
    ans = max(ans, min(i, dp[k][i]));
  }
  cout << ans << "\n";
  return 0;
}
