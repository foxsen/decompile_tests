#include <bits/stdc++.h>
using namespace std;
const int ms = 100 + 10;
long long dp[ms][ms], sum[ms];
pair<long long, long long> a[ms], b[ms];
int n, re[ms];
bool cmp(const pair<long long, long long>& l,
         const pair<long long, long long>& r) {
  return l.first < r.first || (l.first == r.first && l.second > r.second);
}
bool check(long long x) {
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; ++i) {
    sum[i] = a[i].first - x * a[i].second;
  }
  sum[n] = 0;
  for (int i = n - 1; i >= 0; --i) sum[i] += sum[i + 1];
  for (int i = n - 1; i >= 0; --i) {
    int r = re[i], k = (r - i + 1);
    for (int j = 0; j < n; ++j) dp[i][j] = dp[i + 1][j];
    for (int j = 0; 2 * j + k < n - r; ++j) {
      dp[i][j + k] = max(dp[i][j + k], dp[r + 1][j] + sum[i] - sum[r + 1]);
    }
  }
  return sum[0] - *max_element(dp[0], dp[0] + n) <= 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i].first, a[i].first *= 1000;
  for (int i = 0; i < n; ++i) cin >> a[i].second;
  sort(a, a + n, cmp);
  for (int i = n - 1; i >= 0; --i) {
    if (a[i].first == a[i + 1].first)
      re[i] = re[i + 1];
    else
      re[i] = i;
  }
  long long l = 0, r = a[n - 1].first, mid, res = 0;
  while (l <= r) {
    mid = (l + r) / 2;
    if (check(mid)) {
      res = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << res;
  return 0;
}
