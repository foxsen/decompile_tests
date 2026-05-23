#include <bits/stdc++.h>
int main() {
  int n;
  while (~scanf("%d", &n)) {
    printf("%d", n);
    for (int i = 1; i < n; i++) {
      printf(" %d", i);
    }
    printf("\n");
  }
  return 0;
}
