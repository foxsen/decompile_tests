#include <bits/stdc++.h>
using namespace std;
int min(int a, int b, int c) {
  if (a < b) {
    return a < c ? a : c;
  }
  return b < c ? b : c;
}
int main() {
  int l, r, a;
  cin >> l >> r >> a;
  int ans = 0;
  cout << min(2 * (l + a), 2 * (r + a), ((l + r + a) - ((l + r + a) % 2)));
  return 0;
}
