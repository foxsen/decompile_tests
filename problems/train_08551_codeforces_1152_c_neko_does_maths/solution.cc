#include <bits/stdc++.h>
using namespace std;
const int MXN = (int)1e6 + 7;
long long gcd(long long v1, long long v2) {
  while (v1) {
    long long tmp = v2 % v1;
    v2 = v1;
    v1 = tmp;
  }
  return v2;
}
int main() {
  long long a, b;
  scanf("%lld %lld", &a, &b);
  if (a > b) swap(a, b);
  if (a == b) {
    puts("0");
    return 0;
  }
  long long c = b - a;
  long long h = sqrt(c);
  pair<long long, long long> mn = {a * b / gcd(a, b), 0LL};
  for (int i = 1; i <= h; i++) {
    if (c % i) continue;
    long long v1 = i, v2 = c / i;
    long long k1 = (v1 - a % v1) % v1;
    long long k2 = (v2 - b % v2) % v2;
    mn = min(mn, {(a + k1) * (b + k1) / gcd(a + k1, b + k1), k1});
    mn = min(mn, {(a + k2) * (b + k2) / gcd(a + k2, b + k2), k2});
  }
  printf("%lld\n", mn.second);
  return 0;
}
