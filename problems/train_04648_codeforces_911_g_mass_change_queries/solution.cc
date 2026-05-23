#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, B = 450, V = 103;
int n, m, a[N];
struct UF {
  int p[B + 1], r[B + 1], v[B + 1];
  void reset() {
    for (int i = 0; i <= B; i++) p[i] = i;
    memset(r, 0, sizeof(r));
  }
  int find(int u) {
    if (p[u] == u) return u;
    p[u] = find(p[u]);
    v[u] = v[p[u]];
    return p[u];
  }
  void merge(int u, int v, int val) {
    u = find(u);
    v = find(v);
    if (u == v) {
      this->v[u] = val;
      return;
    }
    if (r[u] >= r[v]) {
      p[v] = u;
      if (r[u] == r[v]) r[u]++;
      this->v[u] = val;
    } else {
      p[u] = v;
      this->v[v] = val;
    }
  }
};
struct Block {
  UF uf;
  int head[V];
  bool lazy, updated;
  Block() : lazy(false), updated(false) {}
} blk[B];
void build(int b) {
  int i = B * b + 1;
  Block &bl = blk[b];
  memset(bl.head, 0, sizeof(bl.head));
  bl.uf.reset();
  for (int j = i; j < i + B && j <= n; j++) {
    if (bl.head[a[j]] == 0) {
      bl.head[a[j]] = j - i + 1;
      bl.uf.v[j - i + 1] = a[j];
    } else
      bl.uf.merge(bl.head[a[j]], j - i + 1, a[j]);
  }
  bl.lazy = true;
  bl.updated = false;
}
void refactor(int b, int l, int r, int x, int y) {
  int s = b * B + 1, t = min(s + B - 1, n);
  Block &bl = blk[b];
  if (bl.lazy && bl.updated) {
    for (int i = s; i <= t; i++) {
      int z = bl.uf.find(i - s + 1), v = bl.uf.v[z];
      if (v == x && l <= i && i <= r)
        a[i] = y;
      else
        a[i] = v;
    }
  } else {
    if (x != y) {
      for (int i = s; i <= t; i++) {
        if (l <= i && i <= r && a[i] == x) a[i] = y;
      }
    }
  }
  bl.lazy = false;
  bl.updated = false;
}
void update(int l, int r, int x, int y) {
  for (int i = 1; i <= n; i += B) {
    int b = i / B, s = i, t = min(i + B - 1, n);
    if (l > t || r < s) continue;
    if (l <= s && t <= r) {
      Block &bl = blk[b];
      if (!bl.lazy) build(b);
      int u = bl.uf.find(bl.head[x]), v = bl.uf.find(bl.head[y]);
      if (!u) continue;
      if (!v) {
        bl.head[y] = u;
        bl.head[x] = 0;
        bl.uf.v[u] = y;
      } else {
        bl.uf.merge(u, v, y);
        bl.head[x] = 0;
      }
      bl.updated = true;
    } else
      refactor(b, l, r, x, y);
  }
}
void output() {
  for (int i = 1; i <= n; i += B) refactor(i / B, 0, 0, 0, 0);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int l, r, x, y;
    scanf("%d%d%d%d", &l, &r, &x, &y);
    if (x != y) update(l, r, x, y);
  }
  output();
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  puts("");
}
