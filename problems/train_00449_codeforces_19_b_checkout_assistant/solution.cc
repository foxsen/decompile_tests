#include <bits/stdc++.h>
using namespace std;
const long long INFL = 1152921504606846976ll;
int n;
int t[(1 << 11)], c[(1 << 11)];
long long dp[(1 << 11)];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    dp[i] = INFL;
  }
  dp[0] = 0ll;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &t[i], &c[i]);
    for (int j = n - 1; j >= 0; j--) {
      int tmp;
      if (j + t[i] + 1 > n) {
        tmp = n;
      } else {
        tmp = j + t[i] + 1;
      }
      dp[tmp] = (long long)min((long long)dp[tmp],
                               (long long)dp[j] + (long long)c[i]);
    }
  }
  printf("%I64d\n", dp[n]);
  return 0;
}
