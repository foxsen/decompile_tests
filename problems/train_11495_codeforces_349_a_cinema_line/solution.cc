#include <bits/stdc++.h>
using namespace std;
long long int x[1000007], y[1000007], z[1000007];
string s;
int main() {
  {
    long long int a = 0, b = 0, d, e, i, j, k, l, m, n, p = 1, q, r, t, u, val,
                  w, tc, mn = 2134567891, mx = 0, sum = 0, ans = 0;
    cin >> n;
    for (i = 0; i < n; i++) cin >> x[i];
    for (i = 0; i < n; i++) {
      if (x[i] == 25)
        a++;
      else if (x[i] == 50) {
        if (a)
          a--, b++;
        else {
          p = 0;
          break;
        }
      } else {
        if (a && b)
          a--, b--;
        else if (a >= 3)
          a -= 3;
        else {
          p = 0;
          break;
        }
      }
    }
    if (p)
      cout << "YES\n";
    else
      cout << "NO\n";
    memset(x, 0, sizeof(x));
  }
  return 0;
}
