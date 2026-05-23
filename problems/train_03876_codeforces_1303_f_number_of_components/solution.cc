#include <bits/stdc++.h>
using namespace std;
const int N = 310, M = 2e6 + 10;
template <typename T>
inline void gi(T &x) {
  x = 0;
  bool f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') f |= (ch == '-'), ch = getchar();
  while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  if (f) x = -x;
}
inline void write(int x) {
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
int n, m, Q, x, y, z, w, cnt, num;
int a[N][N], id[N][N], ans[M], fa[M * 2];
struct Que {
  int x, y, col, bef;
} q[M];
int find(int x) { return (fa[x] == x) ? fa[x] : fa[x] = find(fa[x]); }
void merge(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) fa[fy] = fx, num--;
}
void check(int x, int y) {
  if (a[x][y] == a[x - 1][y]) merge(id[x][y], id[x - 1][y]);
  if (a[x][y] == a[x + 1][y]) merge(id[x][y], id[x + 1][y]);
  if (a[x][y] == a[x][y - 1]) merge(id[x][y], id[x][y - 1]);
  if (a[x][y] == a[x][y + 1]) merge(id[x][y], id[x][y + 1]);
}
void solve1() {
  memset(a, -1, sizeof(a));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) a[i][j] = 0;
  for (int i = 1; i <= Q; i++) {
    if (q[i].col == q[i].bef) continue;
    int fx = q[i].x, fy = q[i].y;
    num = 1;
    a[fx][fy] = q[i].col, id[fx][fy] = ++cnt, fa[cnt] = cnt;
    check(fx, fy), ans[i] += num;
  }
}
void solve2() {
  memset(fa, 0, sizeof(fa));
  cnt = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) id[i][j] = ++cnt, fa[cnt] = cnt;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) check(i, j);
  for (int i = Q; i >= 1; i--) {
    if (q[i].col == q[i].bef) continue;
    int fx = q[i].x, fy = q[i].y;
    num = 1;
    a[fx][fy] = q[i].bef, id[fx][fy] = ++cnt, fa[cnt] = cnt;
    check(fx, fy), ans[i] -= num;
  }
}
int main() {
  gi(n), gi(m), gi(Q);
  for (int i = 1; i <= Q; i++) {
    gi(x), gi(y), gi(z), w = a[x][y];
    q[i] = (Que){x, y, z, w}, a[x][y] = z;
  }
  ans[0] = 1;
  solve1(), solve2();
  for (int i = 1; i <= Q; i++)
    ans[i] += ans[i - 1], write(ans[i]), putchar('\n');
}
