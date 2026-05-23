#include <bits/stdc++.h>
using namespace std;
int f[1000001];
vector<pair<int, int> > v;
int main() {
  int n, m, i, j, k;
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    cin >> j >> k;
    v.push_back(make_pair(j, k));
  }
  for (i = 0; i < m; i++) {
    int64_t x1 = v[i].first, y1 = v[i].second;
    for (j = i + 1; j < m; j++) {
      int64_t x2 = v[j].first, y2 = v[j].second;
      int64_t w = x1 * y2 - x2 * y1;
      if ((y1 - y2) != 0 && w % (y2 - y1) == 0) {
        int64_t id = w / (y2 - y1);
        if (id > 0 && id <= n) {
          int sum = 0;
          for (k = 0; k < m; k++) {
            if ((y1 - y2) * (x1 - v[k].first) == (x1 - x2) * (y1 - v[k].second))
              sum++;
          }
          f[id] = max(f[id], sum);
        }
      }
    }
  }
  int ans = 0;
  for (i = 1; i <= n; i++) ans += f[i] ? f[i] : 1;
  cout << ans << endl;
}
