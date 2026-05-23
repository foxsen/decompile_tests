#include <bits/stdc++.h>
const int maxn = 3e5 + 7;
const int inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
using namespace std;
long long a[maxn], b[maxn];
int main() {
  long long n, m, sum = 0;
  scanf("%lld%lld", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%lld", a + i);
    sum += a[i] * m;
  }
  for (int i = 0; i < m; i++) scanf("%lld", b + i);
  sort(a, a + n);
  sort(b, b + m);
  for (int i = 0; i < m; i++) sum += b[i] - a[n - 1];
  if (b[0] != a[n - 1]) {
    sum = sum - (b[0] - a[n - 1]) + (b[0] - a[n - 2]);
  }
  if (a[n - 1] > b[0]) sum = -1;
  printf("%lld\n", sum);
  return 0;
}
