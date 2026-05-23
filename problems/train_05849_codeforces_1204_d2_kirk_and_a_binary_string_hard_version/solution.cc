#include <bits/stdc++.h>
static char buf[100000], *pa(buf), *pb(buf);
inline int read() {
  register int x(0);
  register char c(
      pa == pb && (pb = (pa = buf) + fread(buf, 1, 100000, stdin), pa == pb)
          ? EOF
          : *pa++);
  while ((c < '0' || c > '9') && c != '-')
    c = pa == pb && (pb = (pa = buf) + fread(buf, 1, 100000, stdin), pa == pb)
            ? EOF
            : *pa++;
  register int f(c == '-' ? c = pa == pb && (pb = (pa = buf) +
                                                  fread(buf, 1, 100000, stdin),
                                             pa == pb)
                                    ? EOF
                                    : *pa++,
                 -1       : 1);
  while (c >= '0' && c <= '9')
    x = x * 10 + c - 48,
    c = pa == pb && (pb = (pa = buf) + fread(buf, 1, 100000, stdin), pa == pb)
            ? EOF
            : *pa++;
  return x * f;
}
const int maxn = 100100;
int n, m;
char s[maxn];
int num[maxn], ans[maxn];
int f[maxn], g[maxn], cnt;
inline int max(int a, int b) { return a > b ? a : b; }
int main() {
  scanf("%s", s + 1);
  while (s[n + 1]) ++n;
  for (register int i = 1; i <= n; ++i) num[i] = s[i] - '0';
  for (register int i = 1; i <= n; ++i) {
    f[i] = f[i - 1];
    g[i] = g[i - 1];
    if (num[i])
      f[i] = max(f[i - 1], g[i - 1]) + 1;
    else
      g[i] = g[i - 1] + 1;
  }
  if (g[n] >= f[n]) {
    printf("%s", s + 1);
    return 0;
  }
  cnt = f[n] - g[n];
  for (register int i = n; i >= 1; --i) {
    if (num[i] == 0)
      ans[i] = 0;
    else {
      if (cnt > 0 && f[i] - g[i] == cnt) {
        ans[i] = 0;
        --cnt;
      } else
        ans[i] = 1;
    }
  }
  for (register int i = 1; i <= n; ++i) printf("%d", ans[i]);
  puts("");
  return 0;
}
