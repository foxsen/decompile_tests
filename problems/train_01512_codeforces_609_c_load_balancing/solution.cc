#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
int t, n, a[100005], tot, bal, ans;
inline int _abs(int x) { return x > 0 ? x : -x; }
bool cmp(int x, int y) { return x > y; }
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read(), tot += a[i];
  sort(a + 1, a + n + 1, cmp);
  bal = tot % n, tot /= n;
  for (int i = 1; i <= n; i++)
    if (bal)
      bal--, ans += _abs(a[i] - tot - 1);
    else
      ans += _abs(a[i] - tot);
  ans /= 2;
  printf("%d\n", ans);
  ans = tot = 0;
  return 0;
}
