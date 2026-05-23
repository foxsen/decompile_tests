#include <bits/stdc++.h>
using namespace std;
void Emsawy() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
const double PI = acos(-1.0);
const double eps = 1e-10;
const long long mod = 1e9 + 7, oo = 1e9;
int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};
int n, m, k, c;
const int N = 100000 + 5;
pair<int, int> g[N];
int cnt[N], p[300], lstp[300];
int main() {
  Emsawy();
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> g[i].first;
    }
    for (int i = 0; i < n; i++) {
      cin >> g[i].second;
    }
    sort(g, g + n);
    for (int i = n - 1; i >= 0; i--) {
      cnt[i] = g[i].second;
      if (i + 1 < n) {
        cnt[i] += cnt[i + 1];
      }
    }
    int ans = oo, maxlen = 0;
    for (int i = 0; i < n; i++) {
      p[g[i].second]++;
      maxlen++;
      if (g[i].first != g[i + 1].first) {
        int cur = 0, rem = (i + 1) - (maxlen * 2 - 1);
        if (rem > 0) {
          for (int j = 0; j < 300; j++) {
            if (rem - lstp[j] >= 0) {
              rem -= lstp[j];
              cur += lstp[j] * j;
            } else {
              cur += rem * j;
              rem = 0;
              break;
            }
          }
        }
        ans = min(ans, cnt[i + 1] + cur);
        for (int j = 0; j < 300; j++) {
          lstp[j] += p[j];
        }
        memset(p, 0, sizeof(p));
        maxlen = 0;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
