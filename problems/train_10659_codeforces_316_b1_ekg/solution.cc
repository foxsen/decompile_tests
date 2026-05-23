#include <bits/stdc++.h>
using namespace std;
int f[1024], w[1024], front[1024], cntw, n, x;
bool g[1024];
int getfa(int x) {
  if (!f[x]) return x;
  f[x] = getfa(f[x]);
  return f[x];
}
int main() {
  cin >> n >> x;
  for (int i = 1; i <= n; ++i) {
    int y;
    scanf("%d", &y);
    front[i] = y;
    if (!y) continue;
    f[i] = getfa(y);
  }
  int fa(getfa(x)), cntx(1);
  int y(front[x]);
  while (y) {
    ++cntx;
    y = front[y];
  }
  for (int i = 1; i <= n; ++i) {
    if (i == fa || f[i]) continue;
    ++cntw;
    for (int j = 1; j <= n; ++j)
      if (getfa(j) == getfa(i)) ++w[cntw];
  }
  g[0] = true;
  for (int i = 1; i <= cntw; ++i)
    for (int j = n; j >= w[i]; --j) g[j] |= g[j - w[i]];
  for (int i = 0; i <= n; ++i)
    if (g[i]) printf("%d\n", i + cntx);
  return 0;
}
