#include <bits/stdc++.h>
int sx, sy, tx, ty, ans;
int main() {
  scanf("%d%d\n%d%d", &sx, &sy, &tx, &ty);
  ans = std::max(abs(sx - tx), abs(sy - ty));
  printf("%d\n", ans);
}
