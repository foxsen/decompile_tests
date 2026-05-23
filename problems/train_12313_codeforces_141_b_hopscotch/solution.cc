#include <bits/stdc++.h>
using namespace std;
const long long int inf = 1000000000;
const long long int MOD = 1000000007;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  register long long int i, j, x, y, t = 1, k, sum = 0, max, min, count = 0,
                                     temp, w, q;
  double a;
  cin >> temp >> x >> y;
  a = temp;
  k = y / a;
  if (k > 1) {
    if (k % 2 == 0) t = 2;
  }
  long long int ans = 2;
  if (k == 1)
    ans = 2;
  else if (k == 2)
    ans = 4;
  else {
    for (i = 2; i <= k; i++) {
      if (i % 2 == 0)
        ans += 2;
      else
        ans += 1;
    }
  }
  if (y == 0 || y % temp == 0)
    cout << -1;
  else if (t == 2) {
    if (abs(x - 0) < a) {
      if (x < 0) {
        cout << ans - 1;
      } else if (x > 0)
        cout << ans;
      else
        cout << "-1";
    } else {
      cout << "-1";
    }
  } else {
    if (abs(x - 0) < a / 2 && abs(y - k * a) < a) {
      if (k == 1)
        cout << 2;
      else if (k == 0)
        cout << 1;
      else {
        cout << ans;
      }
    } else {
      cout << "-1";
    }
  }
}
