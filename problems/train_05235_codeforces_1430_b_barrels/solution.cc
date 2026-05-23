#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<long long>());
    long long sum = 0;
    for (long long i = 0; i < k; i++) sum += a[i];
    a[k] += sum;
    cout << a[k] - 0 << "\n";
  }
  return 0;
}
