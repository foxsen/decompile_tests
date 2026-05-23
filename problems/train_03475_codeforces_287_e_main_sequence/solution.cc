#include <bits/stdc++.h>
using namespace std;
int a[1000100], c[1000100];
int main() {
  int i, j, k, n, m, t;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &t);
  for (i = 1; i <= t; i++) {
    scanf("%d", &k);
    a[k] = -fabs(a[k]);
  }
  m = 0;
  for (i = n; i >= 1; i--) {
    if (m > 0 && a[c[m]] <= 0 && a[i] == -a[c[m]]) {
      m--;
    } else if (m > 0 && a[c[m]] >= 0 && a[i] == a[c[m]]) {
      a[c[m]] *= -1;
      m--;
    } else {
      m++;
      c[m] = i;
    }
  }
  if (m != 0)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    cout << a[1];
    for (i = 2; i <= n; i++) printf(" %d", a[i]);
  }
  return 0;
}
