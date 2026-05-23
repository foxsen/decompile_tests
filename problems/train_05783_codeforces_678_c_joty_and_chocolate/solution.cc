#include <bits/stdc++.h>
using namespace std;
long long getgcd(long long a, long long b) {
  long long t, sum;
  sum = a * b;
  while (b > 0) {
    t = b;
    b = a % b;
    a = t;
  }
  return sum / a;
}
int main() {
  long long n, a, b, p, q, sum1, sum2, sum3, x, y, ans;
  while (scanf("%lld%lld%lld%lld%lld", &n, &a, &b, &p, &q) != EOF) {
    sum1 = n / a;
    sum2 = n / b;
    sum3 = n / getgcd(a, b);
    ans = (sum1 - sum3) * p + (sum2 - sum3) * q + sum3 * max(p, q);
    printf("%lld\n", ans);
  }
  return 0;
}
