#include <bits/stdc++.h>
using namespace std;
long long dp[1111][1111][2];
const long long mod = 1000000007;
int lim, len;
char s[1111];
long long getdp(int l, int less, int last, int ok) {
  if (l == -1) return ok;
  long long &ret = dp[l][last][ok];
  if (!less && ret != -1) return ret;
  long long res = 0;
  int u;
  if (!less)
    u = 9;
  else
    u = s[l] - '0';
  if (ok == 1) {
    for (int i = 0; i <= u; i++) {
      int tl = 0;
      res += getdp(l - 1, less && i == u, 0, 1);
      if (res >= mod) res -= mod;
    }
    if (!less) ret = res;
    return res;
  }
  for (int i = 0; i <= u; i++) {
    int tl = 0;
    if (i == 4 || i == 7) {
      if (last != 1003 && last - l <= lim)
        res += getdp(l - 1, less && i == u, l, 1);
      else
        res += getdp(l - 1, less && i == u, l, 0);
    } else
      res += getdp(l - 1, less && i == u, last, 0);
    if (res >= mod) res -= mod;
  }
  if (!less) ret = res;
  return res;
}
long gao(char *x) {
  strcpy(s, x);
  len = strlen(s);
  reverse(s, s + len);
  return getdp(len - 1, 1, 1003, 0);
}
long long test(char *x) {
  int aa[1111], nn = 0, lll = strlen(x), i;
  for (i = 0; i < lll; i++)
    if (x[i] == '4' || x[i] == '7') aa[nn++] = i;
  for (i = 0; i < nn - 1; i++) {
    if (aa[i + 1] - aa[i] <= lim) return 1;
  }
  return 0;
}
void run() {
  int cas;
  scanf("%d%d", &cas, &lim);
  char l[1111], r[1111];
  while (cas--) {
    scanf("%s%s", l, r);
    long long ans = gao(r) - gao(l) + test(l);
    ans = (ans % mod + mod) % mod;
    cout << ans << endl;
  }
}
int main() {
  memset(dp, -1, sizeof(dp));
  run();
  return 0;
}
