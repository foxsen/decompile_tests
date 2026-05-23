#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int cas, n;
pair<long long, long long> a[maxn];
long long k;
bool chk(long long mid) {
  long long tmp = 0;
  int pos = n / 2 + 1;
  for (int i = 1; i <= n; i++) {
    if (a[i].second >= mid && pos) {
      tmp += max(mid, a[i].first);
      pos--;
    } else
      tmp += a[i].first;
  }
  return tmp <= k && !pos;
}
int main() {
  cin >> cas;
  while (cas--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + 1 + n, greater<pair<long long, long long> >{});
    long long l = 0, r = 1e9 + 1;
    while (l < r) {
      long long mid = l + r + 1 >> 1;
      if (chk(mid))
        l = mid;
      else
        r = mid - 1;
    }
    cout << l << endl;
  }
  return 0;
}
