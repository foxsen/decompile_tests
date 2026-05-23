#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
struct Dinic {
  int N, E;
  vector<int> head, dis, ptr;
  vector<int> to, prv, cap, flo;
  Dinic(int N) : N(N), E(0), head(N, -1), dis(N) {}
  void addEdge(int v, int u, int vu, int uv = 0) {
    to.resize(E + 2);
    prv.resize(E + 2);
    cap.resize(E + 2);
    flo.resize(E + 2);
    to[E] = u, prv[E] = head[v], cap[E] = vu, head[v] = E++;
    to[E] = v, prv[E] = head[u], cap[E] = uv, head[u] = E++;
  }
  void clear() {
    E = 0;
    fill(head.begin(), head.end(), -1);
  }
  bool bfs(int source, int sink) {
    fill(dis.begin(), dis.end(), INF);
    dis[source] = 0;
    int h = 0, t = 0;
    vector<int> q(N);
    q[t++] = source;
    while (h < t) {
      int v = q[h++];
      for (int e = head[v]; e != -1; e = prv[e]) {
        if (cap[e] - flo[e] > 0 && dis[to[e]] > dis[v] + 1) {
          dis[to[e]] = dis[v] + 1, q[t++] = to[e];
          if (to[e] == sink) return 1;
        }
      }
    }
    return 0;
  }
  int dfs(int v, int sink, int flow = INF) {
    if (v == sink || flow == 0) return flow;
    int ret = 0;
    for (int &e = ptr[v]; e != -1; e = prv[e]) {
      if (dis[v] == dis[to[e]] - 1) {
        int x = dfs(to[e], sink, min(flow, cap[e] - flo[e]));
        flow -= x, ret += x;
        flo[e] += x, flo[e ^ 1] -= x;
        if (flow == 0) break;
      }
    }
    return ret;
  }
  int maxFlow(int source, int sink) {
    fill(flo.begin(), flo.end(), 0);
    int ans = 0;
    while (bfs(source, sink)) {
      ptr = head;
      ans += dfs(source, sink);
    }
    return ans;
  }
};
struct primeFactor {
  int id, p, c;
};
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<primeFactor>> V(n);
  int id = 0;
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    for (int j = 2; j * j <= t; j++) {
      int c = 0;
      while (t % j == 0) {
        c++, t /= j;
      }
      if (c) V[i].push_back({id++, j, c});
    }
    if (t > 1) {
      V[i].push_back({id++, t, 1});
    }
  }
  int nodes = id + 2;
  int S = id, T = id + 1;
  Dinic G(nodes);
  for (int i = 0; i < n; i++) {
    if (i % 2) {
      for (auto &p : V[i]) {
        G.addEdge(p.id, T, p.c);
      }
    } else {
      for (auto &p : V[i]) {
        G.addEdge(S, p.id, p.c);
      }
    }
  }
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    if (u % 2) swap(u, v);
    for (auto &pu : V[u]) {
      for (auto &pv : V[v]) {
        if (pu.p == pv.p) {
          G.addEdge(pu.id, pv.id, INF);
        }
      }
    }
  }
  printf("%d\n", G.maxFlow(S, T));
}
