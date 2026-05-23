#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)1e5 + 5;
const int MAXM = (int)1e6 + 5;
const long long INF = (long long)1e18;
vector<int> vec[MAXM];
pair<int, int> e[MAXN];
vector<int> adj[MAXN];
int w[MAXN];
long long dist[MAXN], dist2[MAXN], w2[MAXN];
int n, m, q;
void dijkstraSlow() {
  priority_queue<pair<long long, int>> Q;
  for (int i = 1; i <= n; ++i) {
    dist[i] = INF;
  }
  dist[1] = 0;
  Q.push(make_pair(0, 1));
  while (!Q.empty()) {
    long long cd = -Q.top().first;
    int v = Q.top().second;
    Q.pop();
    if (cd != dist[v]) {
      continue;
    }
    for (int id : adj[v]) {
      int to = e[id].second;
      long long nd = cd + w[id];
      if (nd < dist[to]) {
        dist[to] = nd;
        Q.push(make_pair(-nd, to));
      }
    }
  }
}
void dijkstraFast(int lim) {
  for (int i = 1; i <= n; ++i) {
    dist2[i] = INF;
  }
  dist2[1] = 0;
  vec[0].push_back(1);
  int ptr = 0;
  while (1) {
    while (ptr <= lim && vec[ptr].empty()) {
      ++ptr;
    }
    if (ptr > lim) {
      break;
    }
    int v = vec[ptr].back();
    vec[ptr].pop_back();
    if (dist2[v] != ptr) {
      continue;
    }
    for (int id : adj[v]) {
      int to = e[id].second;
      long long nd = ptr + w2[id];
      if (nd <= lim && nd < dist2[to]) {
        dist2[to] = nd;
        vec[nd].push_back(to);
      }
    }
  }
}
void solve() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d %d %d", &u, &v, &w[i]);
    e[i] = make_pair(u, v);
    adj[u].push_back(i);
  }
  dijkstraSlow();
  while (q--) {
    int tp;
    scanf("%d", &tp);
    if (tp == 1) {
      int x;
      scanf("%d", &x);
      if (dist[x] == INF) {
        printf("-1\n");
      } else {
        printf("%lld\n", dist[x]);
      }
    } else {
      int k;
      scanf("%d", &k);
      for (int i = 1; i <= m; ++i) {
        int u = e[i].first;
        int v = e[i].second;
        w2[i] = w[i] + dist[u] - dist[v];
      }
      for (int i = 1; i <= k; ++i) {
        int x;
        scanf("%d", &x);
        ++w[x];
        ++w2[x];
      }
      dijkstraFast(k);
      for (int i = 1; i <= n; ++i) {
        if (dist[i] != INF) {
          dist[i] += dist2[i];
        }
      }
    }
  }
}
int main() {
  int tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}
