#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k, z;
    cin >> n >> k >> z;
    long long a[n + 7];
    for (int i = 0; i < n; i++) cin >> a[i];
    long long ans = 0;
    for (int i = 0; i <= (z); i++) {
      long long r = (k - (2 * i)), sum = 0, mx = 0;
      for (long long j = 0; j <= r; j++) {
        sum += a[j];
        mx = max(mx, a[j] + a[j + 1]);
      }
      ans = max(ans, sum + (mx * i));
    }
    cout << ans << '\n';
  }
  return 0;
}
