#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[200500];
pair<int, int> b[200500];
int main() {
  int shit, n, p, t;
  ios_base::sync_with_stdio(false);
  cin >> shit >> n >> p >> t;
  int pos = 0;
  a[0] = {-t - 1, 0};
  int tot = 1;
  while (n--) {
    int l, r;
    cin >> l >> r;
    while (pos + 1 < tot && a[pos + 1].first + t <= l) pos++;
    int z = 0;
    int cnt = (r - l) / p;
    b[z++] = {cnt * p + l, cnt + a[pos].second};
    while (pos + 1 < tot && a[pos + 1].first + t <= r) {
      pos++;
      int cnt = (r - a[pos].first - t) / p;
      if (cnt == 0) break;
      b[z++] = {cnt * p + a[pos].first + t, cnt + a[pos].second};
    }
    sort(b, b + z);
    for (int i = 0; i < z; i++) {
      if (b[i].second <= a[tot - 1].second) continue;
      a[tot++] = b[i];
    }
  }
  cout << a[tot - 1].second;
  return 0;
}
