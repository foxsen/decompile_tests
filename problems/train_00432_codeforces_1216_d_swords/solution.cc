#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long z) {
  long long ret = 1;
  while (y > 0) {
    if (y & 1) ret = (ret * x) % z;
    x = (x * x) % z;
    y >>= 1;
  }
  return ret;
}
const long long N = 2e5 + 5;
long long A[N];
long long __gcd(long long a, long long b) {
  if (!b) return a;
  return __gcd(b, a % b);
}
int main() {
  long long n;
  scanf("%lld", &n);
  for (long long i = 1; i <= n; ++i) scanf("%lld", &A[i]);
  sort(A + 1, A + 1 + n);
  long long x = A[1], y = 0, z = 0, sum = A[1];
  for (long long i = 2; i <= n; ++i) {
    if (A[i] != A[i - 1]) {
      z = __gcd(z, A[i] - A[i - 1]);
    }
    x = max(x, A[i]);
    sum += A[i];
  }
  long long l1 = sum % z, l2 = n % z;
  long long pz = z, tz = z;
  for (long long i = 2; i < N; ++i) {
    if (tz % i == 0) {
      while (tz % i == 0) tz /= i;
      pz -= pz / i;
    }
  }
  if (tz > 1) pz -= pz / tz;
  long long l3 = power(l2, pz - 1, z);
  l3 = (l3 * l1) % z;
  long long lo = 1, hi = 1e10, mid, tx = x;
  while (lo <= hi) {
    mid = (lo + hi) >> 1;
    if ((l3 + z * mid) >= tx)
      hi = mid - 1, x = (l3 + z * mid);
    else
      lo = mid + 1;
  }
  long long ts = n * x - sum;
  y = (n * x - sum) / z;
  if (__gcd(l2, z) != 1) y = (n * tx - sum) / z;
  printf("%lld %lld\n", y, z);
  return 0;
}
