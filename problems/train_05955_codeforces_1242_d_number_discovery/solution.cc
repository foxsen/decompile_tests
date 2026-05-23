#include <bits/stdc++.h>
using namespace std;
const long long M = 1e7 + 19;
long long h[M], g[M];
vector<int> buc;
int gethash(long long a) {
  int x = a % M;
  while (h[x] && h[x] != a) x = (x + 1) % M;
  return x;
}
long long n, k, T;
long long lim = 1000000;
long long f(long long n) {
  if (n < k * (k + 1) / 2) return 0;
  int k1 = gethash(n);
  if (h[k1]) return g[k1];
  h[k1] = n;
  buc.push_back(k1);
  long long n1 = n - k * (k + 1) / 2, q = n1 % k;
  long long x1 = n1 / k + k + (q != 0), x2 = q ? x1 - q : x1 - k;
  if (q == 0) {
    long long z = f(x1);
    return g[k1] = (x1 - z) / k;
  } else {
    long long z1 = f(x1), z2 = f(x2 - 1);
    long long ans = (x1 - z1) / k;
    if (z1 == z2 && (x1 - z1) % k == 0) ans--;
    return g[k1] = ans;
  }
}
int main() {
  scanf("%lld", &T);
  for (; T--;) {
    scanf("%lld%lld", &n, &k);
    while (buc.size()) h[buc.back()] = g[buc.back()] = 0, buc.pop_back();
    if (f(n) > f(n - 1)) {
      printf("%lld\n", (k + 1) * f(n));
      continue;
    } else {
      long long n1 = n - f(n), ans = n1 / k * (k + 1);
      if (n1 % k == 0)
        ans--;
      else
        ans += n1 % k;
      printf("%lld\n", ans);
    }
  }
}
