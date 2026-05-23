#include <bits/stdc++.h>
using namespace std;
int n, m, sum;
int a[101];
long double f[101000], s[101000], ans;
int main() {
  cin >> n >> m;
  if (m == 1) {
    printf("1.0000000000000000\n");
    return 0;
  }
  f[0] = m - 1;
  int now = 0;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), sum += a[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m * i; j++) s[j] = 0;
    for (int j = 0; j <= m * i; j++) {
      if (f[j] < 1e-12) continue;
      s[j + 1] += f[j];
      s[j + a[i]] -= f[j];
      s[j + a[i] + 1] += f[j];
      s[j + m + 1] -= f[j];
    }
    for (int j = 1; j <= m * i; j++) s[j] += s[j - 1];
    for (int j = 0; j <= m * i; j++) f[j] = s[j] / (m - 1);
  }
  for (int i = 0; i < sum; i++) ans += f[i];
  printf("%.16lf\n", (double)ans + 1);
}
