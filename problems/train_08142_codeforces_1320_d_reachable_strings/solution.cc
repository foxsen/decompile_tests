#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const LL H = 998244353;
LL n, q, s[200010], sum[200010], h[2][200010];
char str[200010];
LL pw(LL x, LL p) {
  if (!p) return 1;
  LL t = pw(x, p / 2);
  if (p % 2)
    return t * t % H * x % H;
  else
    return t * t % H;
}
int main() {
  scanf("%lld%s%lld", &n, str + 1, &q);
  LL l = 0;
  for (LL i = 1; i <= n; i++)
    if (str[i] == '0') {
      sum[i] = sum[i - 1] + 1;
      s[++l] = i % 2;
    } else
      sum[i] = sum[i - 1];
  for (LL i = 1; i <= l; i++) {
    h[0][i] = (h[0][i - 1] * 2 + s[i]) % H;
    h[1][i] = (h[1][i - 1] * 2 + 1 - s[i]) % H;
  }
  while (q--) {
    LL p1, p2, len, q1, q2, c1, c2, h1, h2;
    scanf("%lld%lld%lld", &p1, &p2, &len);
    q1 = sum[p1 - 1], c1 = sum[p1 + len - 1] - q1;
    q2 = sum[p2 - 1], c2 = sum[p2 + len - 1] - q2;
    if (c1 != c2) {
      puts("No");
      continue;
    }
    h1 = ((h[p1 % 2][q1 + c1] - h[p1 % 2][q1] * pw(2, c1)) % H + H) % H;
    h2 = ((h[p2 % 2][q2 + c2] - h[p2 % 2][q2] * pw(2, c2)) % H + H) % H;
    if (h1 == h2)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
