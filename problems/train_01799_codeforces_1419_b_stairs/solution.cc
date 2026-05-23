#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  long long int dp[35];
  dp[0] = 1;
  for (int i = 1; i < 35; i++) dp[i] = 2 * dp[i - 1] + 1;
  long long int cells[35];
  for (int i = 0; i < 35; i++) cells[i] = dp[i] * (dp[i] + 1) / 2;
  for (int i = 1; i < 35; i++) cells[i] += cells[i - 1];
  while (t--) {
    long long int x;
    cin >> x;
    int ans = 0;
    for (int i = 0; i < 35; i++) {
      if (cells[i] > x) {
        ans = i;
        break;
      }
    }
    cout << ans << endl;
  }
}
