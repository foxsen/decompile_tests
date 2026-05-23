#include <bits/stdc++.h>
using namespace std;
int pre[200005], dp[200005], n, a[200005], cnt[200005];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], cnt[a[i]]++;
  int ans = 0, pos, last = 1;
  for (int i = 1; i <= 200000; i++) {
    if (cnt[i] == 0) {
      last = i + 1;
      dp[i] = 0;
      pre[i] = i;
    }
    if (cnt[i] == 1) {
      pre[i] = last;
      dp[i] = dp[i - 1] + 1;
      if (dp[i] - dp[pre[i] - 1] > ans) ans = dp[i] - dp[pre[i] - 1], pos = i;
      last = i;
    }
    if (cnt[i] >= 2) {
      pre[i] = last;
      dp[i] = dp[i - 1] + cnt[i];
      if (dp[i] - dp[pre[i] - 1] > ans) ans = dp[i] - dp[pre[i] - 1], pos = i;
    }
  }
  if (ans <= 0) {
    puts("0");
    return 0;
  }
  cout << ans << '\n';
  for (int i = pre[pos]; i <= pos; i++) cout << i << " ", cnt[i]--;
  for (int i = pos; i >= pre[pos]; i--)
    while (cnt[i]) cout << i << " ", cnt[i]--;
}
