#include <bits/stdc++.h>
int main() {
  int i, j, k, r, price;
  scanf("%d %d", &k, &r);
  for (i = 1; i <= 10; i++) {
    price = i * k;
    if ((price - r) % 10 == 0 || price % 10 == 0) {
      printf("%d\n", i);
      return 0;
    }
  }
  return 0;
}
