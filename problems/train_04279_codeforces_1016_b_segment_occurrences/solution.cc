#include <bits/stdc++.h>
using namespace std;
void qmax(int &x, int y) {
  if (x < y) x = y;
}
void qmin(long long &x, long long y) {
  if (x > y) x = y;
}
inline long long read() {
  char s;
  long long k = 0, base = 1;
  while ((s = getchar()) != '-' && s != EOF && !(isdigit(s)))
    ;
  if (s == EOF) exit(0);
  if (s == '-') base = -1, s = getchar();
  while (isdigit(s)) {
    k = k * 10 + (s ^ '0');
    s = getchar();
  }
  return k * base;
}
inline void write(int x) {
  static char cnt, num[15];
  cnt = 0;
  if (!x) {
    putchar('0');
    return;
  }
  for (; x; x /= 10) num[++cnt] = x % 10;
  for (; cnt; putchar(num[cnt--] + 48))
    ;
}
int n, m, q;
char b[1010], a[1010];
int dp[1010][1010];
int Next[1010];
int main() {
  n = read(), m = read(), q = read();
  scanf("%s", b + 1);
  scanf("%s", a + 1);
  int p;
  Next[1] = 0;
  p = 0;
  for (int i = 2; i <= m; i++) {
    while (p && a[p + 1] != a[i]) p = Next[p];
    if (a[p + 1] == a[i]) {
      p++;
      Next[i] = p;
    }
  }
  p = 0;
  for (int i = 1; i <= n; i++) {
    while ((p == m) || (p && a[p + 1] != b[i])) p = Next[p];
    if (a[p + 1] == b[i]) {
      p++;
    }
    if (p == m) {
      dp[i - m + 1][i] = 1;
    }
  }
  for (int l = m; l < n; l++)
    for (int i = 1, j = i + l; j <= n; i++, j++) {
      dp[i][j] = dp[i][j - 1];
      if (j - m + 1 > 0) dp[i][j] = dp[i][j - 1] + dp[j - m + 1][j];
    }
  int X, Y;
  while (q--) {
    X = read();
    Y = read();
    printf("%d\n", dp[X][Y]);
  }
  return 0;
}
