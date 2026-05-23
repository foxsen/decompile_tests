#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
int fa[N];
int n, m, q;
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void solve() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n + m; i++) {
    fa[i] = i;
  }
  int res = n + m - 1;
  for (int i = 1; i <= q; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    int fx = find(x), fy = find(y + n);
    if (fx != fy) {
      fa[fx] = fy;
      res--;
    }
  }
  printf("%d\n", res);
}
int main() {
  solve();
  return 0;
}
