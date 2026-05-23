#include <bits/stdc++.h>
using namespace std;
bool valid(int x, int y, int n, int m) {
  return x >= 0 && y >= 0 && x < n && y < m;
}
void bfs(vector<vector<int>> &graph, vector<vector<int>> &v, int n, int m) {
  queue<pair<int, int>> q;
  q.push(make_pair(0, 0));
  v[0][0] += 2;
  while (!q.empty()) {
    int s = q.size();
    vector<int> temp;
    while (s--) {
      pair<int, int> a = q.front();
      q.pop();
      int x = a.first, y = a.second;
      temp.push_back(v[x][y] - 2);
      if (valid(x + 1, y, n, m) && v[x + 1][y] <= 1) {
        v[x + 1][y] += 2;
        q.push(make_pair(x + 1, y));
      }
      if (valid(x, y + 1, n, m) && v[x][y + 1] <= 1) {
        v[x][y + 1] += 2;
        q.push(make_pair(x, y + 1));
      }
    }
    if (temp.size() != 0) graph.push_back(temp);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) cin >> v[i][j];
    vector<vector<int>> graph;
    ;
    bfs(graph, v, n, m);
    long long left = 0, right = graph.size() - 1, ans = 0;
    while (left < right) {
      long long x = accumulate(graph[left].begin(), graph[left].end(), 0);
      x += accumulate(graph[right].begin(), graph[right].end(), 0);
      long long y = graph[left].size() + graph[right].size() - x;
      if (x < y) y = x;
      ans += y;
      left++;
      right--;
    }
    cout << ans << endl;
  }
  return 0;
}
