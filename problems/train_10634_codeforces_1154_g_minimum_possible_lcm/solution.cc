#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000003;
long long n, m, m1, x, y, ansx, ansy;
long long a[maxn];
vector<long long> v[maxn * 10];
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
int main() {
  m = 0;
  m1 = 1e18;
  scanf("%lld", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
    v[a[i]].emplace_back(i);
    m = max(m, a[i]);
  }
  for (long long i = 1; i <= m; ++i) {
    x = y = -1;
    for (long long j = i; j <= m; j += i) {
      int sz = v[j].size();
      if (x == -1 && sz) {
        x = v[j][0];
        if (sz > 1) y = v[j][1];
      } else if (y == -1 && sz)
        y = v[j][0];
      if (x != -1 && y != -1) break;
    }
    if (x != -1 && y != -1) {
      long long d = gcd(a[x], a[y]);
      if (d != i) continue;
      long long t = a[x] * a[y] / d;
      if (t < m1) {
        m1 = t;
        ansx = x;
        ansy = y;
      }
    }
  }
  if (ansx > ansy) swap(ansx, ansy);
  printf("%lld %lld\n", ansx, ansy);
  return 0;
}
