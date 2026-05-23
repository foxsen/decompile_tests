#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
inline int gcd(int a, int b) {
  if (a < b) {
    a ^= b;
    b ^= a;
    a ^= b;
  };
  return (a > b) ? gcd(a - b, b) : a;
}
inline int abs(int x) { return x > 0 ? x : -x; }
void solve() {
  int a, b, c, t, all;
  bool fin = false;
  cin >> a >> b >> c;
  if (b >= a) {
    cout << 0;
    return;
  }
  t = 0;
  all = (c * a + b - 1) / b;
  while (++t)
    if (all * b >= (all - t) * a) break;
  cout << t;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
