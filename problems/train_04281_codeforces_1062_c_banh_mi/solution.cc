#include <bits/stdc++.h>
long long n, t, i, j, arr[1000004], a, b, store, arr1[1000004], ans,
    final[1000004], ans1;
long long aa, mod = 1000000007, zero[1000004], one[1000004], zer, on,
              final1[1000004];
char name[1000004];
using namespace std;
int main() {
  scanf("%lld %lld", &n, &t);
  scanf("%s", name);
  store = 0;
  ans = 0;
  for (i = 1; i <= 1000000; i++) {
    ans = (ans + store + 1) % mod;
    final[i] = ans;
    store = ans % mod;
  }
  aa = 2;
  final[0] = 0;
  final1[0] = 1;
  for (i = 1; i <= 1000000; i++) {
    if (i == 1) {
      final1[i] = 2;
    } else {
      final1[i] = ((final1[i - 1] % mod) * 2) % mod;
    }
  }
  for (i = 0; i < n; i++) {
    arr[i] = (int)name[i] - '0';
  }
  for (i = 0; i < n; i++) {
    if (i == 0) {
      if (arr[0] == 0) {
        zero[0] = 1;
        one[0] = 0;
      } else {
        zero[0] = 0;
        one[0] = 1;
      }
    } else {
      if (arr[i] == 1) {
        zero[i] = zero[i - 1];
        one[i] = one[i - 1] + 1;
      } else {
        zero[i] = zero[i - 1] + 1;
        one[i] = one[i - 1];
      }
    }
  }
  while (t--) {
    ans = 0;
    j = 0;
    scanf("%lld %lld", &a, &b);
    if (a == 1) {
      zer = zero[b - 1];
      on = one[b - 1];
    } else {
      zer = zero[b - 1] - zero[a - 2];
      on = one[b - 1] - one[a - 2];
    }
    ans = final[on];
    ans1 = final1[zer];
    ans = ((ans1 % mod) * (ans % mod)) % mod;
    printf("%lld\n", ans);
  }
}
