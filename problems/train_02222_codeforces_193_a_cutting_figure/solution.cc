#include <bits/stdc++.h>
using namespace std;
vector<int> adj[2505];
bool visited[2505];
set<int> a_points;
int tin[2505];
int low[2505];
int timer;
void dfs(int u, int p) {
  visited[u] = true;
  tin[u] = low[u] = timer++;
  int child = 0;
  for (int v : adj[u]) {
    if (p == v) {
      continue;
    } else if (visited[v]) {
      low[u] = min(tin[v], low[u]);
    } else {
      child++;
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] >= tin[u] && p != -1) {
        a_points.insert(u);
      }
    }
  }
  if (child > 1 && p == -1) {
    a_points.insert(u);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  timer = 0;
  memset(visited, false, sizeof(visited));
  memset(tin, 0, sizeof(tin));
  memset(low, 0, sizeof(low));
  int n, m;
  cin >> n >> m;
  char c, mat[n][m];
  int arr[n][m];
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, -1, 1};
  int cnt = 1, total = 0, tx, ty, last;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> c;
      mat[i][j] = c;
      arr[i][j] = cnt++;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      c = mat[i][j];
      if (c == '#') {
        total++;
        last = arr[i][j];
        for (int k = 0; k < 4; k++) {
          tx = i + dx[k];
          ty = j + dy[k];
          if (tx >= 0 && tx < n && ty >= 0 && ty < m && mat[tx][ty] == '#') {
            adj[arr[i][j]].push_back(arr[tx][ty]);
          }
        }
      }
    }
  }
  if (last == -1 || total == 1 || total == 2) {
    cout << "-1\n";
  } else {
    dfs(last, -1);
    if (a_points.size()) {
      cout << "1\n";
    } else {
      cout << "2\n";
    }
  }
  return 0;
}
