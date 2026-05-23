#include <bits/stdc++.h>
long long f1, f2;
int main() {
  f1 = 1;
  f2 = 2;
  long long N;
  scanf("%lld", &N);
  long long x = f1 + f2, ans = 1;
  while (x <= N) {
    f1 = f2;
    f2 = x;
    x = f1 + f2;
    ans++;
  }
  printf("%lld\n", ans);
  return 0;
}
