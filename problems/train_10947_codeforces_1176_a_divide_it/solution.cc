#include <bits/stdc++.h>
using namespace std;
long long q, ans, a[2001];
int main() {
  scanf("%lld", &q);
  for (int i = 1; i <= q; i++) {
    ans = 0;
    scanf("%lld", &a[i]);
    while (a[i] % 5 == 0) {
      a[i] /= 5;
      a[i] *= 4;
      ans++;
    }
    while (a[i] % 3 == 0) {
      a[i] /= 3;
      a[i] *= 2;
      ans++;
    }
    while (a[i] % 2 == 0) {
      a[i] /= 2;
      ans++;
    }
    if (a[i] == 1) {
      printf("%lld\n", ans);
    } else
      printf("-1\n");
  }
}
