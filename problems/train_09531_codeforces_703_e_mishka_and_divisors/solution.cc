#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005, MAXD = 1e4 + 10;
int n, dp[MAXN][MAXD];
long long sum[MAXN][MAXD];
vector<long long> d, p;
long long k, a[MAXN];
int prv[MAXN][MAXD];
long long GCD(long long a, long long b) { return !a ? b : GCD(b % a, a); }
int getind(long long val) {
  return lower_bound(d.begin(), d.end(), val) - d.begin();
}
int main() {
  cin >> n >> k;
  if (k == 1) {
    int ind = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] < a[ind]) ind = i;
    }
    cout << 1 << '\n' << ind + 1;
    return 0;
  }
  for (long long i = 1; i * i <= k; i++) {
    if (k % i == 0) {
      d.push_back(i);
      if (k / i != i) d.push_back(k / i);
    }
  }
  long long tmp = k;
  for (long long i = 2; i * i <= tmp; i++) {
    if (tmp % i == 0) p.push_back(i);
    while (tmp % i == 0) tmp /= i;
  }
  if (tmp != 1) p.push_back(tmp);
  sort(d.begin(), d.end());
  fill_n(dp[0], MAXD, 1e9);
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    long long g = GCD(a[i], k);
    for (int j = 0; j < d.size(); j++)
      dp[i][j] = dp[i - 1][j], sum[i][j] = sum[i - 1][j];
    for (int j = 0; j < d.size(); j++) {
      int t = getind(GCD(k / g, d[j]) * g);
      if (dp[i][t] > dp[i - 1][j] + 1)
        prv[i][t] = j + 1, dp[i][t] = dp[i - 1][j] + 1,
        sum[i][t] = sum[i - 1][j] + a[i];
      if (dp[i][t] == dp[i - 1][j] + 1 && sum[i - 1][j] + a[i] < sum[i][t])
        prv[i][t] = j + 1, sum[i][t] = sum[i - 1][j] + a[i];
    }
  }
  if (dp[n][d.size() - 1] == 1e9)
    cout << -1;
  else {
    cout << dp[n][d.size() - 1] << '\n';
    int t = d.size() - 1, lv = n;
    while (lv != 0) {
      if (prv[lv][t] > 0) cout << lv << ' ', t = prv[lv][t] - 1;
      lv--;
    }
  }
}
