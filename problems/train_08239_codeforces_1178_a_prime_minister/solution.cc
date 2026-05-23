#include <bits/stdc++.h>
using namespace std;
int a[1000], n, b[1000];
int main() {
  scanf("%d", &n);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  int sum2 = a[1];
  b[1] = 1;
  int sum3 = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i] * 2 <= a[1]) {
      b[i] = 1;
      sum2 += a[i];
      sum3++;
    }
  }
  if (sum2 * 2 > sum) {
    printf("%d\n", sum3);
    for (int i = 1; i <= n; i++)
      if (b[i]) printf("%d ", i);
  } else
    puts("0");
  return 0;
}
