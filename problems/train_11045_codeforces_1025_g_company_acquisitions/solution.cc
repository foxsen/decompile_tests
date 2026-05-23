#include <bits/stdc++.h>
using namespace std;
int n, a[500 + 5], p[500 + 5];
int main() {
  register int i;
  for (scanf("%d", &n), i = 1; i <= n; ++i) p[i] = 1;
  for (i = 1; i <= n; ++i)
    scanf("%d", a + i), ~a[i] && (p[a[i]] = 2LL * p[a[i]] % 1000000007);
  register int t = 1;
  for (i = 1; i ^ n; ++i) t = 2LL * t % 1000000007;
  for (--t, i = 1; i <= n; ++i)
    !~a[i] && (t = (t - (p[i] - 1) + 1000000007) % 1000000007);
  return printf("%d\n", t), 0;
}
