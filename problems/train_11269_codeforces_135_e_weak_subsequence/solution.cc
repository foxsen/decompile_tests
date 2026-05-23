#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int f1[1000000 + 10], f2[1000000 + 10], t;
int powe(int a, int b) {
  int s = 1;
  while (b) {
    if (b & 1) s = (long long)s * a % 1000000007;
    a = (long long)a * a % 1000000007;
    b >>= 1;
  }
  return s;
}
int calc(int k, int w) {
  int res = 0, i;
  for (i = t; i <= w + k && i <= 2 * w; ++i)
    res = (res +
           (long long)((long long)(((long long)f1[(k)] * f2[(k) - (i - w)] %
                                    1000000007)) *
                       (((long long)f1[(k)] * f2[(k) - (i - w)] % 1000000007)) %
                       1000000007) *
               powe(k, 2 * w - i)) %
          1000000007;
  for (i = 1; i <= k - w; ++i)
    res = (res +
           (long long)((long long)f1[(k)] * f2[(k) - (i)] % 1000000007) *
               ((long long)(((long long)f1[(k - i)] * f2[(k - i) - (w)] %
                             1000000007)) *
                (((long long)f1[(k - i)] * f2[(k - i) - (w)] % 1000000007)) %
                1000000007)) %
          1000000007;
  return res;
}
int main() {
  int k, w, i;
  scanf("%d%d", &k, &w);
  f1[0] = f2[0] = 1;
  for (i = 1; i <= k; ++i) {
    f1[i] = (long long)f1[i - 1] * i % 1000000007;
    f2[i] = powe(f1[i], 1000000007 - 2);
  }
  t = w + 1;
  printf("%d\n", (calc(k, w) - calc(k, w - 1) + 1000000007) % 1000000007);
  return 0;
}
