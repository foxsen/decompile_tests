#include <bits/stdc++.h>
using namespace std;
int numdigits(long long m) {
  int ret = 0;
  while (m) {
    m /= 10;
    ret++;
  }
  return ret;
}
long long extract(int x) {
  long long last = 10, first = 10;
  x -= 2;
  while (x--) {
    first *= 10;
  }
  last *= first;
  return (last - first);
}
long long T[23];
int main() {
  long long w, m, ans = 0, k;
  cin >> w >> m >> k;
  int digits = numdigits(m);
  int copy = digits;
  long long base = 10;
  copy--;
  while (copy--) base *= 10;
  T[digits] = base - m;
  for (int i = digits + 1; i <= 23; i++) T[i] = extract(i);
  for (int i = digits; i <= 23 && w > 0; i++) {
    if (w / (i * k) == 0) {
      break;
    }
    long long x = (w / (i * k)) >= T[i] ? T[i] : (w / (i * k));
    ans += x;
    w -= x * i * k;
  }
  cout << ans;
  return 0;
}
