#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100003;
int n;
long long a[MAX_N];
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%I64d", &a[i]);
  a[n] = 0;
  long long g = 0;
  for (int i = 0; i < n; i++) {
    g = gcd(g, a[i]);
    if (g == 1) break;
  }
  printf("YES\n");
  if (g > 1)
    printf("0\n");
  else {
    int res = 0;
    for (int i = 1; i <= n; i++) {
      while (a[i - 1] & 1) {
        int tmp = a[i - 1];
        a[i - 1] -= a[i];
        a[i] += tmp;
        res++;
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
