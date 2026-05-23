#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int x = 0;
  register int y = 1;
  register char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') y = 0;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + (c ^ 48);
    c = getchar();
  }
  return y ? x : -x;
}
char s[3005], t[3005];
int f[3005][3005];
int main() {
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  int n = strlen(s + 1), m = strlen(t + 1);
  for (register int i = 1; i <= m; i++) f[i][i] = (s[1] == t[i]) << 1;
  for (register int i = m + 1; i <= n; i++) f[i][i] = 2;
  for (register int i = 2, len = 2; i <= n; i++, len++) {
    for (register int l = 1, r = len; r <= n; l++, r++) {
      if (l > m || s[i] == t[l]) f[l][r] += f[l + 1][r], f[l][r] %= 998244353;
      if (r > m || s[i] == t[r]) f[l][r] += f[l][r - 1], f[l][r] %= 998244353;
    }
  }
  int ans = 0;
  for (register int i = m; i <= n; i++) ans = (ans + f[1][i]) % 998244353;
  printf("%d", ans);
  return 0;
}
