#include <bits/stdc++.h>
using namespace std;
int cnt = 1, n, d, k;
vector<vector<int>> graph;
vector<pair<int, int>> edges;
void dfs(int u, int maxd);
int main() {
  cin >> n >> d >> k;
  graph = vector<vector<int>>(n + 1);
  if (n < d + 1) {
    cout << "NO" << endl;
    return 0;
  }
  for (int i = 0; i < d; i++) {
    edges.push_back({cnt, cnt + 1});
    graph[cnt].push_back(cnt + 1);
    graph[cnt + 1].push_back(cnt);
    if (graph[cnt].size() > k || graph[cnt + 1].size() > k) {
      cout << "NO" << endl;
      return 0;
    }
    cnt++;
  }
  for (int i = 1; i <= d + 1; i++) {
    dfs(i, min(d + 1 - i, i - 1));
  }
  if (cnt < n)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    for (int i = 0; i < edges.size(); i++) {
      cout << edges[i].first << " " << edges[i].second << endl;
    }
  }
  return 0;
}
void dfs(int u, int maxd) {
  if (maxd == 0) return;
  for (int i = graph[u].size(); i < k; i++) {
    if (cnt == n) return;
    edges.push_back({u, ++cnt});
    graph[u].push_back(cnt);
    graph[cnt].push_back(u);
    dfs(cnt, maxd - 1);
  }
}
