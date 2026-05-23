#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 100;
int head[mx], vis[mx], dis1[mx], dis2[mx], dp[mx], son[mx], in[mx];
int cnt = 0, n, k, a, b, c, pa, pb, mid;
struct Edge {
  int to, val, next;
} edge[mx << 2];
struct node {
  int id, len, fa;
  node() {}
  node(int pp, int ll, int ff) {
    id = pp;
    len = ll;
    fa = ff;
  }
  bool operator<(const node a) const { return len < a.len; }
};
void add(int a, int b, int v) {
  edge[cnt].to = b;
  edge[cnt].next = head[a];
  edge[cnt].val = v;
  head[a] = cnt++;
}
void init() {
  cnt = 0;
  memset(head, -1, sizeof(head));
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; i++) {
    son[i] = i;
    dp[i] = 0;
  }
}
void dfs(int x, int fa) {
  for (int i = head[x]; ~i; i = edge[i].next) {
    int nxt = edge[i].to;
    if (nxt == fa) continue;
    dfs(nxt, x);
    if (dp[nxt] + edge[i].val > dp[x]) {
      dp[x] = dp[nxt] + edge[i].val;
      son[x] = nxt;
    }
  }
}
int main() {
  init();
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; i++) {
    scanf("%d%d%d", &a, &b, &c);
    add(a, b, c);
    add(b, a, c);
  }
  int mmax = 0;
  queue<int> que;
  que.push(1);
  dis1[1] = 0;
  vis[1] = 1;
  while (!que.empty()) {
    int now = que.front();
    que.pop();
    for (int i = head[now]; ~i; i = edge[i].next) {
      int nxt = edge[i].to;
      if (vis[nxt]) continue;
      vis[nxt] = 1;
      dis1[nxt] = dis1[now] + edge[i].val;
      que.push(nxt);
      if (dis1[nxt] > mmax) {
        mmax = dis1[nxt];
        pa = nxt;
      }
    }
  }
  mmax = 0;
  dis2[pa] = 0;
  que.push(pa);
  memset(vis, 0, sizeof(vis));
  vis[pa] = 1;
  while (!que.empty()) {
    int now = que.front();
    que.pop();
    for (int i = head[now]; ~i; i = edge[i].next) {
      int nxt = edge[i].to;
      if (vis[nxt]) continue;
      vis[nxt] = 1;
      dis2[nxt] = dis2[now] + edge[i].val;
      que.push(nxt);
      if (dis2[nxt] > mmax) {
        mmax = dis2[nxt];
        pb = nxt;
      }
    }
  }
  mmax = 0;
  dis1[pb] = 0;
  que.push(pb);
  memset(vis, 0, sizeof(vis));
  vis[pb] = 1;
  while (!que.empty()) {
    int now = que.front();
    que.pop();
    for (int i = head[now]; ~i; i = edge[i].next) {
      int nxt = edge[i].to;
      if (vis[nxt]) continue;
      vis[nxt] = 1;
      dis1[nxt] = dis1[now] + edge[i].val;
      que.push(nxt);
    }
  }
  mmax = 2000000000;
  for (int i = 1; i <= n; i++)
    if (max(dis1[i], dis2[i]) < mmax) mmax = max(dis1[i], dis2[i]), mid = i;
  dfs(mid, mid);
  int cont = 1;
  mmax = 0;
  priority_queue<node> q;
  q.push(node(mid, dp[mid], mid));
  while (!q.empty()) {
    if (cont >= k) break;
    node now = q.top();
    if (now.fa != now.id) {
      if (in[now.id] >= 2 || in[now.fa] >= 2) break;
      in[now.id]++;
      in[now.fa]++;
      cont++;
      q.pop();
    } else
      q.pop();
    for (int i = head[now.id]; ~i; i = edge[i].next) {
      int nxt = edge[i].to;
      if (nxt == now.fa) continue;
      q.push(node(nxt, dp[nxt] + edge[i].val, now.id));
    }
  }
  if (q.empty())
    puts("0");
  else {
    node res = q.top();
    printf("%d\n", res.len);
  }
  return 0;
}
