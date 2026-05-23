#include <bits/stdc++.h>
using namespace std;
long long INF = 1e18;
long long x = INF;
long long y = -INF;
long long nod(long long a, long long b) {
  while (a > 0 && b > 0) {
    long long c = a % b;
    a = b;
    b = c;
  }
  return a + b;
}
void f(long long start, long long b, long long n, long long k) {
  long long l1 = -1, l2 = -1, k1, k2;
  for (int l = 1; l <= k; l++) {
    if (start + l - ((start + l - 1) / k * k + 1) == b) {
      l1 = l;
    }
    if (((start + l - 1) / k + 1) * k + 1 - (start + l) == b) {
      l2 = l;
    }
  }
  for (int i = 0; i < n; i++) {
    if (l1 != -1) {
      k1 = (n * k) / nod(i * k + l1, n * k);
      x = min(x, k1);
      y = max(y, k1);
    }
    if (l2 != -1) {
      k2 = (n * k) / nod(i * k + l2, n * k);
      x = min(x, k2);
      y = max(y, k2);
    }
  }
}
int main() {
  long long n, k, a, b;
  cin >> n >> k;
  cin >> a >> b;
  f(a + 1, b, n, k);
  f(k + 1 - a, b, n, k);
  std::cout << x << ' ' << y;
}
