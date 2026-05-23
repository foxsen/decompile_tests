#include <bits/stdc++.h>
const int maxn = 5e5 + 10;
using namespace std;
int n;
int l, r, k, gap;
long long a[maxn], x, pre[maxn], tmp;
bool f;
int main() {
  scanf("%d", &n);
  l = ceil(1.0 * n / 2);
  r = n - l;
  for (int i = 1; i <= l; i++) scanf("%lld", &a[i]), pre[i] = pre[i - 1] + a[i];
  scanf("%lld", &x);
  for (int i = l + 1; i <= n; i++) pre[i] = pre[i - 1] + x;
  if (x >= 0) {
    if (pre[n] <= 0)
      printf("-1\n");
    else
      printf("%d\n", n);
  } else {
    long long Min = 1e18;
    for (int i = 0; i < l; i++) {
      long long tmp = pre[n] - pre[i];
      if (Min == 1e18)
        Min = tmp;
      else {
        Min -= x;
        Min = min(Min, tmp);
      }
      if (Min > 0) {
        printf("%d\n", n - i);
        return 0;
      }
    }
    printf("-1\n");
  }
  return 0;
}
