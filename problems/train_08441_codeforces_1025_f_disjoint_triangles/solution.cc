#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3030;
const double pi = acos(-1);
struct Point {
  int x, y, c, id;
  double k;
  bool operator<(const Point &b) const { return k < b.k; }
} p[MAXN], o;
int n, cnt[2], bl[MAXN];
long long ans, tmp[2];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &p[i].x, &p[i].y), p[i].id = i;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      if (p[j].id == i) {
        o = p[j];
        break;
      }
    for (int j = 1; j <= n; j++) {
      p[j].k = (p[j].id == i) ? 1e9 : atan2(p[j].y - o.y, p[j].x - o.x);
      if (p[j].k <= 0) p[j].k += pi;
    }
    memset(cnt, 0, sizeof cnt);
    sort(p + 1, p + n + 1);
    for (int j = 1; j < n; j++)
      if (p[j].y < o.y || (p[j].y == o.y && p[j].x > o.x))
        cnt[bl[j] = 0]++;
      else
        cnt[bl[j] = 1]++;
    tmp[0] = cnt[0] * (cnt[0] - 1) / 2;
    tmp[1] = cnt[1] * (cnt[1] - 1) / 2;
    for (int j = 1; j < n; j++) {
      tmp[bl[j]] -= --cnt[bl[j]];
      ans += tmp[0] * tmp[1];
      bl[j] ^= 1;
      tmp[bl[j]] += cnt[bl[j]]++;
    }
  }
  cout << ans / 2 << endl;
}
