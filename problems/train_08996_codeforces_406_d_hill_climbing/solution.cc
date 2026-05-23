#include <bits/stdc++.h>
using namespace std;
struct point {
  long long x, y;
  point() {}
  point(long long _x, long long _y) {
    x = _x;
    y = _y;
  }
};
inline long long CCW(point a, point b, point c) {
  long long a1 = b.x - a.x, b1 = b.y - a.y;
  long long a2 = c.x - b.x, b2 = c.y - b.y;
  return a1 * b2 - a2 * b1;
}
const int maxN = 1e5 + 5;
int n, m;
point p[maxN];
vector<int> head[maxN];
int st[maxN], top;
int parent[maxN][20], h[maxN];
void DFS(int u) {
  for (int i = 0; i < (int)head[u].size(); ++i) {
    int v = head[u][i];
    parent[v][0] = u;
    h[v] = h[u] + 1;
    DFS(v);
  }
}
void Init() {
  m = (int)log2(n) + 1;
  for (int j = 1; j <= m; ++j)
    for (int i = 1; i <= n; ++i) parent[i][j] = parent[parent[i][j - 1]][j - 1];
}
void Jump(int &u, int x) {
  for (int i = m; i >= 0; --i)
    if (x >= (1 << i)) {
      u = parent[u][i];
      x -= (1 << i);
    }
}
int LCA(int u, int v) {
  if (h[u] > h[v])
    Jump(u, h[u] - h[v]);
  else
    Jump(v, h[v] - h[u]);
  if (u == v) return u;
  for (int i = m; i >= 0; --i)
    if (parent[u][i] != parent[v][i]) {
      u = parent[u][i];
      v = parent[v][i];
    }
  return parent[u][0];
}
int main() {
  ios_base::sync_with_stdio(false);
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    long long x, y;
    scanf("%I64d%I64d", &x, &y);
    p[i] = point(x, y);
  }
  head[n].push_back(n - 1);
  top = 2;
  st[1] = n;
  st[2] = n - 1;
  for (int i = n - 2; i >= 1; --i) {
    while (top >= 2 && CCW(p[st[top - 1]], p[st[top]], p[i]) < 0) --top;
    head[st[top]].push_back(i);
    st[++top] = i;
  }
  DFS(n);
  Init();
  int q = 0;
  scanf("%d", &q);
  while (q--) {
    int u, v;
    scanf("%d%d", &u, &v);
    printf("%d ", LCA(u, v));
  }
  return 0;
}
