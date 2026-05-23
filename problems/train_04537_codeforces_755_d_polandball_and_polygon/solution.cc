#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  if (k > n / 2) k = n - k;
  long long ans = 1;
  int j = 1, i, circle = 0;
  for (i = 0; i < n; i++) {
    if (j + k > n + 1) {
      ans += circle * 2 + 2;
      j = (j + k) % n;
      if (j == 0) j = n;
      circle++;
    } else {
      ans += circle * 2 + 1;
      j = (j + k) % n;
      if (j == 0) j = n;
    }
    printf(i == n - 1 ? "%lld\n" : "%lld ", ans);
  }
  return 0;
}
