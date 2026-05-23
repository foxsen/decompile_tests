#include <bits/stdc++.h>
using namespace std;
vector<long long> res;
vector<vector<int>> G;
vector<vector<pair<int, int>>> root_queries;
vector<bool> mark;
vector<long long> ft(300010, 0);
long long point_query(int b) {
  long long sum = 0;
  for (; b; b -= (b & (-b))) sum += ft[b];
  return sum;
}
void point_update(int k, long long v) {
  for (; k < ft.size(); k += (k & (-k))) ft[k] += v;
}
void range_update(int i, int j, long long v) {
  point_update(i, v);
  point_update(j + 1, -v);
}
void dfs(int u, int depth) {
  mark[u] = true;
  for (auto &p : root_queries[u]) {
    range_update(depth, min(depth + p.second, 300001), (long long)p.first);
  }
  res[u] = point_query(depth);
  for (auto &v : G[u])
    if (!mark[v]) {
      dfs(v, depth + 1);
    }
  for (auto &p : root_queries[u]) {
    range_update(depth, min(depth + p.second, 300001), -(long long)p.first);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  mark = vector<bool>(n, false);
  res = vector<long long>(n, 0);
  G = vector<vector<int>>(n, vector<int>());
  int x, y, v, d;
  for (int i = 0; i < n - 1; ++i) {
    cin >> x >> y;
    --x;
    --y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  root_queries = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> v >> d >> x;
    root_queries[v - 1].emplace_back(x, d);
  }
  dfs(0, 1);
  for (auto i : res) cout << i << " ";
  cout << "\n";
  return 0;
}
