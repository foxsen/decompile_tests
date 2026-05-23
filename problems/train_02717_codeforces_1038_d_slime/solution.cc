#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n;
  cin >> n;
  vector<long long> val(n);
  for (long long i = 0; i < n; i++) cin >> val[i];
  sort(val.begin(), val.end());
  if (n == 1) {
    cout << val[0];
    return 0;
  }
  long long ans = val[0];
  for (long long i = 1; i < n - 1; i++)
    if (val[i] >= 0) ans -= val[i];
  ans = val.back() - ans;
  for (long long i = 1; i < n - 1; i++)
    if (val[i] < 0) ans -= val[i];
  cout << ans << endl;
}
