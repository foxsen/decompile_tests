#include <bits/stdc++.h>
using namespace std;
int Abs(int x) {
  if (x < 0) return -x;
  return x;
}
vector<pair<int, int> > g[128];
int a[128], x[128], y[128];
int n, d;
int cost[128], dist[128];
int dijkstra() {
  priority_queue<pair<int, int> > q;
  q.push(make_pair(0, 0));
  for (int i = 0; i < n; ++i) cost[i] = 1 << 30;
  cost[0] = 0;
  int src;
  while (!q.empty()) {
    src = q.top().second;
    if (-q.top().first > cost[src]) {
      q.pop();
      continue;
    }
    q.pop();
    if (src == n - 1) return cost[src];
    for (int i = 0; i < g[src].size(); ++i)
      if (cost[g[src][i].first] > cost[src] + g[src][i].second * d - a[src]) {
        cost[g[src][i].first] = cost[src] + g[src][i].second * d - a[src];
        dist[g[src][i].first] = dist[src] + g[src][i].second;
        q.push(make_pair(-cost[g[src][i].first], g[src][i].first));
      }
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &d);
  for (int i = 2; i < n; ++i) scanf("%d", &a[i - 1]);
  for (int i = 0; i < n; ++i) scanf("%d%d", x + i, y + i);
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) {
      int c = Abs(x[i] - x[j]) + Abs(y[i] - y[j]);
      g[i].push_back(make_pair(j, c));
      g[j].push_back(make_pair(i, c));
    }
  printf("%d\n", dijkstra());
  return 0;
}
