#include <bits/stdc++.h>
using namespace std;
int n;
int input() {
  cin >> n;
  return 0;
}
int gcd(int p, int q) {
  int r;
  if (p < q) {
    int t = p;
    p = q;
    q = t;
  };
  while (1) {
    r = p % q;
    if (r == 0) break;
    p = q;
    q = r;
  }
  return q;
}
int f(int a, int b) {
  int t;
  if (gcd(a, b) != 1) return -1;
  for (int i = 0;; i++) {
    if (a < b) {
      int t = a;
      a = b;
      b = t;
    };
    if (a == 2 && b == 1) return 1 + i;
    if (a == 1 && b == 1) return i;
    if (a < 1 || b < 1) return -1;
    if (a == b) return -1;
    if (b == 1) return (a - 1) + i;
    t = a - b;
    a = b;
    b = t;
  }
}
int solve() {
  int i, min = -1, x;
  if (n == 1) return 0;
  for (i = n / 2; i; i--) {
    x = f(n, i);
    if (x == -1) continue;
    if (min == -1 || x < min) min = x;
  }
  return min;
}
int main() {
  input();
  cout << solve() << endl;
  return 0;
}
