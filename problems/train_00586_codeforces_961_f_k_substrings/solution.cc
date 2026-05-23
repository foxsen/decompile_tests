#include <bits/stdc++.h>
const int P = 233;
const int P2 = 131;
const int maxn = 1000000 + 3;
const int MOD = 1000000007;
inline int getint() {
  bool flag = 0;
  register int n = 0;
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    n = ch - '0' + (n << 3) + (n << 1);
    ch = getchar();
  }
  return flag ? (-n) : n;
}
int n;
int k;
int now;
int F[maxn];
int F2[maxn];
char s[maxn];
int ans[maxn];
int hash[maxn];
int hash2[maxn];
inline int Gethash(int l, int r) {
  return (hash[r] - 1ll * hash[l - 1] * F[r - l + 1] % MOD + MOD) % MOD;
}
inline int Gethash2(int l, int r) {
  return (hash2[r] - 1ll * hash2[l - 1] * F2[r - l + 1] % MOD + MOD) % MOD;
}
int main() {
  F[0] = 1;
  for (int i = 1; i < maxn; i++) F[i] = 1ll * F[i - 1] * P % MOD;
  F2[0] = 1;
  for (int i = 1; i < maxn; i++) F2[i] = 1ll * F2[i - 1] * P2 % MOD;
  n = getint();
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++)
    hash[i] = (1ll * hash[i - 1] * P % MOD + s[i] - 'a' + 1) % MOD,
    hash2[i] = (1ll * hash2[i - 1] * P2 % MOD + s[i] - 'a' + 1) % MOD;
  k = (n + 1) >> 1;
  now = 1;
  int cur = k;
  while (cur) {
    int len = n - cur + 1 - cur + 1;
    now = std::min(now, (len & 1) ? len - 2 : len - 1);
    while (now > -1 &&
           Gethash(cur, cur + now - 1) !=
               Gethash(cur + len - 1 - now + 1, cur + len - 1) &&
           Gethash2(cur, cur + now - 1) !=
               Gethash2(cur + len - 1 - now + 1, cur + len - 1))
      now -= 2;
    ans[cur] = now;
    cur--;
    now += 2;
  }
  for (int i = 1; i <= k; i++) printf("%d ", ans[i]);
  return 0;
}
