#include <bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<vector<int>> edges;
long long ans;
int n;
int magic = 550;
int maxk = 2;
vector<vector<int>> depth, children;
void solve(int u) {
  int d = children[u].size();
  vector<vector<int>> values(d + 2);
  for (int i = 0; i < d; ++i)
    for (int j = 1; j < min(d + 1, (int)depth[children[u][i]].size()); ++j)
      values[j].push_back(depth[children[u][i]][j]);
  depth[u].resize(d + 2, 1);
  for (int k = 1; k <= d; ++k) {
    if (values[k].size() < k)
      depth[u][k] = 2;
    else {
      nth_element(values[k].begin(), values[k].begin() + k - 1, values[k].end(),
                  greater<int>());
      depth[u][k] = values[k][k - 1] + 1;
    };
    if (depth[u][k] > 2) maxk = max(maxk, k);
  };
};
void process() {
  scanf("%d", &n);
  visited.resize(n, false);
  edges.resize(n);
  depth.resize(n);
  children.resize(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--;
    v--;
    edges[u].push_back(v);
    edges[v].push_back(u);
  };
  vector<pair<int, int>> stack;
  vector<int> postorder;
  visited[0] = true;
  stack.push_back(make_pair(0, -1));
  while (stack.size()) {
    auto p = stack.back();
    stack.pop_back();
    int u = p.first;
    if (p.second == -1) {
      stack.push_back(make_pair(u, 0));
      for (auto v : edges[u]) {
        if (!visited[v]) {
          stack.push_back(make_pair(v, -1));
          visited[v] = true;
          children[u].push_back(v);
        };
      };
    } else {
      postorder.push_back(u);
    }
  };
  for (auto u : postorder) solve(u);
  ans = 0;
  for (int u = 0; u < n; ++u) {
    ans += depth[u][1];
  }
  vector<int> val(n, 1);
  magic = maxk;
  for (int k = 2; k <= min(magic, n); ++k) {
    for (auto u : postorder) {
      int temp = 1;
      if (depth[u].size() > k) {
        temp = depth[u][k];
      };
      for (auto v : children[u])
        if (val[v] > temp) temp = val[v];
      ans += temp;
      val[u] = temp;
    };
  };
  if (n > magic) {
    vector<int> degree(n + 1);
    for (auto u : postorder) {
      degree[u] = children[u].size();
      for (auto v : children[u]) degree[u] = max(degree[u], degree[v]);
      if (degree[u] > magic) {
        ans += n - magic + (degree[u] - magic);
      } else {
        ans += (n - magic);
      }
    };
  }
  printf("%lld\n", ans);
};
int main() { process(); }
