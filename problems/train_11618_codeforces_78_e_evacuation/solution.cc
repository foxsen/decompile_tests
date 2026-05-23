#include <bits/stdc++.h>
using namespace std;
char s1[15][15], s2[15][15];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int idx[65][15][15];
int dp[15][15];
int id = 1;
struct Edge {
  int u, v;
  long long cap, flow;
  Edge() {}
  Edge(int u, int v, long long cap) : u(u), v(v), cap(cap), flow(0) {}
};
struct Dinic {
  int N;
  vector<Edge> E;
  vector<vector<int>> g;
  vector<int> d, pt;
  Dinic(int N) : N(N), E(0), g(N), d(N), pt(N) {}
  void AddEdge(int u, int v, long long cap) {
    if (u != v) {
      E.emplace_back(Edge(u, v, cap));
      g[u].emplace_back(E.size() - 1);
      E.emplace_back(Edge(v, u, 0));
      g[v].emplace_back(E.size() - 1);
    }
  }
  bool BFS(int S, int T) {
    queue<int> q({S});
    fill(d.begin(), d.end(), N + 1);
    d[S] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (u == T) break;
      for (int k : g[u]) {
        Edge &e = E[k];
        if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.emplace(e.v);
        }
      }
    }
    return d[T] != N + 1;
  }
  long long DFS(int u, int T, long long flow = -1) {
    if (u == T || flow == 0) return flow;
    for (int &i = pt[u]; i < g[u].size(); ++i) {
      Edge &e = E[g[u][i]];
      Edge &oe = E[g[u][i] ^ 1];
      if (d[e.v] == d[e.u] + 1) {
        long long amt = e.cap - e.flow;
        if (flow != -1 && amt > flow) amt = flow;
        if (long long pushed = DFS(e.v, T, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }
  long long MaxFlow(int S, int T) {
    long long total = 0;
    while (BFS(S, T)) {
      fill(pt.begin(), pt.end(), 0);
      while (long long flow = DFS(S, T)) total += flow;
    }
    return total;
  }
};
int main() {
  memset(dp, -1, sizeof(dp));
  int n, t;
  scanf("%d%d", &n, &t);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s1[i] + 1);
  }
  for (int i = 0; i <= t + 1; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        idx[i][j][k] = id++;
      }
    }
  }
  id++;
  for (int i = 1; i <= n; i++) {
    scanf("%s", s2[i] + 1);
  }
  queue<pair<int, int>> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (s1[i][j] == 'Z') {
        q.push(pair<int, int>(i, j));
        dp[i][j] = 0;
      }
    }
  }
  while (!q.empty()) {
    int uy = q.front().first, ux = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int vy = uy + dir[i][0], vx = ux + dir[i][1];
      if (vy >= 1 && vy <= n && vx >= 1 && vx <= n && s1[vy][vx] != 'Y' &&
          dp[vy][vx] == -1) {
        dp[vy][vx] = dp[uy][ux] + 1;
        q.push(pair<int, int>(vy, vx));
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dp[i][j] == -1) dp[i][j] = 1e9;
      if (dp[i][j] > t) dp[i][j] = 1e9;
    }
  }
  int source = 0, sink = id - 1;
  Dinic dinic(id);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (s1[i][j] >= '1' && s1[i][j] <= '9') {
        dinic.AddEdge(source, idx[0][i][j], s1[i][j] - '0');
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (s1[i][j] == 'Y' || s1[i][j] == 'Z') continue;
      for (int k = 0; k < 4; k++) {
        int vy = i + dir[k][0], vx = j + dir[k][1];
        if (vy >= 1 && vy <= n && vx >= 1 && vx <= n && s1[vy][vx] != 'Y' &&
            s1[vy][vx] != 'Z') {
          for (int x = 0; x < t; x++) {
            if (dp[vy][vx] >= x + 1 && dp[i][j] > x) {
              dinic.AddEdge(idx[x][i][j], idx[x + 1][vy][vx], 1000);
            }
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (s1[i][j] == 'Y' || s1[i][j] == 'Z') continue;
      for (int x = 0; x <= t; x++) {
        if (s2[i][j] >= '1' && s2[i][j] <= '9') {
          dinic.AddEdge(idx[x][i][j], idx[t + 1][i][j], s2[i][j] - '0');
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (s1[i][j] == 'Y' || s1[i][j] == 'Z') continue;
      if (s2[i][j] >= '1' && s2[i][j] <= '9') {
        dinic.AddEdge(idx[t + 1][i][j], sink, s2[i][j] - '0');
      }
    }
  }
  printf("%d\n", dinic.MaxFlow(source, sink));
}
