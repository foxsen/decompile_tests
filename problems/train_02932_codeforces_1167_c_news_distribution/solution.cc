#include <bits/stdc++.h>
using namespace std;
int visited[5 * 100000] = {};
void dfs(vector<int> grid[], int start, int* visited, int& cnt,
         vector<int>& comp) {
  cnt++;
  visited[start] = 1;
  comp.push_back(start);
  if (grid[start].size() == 0) return;
  for (int i = 0; i < grid[start].size(); i++) {
    if (visited[grid[start][i]] == 0) {
      dfs(grid, grid[start][i], visited, cnt, comp);
    }
  }
}
int main() {
  int t = 1;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> grid[n];
    for (int i = 0; i < m; i++) {
      int size;
      cin >> size;
      vector<int> v;
      if (size == 0) continue;
      for (int j = 0; j < size; j++) {
        int x;
        cin >> x;
        v.push_back(x - 1);
      }
      for (int k = 0; k < v.size() - 1; k++) {
        grid[v[k]].push_back(v[k + 1]);
        grid[v[k + 1]].push_back(v[k]);
      }
    }
    int ans[n];
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        int cnt = 0;
        vector<int> comp;
        dfs(grid, i, visited, cnt, comp);
        for (auto x : comp) ans[x] = cnt;
      }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
  }
}
