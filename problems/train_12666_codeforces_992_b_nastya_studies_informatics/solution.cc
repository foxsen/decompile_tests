#include <bits/stdc++.h>
using namespace std;
int l, r, x, y;
vector<int> k, n, m;
int power(int a, int b) {
  int res = 1;
  for (int i = 0; i < b; i++) res *= a;
  return res;
}
int calc(int i, int x, int y) {
  if (i == k.size()) return (l <= x && x <= r && l <= y && y <= r);
  int res = calc(i + 1, x * power(k[i], n[i]), y * power(k[i], m[i]));
  if (n[i] > m[i])
    res += calc(i + 1, x * power(k[i], m[i]), y * power(k[i], n[i]));
  return res;
}
int main() {
  cin >> l >> r >> x >> y;
  if (x == y) {
    cout << (l <= x && x <= r);
    return 0;
  }
  if (y % x) {
    cout << 0;
    return 0;
  }
  for (int i = 2; i * i <= y; i++)
    if (y % i == 0) {
      k.push_back(i);
      int cnt = 0;
      for (cnt; y % i == 0; y /= i, cnt++)
        ;
      n.push_back(cnt);
    }
  if (y > 1) k.push_back(y), n.push_back(1);
  for (int i = 0; i < k.size(); i++) {
    int cnt = 0;
    for (cnt; x % k[i] == 0; x /= k[i], cnt++)
      ;
    m.push_back(cnt);
  }
  cout << calc(0, 1, 1);
}
