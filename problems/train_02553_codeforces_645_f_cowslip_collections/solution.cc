#include <bits/stdc++.h>
using namespace std;
int N, K, Q;
int freq[1000010];
long long F[1000010], inv[1000010], Finv[1000010];
long long C[1000010];
long long coef[1000010];
int minp[1000010];
long long query(int x) {
  long long ans = C[freq[x] + 1] - C[freq[x]] + 1000000007ll;
  if (ans >= 1000000007ll) ans -= 1000000007ll;
  ans = ans * coef[x] % 1000000007ll;
  freq[x]++;
  return ans;
}
int main(void) {
  int i, j;
  inv[1] = 1;
  for (i = 2; i < 1000010; i++)
    inv[i] = (1000000007ll - 1000000007ll / i) * inv[1000000007ll % i] %
             1000000007ll;
  F[0] = Finv[0] = 1;
  for (i = 1; i < 1000010; i++) F[i] = F[i - 1] * i % 1000000007ll;
  for (i = 1; i < 1000010; i++) Finv[i] = Finv[i - 1] * inv[i] % 1000000007ll;
  cin >> N >> K >> Q;
  for ((i) = 0; (i) < (int)(1000010); (i)++)
    if (i >= K)
      C[i] = F[i] * Finv[K] % 1000000007ll * Finv[i - K] % 1000000007ll;
  for (i = 2; i < 1000010; i++) minp[i] = i;
  for (i = 2; i < 1000010; i++)
    if (minp[i] == i)
      for (j = 2 * i; j < 1000010; j += i) minp[j] = min(minp[j], i);
  for (i = 1; i < 1000010; i++) {
    int n = i;
    int x = i;
    while (n > 1) {
      int p = minp[n];
      while (n % p == 0) n /= p;
      x -= x / p;
    }
    coef[i] = x;
  }
  long long ans = 0;
  for ((i) = 0; (i) < (int)(N + Q); (i)++) {
    int x;
    scanf("%d", &x);
    for (int d = 1; d * d <= x; d++)
      if (x % d == 0) {
        ans += query(d);
        if (d * d != x) ans += query(x / d);
      }
    ans %= 1000000007ll;
    if (i >= N) printf("%I64d\n", ans);
  }
  return 0;
}
