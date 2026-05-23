#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long n, k;
long long a[N];
long long check(long long sz) {
  multiset<long long> s;
  for (long long i = 1; i <= n; i++) s.insert(a[i]);
  long long cnt = 0;
  while (s.size()) {
    cnt++;
    long long elem = *(--s.end());
    if (elem > sz) return 0;
    s.erase(--s.end());
    auto it = s.upper_bound(sz - elem);
    if (it != s.begin()) {
      s.erase(--it);
    }
  }
  return cnt <= k;
}
long long binsearch(long long lo, long long hi) {
  while (lo < hi) {
    long long mid = (lo + hi) / 2;
    if (check(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  return lo;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  long long ans = binsearch(1, 2e6);
  cout << ans;
  return 0;
}
