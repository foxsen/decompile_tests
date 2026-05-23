#include <bits/stdc++.h>
using namespace std;
const int nn = 2e5 + 5;
long long pre[nn];
int main() {
  long long n, k, tot = 0;
  vector<int> v;
  scanf("%lld %lld", &n, &k);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    tot += x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  for (int i = n - 1; i >= 0; i--) {
    pre[i] = pre[i + 1] + v[i];
  }
  long long val = 0, ans = 0;
  while (val < tot - (v[0] * n)) {
    int l = 1, r = v.back(), h;
    while (l <= r) {
      int mid = (l + r) >> 1;
      int idx = upper_bound(v.begin(), v.end(), mid) - v.begin();
      if (pre[idx] - (mid * (n - idx)) - val <= k) {
        h = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    int idx = upper_bound(v.begin(), v.end(), h) - v.begin();
    val = (pre[idx] - (h * (n - idx)));
    ans++;
  }
  printf("%lld\n", ans);
}
