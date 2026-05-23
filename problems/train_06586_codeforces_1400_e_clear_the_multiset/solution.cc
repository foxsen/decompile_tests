#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
int a[maxn];
inline int dac(int l, int r) {
  if (l == r) return 1;
  int ans = r - l + 1, p = 0x3f3f3f3f, ansp;
  for (register int i = l; i <= r; i++) p = min(p, a[i]);
  ansp = p;
  int kl = l, kr;
  for (register int i = l; i <= r; i++) {
    a[i] -= p;
    if (a[i] == 0) {
      if (kl <= i) ansp += dac(kl, i - 1);
      kl = r + 1;
    } else
      kl = min(kl, i);
  }
  if (kl <= r) ansp += dac(kl, r);
  return min(ans, ansp);
}
int main() {
  int n;
  scanf("%d", &n);
  for (register int i = 1; i <= n; i++) scanf("%d", a + i);
  int l = 0, r = 0, ans = 0;
  for (register int i = 1; i <= n + 1; i++) {
    if (a[i] > 0 && a[i - 1] == 0) l = i;
    if (a[i] == 0 && a[i - 1] > 0) {
      r = i - 1;
      if (l <= r) ans += dac(l, r);
    }
  }
  printf("%d", ans);
}
