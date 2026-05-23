#include <bits/stdc++.h>
int main() {
  long long int records, n, w, eq = 0, tc, min = 0, max = 0, ans;
  scanf("%lld %lld", &n, &w);
  while (n--) {
    scanf("%lld", &records);
    eq += records;
    if (eq < min) min = eq;
    if (eq > max) max = eq;
  }
  ans = w - max + min + 1;
  if (ans < 0 || ans > (w + 1) || max > w || min < (-1 * w))
    printf("0\n");
  else
    printf("%lld\n", ans);
}
