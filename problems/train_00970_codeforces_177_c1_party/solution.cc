#include <bits/stdc++.h>
using namespace std;
const long long N_max = 0;
class graph {
 private:
  long long V;
  long long k, m;
  vector<pair<long long, long long>> L;
  vector<pair<long long, long long>> L2;

 public:
  graph(long long n) { V = n; }
  void add_edge(long long u, long long v) { L.push_back({u, v}); }
  long long find_set(long long i, long long parent[]) {
    if (parent[i] == -1) return i;
    parent[i] = find_set(parent[i], parent);
    return find_set(parent[i], parent);
  }
  void union_set(long long x, long long y, long long parent[],
                 long long rank[]) {
    long long S1 = find_set(x, parent);
    long long S2 = find_set(y, parent);
    if (S1 != S2) {
      if (rank[S1] < rank[S2]) {
        parent[S1] = S2;
        rank[S2] += rank[S1];
      } else {
        parent[S2] = S1;
        rank[S1] += rank[S2];
      }
    }
  }
  void solve() {
    long long m, i, x, y, u, v, ans, leader, sz;
    long long parent[V];
    long long rank[V];
    bool isValid[V];
    for (i = 0; i < V; i++) {
      parent[i] = -1;
      rank[i] = 1;
      isValid[i] = true;
    }
    for (auto edge : L) {
      u = edge.first;
      v = edge.second;
      union_set(u, v, parent, rank);
    }
    cin >> m;
    for (i = 0; i < m; i++) {
      cin >> u >> v;
      u -= 1, v -= 1;
      x = find_set(u, parent);
      y = find_set(v, parent);
      if (x == y) {
        isValid[x] = false;
      }
    }
    ans = 0;
    for (i = 0; i < V; i++) {
      leader = find_set(i, parent);
      if (isValid[leader]) {
        sz = rank[leader];
        ans = max(ans, sz);
      }
    }
    cout << ans << "\n";
  }
};
void run_case() {
  long long n, i, k, u, v;
  cin >> n;
  graph G(n);
  cin >> k;
  for (i = 0; i < k; i++) {
    cin >> u >> v;
    u -= 1, v -= 1;
    G.add_edge(u, v);
  }
  G.solve();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T = 1;
  while (T--) run_case();
  return 0;
}
