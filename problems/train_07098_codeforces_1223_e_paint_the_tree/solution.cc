#include <bits/stdc++.h>
using namespace std;
int inline read() {
  int num = 0, neg = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') neg = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    num = (num << 3) + (num << 1) + c - '0';
    c = getchar();
  }
  return num * neg;
}
const int maxn = 500010;
int n, T, k, head[maxn], cnt, deg[maxn], used[maxn];
long long f[maxn][2];
struct Edge {
  int nxt, to, dis;
} edge[maxn << 1];
void add_edge(int x, int y, int z) {
  edge[++cnt].nxt = head[x];
  edge[cnt].to = y;
  edge[cnt].dis = z;
  head[x] = cnt;
}
struct Node {
  int val, id;
} A[maxn];
bool cmp(Node x, Node y) { return x.val > y.val; }
void dfs(int x, int fa) {
  int flag = 1;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v == fa) continue;
    flag = 0;
    dfs(v, x);
  }
  int tot = 0;
  if (flag) return;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v == fa) continue;
    A[++tot].id = v;
    A[tot].val = f[v][1] + edge[i].dis - f[v][0];
  }
  sort(A + 1, A + tot + 1, cmp);
  for (int i = 1; i <= min(k, tot); i++) {
    if (A[i].val <= 0) break;
    f[x][0] += A[i].val + f[A[i].id][0];
    used[A[i].id] = 1;
    if (i != k) f[x][1] += A[i].val + f[A[i].id][0];
  }
  if (k <= tot && used[A[k].id]) f[x][1] += f[A[k].id][0];
  for (int i = head[x]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v == fa) continue;
    if (used[v]) continue;
    f[x][1] += f[v][0];
    f[x][0] += f[v][0];
  }
}
int main() {
  T = read();
  while (T--) {
    n = read();
    k = read();
    cnt = 0;
    long long ans = 0;
    for (int i = 1; i < n; i++) {
      int u = read(), v = read(), w = read();
      add_edge(u, v, w);
      add_edge(v, u, w);
      deg[u]++;
      deg[v]++;
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) ans = max(ans, max(f[i][0], f[i][1]));
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
      head[i] = deg[i] = f[i][0] = f[i][1] = used[i] = 0;
  }
  return 0;
}
