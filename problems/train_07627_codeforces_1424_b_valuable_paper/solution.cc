#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long num = 0, neg = 1;
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
const int INF = 0x3f3f3f3f;
int dis[20010], n, m, s, e;
int to[300010], val[300010], nxt[300010], head[20010], cnt;
int vis[20010];
struct node {
  int x, y, val;
} side[100010];
void insert(int x, int y, int z) {
  to[cnt] = y, val[cnt] = z;
  nxt[cnt] = head[x];
  head[x] = cnt;
  cnt++;
  to[cnt] = x, val[cnt] = 0;
  nxt[cnt] = head[y];
  head[y] = cnt;
  cnt++;
}
bool bfs() {
  queue<int> line;
  memset(dis, 0, sizeof(dis));
  dis[s] = 1;
  line.push(s);
  while (!line.empty()) {
    int u = line.front();
    line.pop();
    for (int i = head[u]; i != -1; i = nxt[i]) {
      int v = to[i];
      if (!val[i]) continue;
      if (!dis[v]) {
        dis[v] = dis[u] + val[i];
        line.push(v);
        if (v == e) return 1;
      }
    }
  }
  return 0;
}
int dinic(int now, int x) {
  if (now == e) return x;
  int rest = x;
  for (int i = head[now]; i != -1 && rest; i = nxt[i]) {
    if (dis[to[i]] == dis[now] + 1 && val[i]) {
      int flow = dinic(to[i], min(rest, val[i]));
      if (flow) {
        val[i] -= flow;
        val[i ^ 1] += flow;
        rest -= flow;
      } else
        dis[to[i]] = 0;
    }
  }
  return x - rest;
}
bool cmp1(node x, node y) { return x.val < y.val; }
inline bool check(int x) {
  memset(head, -1, sizeof(head));
  cnt = 0;
  for (int i = 1; i <= n; i++) insert(s, i, 1), insert(i + n, e, 1);
  for (int i = 1; i <= min(x, m); i++) insert(side[i].x, side[i].y + n, 1);
  int flow = 0, ans = 0;
  while (bfs()) {
    while (flow = dinic(s, 1e9)) ans += flow;
  }
  if (ans == n) return 1;
  return 0;
}
signed main() {
  memset(head, -1, sizeof(head));
  cin >> n >> m;
  s = 0, e = 2 * n + 1;
  for (int i = 1; i <= m; i++)
    side[i].x = read(), side[i].y = read(), side[i].val = read();
  sort(side + 1, side + m + 1, cmp1);
  int l = 1, r = m + 1, mid;
  while (l < r) {
    mid = l + r >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", l > m ? -1 : side[l].val);
  return 0;
}
