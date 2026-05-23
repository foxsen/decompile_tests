#include <bits/stdc++.h>
using namespace std;
int mod;
bool prime(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) return 0;
  }
  return 1;
}
int fastpower(int b, int p) {
  int res = 1;
  int v = b;
  while (p) {
    if (p & 1) res = (1ll * v * res) % mod;
    v = (1ll * v * v) % mod;
    p /= 2;
  }
  return res;
}
int main() {
  scanf("%d", &mod);
  if (mod == 1) {
    puts("YES\n1");
    return 0;
  } else if (mod == 4) {
    puts("YES\n1\n3\n2\n4");
    return 0;
  } else {
    if (!prime(mod)) {
      puts("NO");
      return 0;
    }
    puts("YES\n1");
    for (int i = 2; i < mod; ++i) {
      printf("%lld\n", (1ll * i * fastpower(i - 1, mod - 2)) % mod);
    }
    printf("%d\n", mod);
  }
}
