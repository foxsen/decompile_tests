#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, cnt = 0;
  scanf("%d", &n);
  if (n == 3)
    printf("1 1 3");
  else {
    int x = n;
    for (i = 1; x > 3; i <<= 1) {
      int y = x - x / 2;
      x /= 2;
      for (j = 1; j <= y; ++j) printf("%d ", i), cnt++;
    }
    if (x == 3) printf("%d %d %d", i, i, i * 3);
    if (x == 2) printf("%d %d", i, i * 2);
    if (x == 1) printf("%d", i);
  }
}
