#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 15;
int a[maxn], b[maxn];
int sum1, sum2;
int n, m;
int pow_mod(int a, int k, int mod) {
  int ret = 1;
  while (k) {
    if (k & 1) ret = 1LL * ret * a % mod;
    a = 1LL * a * a % mod;
    k >>= 1;
  }
  return ret;
}
void get_data() {
  scanf("%d%d", &m, &n);
  sum1 = sum2 = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum1 = (sum1 + a[i]) % m;
    sum2 = (sum2 + 1LL * a[i] * a[i] % m) % m;
  }
}
void infinity() {
  sort(a, a + n);
  if (n == 1) {
    printf("%d 0\n", a[0]);
    return;
  }
  if (n == m) {
    printf("%d 1\n", a[0]);
    return;
  }
  for (int i = 1; i < n; i++) {
    int d = (a[i] - a[0] + m) % m;
    int fst = 1LL * (sum1 - 1LL * n * (n - 1) / 2 % m * d % m + m) *
              pow_mod(n, m - 2, m) % m;
    int sum = 1LL * n * fst % m * fst % m;
    sum = (sum + 1LL * n % m * (n - 1) % m * fst % m * d % m) % m;
    sum = (sum + 1LL * (n - 1) * n * (2 * n - 1) / 6 % m * d % m * d % m) % m;
    if (sum == sum2) {
      b[0] = fst;
      for (int j = 1; j < n; j++) b[j] = (b[j - 1] + d) % m;
      sort(b, b + n);
      int flag = 1;
      for (int j = 0; j < n; j++)
        if (a[j] != b[j]) {
          flag = 0;
          break;
        }
      if (flag) {
        printf("%d %d\n", fst, d);
        return;
      }
    }
  }
  puts("-1");
  return;
}
int main() {
  get_data();
  infinity();
  return 0;
}
