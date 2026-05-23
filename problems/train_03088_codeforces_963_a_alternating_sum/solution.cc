#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 9;
const int MAXN = 1e5 + 5;
long long n, a, b, k, res, ans;
char s[MAXN];
long long qpow(long long a, long long p) {
  long long res = 1;
  while (p) {
    if (p & 1) res = res * a % MOD;
    a = a * a % MOD;
    p >>= 1;
  }
  return res;
}
int main() {
  cin >> n >> a >> b >> k;
  scanf("%s", s + 1);
  long long v = qpow(a, MOD - 2), x = qpow(a, n), len = (n + 1) / k;
  for (int i = 1; i <= k; i++) {
    if (s[i] == '+')
      res = (res + x) % MOD;
    else
      res = (res - x) % MOD;
    x = x * v % MOD * b % MOD;
  }
  x = qpow(v, k) * qpow(b, k) % MOD;
  if (x == 1)
    ans = res * len % MOD;
  else
    ans = res * (qpow(x, len) - 1) % MOD * qpow(x - 1, MOD - 2) % MOD;
  if (ans < 0) ans += MOD;
  cout << ans << endl;
  return 0;
}
