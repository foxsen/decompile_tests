#include <bits/stdc++.h>
using namespace std;
const int nit = 1 << 18;
int it[2 * nit];
int it_get(int l, int r) {
  l += nit, r += nit;
  int res = 0;
  while (l < r) {
    if (l % 2 == 1) res += it[l++];
    if (r % 2 == 0) res += it[r--];
    l /= 2;
    r /= 2;
  }
  if (l == r) res += it[l];
  return res;
}
long long test(int n, long long *a, long long x) {
  long long sum[n + 1];
  sum[0] = 0;
  for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + a[i];
  vector<pair<long long, int> > ss;
  for (int i = 0; i <= n; i++) ss.push_back(make_pair(sum[i], i));
  sort(ss.begin(), ss.end());
  int rp[n + 1];
  for (int i = 0; i <= n; i++) rp[ss[i].second] = i;
  for (int i = 0; i <= n; i++) it[nit + i] = 1;
  for (int i = nit - 1; i > 0; i--) it[i] = it[i * 2] + it[i * 2 + 1];
  long long res = 0;
  for (int i = 0; i < n; i++) {
    for (int k = rp[i] + nit; k >= 1; k /= 2) it[k]--;
    int mi = 0, ma = n + 1;
    while (mi < ma) {
      int av = (mi + ma) / 2;
      if (ss[av].first >= x + sum[i])
        ma = av;
      else
        mi = av + 1;
    }
    int bonus = it_get(mi, n);
    res += bonus;
  }
  return res;
}
int main() {
  int n;
  long long k;
  cin >> n >> k;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  long long mn = (long long)-1e15, mx = (long long)1e15;
  while (mn < mx) {
    long long av = (mn + mx + 1) / 2;
    long long cnt = test(n, a, av);
    if (cnt < k)
      mx = av - 1;
    else
      mn = av;
  }
  cout << mn << endl;
  return 0;
}
