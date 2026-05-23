#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long a, b, c, ans = 1;
    scanf("%lld%lld", &a, &b);
    c = b;
    for (long long i = 2, nowa; i * i <= c; i++)
      if (c % i == 0) {
        nowa = a;
        while (nowa % i == 0 && nowa % b == 0) nowa /= i;
        if (nowa % b != 0) ans = max(ans, nowa);
        while (c % i == 0) c /= i;
      }
    if (c > 1) {
      long long nowa = a;
      while (nowa % c == 0 && nowa % b == 0) nowa /= c;
      if (nowa % b != 0) ans = max(ans, nowa);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
