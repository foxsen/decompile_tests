#include <bits/stdc++.h>
using namespace std;
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
long long add(long long a, long long b) {
  long long ret = a + b;
  if (ret >= 7340033) ret -= 7340033;
  return ret;
}
long long subtract(long long a, long long b) {
  long long ret = a - b;
  if (ret < 0) ret += 7340033;
  return ret;
}
long long mult(long long a, long long b) {
  long long ret = a * b;
  if (ret >= 7340033) ret %= 7340033;
  return ret;
}
long long bigmod(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = mult(ret, a);
    b >>= 1;
    a = mult(a, a);
  }
  return ret;
}
int dp2[40][1007], dp4[40][1007];
int main() {
  int i, j, k, l, q, n;
  dp4[0][0] = 1;
  for (i = 1; i < 35; i++) {
    for (j = 0; j <= 1000; j++) {
      for (k = 0; k <= j; k++) {
        l = j - k;
        dp2[i][j] = add(dp2[i][j], mult(dp4[i - 1][k], dp4[i - 1][l]));
      }
    }
    dp4[i][0] = 1;
    for (j = 0; j <= 1000; j++) {
      for (k = 0; k < j; k++) {
        l = j - k - 1;
        dp4[i][j] = add(dp4[i][j], mult(dp2[i][k], dp2[i][l]));
      }
    }
  }
  scanf("%d", &q);
  while (q--) {
    scanf("%d %d", &n, &k);
    i = 0;
    while ((n & 1) && (n > 1)) {
      i++;
      n /= 2;
    };
    printf("%d\n", dp4[i][k]);
  }
  return 0;
}
