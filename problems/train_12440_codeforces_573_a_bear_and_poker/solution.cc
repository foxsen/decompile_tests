#include <bits/stdc++.h>
using namespace std;
const int nm = 100010;
int n, a[nm];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    while (a[i] % 2 == 0) a[i] >>= 1;
    while (a[i] % 3 == 0) a[i] /= 3;
    if (i > 1 && a[i] != a[i - 1]) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
}
