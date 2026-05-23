#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, a[N], b[N], st[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%1d", &st[i]);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
  int ans = 0;
  for (int i = 1; i <= 100000; i++) {
    int sum = 0;
    for (int j = 1; j <= n; j++) {
      sum += st[j];
      if (i >= b[j] && (i - b[j]) % a[j] == 0) st[j] ^= 1;
    }
    ans = max(ans, sum);
  }
  printf("%d\n", ans);
  return 0;
}
