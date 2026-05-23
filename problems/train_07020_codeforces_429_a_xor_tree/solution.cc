#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > G;
vector<int> a, b, sol;
void DFS(int node, int parent, bool even_times, bool odd_times, int level) {
  bool ok = false;
  if (level & 1) {
    if (odd_times) a[node] ^= 1;
  } else if (even_times)
    a[node] ^= 1;
  if (a[node] != b[node]) {
    sol.emplace_back(node);
    a[node] ^= 1;
    ok = true;
  }
  for (int next : G[node])
    if (next != parent) {
      bool new_even_times = even_times, new_odd_times = odd_times;
      if (ok) {
        if (level & 1)
          new_odd_times ^= 1;
        else
          new_even_times ^= 1;
      }
      DFS(next, node, new_even_times, new_odd_times, level + 1);
    }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N;
  cin >> N;
  G.resize(N + 1), a.resize(N + 1), b.resize(N + 1);
  for (int i = 1; i < N; ++i) {
    int u, v;
    cin >> u >> v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  for (int i = 1; i <= N; ++i) cin >> a[i];
  for (int i = 1; i <= N; ++i) cin >> b[i];
  DFS(1, 0, false, false, 0);
  cout << (int)sol.size() << '\n';
  for (int node : sol) cout << node << '\n';
}
