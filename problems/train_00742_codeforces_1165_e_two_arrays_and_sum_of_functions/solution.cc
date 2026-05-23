#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
const int mod = 998244353;
long long a[maxn];
long long b[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    a[i] = a[i] * (n - i + 1) * i;
  }
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + n);
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    ans = (ans + a[i] % mod * b[n - i + 1] % mod) % mod;
  printf("%lld\n", ans);
  return 0;
}
