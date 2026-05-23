#include <bits/stdc++.h>
using namespace std;
const int SIZE = 2000010;
pair<int, int> pr[SIZE];
bool vis[SIZE];
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    y += x - 1;
    if (pr[x].first < y) {
      pr[x] = {y, i};
    }
  }
  int res = m;
  int r = 0, id = 0, pre = 0;
  for (int i = 1; i <= n; i++) {
    if (pr[i].first > r) {
      r = pr[i].first;
      id = pr[i].second;
    }
    if (i > pre && r >= i) {
      vis[id] = true;
      res--;
      pre = r;
    }
  }
  cout << res << "\n";
  for (int i = 1; i <= m; i++) {
    if (!vis[i]) {
      cout << i << " ";
    }
  }
  return 0;
}
