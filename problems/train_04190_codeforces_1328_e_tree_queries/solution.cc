#include <bits/stdc++.h>
using namespace std;
const int N = 200010, M = 2 * N;
int n, m, T;
int h[N], e[M], ne[M], idx;
int depth[N], pre[N], tin[N], tout[N];
int qv[N];
void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }
void dfs(int u, int p, int d) {
  tin[u] = T++;
  pre[u] = p;
  depth[u] = d;
  for (int i = h[u]; ~i; i = ne[i]) {
    int j = e[i];
    if (pre[u] == j) continue;
    dfs(j, u, d + 1);
  }
  tout[u] = T++;
}
bool check(int v, int dv) { return tin[v] <= tin[dv] && tout[dv] <= tout[v]; }
int main() {
  memset(h, -1, sizeof h);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }
  dfs(1, -1, 1);
  while (m--) {
    int k, deepest = -1, dv;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
      int x;
      scanf("%d", &x);
      qv[i] = x;
      if (depth[x] > deepest) {
        deepest = depth[x];
        dv = x;
      }
    }
    bool flag = true;
    for (int i = 0; i < k; i++) {
      if (qv[i] != dv && pre[qv[i]] != -1) qv[i] = pre[qv[i]];
      if (!check(qv[i], dv)) {
        flag = false;
        break;
      }
    }
    if (flag)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
