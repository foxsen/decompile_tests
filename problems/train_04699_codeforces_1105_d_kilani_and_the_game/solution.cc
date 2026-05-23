#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int K = 10;
int a[N][N];
int speed[10];
int n, m;
bool isValid(int x, int y) { return (x >= 0 && y >= 0 && x < n && y < m); }
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int p;
  cin >> n >> m >> p;
  for (int i = 1; i <= p; i++) cin >> speed[i];
  queue<pair<int, int> > q[K];
  char ch;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> ch;
      if (ch >= '1' && ch <= '9') {
        int id = (ch - '0');
        a[i][j] = id;
        q[id].push({i, j});
      } else if (ch == '#') {
        a[i][j] = 10;
      } else {
        a[i][j] = 0;
      }
    }
  }
  vector<int> dx = {-1, 1, 0, 0};
  vector<int> dy = {0, 0, 1, -1};
  while (1) {
    bool leftCells = 0;
    for (int playerId = 1; playerId <= p; playerId++) {
      for (int i = 0; i < speed[playerId]; i++) {
        if (q[playerId].empty()) break;
        queue<pair<int, int> > tempQ;
        while (q[playerId].size()) {
          pair<int, int> p = q[playerId].front();
          q[playerId].pop();
          for (int k = 0; k < 4; k++) {
            int newX = p.first + dx[k], newY = p.second + dy[k];
            if (isValid(newX, newY) && a[newX][newY] == 0) {
              tempQ.push({newX, newY});
              a[newX][newY] = playerId;
              leftCells = 1;
            }
          }
        }
        swap(q[playerId], tempQ);
      }
    }
    if (leftCells == 0) break;
  }
  vector<int> ans(11, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans[a[i][j]]++;
    }
  }
  for (int i = 1; i <= p; i++) cout << ans[i] << " ";
  return 0;
}
