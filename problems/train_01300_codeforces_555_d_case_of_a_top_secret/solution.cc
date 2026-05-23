#include <bits/stdc++.h>
using namespace std;
const int maxn = 200003;
long long INF = 0x3f3f3f3f3f3f3f3fll;
int n, Q, pos[maxn];
pair<long long, int> a[maxn];
int main() {
  scanf("%d%d", &n, &Q);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i].first), a[i].second = i;
  sort(a + 1, a + n + 1);
  a[0].first = -INF, a[n + 1].first = INF;
  for (int i = 1; i <= n; i++) pos[a[i].second] = i;
  while (Q--) {
    int y, p;
    long long l;
    scanf("%d%lld", &y, &l);
    y = pos[y];
    bool dir = 1;
    int flag = 0;
    while (1) {
      if (flag == 2) {
        printf("%d\n", a[p].second);
        break;
      }
      if (dir) {
        p = upper_bound(a + 1, a + n + 1,
                        pair<long long, int>(a[y].first + l, maxn)) -
            a - 1;
        long long len = a[p].first - a[y].first;
        if (p == y) {
          flag++;
          dir = 0;
          continue;
        }
        flag = 0;
        if (l < a[p + 1].first - a[y].first &&
            a[y].first + len - l > a[y - 1].first) {
          if (l / len % 2) dir = 0, y = p;
          l %= len;
        } else {
          l -= len;
          y = p;
          dir = 0;
        }
      } else {
        p = lower_bound(a + 1, a + n + 1,
                        pair<long long, int>(a[y].first - l, 0)) -
            a;
        long long len = a[y].first - a[p].first;
        if (p == y) {
          flag++;
          dir = 1;
          continue;
        }
        flag = 0;
        if (l > a[p - 1].first && a[y].first - len + l < a[y + 1].first) {
          if (l / len % 2) dir = 0, y = p;
          l %= len;
        } else {
          l -= len;
          y = p;
          dir = 1;
        }
      }
    }
  }
  return 0;
}
