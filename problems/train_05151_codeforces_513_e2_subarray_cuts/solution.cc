#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkmax(T &x, T y) {
  x = x > y ? x : y;
}
template <typename T>
void chkmin(T &x, T y) {
  x = x > y ? y : x;
}
const int INF = (1ll << 30) - 1;
template <typename T>
void read(T &x) {
  x = 0;
  bool f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = 0;
  } while (ch > '9' || ch < '0');
  do {
    x = x * 10 + ch - '0';
    ch = getchar();
  } while (ch >= '0' && ch <= '9');
  x = f ? x : -x;
}
template <typename T>
void write(T x) {
  if (x < 0) x = ~x + 1, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const int N = 3e4 + 5;
const int K = 200 + 5;
int n, m, a[N], f[N][K][4];
int main() {
  read(n);
  read(m);
  memset(f, -0x3f, sizeof(f));
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j < 4; j++) f[i][0][j] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x = 1 + (j != 1 && j != m);
      f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j - 1][3]) + x * a[i];
      f[i][j][1] = max(f[i][j][0], f[i - 1][j][1]);
      f[i][j][2] = max(f[i - 1][j][2], f[i - 1][j - 1][1]) - x * a[i];
      f[i][j][3] = max(f[i][j][2], f[i - 1][j][3]);
      if (x == 2) f[i][j][1] = max(f[i][j][1], f[i - 1][j - 1][1]);
      if (x == 2) f[i][j][3] = max(f[i][j][3], f[i - 1][j - 1][3]);
    }
  }
  int ans = 0;
  for (int i = 0; i < 4; i++) chkmax(ans, f[n][m][i]);
  printf("%d\n", ans);
  return 0;
}
