#include <bits/stdc++.h>
using namespace std;
long long n;
int m;
const int maxN = 4e5 + 20;
long long a[maxN];
long long p[maxN];
long long k;
long long fMin(long long x) {
  long long c = 0;
  for (int i = 1; i <= m; i++) {
    c += (a[i] / x);
  }
  return c;
}
long long fMax(long long x) {
  long long c = 0;
  for (int i = 1; i <= m; i++) {
    c += (a[i] + x - 1) / x;
  }
  return c;
}
long long sufMin[maxN];
void solve() {
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    cin >> p[i];
    a[i] = p[i] - p[i - 1];
  }
  a[m + 1] = n - p[m];
  m++;
  k += m;
  long long l = 1;
  long long r = *min_element(a + 1, a + m + 1) + 1;
  while (r - l > 1) {
    long long mid = (r + l) / 2;
    if (fMin(mid) >= k)
      l = mid;
    else
      r = mid;
  }
  long long X = l;
  l = 0;
  r = *max_element(a + 1, a + m + 1) + 1;
  while (r - l > 1) {
    long long mid = (r + l) / 2;
    if (fMax(mid) <= k)
      r = mid;
    else
      l = mid;
  }
  long long Y = r;
  vector<pair<long long, long long> > all;
  for (int i = 1; i <= m; i++) {
    if (a[i] / X >= (a[i] + Y - 1) / Y) continue;
    long long c1 = a[i] / X + 1;
    assert(a[i] / c1 < X);
    assert((a[i] + c1 - 2) / (c1 - 1) > Y);
    all.emplace_back((a[i] + c1 - 2) / (c1 - 1), a[i] / c1);
  }
  sort(all.begin(), all.end());
  sufMin[all.size()] = X;
  for (int i = (int)all.size() - 1; i >= 0; i--) {
    sufMin[i] = min(sufMin[i + 1], all[i].second);
  }
  long long best = 1e18;
  for (int cnt = 0; cnt <= all.size(); cnt++) {
    long long hi = (cnt == 0 ? Y : all[cnt - 1].first);
    long long lo = sufMin[cnt];
    best = min(best, hi - lo);
  }
  cout << best << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tst;
  cin >> tst;
  while (tst--) solve();
  return 0;
}
