#include <bits/stdc++.h>
using namespace std;
namespace IO {
inline int read() {
  register char ch = getchar();
  register int x = 0;
  while (ch < '0' || ch > '9') {
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + (ch ^ 48), ch = getchar();
  return x;
}
}  // namespace IO
using namespace IO;
int n, cnt, head[100010], m;
int p[63], dis[100010];
bool vis[100010];
inline void insert(int x) {
  for (int i = 62; ~i; i--) {
    if (x & (1 << i)) {
      if (!p[i]) {
        p[i] = x;
        return;
      }
      x ^= p[i];
    }
  }
}
inline int qMin(int qwq) {
  for (int i = 62; ~i; i--) {
    qwq = min(qwq, qwq ^ p[i]);
  }
  return qwq;
}
struct Edge {
  int to, nxt;
  int cost;
} a[200001];
inline void add(int u, int v, int w) {
  cnt++;
  a[cnt].to = v;
  a[cnt].nxt = head[u];
  a[cnt].cost = w;
  head[u] = cnt;
}
void dfs(int x, int fa, int v) {
  dis[x] = v;
  vis[x] = true;
  for (int i = head[x]; i; i = a[i].nxt) {
    int y = a[i].to;
    if (y == fa) continue;
    if (!vis[y]) {
      dfs(y, x, v ^ a[i].cost);
    } else {
      insert(v ^ dis[y] ^ a[i].cost);
    }
  }
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read();
    int w = read();
    add(u, v, w);
    add(v, u, w);
  }
  dfs(1, 0, 0);
  printf("%d", qMin(dis[n]));
  return 0;
}
