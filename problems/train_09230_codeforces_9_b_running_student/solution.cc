#include <bits/stdc++.h>
int main() {
  int n, vb, vs, i, offstop, ux, uy;
  int stop[110];
  float dis, temp, mintime;
  scanf("%d %d %d", &n, &vb, &vs);
  for (i = 1; i <= n; i++) scanf("%d", &stop[i]);
  scanf("%d %d", &ux, &uy);
  mintime = INT_MAX;
  for (i = 1; i <= n; i++) {
    dis = sqrt((fabs(stop[i] - ux) * (fabs(stop[i] - ux))) + (float)uy * uy);
    temp = (float)stop[i] / vb + (float)dis / vs;
    if (temp <= mintime) {
      offstop = i;
      mintime = temp;
    } else
      break;
  }
  if (offstop == 1) offstop++;
  printf("%d\n", offstop);
  return 0;
}
