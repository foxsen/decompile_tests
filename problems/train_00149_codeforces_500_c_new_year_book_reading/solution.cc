#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
inline int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    ch = getchar();
    if (ch == '-') w = -1;
  }
  while (ch <= '9' && ch >= '0') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * w;
}
int n, m, tot, s[N], Ans;
int a[N], w[N], ans[N];
bool vis[N];
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) w[i] = read();
  for (int i = 1; i <= m; ++i) {
    a[i] = read();
    memset(vis, 0, sizeof(vis));
    for (int j = i - 1; j; --j) {
      if (a[i] == a[j]) break;
      if (vis[a[j]]) continue;
      vis[a[j]] = 1;
      Ans += w[a[j]];
    }
  }
  printf("%d\n", Ans);
  return 0;
}
