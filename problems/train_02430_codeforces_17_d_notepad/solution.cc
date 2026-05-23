#include <bits/stdc++.h>
using namespace std;
long long po(long long x, long long n, long long mo) {
  long long s = 1, m = x;
  while (n) {
    if (n & (long long)1) s = (s * m) % mo;
    m = (m * m) % mo;
    n >>= 1;
  }
  return (mo + s) % mo;
}
long long ou(long long x) {
  long long ans = 1;
  for (long long i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      ans *= (i - 1);
      x /= i;
      while (x % i == 0) {
        ans *= i;
        x /= i;
      }
    }
  }
  if (x > 1) ans *= (x - 1);
  return ans;
}
char b[1000009], n[1000009];
long long c;
int main() {
  while (scanf("%s%s%lld", b, n, &c) != EOF) {
    long long rb = 0;
    int l1 = strlen(b), l2 = strlen(n);
    for (int i = 0; i < l1; i++) {
      rb = (rb * 10 + b[i] - '0') % c;
    }
    long long rn = 0, ol = ou(c);
    bool flag = 0;
    for (int i = 0; i < l2; i++) {
      rn = (rn * 10 + n[i] - '0');
      if (rn > c) {
        flag = 1;
        break;
      }
    }
    if (flag) {
      long long ans1 = 0;
      for (int i = 0; i < l2; i++) {
        ans1 = (ans1 * 10 + n[i] - '0') % ol;
      }
      long long ans2 = (ans1 - 1 + ol) % ol;
      long long pp = po(rb, ans1 + ol, c);
      long long qq = po(rb, ans2 + ol, c);
      long long ss = (pp - qq + c) % c;
      if (ss)
        printf("%lld\n", ss);
      else
        printf("%lld\n", c);
    } else {
      long long nn = po(rb, rn, c);
      long long mm = po(rb, rn - 1, c);
      long long ss = (nn - mm + c) % c;
      if (ss)
        printf("%lld\n", ss);
      else
        printf("%lld\n", c);
    }
  }
  return 0;
}
