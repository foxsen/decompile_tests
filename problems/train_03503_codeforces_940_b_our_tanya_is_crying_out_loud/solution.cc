#include <bits/stdc++.h>
const int N = 123456;
int arr[N], i, j;
using namespace std;
int main() {
  long long n, k, a, b, ans1 = 0, ans2 = 0, ans = 0;
  scanf("%lld %lld", &n, &k);
  scanf("%lld %lld", &a, &b);
  ans1 = (n - 1) * a;
  if (k == 1) return cout << ans1 << endl, 0;
  while (n != 0 && n != 1) {
    if (n % k == 0) {
      if (b < a * (n - n / k))
        ans += b;
      else
        ans += a * (n - n / k);
      n = n / k;
    } else {
      ans += ((n % k) * a);
      n = n - (n % k);
    }
  }
  if (n == 0) ans -= a;
  printf("%lld\n", ans);
  return 0;
}
