#include <bits/stdc++.h>
int p(int n) {
  int i, k = 1;
  for (i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      k = 0;
      break;
    }
  }
  if (n == 3 || n == 2)
    return 1;
  else
    return k;
}
int main() {
  int n, m, i;
  while (scanf("%d%d", &n, &m) != EOF) {
    for (i = n + 1; i <= m; i++) {
      if (p(i)) break;
    }
    if (i == m)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
