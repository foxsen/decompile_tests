#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx")
using namespace std;
int a[100010], n, m;
int main() {
  register int i;
  float x;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (register int k, l, r, s; m--;) {
    scanf("%d%d%d%f", &k, &l, &r, &x);
    if (k == 1)
      for (i = l; i <= r; ++i) a[i] -= a[i] > x ? x : 0;
    else {
      for (s = 0, i = l; i <= r; ++i) a[i] == x ? ++s : 0;
      printf("%d\n", s);
    }
  }
}
