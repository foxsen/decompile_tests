#include <bits/stdc++.h>
using namespace std;
struct edge {
  int to, flow, cap, rev;
  double cost;
  edge(int to, int flow, int cap, double cost, int rev)
      : to(to), flow(flow), cap(cap), cost(cost), rev(rev) {}
};
class MinCostMaxFlow {
  int n_;
  vector<double> potentials_;
  vector<pair<int, int>> path_;
  vector<vector<edge>> graph_;

 public:
  MinCostMaxFlow(int n) : n_(n), potentials_(n), path_(n), graph_(n) {}
  void AddEdge(int u, int v, int cap, double cost) {
    edge e1 = edge(v, 0, cap, cost, graph_[v].size());
    edge e2 = edge(u, 0, 0, -cost, graph_[u].size());
    graph_[u].push_back(e1);
    graph_[v].push_back(e2);
  }
  bool SPFA(int s, int t) {
    queue<int> q;
    vector<bool> in_queue(n_, false);
    vector<double> dists(n_, 1e20);
    dists[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      in_queue[cur] = false;
      for (int i = 0; i < graph_[cur].size(); i++) {
        edge e = graph_[cur][i];
        int next = e.to;
        double cost = e.cost;
        if (e.flow < e.cap && dists[cur] + cost + 1e-8 < dists[next]) {
          dists[next] = dists[cur] + cost;
          path_[next] = {cur, i};
          if (!in_queue[next]) {
            q.push(next);
            in_queue[next] = true;
          }
        }
      }
    }
    return dists[t] < 1e15;
  }
  void BellmanFord(int s) {
    queue<int> q;
    vector<int> in_queue(n_, false);
    fill(potentials_.begin(), potentials_.end(), 1e11);
    potentials_[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      in_queue[cur] = false;
      for (edge& e : graph_[cur]) {
        if (e.flow >= e.cap) continue;
        int next = e.to;
        double cost = e.cost;
        if (potentials_[next] > potentials_[cur] + cost) {
          potentials_[next] = potentials_[cur] + cost;
          if (!in_queue[next]) {
            in_queue[next] = true;
            q.push(next);
          }
        }
      }
    }
  }
  int Dijkstra(int s, int t) {
    auto comp = [](pair<double, int> a, pair<double, int> b) {
      return a.first > b.first;
    };
    priority_queue<pair<double, int>, vector<pair<double, int>>, decltype(comp)>
        q(comp);
    vector<double> dists(n_, 1e11);
    vector<int> flow(n_, 0);
    q.push({0, s});
    dists[s] = 0;
    flow[s] = INT_MAX;
    while (!q.empty()) {
      int cur = q.top().second;
      double dist = q.top().first;
      q.pop();
      if (dist != dists[cur]) continue;
      for (int i = 0; i < graph_[cur].size(); i++) {
        edge& e = graph_[cur][i];
        int next = e.to;
        if (e.flow >= e.cap) continue;
        double next_dist = dist + e.cost + potentials_[cur] - potentials_[next];
        if (next_dist + 1e-8 < dists[next]) {
          path_[next] = {cur, i};
          flow[next] = min(flow[cur], e.cap - e.flow);
          dists[next] = next_dist;
          q.push({next_dist, next});
        }
      }
    }
    if (dists[t] > 1e10) {
      return -1;
    }
    for (int i = t; i != s; i = path_[i].first) {
      potentials_[i] += dists[i];
    }
    return flow[t];
  }
  pair<int, double> MinCostFlow1(int s, int t) {
    BellmanFord(s);
    int total_flow = 0;
    double total_cost = 0;
    int flow = Dijkstra(s, t);
    while (flow > 0) {
      total_flow += flow;
      int cur = t;
      while (cur != s) {
        edge& e = graph_[path_[cur].first][path_[cur].second];
        total_cost += e.cost * flow;
        e.flow += flow;
        graph_[cur][e.rev].flow -= flow;
        cur = path_[cur].first;
      }
      flow = Dijkstra(s, t);
    }
    return {total_flow, total_cost};
  }
  pair<int, double> MinCostFlow2(int s, int t) {
    double total_cost = 0;
    int total_flow = 0;
    while (SPFA(s, t)) {
      int cur = t;
      int flow = INT_MAX;
      while (cur != s) {
        edge& e = graph_[path_[cur].first][path_[cur].second];
        flow = min(e.cap - e.flow, flow);
        cur = path_[cur].first;
      }
      total_flow += flow;
      cur = t;
      while (cur != s) {
        cout << cur << ' ';
        edge& e = graph_[path_[cur].first][path_[cur].second];
        e.flow += flow;
        total_cost += e.cost * flow;
        edge& e2 = graph_[cur][e.rev];
        e2.flow -= flow;
        cur = path_[cur].first;
      }
      cout << endl;
      cout << total_cost << endl;
    }
    return {total_flow, total_cost};
  }
};
int main() {
  const int N = 450;
  int x[N], y[N];
  int n, s, t;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  s = 0;
  t = n + n + 1;
  MinCostMaxFlow mcmf(2 * n + 2);
  for (int i = 1; i <= n; i++) {
    mcmf.AddEdge(s, i, 1, 0);
    mcmf.AddEdge(n + i, t, 2, 0);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (y[i] < y[j]) {
        double cost =
            sqrt((y[i] - y[j]) * (y[i] - y[j]) + (x[i] - x[j]) * (x[i] - x[j]));
        mcmf.AddEdge(i, n + j, 1, cost);
      }
    }
  }
  pair<int, double> ans = mcmf.MinCostFlow1(s, t);
  cout << fixed << setprecision(10);
  if (ans.first == n - 1) {
    cout << ans.second;
  } else {
    cout << -1;
  }
}
