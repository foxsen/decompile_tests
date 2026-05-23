#include <bits/stdc++.h>
using namespace std;
int a[4] = {1, 2, 3, 5};
int main(void) {
  int n, k;
  scanf("%d%d", &n, &k);
  printf("%d\n", (5 + 6 * (n - 1)) * k);
  for (int i = 0; i < n; i++) {
    printf("%d %d %d %d\n", (a[0] + 6 * i) * k, (a[1] + 6 * i) * k,
           (a[2] + 6 * i) * k, (a[3] + 6 * i) * k);
  }
}
