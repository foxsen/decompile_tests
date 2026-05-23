#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, a[1005], k = 0, b[1005];
  bool flag = 0;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  for (i = 0; i < n / 2; ++i) {
    b[k] = a[i];
    b[k + 1] = a[n - 1 - i];
    k += 2;
  }
  if (n % 2 == 1) {
    b[k] = a[n / 2];
    k++;
  }
  for (i = 1; i < k; ++i) {
    if (i % 2 == 1) {
      if (b[i] < b[i - 1]) {
        flag = 1;
      }
    } else {
      if (b[i] > b[i - 1]) {
        flag = 1;
      }
    }
  }
  if (!flag) {
    for (i = 0; i < k; ++i) {
      printf("%d ", b[i]);
    }
  } else {
    printf("Impossible\n");
  }
}
