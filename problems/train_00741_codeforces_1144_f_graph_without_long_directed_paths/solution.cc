#include <bits/stdc++.h>
using namespace std;
bool answer = true;
void dfs(vector<int>& visited, vector<vector<int>>& g, int vertex, int oddity) {
  visited[vertex] = oddity;
  for (int i = 0; i < g[vertex].size(); ++i) {
    if (visited[g[vertex][i]] == 0) {
      dfs(visited, g, g[vertex][i], oddity == 1 ? -1 : 1);
    } else if (visited[g[vertex][i]] == visited[vertex]) {
      answer = false;
      return;
    }
  }
  return;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  int x, y;
  vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    --x;
    --y;
    g[x].push_back(y);
    g[y].push_back(x);
    edges[i].first = x;
    edges[i].second = y;
  }
  vector<int> visited(n, 0);
  dfs(visited, g, 0, 1);
  if (answer == false) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for (int i = 0; i < m; ++i) {
      if (visited[edges[i].first] == 1) {
        cout << 1;
      } else {
        cout << 0;
      }
    }
    cout << endl;
  }
  return 0;
}
