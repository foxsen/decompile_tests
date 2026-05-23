#include <bits/stdc++.h>
using namespace std;
template <class T>
constexpr T inf = numeric_limits<T>::max() / 2;
long long calc(long long border, const vector<int> &h,
               const vector<long long> &acc, const vector<long long> &acc_rev,
               int a, int r, int m) {
  int n = h.size();
  if (border > h[n - 1] || border < h[0]) return inf<long long>;
  int pos = -1;
  for (int i = 0; (i) < (int)(n); (i)++) {
    if (h[i] <= border && (i == n - 1 || h[i + 1] > border)) {
      pos = i;
      break;
    }
  }
  assert(pos != -1);
  long long x = border * (pos + 1) - acc[pos];
  long long y = (pos == n - 1 ? 0 : acc_rev[pos + 1] - border * (n - pos - 1));
  if (y >= x) {
    return (long long)(y - x) * r + (long long)x * m;
  } else {
    return (long long)(x - y) * a + (long long)y * m;
  }
}
int main() {
  int n, a, r, m;
  scanf("%d%d%d%d", &n, &a, &r, &m);
  m = min(m, a + r);
  vector<int> h(n);
  for (int i = 0; (i) < (int)(n); (i)++) {
    scanf("%d", &h[i]);
  }
  sort(h.begin(), h.end());
  vector<long long> acc(n), acc_rev(n);
  acc[0] = h[0];
  for (int i = 0; (i) < (int)(n); (i)++)
    if (i) acc[i] = acc[i - 1] + h[i];
  acc_rev[n - 1] = h[n - 1];
  for (int i = n - 2; i >= 0; i--) acc_rev[i] = acc_rev[i + 1] + h[i];
  long long lb = h[0], ub = h[n - 1] + 1;
  while (ub - lb > 3) {
    long long ml = (2 * lb + ub) / 3;
    long long mr = (lb + 2 * ub) / 3;
    long long cl = calc(ml, h, acc, acc_rev, a, r, m);
    long long cr = calc(mr, h, acc, acc_rev, a, r, m);
    if (cl < cr) {
      ub = mr;
    } else {
      lb = ml;
    }
  }
  long long ans = inf<long long>;
  for (int p = lb - 3; p <= lb + 10; p++) {
    ans = min(ans, calc(p, h, acc, acc_rev, a, r, m));
  }
  printf("%lld\n", ans);
  return 0;
}
