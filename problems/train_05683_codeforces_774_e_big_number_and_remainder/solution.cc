#include <bits/stdc++.h>
using namespace std;
char s[400010];
long long m, slen, g[200010];
long long pow10(long long n) {
  long long ans = 1, a = 10;
  while (n) {
    if (n & 1) ans = (ans * a) % m;
    n >>= 1;
    a = (a * a) % m;
  }
  return ans % m;
}
signed main() {
  long long ans, cnt0, powww;
  scanf("%s", s);
  scanf("%lld", &m);
  slen = strlen(s);
  for (long long i = slen; i < 2 * slen; i++) {
    s[i] = s[i - slen];
  }
  for (long long i = slen - 1; i >= 0; i--) {
    g[1] = (g[1] + (s[i] - '0') * pow10(slen - i - 1)) % m;
  }
  ans = g[1];
  cnt0 = 0;
  powww = pow10(slen - 1);
  for (long long i = 2; i <= slen; i++) {
    g[i] =
        (g[i - 1] - ((s[i - 2] - '0') * powww)) % m * 10 % m + (s[i - 2] - '0');
    g[i] %= m;
    if (g[i] < 0) g[i] += m;
    if (s[i - 1] - '0' != 0 && ans > g[i]) ans = g[i];
  }
  printf("%lld\n", ans);
  return 0;
}
