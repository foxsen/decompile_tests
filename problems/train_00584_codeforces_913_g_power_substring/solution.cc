#include <bits/stdc++.h>
using namespace std;
int T, n, m;
long long x, y, a, b;
inline long long ps(long long x, long long y, long long P) {
  long long z = 0;
  while (y) {
    if (y & 1) z = z + x;
    x <<= 1, y >>= 1;
    if (x >= P) x -= P;
    if (z >= P) z -= P;
  }
  return z;
}
inline long long pm(long long x, long long y, long long P) {
  long long z = 1;
  x %= P;
  while (y) {
    if (y & 1) z = ps(z, x, P);
    x = ps(x, x, P), y >>= 1;
  }
  return z;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%lld", &a);
    long long t = a, m1 = 1;
    n = 0;
    while (t) t /= 10, n++;
    for (m = 0;; m++, a *= 10, m1 *= 10) {
      b = (-a) & ((1 << (n + m)) - 1);
      if ((a + b) % 5 == 0) b += 1 << (n + m);
      if (b >= m1) continue;
      x = a + b, y = x >> (n + m);
      int i, j;
      long long now = 0, phi, pw;
      for (i = 0; i < 4; i++)
        if (pm(2, i, 5) == y % 5) now = i;
      phi = 4, pw = 5;
      for (i = 2; i <= n + m; i++) {
        pw *= 5;
        for (j = 0; j < 5; j++)
          if (pm(2, now + j * phi, pw) == y % pw) {
            now += j * phi;
            break;
          }
        phi *= 5;
      }
      printf("%lld\n", now + n + m);
      break;
    }
  }
  return 0;
}
