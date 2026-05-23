#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1100, M = 1e5 + 10;
int g[N], nxt[M], v[M], w[M], ed;
void add(int x, int y, int z) {
  v[++ed] = y, nxt[ed] = g[x], g[x] = ed, w[ed] = z;
}
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    q;
void dj(int s, int n, long long *d) {
  int x;
  for (int i = 1; i <= n; i++) d[i] = inf;
  q.push({d[s] = 0, s});
  while (!q.empty()) {
    pair<int, int> t = q.top();
    q.pop();
    if (d[x = t.second] < t.first) continue;
    for (int i = g[x]; i; i = nxt[i])
      if (d[x] + w[i] < d[v[i]]) {
        q.push({d[v[i]] = d[x] + w[i], v[i]});
      }
  }
}
long long d[N][N];
pair<int, int> a[N], b[N];
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1, x, y, z; i <= m; i++) {
    cin >> x >> y >> z;
    b[i].first = x, b[i].second = y;
    add(x, y, z), add(y, x, z);
  }
  for (int i = 1; i <= k; i++) cin >> a[i].first >> a[i].second;
  for (int i = 1; i <= n; i++) dj(i, n, d[i]);
  long long ans = inf;
  for (int i = 1; i <= m; i++) {
    long long sum = 0;
    int x = b[i].first, y = b[i].second;
    for (int j = 1; j <= k; j++) {
      int s = a[j].first, t = a[j].second;
      long long d1 = d[s][t];
      long long d2 = d[s][x] + d[y][t];
      long long d3 = d[s][y] + d[x][t];
      sum += min(d1, min(d2, d3));
    }
    ans = min(ans, sum);
  }
  cout << ans << '\n';
  return 0;
}
