#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double EPS = 0.0000001;
const double PI = 3.141592653589793;
const int MAX_N = 100002;
const int MAX_VAL = 100002;
const long long LLINF = 99999999999999999LL;
int N, K;
int v[MAX_N], c[MAX_N];
long long dp[MAX_N][2], maxVal[MAX_N];
set<long long, int> mySet;
inline int double_cmp(double a, double b) {
  if (a - b < -EPS) return -1;
  if (a - b > EPS) return 1;
  return 0;
}
int main() {
  int Q;
  cin >> N >> Q;
  for (int i = 1; i <= N; ++i) cin >> v[i];
  for (int i = 1; i <= N; ++i) cin >> c[i];
  for (int q = 1; q <= Q; ++q) {
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= N; ++i) maxVal[i] = -LLINF;
    dp[1][0] = -LLINF;
    dp[1][1] = 1LL * v[1] * b;
    maxVal[c[1]] = dp[1][1];
    long long ans = dp[1][1], max1 = dp[1][1], c1 = c[1], max2 = -LLINF,
              c2 = -1;
    for (int i = 2; i <= N; ++i) {
      dp[i][0] = dp[i][1] = -LLINF;
      long long x = maxVal[c[i]];
      if (x != -LLINF) {
        x += 1LL * v[i] * a;
        dp[i][0] = x;
        if (x > maxVal[c[i]]) maxVal[c[i]] = x;
        if (x > max1) {
          if (c[i] != c1) {
            c2 = c1;
            max2 = max1;
            c1 = c[i];
            max1 = x;
          } else
            max1 = x;
        } else if (x > max2 && c[i] != c1) {
          c2 = c[i];
          max2 = x;
        }
      }
      x = 1LL * v[i] * b;
      if (c1 != c[i])
        x = max(x, x + max1);
      else
        x = max(x, x + max2);
      dp[i][1] = x;
      if (x > maxVal[c[i]]) maxVal[c[i]] = x;
      if (x > max1) {
        if (c[i] != c1) {
          c2 = c1;
          max2 = max1;
          c1 = c[i];
          max1 = x;
        } else
          max1 = x;
      } else if (x > max2 && c[i] != c1) {
        c2 = c[i];
        max2 = x;
      }
      ans = max(ans, dp[i][0]);
      ans = max(ans, dp[i][1]);
    }
    ans = max(ans, 0LL);
    cout << ans << "\n";
  }
  return 0;
}
