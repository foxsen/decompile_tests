#include <bits/stdc++.h>
using namespace std;
int a[5];
int main() {
  int n, i;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  if (n == 0)
    printf("YES\n1\n1\n3\n3\n");
  else if (n == 1)
    printf("YES\n%d\n%d\n%d\n", a[1], a[1] * 3, a[1] * 3);
  else if (n == 2) {
    if (4 * a[1] - a[2] > 0)
      printf("YES\n%d\n%d\n", 4 * a[1] - a[2], 3 * a[1]);
    else
      printf("NO\n");
  } else if (n == 3) {
    if (a[3] == 4 * a[1] - a[2])
      printf("YES\n%d\n", 3 * a[1]);
    else if (a[3] == 3 * a[1] && a[1] <= 4 * a[1] - a[2])
      printf("YES\n%d\n", 4 * a[1] - a[2]);
    else if (a[3] * 4 == (a[1] + a[2]) * 3 && a[3] / 3 <= a[1])
      printf("YES\n%d\n", a[3] / 3);
    else
      printf("NO\n");
  } else {
    if (a[4] == 3 * a[1] && a[2] + a[3] == 4 * a[1])
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
