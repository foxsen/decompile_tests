#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const long long P = 1e9 + 7;
int n, f[N][N * 2];
long long a[N], b[N], cnt[N];
int main() {
  cin >> n;
  cnt[1] = 1;
  for (int i = (1); i <= (n - 1); i++) {
    scanf("%lld", &a[i]);
    cnt[i + 1] = cnt[i] * a[i] % P, b[i] = a[i] * a[i] % P;
  }
  for (int i = (n); i >= (1); i--) {
    f[i][0] = 2;
    for (int j = (1); j <= (n - i); j++)
      f[i][j] = f[i][j - 1] * a[i + j - 1] % P;
    f[i][0] = 1;
    for (int j = (2); j <= ((n - i) * 2); j++) {
      f[i][j] += b[i] * f[i + 1][j - 2] % P;
      if (f[i][j] >= P) f[i][j] -= P;
    }
  }
  for (int k = (1); k <= (n * 2 - 2); k++) {
    long long ans = 0;
    for (int i = (1); i <= (n); i++)
      (ans += (f[i][k] + (k > 1 && i > 1 ? P - f[i][k - 2] : 0)) * cnt[i]) %= P;
    printf("%lld ", ans * 500000004 % P);
  }
  return 0;
}
