#include <bits/stdc++.h>
using namespace std;
long long int n2(long long int num) {
  long long a = 1, sum = 0;
  while (a <= num) {
    sum += min(a, num - a + 1);
    if (a > num / 10) break;
    a *= 10;
  }
  return sum;
}
long long int n1(long long int l, long long int r) { return n2(r) - n2(l - 1); }
double dp[1010][1010];
int main() {
  int n;
  cin >> n;
  long long int x, y;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) dp[i][j] = 0;
  dp[1][0] = 1;
  for (int j = 1; j <= n; j++) {
    cin >> x >> y;
    double p = double(n1(x, y)) / double(y - x + 1);
    for (int i = 1; i <= j + 1; i++) {
      dp[i][j] = dp[i][j - 1] * (1 - p) + dp[i - 1][j - 1] * p;
    }
  }
  double r;
  cin >> r;
  int rel = ceil(r * n / 100);
  double ans = 0;
  for (int i = rel + 1; i <= n + 1; i++) {
    ans += dp[i][n];
  }
  cout << fixed << setprecision(9) << ans << endl;
}
