#include <bits/stdc++.h>
using namespace std;
int n, m;
long long ans;
int main() {
  scanf("%d%d", &n, &m);
  n++;
  m++;
  for (int i = m; i * 2 <= n; i++)
    for (int j = m, k = n - m; j <= n - m; j++) {
      for (; k >= m && (j - 2 * i) * (2 * (i - n) + k) - 3 * j * k <= 0; k--)
        ;
      if (k < m) break;
      ans += (k - m + 1) * (i * 2 == n ? 1 : 2);
    }
  printf("%lld\n", ans * 3);
}
