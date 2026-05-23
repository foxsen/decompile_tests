#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int f(int a, int b, int c, int d, int n) {
  if (a > b || c > d) return 0;
  if (a == c) return min(b, d) - a + 1;
  if (a > c) swap(a, c), swap(b, d);
  if (b >= d) return d - c + 1;
  int x = 1 << n;
  if (b < x && d < x) return f(a, b, c, d, n - 1);
  if (a > x && c > x) return f(a - x, b - x, c - x, d - x, n);
  if (c > x) return f(a, b, c - x, d - x, n);
  return max(b - c + 1, max(f(a, b, c, x - 1, n), f(a, b, x + 1, d, n)));
}
int main() {
  cin >> a >> b >> c >> d;
  cout << f(a, b, c, d, 30);
}
