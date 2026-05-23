#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 6, nBits = 2e8 + 5, M = (1 << 16), MAX = 1111,
          OO = 0x3f3f3f3f, MOD = 1e9 + 7, inf = 1 << 30;
const long long INF = (long long)1e18;
long long GCD(long long a, long long b) { return !b ? a : GCD(b, a % b); }
long long LCM(long long x, long long y) { return (x * y / GCD(x, y)); }
long long fact(long long z) { return (z <= 1) ? 1 : z * fact(z - 1); }
int n, k, x, A[N], freq[111], ans, last;
bool f;
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", A + i);
  while (A[0] < k) {
    ++ans;
    last = k;
    for (int i = n - 1; ~i; --i)
      if (A[i] != last) last = A[i]++;
  }
  printf("%d\n", ans);
  return 0;
}
