#include <bits/stdc++.h>
int main() {
  int n, a[100], i;
  float sum;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  sum = sum / n;
  printf("%f", sum);
}
