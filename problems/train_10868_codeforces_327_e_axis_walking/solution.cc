#include <bits/stdc++.h>
using namespace std;
int INP, AM, REACHEOF;
char BUF[(1 << 12) + 1], *inp = BUF;
const long double PI = acos((long double)-1.0);
const long long MOD = 1000000007LL;
const int oo = 1000000001;
;
int n, a[25], x[25], k;
int sum[(1 << (24))], f[(1 << (24))];
int main() {
  while (scanf("%d", &n) == 1) {
    for (int i = 0, _a = (n); i < _a; i++) {
      scanf("%d", &a[i]);
      sum[(1 << (i))] = a[i];
    }
    x[1] = x[2] = -1;
    scanf("%d", &k);
    for (int i = (1), _b = (k); i <= _b; i++) scanf("%d", &x[i]);
    f[0] = 1;
    sum[0] = 0;
    int u;
    for (int mask = 0, _a = ((1 << (n))); mask < _a; mask++)
      if (mask) {
        if (__builtin_popcount(mask) > 1) {
          u = mask & (-mask);
          sum[mask] = sum[mask - u] + sum[u];
          if (sum[mask] > oo) sum[mask] = oo;
        }
        if (sum[mask] == x[1] || sum[mask] == x[2]) {
          f[mask] = 0;
        } else {
          f[mask] = 0;
          for (int i = 0; i < n; ++i)
            if ((mask & (1 << (i)))) {
              f[mask] += f[mask - (1 << (i))];
              if (f[mask] >= MOD) f[mask] -= MOD;
            }
        }
      }
    cout << f[(1 << (n)) - 1] << endl;
  }
  return 0;
}
