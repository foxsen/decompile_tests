#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, a, b;
int gcd(int a1, int a2) {
  if (a2 == 0) return a1;
  return gcd(a2, a1 % a2);
}
int main() {
  scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &a, &b);
  int g = gcd(a, b);
  a = a / g;
  b = b / g;
  int M = min(n / a, m / b);
  int L = a * M, W = b * M;
  int x1 = max(0, min(x - (L + 1) / 2, n - L));
  int y1 = max(0, min(y - (W + 1) / 2, m - W));
  printf("%d %d %d %d\n", x1, y1, x1 + L, y1 + W);
  return 0;
}
