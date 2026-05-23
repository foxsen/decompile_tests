#include <bits/stdc++.h>
using namespace std;
int dp[100005], ans[100005];
void solve(int num) {
  if (dp[num] != -1) return;
  ans[num] = -1;
  dp[num] = 0;
  int i, n = 2, a, sum;
  set<int> myset;
  myset.clear();
  while (2 * num - n * (n - 1) > 0) {
    if ((2 * num - n * (n - 1)) % (2 * n) == 0) {
      a = (2 * num - n * (n - 1)) / (2 * n);
      for (i = a, sum = 0; i <= a + n - 1; i++) {
        solve(i);
        sum ^= dp[i];
      }
      if (sum == 0 && ans[num] == -1) ans[num] = n;
      myset.insert(sum);
    }
    n++;
  }
  while (myset.count(dp[num])) dp[num]++;
  return;
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    memset(dp, -1, sizeof(dp));
    solve(n);
    printf("%d\n", ans[n]);
  }
  return 0;
}
