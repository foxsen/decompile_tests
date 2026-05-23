#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    double s = 0, s1;
    for (long long i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (long long i = 0; i < n - 1; i++) s += a[i];
    s1 = (s / (n - 1)) + a[n - 1];
    printf("%0.9lf\n", s1);
  }
  return 0;
}
