#include <bits/stdc++.h>
using namespace std;
struct node {
  int to, nxt, w, f;
} e[200005];
const int N = 60;
int head[N], cnt = 1, s, t, l[N];
int maxf, mins, fl[N], pre[N], dis[N];
int sf[N << 15], sw[N << 15], k, p, n, m, xk;
double ans;
bool vis[N];
queue<int> q;
void add(int u, int v, int f, int w) {
  cnt++;
  e[cnt].to = v;
  e[cnt].w = w;
  e[cnt].f = f;
  e[cnt].nxt = head[u];
  head[u] = cnt;
}
bool spfa() {
  memset(dis, 127, sizeof(dis));
  memset(fl, 127, sizeof(fl));
  q.push(s);
  dis[s] = 0;
  pre[t] = -1;
  vis[s] = 1;
  while (!q.empty()) {
    int u = q.front();
    vis[u] = 0;
    q.pop();
    for (int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].to;
      if (e[i].f > 0 && dis[v] > dis[u] + e[i].w) {
        dis[v] = dis[u] + e[i].w;
        pre[v] = u;
        l[v] = i;
        fl[v] = min(fl[u], e[i].f);
        if (!vis[v]) q.push(v), vis[v] = 1;
      }
    }
  }
  return pre[t] != -1;
}
int main() {
  cin >> n >> m;
  s = 1;
  t = n;
  for (int i = 1; i <= m; i++) {
    int u, v, f;
    scanf("%d%d%d", &u, &v, &f);
    add(u, v, 1, f);
    add(v, u, 0, -f);
  }
  while (spfa()) {
    int u = t;
    maxf += fl[t];
    mins += fl[t] * dis[t];
    sf[++k] = maxf;
    sw[k] = mins;
    while (u != s) {
      e[l[u]].f -= fl[t];
      e[l[u] ^ 1].f += fl[t];
      u = pre[u];
    }
  }
  cin >> p;
  for (int i = 1; i <= p; i++) {
    scanf("%d", &xk);
    ans = 2e9;
    for (int j = 1; j <= k; j++) ans = min(ans, 1.0 * (sw[j] + xk) / sf[j]);
    printf("%.10lf\n", ans);
  }
}
