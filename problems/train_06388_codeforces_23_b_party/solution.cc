#include <bits/stdc++.h>
int t, n;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    printf("%d\n", n == 1 ? 0 : n - 2);
  }
  return 0;
}
