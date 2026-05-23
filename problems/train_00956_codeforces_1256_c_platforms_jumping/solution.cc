#include <bits/stdc++.h>
int n, m, d, a[1005], c[1005], i, j, k, l, sum;
int main() {
  for (scanf("%d%d%d", &n, &m, &d), i = 0; i < m; i++)
    scanf("%d", &c[i]), sum += c[i];
  if (sum + (d - 1) * (m + 1) < n || sum > n) {
    printf("NO\n");
    return 0;
  } else
    printf("YES\n");
  for (i = j = 0; i < n; i++) {
    bool b = false;
    if (sum + j >= n) {
      i--;
      break;
    }
    j += d - 1;
    sum -= c[i];
    for (k = j; k - j < c[i]; k++) {
      if (k + sum >= n) {
        for (k = j; k + sum < n; k++) a[k] = 0;
        i--;
        b = true;
        break;
      }
      a[k] = i + 1;
    }
    j = k;
    if (b) break;
  }
  k = j = n - 1;
  for (l = m - 1; l > i; l--) {
    for (k = j; j - k < c[l]; k--) a[k] = l + 1;
    j = k;
  }
  for (i = 0; i < n; i++) printf("%d ", a[i]);
  return 0;
}
