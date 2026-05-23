#include <bits/stdc++.h>
using namespace std;
bool ispow(long long n) { return (n & (n - 1)) == 0; }
const int mod = 1e9 + 7;
int a[300005];
int dp[300005];
int s1[300005], s2[300005];
int cnt1 = 0, cnt2 = 0;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) dp[i] = 1e8;
  s1[++cnt1] = 1;
  s2[++cnt2] = 1;
  dp[1] = 0;
  for (int i = 2; i <= n; i++) {
    while (cnt1 > 0 && a[s1[cnt1]] < a[i]) {
      dp[i] = min(dp[i], dp[s1[cnt1]] + 1);
      cnt1--;
    }
    if (cnt1 > 0) {
      dp[i] = min(dp[i], dp[s1[cnt1]] + 1);
      if (a[s1[cnt1]] == a[i]) cnt1--;
    }
    s1[++cnt1] = i;
    while (cnt2 > 0 && a[s2[cnt2]] > a[i]) {
      dp[i] = min(dp[i], dp[s2[cnt2]] + 1);
      cnt2--;
    }
    if (cnt2 > 0) {
      dp[i] = min(dp[i], dp[s2[cnt2]] + 1);
      if (a[s2[cnt2]] == a[i]) cnt2--;
    }
    s2[++cnt2] = i;
  }
  cout << dp[n];
  return 0;
}
