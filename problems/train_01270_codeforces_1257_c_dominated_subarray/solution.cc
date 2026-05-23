#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b > a) return gcd(b, a);
  return b == 0 ? a : gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    long long a[n + 1];
    for (long long i = 1; i < n + 1; i++) cin >> a[i];
    map<long long, long long> count;
    long long ans = n;
    long long d = 0;
    for (long long i = 1; i < n + 1; i++) {
      if (count[a[i]]) {
        ans = min(ans, i - count[a[i]] + 1);
        d = 1;
      }
      count[a[i]] = i;
    }
    if (ans == 1 || d == 0) {
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
  return 0;
}
