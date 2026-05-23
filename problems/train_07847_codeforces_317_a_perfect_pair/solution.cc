#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  long long x, y, m;
  cin >> x >> y >> m;
  if (x < y) swap(x, y);
  if (x >= m) {
    cout << 0;
    return 0;
  }
  if (x <= 0) {
    cout << -1;
    return 0;
  }
  long long res = 0;
  if (y < 0) {
    res = -y / x;
    y += x * res;
  }
  while (x < m && y < m) {
    if (x < y)
      x += y;
    else
      y += x;
    res++;
  }
  cout << res;
  return 0;
}
