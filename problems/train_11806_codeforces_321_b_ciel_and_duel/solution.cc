#include <bits/stdc++.h>
using namespace std;
int adj[222][222], deg[222], flow[222][222], cost[222][222], dis[222], pre[222];
int N, M, fl;
void add_edge(int u, int v, int w, int c = 0) {
  adj[u][deg[u]++] = v;
  adj[v][deg[v]++] = u;
  flow[u][v] = w;
  flow[v][u] = 0;
  cost[u][v] = c;
  cost[v][u] = -c;
}
queue<int> q;
int max_flow(int s, int t) {
  int ans = 0, u, v, bot;
  while (1) {
    q = queue<int>();
    q.push(s);
    memset(pre, -1, sizeof(pre));
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    while (!q.empty()) {
      u = q.front();
      q.pop();
      for (int i = 0; i < deg[u]; i++) {
        v = adj[u][i];
        if (flow[u][v] == 0) continue;
        if (dis[v] > dis[u] + cost[u][v]) {
          dis[v] = dis[u] + cost[u][v];
          q.push(v);
          pre[v] = u;
        }
      }
    }
    if (dis[t] == 0x3f3f3f3f) return ans;
    bot = 0x3f3f3f3f;
    for (u = t; u != s; u = pre[u]) bot = min(bot, flow[pre[u]][u]);
    for (u = t; u != s; u = pre[u]) {
      flow[pre[u]][u] -= bot;
      flow[u][pre[u]] += bot;
    }
    fl += bot;
    ans += dis[t] * bot;
  }
}
char s[11];
int a[222], b[222], tp[222];
int main() {
  scanf("%d %d", &N, &M);
  int src = 0, tar = N + M + 1;
  for (int i = 1; i <= N; i++) {
    scanf("%s %d", s, b + i);
    tp[i] = (strcmp(s, "ATK") == 0);
  }
  for (int i = 1; i <= M; i++) {
    scanf("%d", a + i);
  }
  int mx = 0, MM = 100000;
  int S = N + M + 2, tmp = S + 1;
  for (int k = 1; k <= M; k++) {
    memset(deg, 0, sizeof(deg));
    add_edge(S, src, k);
    for (int i = 1; i <= N; i++) add_edge(M + i, tar, 1);
    for (int i = 1; i <= M; i++) {
      add_edge(src, i, 1);
      add_edge(i, tmp, 1, -a[i]);
      for (int j = 1; j <= N; j++) {
        if (tp[j] && a[i] >= b[j]) add_edge(i, M + j, 1, b[j] - a[i]);
        if (!tp[j] && a[i] > b[j]) add_edge(i, M + j, 1);
      }
    }
    add_edge(tmp, tar, M, MM);
    int ans = -max_flow(S, tar);
    if (M - flow[tmp][tar] > max(0, k - N)) continue;
    mx = max(mx, ans + MM * (M - flow[tmp][tar]));
  }
  printf("%d\n", mx);
  return 0;
}
