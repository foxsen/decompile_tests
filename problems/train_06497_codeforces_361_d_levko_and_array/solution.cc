#include <bits/stdc++.h>
using namespace std;
const int M = 2e3 + 20;
long long mid, en, st, dp[M][3], y, maxx, a[M], n, k;
bool check(long long x) {
  for (int i = 0; i < n; i++) {
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
    dp[i][0] = i;
    for (int j = i - 1; j >= 0; j--) {
      if ((i - j) * x >= abs(a[i] - a[j])) {
        dp[i][0] = min(dp[i][0], dp[j][0] + i - j - 1);
      }
    }
  }
  int y = min(dp[n - 1][0], dp[n - 1][1]);
  if (y <= k)
    return true;
  else
    return false;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    maxx = max(maxx, abs(a[i] - a[i + 1]));
  }
  st = 0;
  en = maxx;
  while (en - st > 1) {
    mid = (long long)(en + st) / 2;
    if (check(mid)) {
      en = mid;
    } else {
      st = mid;
    }
  }
  if (check(st))
    cout << st;
  else
    cout << en;
}
