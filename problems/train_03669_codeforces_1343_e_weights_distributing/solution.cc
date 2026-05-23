#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int MX = 2e5 + 7;
const int mod = 1e9 + 7;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long quimod(long long a, long long k) {
  long long res = 1;
  while (k) {
    if (k & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    k >>= 1;
  }
  return res;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
int n, m;
int a, b, c;
int v[MX];
long long dis[MX][5];
vector<int> Edge[MX];
void bfs(int st, int id) {
  bool vis[MX];
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    dis[i][id] = INF;
    vis[i] = false;
  }
  dis[st][id] = 0;
  q.push(st);
  vis[st] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : Edge[u]) {
      if (vis[v]) continue;
      dis[v][id] = dis[u][id] + 1;
      vis[v] = true;
      q.push(v);
    }
  }
}
long long solve() {
  long long pre[MX];
  long long res = LINF, tmp = 0;
  bfs(a, 0);
  bfs(b, 1);
  bfs(c, 2);
  sort(v + 1, v + 1 + m);
  for (int i = 1; i <= m; ++i) pre[i] = pre[i - 1] + 1ll * v[i];
  for (int i = 1; i <= n; ++i) {
    int x = i;
    if (1ll * dis[x][0] + dis[x][1] + dis[x][2] <= 1ll * m) {
      tmp = pre[dis[x][0] + dis[x][1] + dis[x][2]] + pre[dis[x][1]],
      res = min(res, tmp);
    } else
      continue;
  }
  return res;
}
void init() {
  for (int i = 1; i <= n; ++i) {
    Edge[i].clear();
    dis[i][0] = dis[i][1] = dis[i][2] = 0;
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d %d %d %d", &n, &m, &a, &b, &c);
    init();
    for (int i = 1; i <= m; ++i) scanf("%d", &v[i]);
    for (int i = 1; i <= m; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      Edge[u].push_back(v);
      Edge[v].push_back(u);
    }
    long long res = solve();
    printf("%lld\n", res);
  }
  return 0;
}
