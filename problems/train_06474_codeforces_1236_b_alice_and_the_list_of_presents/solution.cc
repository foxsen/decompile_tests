#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long qpow(long long a, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = ans * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return ans;
}
int main() {
  long long n, m;
  scanf("%lld%lld", &n, &m);
  printf("%lld", qpow(qpow(2, m) - 1, n));
  return 0;
}
