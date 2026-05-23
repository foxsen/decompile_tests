#include <bits/stdc++.h>
using std::forward_list;
using std::queue;
using std::vector;
constexpr int64_t INF = 0x3f3f3f3f3f3f3f3fLL;
struct Edge {
  int to;
  int64_t flow;
  Edge* back = nullptr;
  Edge(int to, int64_t flow) : to(to), flow(flow) {}
};
void insert(vector<forward_list<Edge>>& edges, int from, int to, int64_t flow) {
  edges[from].emplace_front(to, flow);
  edges[to].emplace_front(from, 0);
  edges[from].front().back = &edges[to].front();
  edges[to].front().back = &edges[from].front();
}
int64_t maxFlow(vector<forward_list<Edge>>& edges, const int source,
                const int sink) {
  const int nNodes = edges.size();
  vector<int> levels(nNodes), counts(nNodes);
  counts[0] = nNodes;
  std::function<int64_t(int, int64_t)> sap =
      [nNodes, source, sink, &edges, &levels, &counts, &sap](
          int node, int64_t limit) mutable {
        if (node == sink) return limit;
        int64_t flow = 0;
        for (auto& edge : edges[node]) {
          if (edge.flow > 0 && levels[node] == levels[edge.to] + 1) {
            int64_t current = sap(edge.to, std::min(limit - flow, edge.flow));
            edge.flow -= current;
            edge.back->flow += current;
            flow += current;
            if (flow == limit) return flow;
          }
        }
        if (levels[source] >= nNodes) return flow;
        if (--counts[levels[node]] == 0) levels[source] = nNodes;
        ++counts[++levels[node]];
        return flow;
      };
  int64_t flow = 0;
  while (levels[source] < nNodes) flow += sap(source, INF);
  return flow;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int source = n + m, sink = n + m + 1;
  int nNodes = n + m + 2;
  vector<forward_list<Edge>> edges(nNodes);
  int64_t cost = 0;
  for (int i = 0; i < n; ++i) {
    int value;
    scanf("%d", &value);
    insert(edges, source, i, value);
  }
  for (int j = 0; j < m; ++j) {
    int from, to, value;
    scanf("%d%d%d", &from, &to, &value);
    --from;
    --to;
    insert(edges, j + n, sink, value);
    insert(edges, from, j + n, INF);
    insert(edges, to, j + n, INF);
    cost += value;
  }
  int64_t minCut = maxFlow(edges, source, sink);
  printf("%lld\n", cost - minCut);
  return 0;
}
