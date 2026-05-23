#include <bits/stdc++.h>
using namespace std;
const int INF = 1061109567;
const long long LINF = 4557430888798830399ll;
const int MOD = 1000000007;
int a[400005];
pair<int, int> p[400005];
int l[400005];
int suffix0[400005];
int suffix1[400005];
void test_case() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  int ans = 0;
  for (int BIT = 0; BIT <= 26; ++BIT) {
    int BITMASK = (1 << BIT) - 1;
    for (int i = 1; i <= n; ++i) {
      p[i].first = a[i] & BITMASK;
      p[i].second = (a[i] >> BIT) & 1;
    }
    sort(p + 1, p + 1 + n);
    suffix0[n + 1] = 0;
    suffix1[n + 1] = 0;
    for (int i = n; i >= 1; --i) {
      suffix0[i] = suffix0[i + 1] + (p[i].second == 0);
      suffix1[i] = suffix1[i + 1] + (p[i].second == 1);
      l[i] = p[i].first;
    }
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
      int pos = upper_bound(l + i + 1, l + n + 1, BITMASK - l[i]) - l;
      if (p[i].second == 0)
        sum += suffix0[pos] + suffix1[i + 1] - suffix1[pos];
      else
        sum += suffix1[pos] + suffix0[i + 1] - suffix0[pos];
    }
    if (sum % 2 == 1) ans |= (1 << BIT);
    continue;
  }
  printf("%d\n", ans);
}
int main() {
  int t = 1;
  for (int i = 1; i <= t; ++i) {
    test_case();
  }
  return 0;
}
