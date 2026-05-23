#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> p;
string maze[55];
string path;
int n, m;
bool simulate(int x, int y) {
  int cx = x, cy = y;
  for (int i = 0; i < path.size(); i++) {
    cx += p[path[i] - '0'].first;
    cy += p[path[i] - '0'].second;
    if (cx < 0 || cx >= n || cy < 0 || cy >= m) return 0;
    if (maze[cx][cy] == 'E') return 1;
    if (maze[cx][cy] == '#') return 0;
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  p.push_back({0, 1});
  p.push_back({0, -1});
  p.push_back({1, 0});
  p.push_back({-1, 0});
  sort(p.begin(), p.end());
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> maze[i];
  cin >> path;
  int sx, sy;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (maze[i][j] == 'S') sx = i, sy = j;
  }
  int res = 0;
  do {
    res += simulate(sx, sy);
  } while (next_permutation(p.begin(), p.end()));
  cout << res << endl;
  return 0;
}
