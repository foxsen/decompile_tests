#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m, k;
int a[N], sz[N], c[N];
bool u[N];
vector<int> g[N];
void go(int v, int comp) {
  c[v] = comp;
  ++sz[comp];
  u[v] = true;
  for (auto to : g[v]) {
    if (u[to]) continue;
    go(to, comp);
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; ++i) {
    scanf("%d", &a[i]);
    --a[i];
  }
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x;
    --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 0; i < k; ++i) go(a[i], i + 1);
  int mx = 1;
  for (int i = 2; i <= k; ++i)
    if (sz[i] > sz[mx]) mx = i;
  for (int i = 0; i < n; ++i)
    if (c[i] == 0) {
      c[i] = mx;
      ++sz[mx];
    }
  int sum = 0;
  for (int i = 0; i < n; ++i) sum += sz[c[i]] - (int)g[i].size() - 1;
  printf("%d\n", sum / 2);
  return 0;
}
