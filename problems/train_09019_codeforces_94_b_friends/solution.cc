#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int inf = int(2e9);
const int _inf = -inf;
const int mod = inf + 7;
const int N = 101;
using namespace std;
bool used[N][N];
vector<int> g[N];
bool was[6];
void solve() {
  int m;
  cin >> m;
  while (m--) {
    int x, y;
    cin >> x >> y;
    used[x][y] = 1;
    used[y][x] = 1;
  }
  bool ok1 = 0, ok2 = 0;
  for (int i = 1; i <= 5; ++i) {
    for (int j = 1; j <= 5; ++j) {
      if (i == j) continue;
      if (!used[i][j]) {
        for (int k = 1; k <= 5; ++k) {
          if (i != k && j != k) {
            if (!used[j][k] && !used[i][k]) ok1 = 1;
          }
        }
      } else {
        for (int k = 1; k <= 5; ++k) {
          if (i != k && j != k) {
            if (used[j][k] && used[i][k]) {
              ok2 = 1;
            }
          }
        }
      }
    }
  }
  if (ok1 || ok2)
    cout << "WIN";
  else
    cout << "FAIL";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
