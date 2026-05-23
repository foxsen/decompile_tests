#include <bits/stdc++.h>
using namespace std;
int target, n, m;
bool same_x(int i, int j) { return ceil(i / (double)m) == ceil(j / (double)m); }
bool same_y(int i, int j) {
  return i - (ceil(i / (double)m) - 1) * m == j - (ceil(j / (double)m) - 1) * m;
}
bool edge_exists(int i, int j) {
  return ((abs(i - j) == 1 && (same_x(i, j) || same_y(i, j))) ||
          (abs(i - j) == m && (same_x(i, j) || same_y(i, j))));
}
void dfs(int vertex, bool visited[]) {
  int x = ceil(vertex / (double)m);
  int y = vertex - (x - 1) * m;
  visited[vertex] = true;
  if (edge_exists(vertex, target)) {
    visited[target] = true;
    return;
  }
  vector<int> v = {vertex - 1, vertex + 1, vertex - m, vertex + m};
  for (auto i : v) {
    if (i >= 1 && i <= n * m && (same_x(vertex, i) || same_y(vertex, i))) {
      if (!visited[i] && !visited[target]) dfs(i, visited);
      if (visited[target]) break;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  char c;
  extern int n, m;
  int counter = 0, start_x, start_y, end_x, end_y;
  cin >> n >> m;
  bool visited[n * m + 1];
  memset(visited, false, sizeof(visited));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> c, visited[++counter] = (c == 'X') ? true : false;
  for (int i = 1, x, y; i <= n * m; i++) {
    x = ceil(i / (double)m);
    y = i - (x - 1) * m;
  }
  cin >> start_x >> start_y >> end_x >> end_y;
  target = (end_x - 1) * m + end_y;
  visited[(start_x - 1) * m + start_y] = false;
  bool again = false;
  if (visited[target]) again = true, visited[target] = false;
  dfs((start_x - 1) * m + start_y, visited);
  if (again && visited[target]) cout << "YES" << endl, exit(0);
  if (visited[target] == true) {
    visited[target] = false;
    vector<int> v = {target - 1, target + 1, target - m, target + m};
    for (auto i : v) {
      if (i >= 1 && i <= n * m && (same_x(target, i) || same_y(target, i)))
        if (visited[i] == false) visited[target] = true;
    }
    if (visited[target] == true)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  } else
    cout << "NO" << endl;
  return 0;
}
