#include <bits/stdc++.h>
using namespace std;
inline long long getint() {
  long long _x = 0, _tmp = 1;
  char _tc = getchar();
  while ((_tc < '0' || _tc > '9') && _tc != '-') _tc = getchar();
  if (_tc == '-') _tc = getchar(), _tmp = -1;
  while (_tc >= '0' && _tc <= '9') _x *= 10, _x += (_tc - '0'), _tc = getchar();
  return _x * _tmp;
}
pair<long long, long long> p[1234567];
long long cum[1234567];
int main() {
  int n;
  int x, y;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    y = max(0, i - x);
    cum[y] += 1;
    cum[i] -= 1;
  }
  int ans = 1;
  for (int i = 1; i < n; i++) {
    cum[i] += cum[i - 1];
    if (cum[i] == 0) ans++;
  }
  cout << ans << endl;
  return 0;
}
