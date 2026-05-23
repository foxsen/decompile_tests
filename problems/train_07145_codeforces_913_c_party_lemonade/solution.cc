#include <bits/stdc++.h>
using namespace std;
unsigned long long dp[40];
unsigned long long N, L, i, C = 0;
int main() {
  cin >> N >> L >> dp[0];
  for (i = 1; i < N; i++) {
    cin >> dp[i];
    dp[i] = min(dp[i], 2 * dp[i - 1]);
  }
  for (; i < 32; i++) {
    dp[i] = 2 * dp[i - 1];
  }
  for (i = 0; L || i < N; i++) {
    C = min(C, dp[i]);
    if (L & 1) C += dp[i];
    L >>= 1;
  }
  cout << C;
  return 0;
}
