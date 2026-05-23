#include <bits/stdc++.h>
void rd(int &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}
void lrd(long long &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}
const int INF = 1e9;
const long long LINF = 1e18;
const int N = 2050;
using namespace std;
int n, m;
int l[N], s[N], c[N << 1];
int f[N << 1][N];
int ans, mx[N];
int main() {
  rd(n);
  rd(m);
  for (int i = 1; i <= n; i++) rd(l[i]);
  for (int i = 1; i <= n; i++) rd(s[i]);
  for (int i = 1; i <= n + m; i++) rd(c[i]);
  for (int i = 1; i <= n; i++) s[i] = c[l[i]] - s[i];
  memset(f, -0x7f, sizeof(f));
  for (int i = 1; i <= m + 20; i++) f[i][0] = 0;
  for (int i = n; i >= 1; i--) {
    int u = l[i];
    for (int j = mx[u]; j >= 0; j--) {
      int x = f[u][j] + s[i], y = j + 1;
      for (int o = u; y;) {
        mx[o] = max(mx[o], y);
        f[o][y] = max(f[o][y], x);
        o++;
        y /= 2;
        x += c[o] * y;
      }
      ans = max(ans, x);
    }
    for (int i = 1; i <= m + 20; i++)
      f[i][0] = max(f[i][0], max(f[i - 1][0], f[i - 1][1]));
  }
  printf("%d\n", ans);
  return 0;
}
