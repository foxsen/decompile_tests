#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y) {
  long long int res = 1;
  while (y) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y / 2, x = (x * x) % 1000000007;
  }
  return res % 1000000007;
}
long long int dp[65][65];
long long int m, k;
long long int func(long long int val) {
  long long int temp = k;
  long long int i;
  long long int ans = (__builtin_popcountll(val) == k);
  for (i = 63; i >= 0; i--) {
    if ((val & (1LL << i)) != 0) {
      ans = ans + dp[i][temp];
      temp--;
    }
    if (temp < 0) break;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> m >> k;
  long long int i, j;
  for (i = 0; i < 65; i++) {
    for (j = 0; j < 65; j++) {
      if (j > i)
        dp[i][j] = 0;
      else if (i == 0 or j == 0)
        dp[i][j] = 1;
      else
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
    }
  }
  long long int low = 1, high = 1e18;
  long long int ans;
  while (low <= high) {
    long long int mid = (low + high) / 2;
    long long int p = func(mid);
    long long int pp = func(2 * mid);
    if (pp - p == m) {
      ans = mid;
      high = mid - 1;
    } else if (pp - p > m) {
      high = mid - 1;
    } else
      low = mid + 1;
  }
  cout << ans;
}
