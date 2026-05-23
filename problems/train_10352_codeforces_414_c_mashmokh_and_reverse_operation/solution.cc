#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int a[2000005];
long long dp[22][2];
void solve1() {
  int cnt = 1;
  for (int i = 0; i < n; i++) {
    if (cnt == m) continue;
    for (int j = 0; j < m; j += cnt * 2) {
      vector<int> v1, v2;
      for (int k = j; k < j + cnt; k++) {
        v1.push_back(a[k]);
        v2.push_back(a[k + cnt]);
      }
      sort(v1.begin(), v1.end());
      sort(v2.begin(), v2.end());
      for (int p = 0; p < v1.size(); p++) {
        int x = v1[p];
        int it = lower_bound(v2.begin(), v2.end(), x) - v2.begin();
        if (it > 0) {
          dp[i + 1][0] += it;
        }
      }
      for (int p = 0; p < v2.size(); p++) {
        int x = v2[p];
        int it = lower_bound(v1.begin(), v1.end(), x) - v1.begin();
        if (it > 0) {
          dp[i + 1][1] += it;
        }
      }
    }
    cnt = cnt * 2;
  }
}
long long solve(int id) {
  for (int i = id; i >= 0; i--) swap(dp[i][0], dp[i][1]);
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    ans += dp[i][0];
  }
  return ans;
}
int main() {
  cin >> n;
  m = 1;
  for (int j = 0; j < n; j++) {
    m = m * 2;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &a[i]);
  }
  solve1();
  int q;
  cin >> q;
  while (q--) {
    int x;
    scanf("%d", &x);
    long long ans = solve(x);
    printf("%I64d\n", ans);
  }
}
