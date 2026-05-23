#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
int a, b, c, d, e, f;
int main() {
  scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
  int tmp1 = min(a, d);
  int tmp2 = min(b, min(c, d));
  int ans = 0;
  if (e > f) {
    ans += tmp1 * e;
    tmp2 = min(tmp2, d - tmp1);
    ans += tmp2 * f;
  } else {
    ans += tmp2 * f;
    tmp1 = min(tmp1, d - tmp2);
    ans += tmp1 * e;
  }
  printf("%d", ans);
}
