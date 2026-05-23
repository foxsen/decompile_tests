#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
struct Shield {
  long long a, b;
  int idx;
  Shield() {}
  bool operator<(const Shield &r) const { return b > r.b; }
} sh[200002];
long long mpow(long long x, long long y) {
  if (!y) return 1;
  if (y & 1) return mpow(x, y - 1) * x % MOD;
  long long tmp = mpow(x, y / 2);
  return tmp * tmp % MOD;
}
int n, m;
long long arr[200002];
long long sum[200002];
long long an[200002];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &arr[i]);
  }
  sort(arr + 1, arr + n + 1);
  reverse(arr + 1, arr + n + 1);
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + arr[i];
  for (int i = 1; i <= m; i++) {
    scanf("%lld %lld", &sh[i].a, &sh[i].b);
    sh[i].idx = i;
  }
  sort(sh + 1, sh + m + 1);
  long long pnt = 0;
  for (int i = 1; i <= m; i++) {
    while (pnt < n && arr[pnt + 1] >= sh[i].b) pnt++;
    if (pnt < sh[i].a) continue;
    long long ans;
    ans = (sum[pnt] % MOD) * (pnt - sh[i].a) % MOD * (pnt + 1) % MOD;
    ans += (sum[n] - sum[pnt]) % MOD * (pnt - sh[i].a + 1) % MOD * pnt % MOD;
    ans %= MOD;
    ans *= mpow(pnt, MOD - 2);
    ans %= MOD;
    ans *= mpow(pnt + 1, MOD - 2);
    ans %= MOD;
    an[sh[i].idx] = ans;
  }
  for (int i = 1; i <= m; i++) {
    printf("%lld\n", an[i]);
  }
}
