#include <bits/stdc++.h>
using namespace std;
namespace FGF {
int n, m, ans;
const int N = 3e5 + 5, mo = 998244353;
int a[N], f[N], inv[N];
void work() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), m += a[i];
  inv[1] = 1;
  for (int i = 2; i <= m; i++) inv[i] = 1ll * inv[mo % i] * (mo - mo / i) % mo;
  for (long long i = 1, y; i < m; i++)
    y = i * (n - 1) % mo * inv[m - i] % mo,
    f[i + 1] =
        (((y + 1) % mo * f[i] % mo - y * (f[i - 1] + 1) % mo) % mo + mo) % mo;
  for (int i = 1; i <= n; i++) ans = (ans + f[a[i]]) % mo;
  printf("%d\n", (ans - f[m] + mo) % mo);
}
}  // namespace FGF
int main() {
  FGF::work();
  return 0;
}
