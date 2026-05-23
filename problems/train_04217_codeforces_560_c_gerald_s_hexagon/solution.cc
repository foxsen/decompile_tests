#include <bits/stdc++.h>
using namespace std;
int main() {
  int u, d, lu, ld, ru, rd;
  scanf("%d%d%d%d%d%d", &u, &lu, &ld, &d, &rd, &ru);
  int nu = min(lu, ru);
  int nd = min(ld, rd);
  int ans = 2 * nu * u + nu * nu;
  ans += 2 * nd * d + nd * nd;
  int t = lu + ld - nu - nd;
  ans += t * (2 * u + 2 * nu);
  printf("%d", ans);
  return 0;
}
