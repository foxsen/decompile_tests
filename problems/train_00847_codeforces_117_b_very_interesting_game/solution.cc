#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, mod;
  scanf("%d%d%d", &a, &b, &mod);
  int n = min(a, mod - 1);
  long long t = 1000000000 % mod;
  for (int i = 1; i <= n; i++) {
    long long p;
    p = t * i % mod;
    if (p == 0) continue;
    if (b < mod - p) {
      printf("1 %09d\n", i);
      return 0;
    }
  }
  printf("2\n");
  return 0;
}
