#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int t, T, n, m, c[N], n1, n2, l[N], r[N], x, y;
vector<int> vec[N];
void fail() {
  puts("IMPOSSIBLE");
  exit(0);
}
void dfs(int x, int col) {
  if (c[x])
    if (c[x] == col)
      return;
    else
      fail();
  c[x] = col;
  for (int i = 0; i < vec[x].size(); i++) dfs(vec[x][i], 3 - col);
}
bool in(int i, int x) { return l[i] <= x && x <= r[i]; }
int main() {
  scanf("%d%d", &t, &T);
  scanf("%d%d", &n, &m);
  n1 = 1e9;
  for (int i = 1; i <= n; i++)
    scanf("%d%d", &l[i], &r[i]), n1 = min(n1, r[i]), n2 = max(n2, l[i]);
  for (int i = 1; i <= m; i++)
    scanf("%d%d", &x, &y), vec[x].push_back(y), vec[y].push_back(x);
  if (n1 + n2 < t)
    n2 = t - n1;
  else if (n1 + n2 > T)
    n1 = T - n2;
  if (n1 < 0 || n2 < 0) fail();
  for (int i = 1; i <= n; i++)
    if (in(i, n1)) {
      if (!in(i, n2)) dfs(i, 1);
    } else if (in(i, n2))
      dfs(i, 2);
    else
      fail();
  for (int i = 1; i <= n; i++)
    if (!c[i]) dfs(i, 1);
  printf("POSSIBLE\n%d %d\n", n1, n2);
  for (int i = 1; i <= n; i++) printf("%d", c[i]);
  puts("");
  return 0;
}
