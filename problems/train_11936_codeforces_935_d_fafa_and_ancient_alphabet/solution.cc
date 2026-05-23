#include <bits/stdc++.h>
using namespace std;
long long n, m, a[100010], b[100010], ac, bc;
long long power(long long a, long long n) {
  long long temp;
  if (n == 0) return 1;
  temp = power(a, n / 2);
  if (n % 2 == 0)
    return (((temp % 1000000007) * (temp % 1000000007)) % 1000000007);
  else {
    long long res = a % 1000000007;
    res = (res * (temp % 1000000007)) % 1000000007;
    res = (res * (temp % 1000000007)) % 1000000007;
    return res;
  }
}
long long gcdExtended(long long a, long long b, long long *x, long long *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  long long x1, y1;
  long long gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
long long modInverse(long long a, long long m) {
  long long x, y;
  long long g = gcdExtended(a, m, &x, &y);
  if (g != 1)
    cout << "Inverse doesn't exist" << endl;
  else {
    long long res = (x % m + m) % m;
    return res;
  }
  return -1;
}
int main() {
  scanf("%lld %lld", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    if (a[i] == 0) ac++;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", &b[i]);
    if (b[i] == 0) bc++;
  }
  long long q = (power(m, ac + bc)) % 1000000007;
  long long ways = 0;
  bool f = false, fail = false;
  long long c = 1;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0 && b[i] == 0) {
      long long x = power(m, ac + bc - 2) % 1000000007;
      long long y = ((m * (m - 1) / 2)) % 1000000007;
      x = (((x * y) % 1000000007) * c) % 1000000007;
      ways = (ways + x) % 1000000007;
      c = (c * (m % 1000000007)) % 1000000007;
      f = true;
      ac--;
      bc--;
    } else if (a[i] == 0) {
      long long x = power(m, ac + bc - 1) % 1000000007;
      long long y = m - b[i];
      x = (((x * y) % 1000000007) * c) % 1000000007;
      ways = (ways + x) % 1000000007;
      ac--;
      f = true;
    } else if (b[i] == 0) {
      long long x = power(m, ac + bc - 1) % 1000000007;
      long long y = a[i] - 1;
      x = (((x * y) % 1000000007) * c) % 1000000007;
      ways = (ways + x) % 1000000007;
      bc--;
      f = true;
    } else if (a[i] > b[i]) {
      long long x = power(m, ac + bc) % 1000000007;
      long long y = 1;
      x = (((x * y) % 1000000007) * c) % 1000000007;
      ways = (ways + x) % 1000000007;
      break;
    } else if (a[i] < b[i]) {
      if (!f) fail = true;
      break;
    }
  }
  if (fail)
    printf("0\n");
  else {
    long long res = (ways * modInverse(q, 1000000007)) % 1000000007;
    printf("%lld\n", res);
  }
  return 0;
}
