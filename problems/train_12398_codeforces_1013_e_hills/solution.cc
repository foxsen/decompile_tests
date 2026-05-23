#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
const int INF = 0x3f3f3f3f;
int dp[maxn][3];
int high[maxn];
int cal1(int i) {
  int ans = 0;
  if (high[i] <= high[i - 1]) ans += (high[i - 1] - high[i] + 1);
  if (high[i] <= high[i + 1]) ans += (high[i + 1] - high[i] + 1);
  return ans;
}
int cal2(int i) {
  int ans = 0;
  int tmp = high[i - 1];
  if (i >= 2 && high[i - 2] <= high[i - 1]) tmp = high[i - 2] - 1;
  if (high[i] <= tmp) ans += (tmp - high[i] + 1);
  if (high[i] <= high[i + 1]) ans += (high[i + 1] - high[i] + 1);
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &high[i]);
  high[0] = -INF;
  high[n + 1] = -INF;
  int m = ceil(n / 2.0);
  int a, b, c;
  memset(dp, INF, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= 1; j--) {
      a = dp[j][0];
      b = dp[j][1];
      c = dp[j][2];
      dp[j][0] = min(a, c);
      dp[j][1] = min(dp[j - 1][0] + cal1(i), dp[j - 1][2] + cal2(i));
      dp[j][2] = b;
    }
  }
  for (int i = 1; i <= m; i++)
    cout << min(min(dp[i][0], dp[i][1]), dp[i][2]) << " ";
  cout << endl;
  return 0;
}
