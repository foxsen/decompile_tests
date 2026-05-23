#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, a[N], p[N << 1], b[N][2];
void nhap() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= m; ++i) {
    int sz;
    scanf("%d", &sz);
    for (int j = 1; j <= sz; ++j) {
      int u;
      scanf("%d", &u);
      if (!b[u][0])
        b[u][0] = i;
      else
        b[u][1] = i;
    }
  }
}
int root(int u) {
  if (p[u] != u) p[u] = root(p[u]);
  return p[u];
}
void add(int u, int v) {
  int ru = root(u), rv = root(v);
  p[rv] = ru;
}
void process() {
  for (int i = 1; i <= (m << 1); ++i) p[i] = i;
  for (int i = 1; i <= n; ++i) {
    if (a[i]) {
      int u = b[i][0], v = b[i][1];
      add(u, v);
      add(u + m, v + m);
    } else {
      int u = b[i][0], v = b[i][1];
      add(u, v + m);
      add(v, u + m);
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (root(i) == root(i + m)) {
      cout << "NO";
      return;
    }
  }
  cout << "YES";
}
int main() {
  nhap();
  process();
  return 0;
}
