#include <bits/stdc++.h>
using namespace std;
int a[200005];
long long pre[200005];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int i;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    pre[i] = pre[i - 1] + a[i];
  }
  int kk = k;
  if (k > (n + 1) / 2) {
    k = k - (n + 1) / 2;
    k = n / 2 + 1 - k;
  }
  long long sum = 0;
  int lo, hi;
  lo = 1;
  hi = n;
  for (i = 1; i <= k; i++) {
    sum += pre[hi] - pre[lo - 1];
    lo++;
    hi--;
  }
  double ans = (sum * 1.0) / (n - kk + 1);
  printf("%.10f\n", ans);
}
