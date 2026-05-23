#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
long long sqr(long long a) { return a * a; }
long long dist(pair<int, int> a, pair<int, int> b) {
  return sqr(a.first - b.first) + sqr(a.second - b.second);
}
pair<int, int> newval(pair<int, int> a, pair<int, int> b) {
  pair<int, int> v((b.first - a.first), (b.second - a.second));
  pair<int, int> r = v;
  r.first = v.second;
  r.second = -v.first;
  v.first = b.first + r.first;
  v.second = b.second + r.second;
  return v;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < (int)n; i++) {
    pair<int, int> a[4];
    pair<int, int> b[4];
    pair<int, int> c[4];
    for (int j = 0; j < (int)4; j++) {
      cin >> a[j].first >> a[j].second >> b[j].first >> b[j].second;
      c[j] = a[j];
    }
    int mi = maxn;
    for (int q = 0; q < 4; q++) {
      for (int w = 0; w < 4; w++) {
        for (int e = 0; e < 4; e++) {
          for (int r = 0; r < 4; r++) {
            vector<long long> y;
            for (int p = 0; p < 4; p++) {
              for (int u = p + 1; u < 4; u++) {
                y.push_back(dist(c[p], c[u]));
              }
            }
            sort(y.begin(), y.end());
            if (y[0] == y[1] && y[0] == y[2] && y[0] == y[3] && y[4] == y[5] &&
                (long long)2 * y[0] == y[5] && y[0] != 0) {
              mi = min(mi, q + w + e + r);
            }
            c[3] = newval(c[3], b[3]);
          }
          c[2] = newval(c[2], b[2]);
        }
        c[1] = newval(c[1], b[1]);
      }
      c[0] = newval(c[0], b[0]);
    }
    if (mi == maxn) {
      cout << -1 << endl;
    } else {
      cout << mi << endl;
    }
  }
  return 0;
}
