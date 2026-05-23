#include <bits/stdc++.h>
using namespace std;
int p, x, y;
bool check(int a) {
  a /= 50;
  a %= 475;
  for (int i = 0; i < 25; ++i) {
    a = (a * 96 + 42) % 475;
    if (a + 26 == p) return true;
  }
  return false;
}
int solve() {
  int a = x;
  a = (y / 50) * 50 + x % 50;
  if (a < y) a += 50;
  while (a < x) {
    if (check(a)) return 0;
    a += 50;
  }
  int res = 0;
  while (!check(a)) {
    ++res;
    a += 50;
    if (!check(a)) a += 50;
  }
  return res;
}
int main() {
  cin >> p >> x >> y;
  cout << solve() << endl;
  return 0;
}
