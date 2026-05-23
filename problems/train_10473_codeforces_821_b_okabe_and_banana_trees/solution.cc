#include <bits/stdc++.h>
using namespace std;
long long qq(long long x, long long y) {
  long long a1 = y * (y + 1) / 2;
  a1 = a1 * (x + 1);
  long long a2 = (y + 1) * (x + 1) * x / 2;
  return a1 + a2;
}
int main() {
  long long a, b;
  scanf("%lld%lld", &a, &b);
  long long ans = 0;
  for (long long i = 0; i <= b * a; i++) {
    long long ans1 = qq(i, -(i / a) + b - (i % a == 0 ? 0 : 1));
    ans = (ans > ans1) ? ans : ans1;
  }
  printf("%lld\n", ans);
  return 0;
}
