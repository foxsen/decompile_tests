#include <bits/stdc++.h>
using namespace std;
int sum[200006];
int main() {
  int ans = 0, n, x;
  cin >> n;
  sum[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (i % 2 == 1)
      sum[i] = sum[i - 1] + x;
    else
      sum[i] = sum[i - 1] - x;
  }
  for (int i = 1; i <= n; i++) {
    if (-(sum[n] - sum[i]) + sum[i - 1] == 0) ans++;
  }
  cout << ans << "\n";
  return 0;
}
