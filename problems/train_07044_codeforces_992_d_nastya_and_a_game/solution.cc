#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10;
long long aft[N], a[N];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, k;
  cin >> n >> k;
  long long ans = 0;
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  aft[n + 1] = n + 1;
  aft[n] = n;
  for (long long i = n - 1; i >= 1; --i) {
    if (a[i] > 1)
      aft[i] = i;
    else
      aft[i] = aft[i + 1];
  }
  long long sum;
  long long mul;
  long long pre, suf;
  for (long long i = 1; i <= n; ++i) {
    sum = 0;
    mul = 1;
    suf = i;
    pre = i - 1;
    while (suf <= n) {
      sum += a[suf];
      if ((long long)2e18 / a[suf] < mul) break;
      mul *= a[suf];
      pre = suf;
      suf = aft[suf + 1];
      if (mul % k == 0 && mul / k >= sum && mul / k <= sum + suf - pre - 1)
        ++ans;
      sum += suf - pre - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
