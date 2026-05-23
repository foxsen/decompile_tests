#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000010;
long long a[MAXN];
long long b[32];
int main() {
  int n, temp = 1;
  long long i;
  b[0] = 0;
  for (i = 1; i <= 30; i++) {
    temp = 2 * temp;
    b[i] = temp - 1;
  }
  scanf("%d", &n);
  long long ans = 0;
  int j = 0;
  memset(a, -1, sizeof(a));
  for (j = 0; j <= 30; j++) {
    if (b[j] >= n) break;
  }
  for (i = n; i >= 0; i--) {
    if (j && b[j - 1] >= i) j--;
    if (a[i] != -1) continue;
    a[i] = i ^ b[j];
    a[a[i]] = i;
    ans += 2 * (a[i] ^ i);
  }
  printf("%lld\n", ans);
  for (i = 0; i <= n; i++) printf("%lld ", a[i]);
  printf("\n");
  return 0;
}
