#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 20;
vector<pair<int, int>> ngraph[maxn], graph[maxn];
int n, m, u, v, w, t, c, s, e;
long long dis[maxn];
bool mark[maxn];
pair<int, int> tmp;
void dijkstra(int x) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      q;
  fill(dis, dis + maxn, 1e15);
  memset(mark, 0, sizeof mark);
  q.push({0, x});
  dis[x] = 0;
  while (q.size()) {
    tmp = q.top();
    q.pop();
    if (mark[tmp.second]) continue;
    mark[tmp.second] = 1;
    if (dis[tmp.second] <= t && tmp.second != x)
      graph[x].push_back({tmp.second, c});
    for (auto u : ngraph[tmp.second])
      if (dis[u.first] > dis[tmp.second] + u.second) {
        dis[u.first] = dis[tmp.second] + u.second;
        q.push({dis[u.first], u.first});
      }
  }
}
int main() {
  ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
  cin >> n >> m >> s >> e;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    ngraph[u].push_back({v, w});
    ngraph[v].push_back({u, w});
  }
  for (int i = 1; i <= n; i++) {
    cin >> t >> c;
    dijkstra(i);
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      q;
  fill(dis, dis + maxn, 1e15);
  memset(mark, 0, sizeof mark);
  dis[s] = 0;
  q.push({0, s});
  while (q.size()) {
    tmp = q.top();
    q.pop();
    if (mark[tmp.second]) continue;
    mark[tmp.second] = 1;
    for (auto u : graph[tmp.second])
      if (dis[u.first] > dis[tmp.second] + u.second) {
        dis[u.first] = dis[tmp.second] + u.second;
        q.push({dis[u.first], u.first});
      }
  }
  if (dis[e] == 1e15) return cout << -1 << endl, 0;
  cout << dis[e] << endl;
}
