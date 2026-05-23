#include <bits/stdc++.h>
using namespace std;
int last[300005], vis[300006], par[300006];
map<pair<int, int>, int> ma;
vector<pair<int, int> > v[300006];
long long dis[300005];
int main() {
  long long ans = 0;
  vector<int> edges;
  int n, m, i, j, u, a, b, c;
  scanf("%d %d", &n, &m);
  ;
  for (i = 0; i < m; i++) {
    scanf("%d %d %d", &a, &b, &c);
    ;
    ma[make_pair(a, b)] = i + 1;
    ma[make_pair(b, a)] = i + 1;
    v[a].push_back(make_pair(b, c));
    v[b].push_back(make_pair(a, c));
  }
  scanf("%d", &u);
  ;
  priority_queue<pair<pair<long long, int>, pair<int, int> >,
                 vector<pair<pair<long long, int>, pair<int, int> > >,
                 greater<pair<pair<long long, int>, pair<int, int> > > >
      pq;
  pq.push(make_pair(make_pair(0, -1), make_pair(u, 0)));
  dis[u] = 0;
  last[u] = 0;
  while (!pq.empty()) {
    pair<pair<long long, int>, pair<int, int> > p = pq.top();
    pq.pop();
    if (!vis[p.second.first]) {
      vis[p.second.first] = 1;
      dis[p.second.first] = p.first.first;
      last[p.second.first] = p.second.second;
      par[p.second.first] = p.first.second;
      for (auto it : v[p.second.first]) {
        pq.push(make_pair(make_pair(it.second + p.first.first, p.second.first),
                          make_pair(it.first, it.second)));
      }
    } else if (dis[p.second.first] == p.first.first) {
      if (last[p.second.first] > p.second.second) {
        last[p.second.first] = min(last[p.second.first], p.second.second);
        par[p.second.first] = p.first.second;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    if (i != u) {
      ans += (last[i]);
      edges.push_back(ma[make_pair(i, par[i])]);
    }
  }
  printf("%lld", ans);
  ;
  printf("\n");
  for (i = 0; i < edges.size(); i++) {
    printf("%d ", edges[i]);
  }
}
