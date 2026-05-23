#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int t, i, j, k, n;
  scanf("%d", &n);
  int a[n], ac[n], m = 0;
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    ac[i] = a[i];
  }
  for (i = 1; i < n; i++) {
    if (a[i] > a[m]) m = i;
  }
  sort(ac, ac + m + 1);
  sort(ac + m + 1, ac + n, greater<int>());
  for (i = 0; i < n; i++) {
    if (a[i] != ac[i]) break;
  }
  if (i == n)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
