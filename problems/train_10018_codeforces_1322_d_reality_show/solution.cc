#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  bool flag = false;
  while (!isdigit(c)) {
    if (c == '-') flag = true;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  if (flag) x = -x;
}
int n, m;
int l[4010], s[4010], c[4010], t[4010], f[4010][4010];
int main() {
  read(n), read(m), t[0] = n, m += n;
  for (int i = 1; i <= n; ++i) t[i] = t[i - 1] >> 1;
  for (int i = n; i; --i) read(l[i]);
  for (int i = n; i; --i) read(s[i]);
  for (int i = 1; i <= m; ++i) read(c[i]);
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) f[i][j] = -1000000000;
  for (int i = 1; i <= n; ++i) {
    int v = l[i];
    for (int j = n; j; --j) f[v][j] = max(f[v][j], f[v][j - 1] + c[v] - s[i]);
    for (int j = v; j <= m; ++j)
      for (int k = 0; k <= t[j - v]; ++k)
        f[j + 1][k / 2] = max(f[j + 1][k / 2], f[j][k] + k / 2 * c[j + 1]);
  }
  printf("%d", f[m][0]);
  return 0;
}
