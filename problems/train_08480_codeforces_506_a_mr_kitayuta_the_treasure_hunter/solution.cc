#include <bits/stdc++.h>
using namespace std;
template <class T>
void chmin(T& a, const T& b) {
  if (a > b) a = b;
}
template <class T>
void chmax(T& a, const T& b) {
  if (a < b) a = b;
}
int n, d;
const int geta = 260;
const int MX = 30000;
int dp[30010][520];
int cnt[30010];
int main() {
  scanf("%d %d", &n, &d);
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    cnt[k]++;
  }
  memset(dp, -1, sizeof(dp));
  dp[d][geta] = cnt[d];
  int ans = 0;
  for (int i = d; i <= MX; i++) {
    for (int j = 0; j < 520; j++) {
      if (dp[i][j] == -1) continue;
      chmax(ans, dp[i][j]);
      int len = d + (j - geta);
      if (len > 1 && i + len - 1 <= MX)
        chmax(dp[i + len - 1][j - 1], dp[i][j] + cnt[i + len - 1]);
      if (i + len <= MX) chmax(dp[i + len][j], dp[i][j] + cnt[i + len]);
      if (i + len + 1 <= MX)
        chmax(dp[i + len + 1][j + 1], dp[i][j] + cnt[i + len + 1]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
