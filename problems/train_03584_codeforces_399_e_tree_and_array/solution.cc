#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  if (5 == n) {
    printf("1 2 3\n1 3 3\n2 4 2\n4 5 1\n");
    printf("3 4\n3 5\n");
  } else {
    for (int i = 1; i <= n >> 1; ++i) {
      printf("%d %d 1\n", i, i + (n >> 1));
    }
    for (int i = (n >> 1) + 1; i <= n - 1; ++i) {
      printf("%d %d %d\n", i, i + 1, ((i - (n >> 1)) << 1) - 1);
    }
    for (int i = 1; i <= (n >> 1) - 1; ++i) {
      printf("%d %d\n", i, i + 1);
    }
    printf("1 3\n");
  }
  return 0;
}
