#include <bits/stdc++.h>
using namespace std;
int a[10005], f[10005][4], q[28000], h2[10005], h3[10005], n, or230[27500],
    or2900[27500];
char toc[200];
int main() {
  char in = getchar();
  while (in != '\n') a[++n] = in - 'a' + 1, in = getchar();
  for (int i = 6; i <= n; i++)
    h2[i] = a[i] * 900 + a[i + 1] * 30, h3[i] = h2[i] + a[i + 2];
  if (n < 7) {
    printf("0\n");
    return 0;
  }
  f[n + 1][2] = f[n + 1][3] = 1, f[n - 1][2] = 1;
  q[h2[n - 1]] = 1;
  for (char c = 'a'; c <= 'z'; c++) toc[c - 'a' + 1] = c;
  for (int i = 0; i < 30; i++)
    for (int j = 30; j <= 27000; j += 30) or230[i + j] = i;
  for (int i = 0; i < 900; i++)
    for (int j = 900; j <= 27000; j += 900) or2900[i + j] = i;
  for (int i = n - 2; i > 5; i--) {
    if (f[i + 2][3] || (f[i + 2][2] && h2[i] != h2[i + 2]))
      f[i][2] = 1, q[h2[i]] = 1;
    if (f[i + 3][2] || (f[i + 3][3] && h3[i] != h3[i + 3]))
      f[i][3] = 1, q[h3[i]] = 1;
  }
  int ans = 0;
  for (int i = 1; i <= 27500; i++) ans += q[i];
  printf("%d\n", ans);
  for (int i = 1; i <= 27500; i++) {
    if (!q[i]) continue;
    if (or230[i])
      putchar(toc[i / 900]), putchar(toc[or2900[i] / 30]),
          putchar(toc[or230[i]]), putchar('\n');
    else
      putchar(toc[i / 900]), putchar(toc[or2900[i] / 30]), putchar('\n');
  }
  return 0;
}
