#include <bits/stdc++.h>
using namespace std;
unsigned int gcd(unsigned int u, unsigned int v) {
  if (u == v) return u;
  if (u == 0) return v;
  if (v == 0) return u;
  if (~u & 1) {
    if (v & 1)
      return gcd(u >> 1, v);
    else
      return gcd(u >> 1, v >> 1) << 1;
  }
  if (~v & 1) return gcd(u, v >> 1);
  if (u > v) return gcd((u - v) >> 1, v);
  return gcd((v - u) >> 1, u);
}
int main() {
  int n, g, a[100000];
  cin >> n;
  cin >> a[0];
  g = a[0];
  for (int i = 1; i < n; ++i) {
    cin >> a[i];
    g = gcd(g, a[i]);
  }
  int flag = 0;
  for (int i = 0; i < n; ++i) {
    int b = a[i] / g;
    while (b % 2 == 0) b = b / 2;
    while (b % 3 == 0) b = b / 3;
    if (b != 1) {
      cout << "No";
      flag = 1;
      break;
    }
  }
  if (flag == 0) cout << "Yes";
}
