#include <bits/stdc++.h>
using namespace std;
long long c[9];
long long solve(long long x, long long y) {
  if (x == 0 && y == 0) return 0;
  long long r = abs(x);
  x /= r;
  y /= r;
  long long ans;
  if (x == 1 && y == 1)
    ans = c[1];
  else if (x == 1 && y == -1)
    ans = c[8];
  else if (x == -1 && y == 1)
    ans = c[7];
  else
    ans = c[4];
  return r * ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long x, y;
    cin >> x >> y;
    for (long long i = 1; i < 7; i++) cin >> c[i];
    c[1] = min(c[1], c[2] + c[6]);
    c[2] = min(c[2], c[1] + c[3]);
    c[3] = min(c[3], c[2] + c[4]);
    c[4] = min(c[4], c[3] + c[5]);
    c[5] = min(c[5], c[4] + c[6]);
    c[6] = min(c[6], c[1] + c[5]);
    c[7] = c[2] + c[3];
    c[8] = c[5] + c[6];
    long long ans = 0;
    if (abs(x) == abs(y))
      ans = solve(x, y);
    else if (abs(x) < abs(y)) {
      if (y > 0) {
        ans += c[2] * (abs(y) - abs(x));
        y -= abs(y) - abs(x);
      } else {
        ans += c[5] * (abs(y) - abs(x));
        y += abs(y) - abs(x);
      }
      ans += solve(x, y);
    } else {
      if (x > 0) {
        ans += c[6] * (abs(x) - abs(y));
        x -= abs(x) - abs(y);
      } else {
        ans += c[3] * (abs(x) - abs(y));
        x += abs(x) - abs(y);
      }
      ans += solve(x, y);
    }
    cout << ans << '\n';
  }
  return 0;
}
