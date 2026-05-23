#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
struct Node {
  int t, a, b;
} p[MAXN];
inline bool cmp(const Node &p, const Node &q) { return p.t < q.t; }
void solve(void) {
  int n, m, c, beg;
  scanf("%d%d%d%d", &n, &m, &c, &beg);
  for (int i = 1; i <= n; ++i) scanf("%d%d%d", &p[i].t, &p[i].a, &p[i].b);
  sort(p + 1, p + n + 1, cmp);
  map<int, int> cost;
  cost[0] = beg;
  int sum = beg;
  p[++n] = (Node){m, 0, 0};
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    register int need = p[i].t - p[i - 1].t;
    if (sum < need) {
      printf("-1\n");
      return;
    }
    while (!cost.empty() && need) {
      pair<int, int> cur = *cost.begin();
      cost.erase(cost.begin());
      int used = min(cur.second, need);
      ans += (long long)used * cur.first;
      need -= used;
      cur.second -= used;
      sum -= used;
      if (cur.second) cost[cur.first] = cur.second;
    }
    if (i == n) break;
    register int a = p[i].a, b = p[i].b;
    int ins = 0;
    if (sum < c) {
      int tmp = min(a, c - sum);
      if (tmp) {
        ins += tmp;
        sum += tmp;
        a -= tmp;
      }
    }
    while (!cost.empty() && a) {
      pair<int, int> cur = *cost.rbegin();
      if (cur.first < b) break;
      cost.erase(cur.first);
      int used = min(cur.second, a);
      cur.second -= used;
      a -= used;
      ins += used;
      if (cur.second) cost[cur.first] += cur.second;
    }
    cost[b] += ins;
  }
  printf("%lld\n", ans);
}
int main(void) {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
