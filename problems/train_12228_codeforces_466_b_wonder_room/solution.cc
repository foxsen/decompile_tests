#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
int main() {
  int flag = 0;
  long long n, a, b;
  cin >> n >> a >> b;
  long long x = a, y = b;
  if (a > b) {
    swap(a, b);
    flag = 1;
  }
  if (a * b > 6 * n) {
    printf("%lld\n", a * b);
    printf("%lld %lld\n", a, b);
    return 0;
  }
  long long ans = 0x3f3f3f3f3f3f3f3f, l = 0, r = 0;
  long long len = sqrt(6 * n) + 1;
  for (int i = a; i <= len + 5; i++) {
    if (6 * n % i == 0 && 6 * n / i >= b) {
      l = i;
      r = 6 * n / i;
      break;
    }
    y = 6 * n / i + 1;
    y = max(y, b);
    if (i * y < ans) {
      l = i;
      r = y;
      ans = l * r;
    }
  }
  if (flag) swap(l, r);
  printf("%lld\n", l * r);
  printf("%lld %lld\n", l, r);
  return 0;
}
