#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  unsigned long long sum1 = 0, ans, sum2 = 0;
  for (int i = n - 1; i >= (n / 2); i--) {
    sum1 += a[i];
  }
  for (int i = 0; i < (n / 2); i++) {
    sum2 += a[i];
  }
  ans = sum1 * sum1 + sum2 * sum2;
  printf("%llu", ans);
  return 0;
}
