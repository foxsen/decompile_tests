#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  pair<long long, long long> prefix[n], suffix[n];
  prefix[0] = make_pair(0, v[0]);
  suffix[n - 1] = make_pair(0, v[n - 1]);
  for (long long i = 1; i < n; i++) {
    if (v[i] > prefix[i - 1].second) {
      prefix[i] = make_pair(prefix[i - 1].first, v[i]);
    } else {
      prefix[i] =
          make_pair(prefix[i - 1].second + 1 - v[i] + prefix[i - 1].first,
                    prefix[i - 1].second + 1);
    }
  }
  for (long long i = n - 2; i >= 0; i--) {
    if (v[i] > suffix[i + 1].second) {
      suffix[i] = make_pair(suffix[i + 1].first, v[i]);
    } else {
      suffix[i] =
          make_pair(suffix[i + 1].second + 1 - v[i] + suffix[i + 1].first,
                    suffix[i + 1].second + 1);
    }
  }
  long long ans = 1e18;
  for (long long i = 0; i < n; i++) {
    ans = min(ans, prefix[i].first + suffix[i].first +
                       abs(prefix[i].second - suffix[i].second) -
                       (max(prefix[i].second, suffix[i].second) - v[i]));
  }
  cout << ans << endl;
  return 0;
}
