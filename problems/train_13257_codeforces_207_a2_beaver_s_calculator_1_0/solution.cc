#include <bits/stdc++.h>
using namespace std;
int *pa = new int[200005];
int *na = new int[200005];
int *p1 = new int[200005];
int *p2 = new int[200005];
int main() {
  int m1 = 1, m2 = 1, c1, c2, fs[5005], ls[5005], n, k[5005], x[5005], y[5005],
      m[5005], i, j;
  long long all = 0, q, nn, xx, yy, ans = 0;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> k[i] >> fs[i] >> x[i] >> y[i] >> m[i];
    all += k[i];
  }
  q = fs[1];
  p1[1] = fs[1];
  for (i = 2; i <= k[1]; i++) {
    xx = x[1];
    yy = y[1];
    nn = (q * xx + yy) % m[1];
    p1[i] = nn;
    q = nn;
  }
  q = fs[2];
  p2[1] = fs[2];
  for (i = 2; i <= k[2]; i++) {
    xx = x[2];
    yy = y[2];
    nn = (q * xx + yy) % m[2];
    p2[i] = nn;
    q = nn;
  }
  q = -1;
  for (i = 1; i <= all; i++) {
    if (m1 <= k[1])
      c1 = p1[m1];
    else
      c1 = 2000000000;
    if (m2 <= k[2])
      c2 = p2[m2];
    else
      c2 = 2000000000;
    if ((c1 != 2000000000) &&
        (((c1 >= c2) && (c1 >= q) && (c2 < q)) || (c2 == 2000000000) ||
         ((c1 <= c2) && (c1 >= q)) || ((c1 <= c2) && (c2 < q)))) {
      if (c1 < q) ans++;
      q = c1;
      if (all <= 200000) {
        pa[i] = p1[m1];
        na[i] = 1;
      }
      m1++;
    } else {
      if (c2 < q) ans++;
      q = c2;
      if (all <= 200000) {
        pa[i] = p2[m2];
        na[i] = 2;
      }
      m2++;
    }
  }
  cout << ans << endl;
  if (all <= 200000) {
    for (i = 1; i <= all; i++) cout << pa[i] << " " << na[i] << endl;
  }
}
