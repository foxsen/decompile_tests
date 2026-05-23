#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 20;
const long double inf = 1e18;
long double dp[maxn][2];
pair<pair<long long, long long>, pair<long long, long double> > a[maxn];
bool cmp(pair<pair<long long, long long>, pair<long long, long double> > a,
         pair<pair<long long, long long>, pair<long long, long double> > b) {
  return a.second.first > b.second.first;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i].first.first >> a[i].first.second >> a[i].second.first >>
        a[i].second.second;
  sort(a, a + n, cmp);
  cout << fixed << setprecision(6);
  dp[0][0] = 0;
  dp[0][1] = a[0].second.second;
  for (int i = 1; i < n; i++) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
    dp[i][1] = a[i].second.second;
    for (int j = i - 1; j > -1; j--)
      if ((a[j].first.first - a[i].first.first) *
                  (a[j].first.first - a[i].first.first) +
              (a[j].first.second - a[i].first.second) *
                  (a[j].first.second - a[i].first.second) <=
          (a[j].second.first - a[i].second.first) *
              (a[j].second.first - a[i].second.first))
        dp[i][1] = max(dp[i][1], dp[j][1] + a[i].second.second);
  }
  cout << max(dp[n - 1][0], dp[n - 1][1]);
}
