#include <bits/stdc++.h>
using namespace std;
long long n, g, b, half;
bool check(long long now) {
  long long G = now / (g + b) * g + min(g, now % (g + b));
  long long B = now - G;
  if (G + B >= n && G >= (n + 1) / 2)
    return true;
  else
    return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> g >> b;
    long long l = 0, r = 1e18 + 7;
    while (r - l > 1) {
      long long mid = (l + r) / 2;
      if (check(mid))
        r = mid;
      else
        l = mid;
    }
    if (check(l))
      cout << l << endl;
    else
      cout << r << endl;
  }
  return 0;
}
