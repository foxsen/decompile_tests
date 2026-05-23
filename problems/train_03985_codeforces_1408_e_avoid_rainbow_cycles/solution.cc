#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int a[N], b[N], fa[2 * N];
long long tot = 0;
int Find(int x) { return fa[x] == x ? x : fa[x] = Find(fa[x]); }
struct edge {
  int u, v, val;
  bool operator<(const edge& rhs) const { return val > rhs.val; }
};
vector<edge> v;
int main() {
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= m; ++i) scanf("%d", a + i);
  for (int i = 1; i <= n; ++i) scanf("%d", b + i);
  for (int i = 1; i <= m + n; ++i) fa[i] = i;
  for (int i = 1; i <= m; ++i) {
    int s;
    scanf("%d", &s);
    int x;
    for (int j = 0; j < s; ++j) {
      scanf("%d", &x);
      tot += 1LL * (a[i] + b[x]);
      edge e;
      e.u = i, e.v = (m + x), e.val = a[i] + b[x];
      v.push_back(e);
    }
  }
  long long maxv = 0;
  sort(v.begin(), v.end());
  for (auto e : v) {
    if (Find(e.u) == Find(e.v)) continue;
    maxv += 1LL * e.val;
    int x = Find(e.u), y = Find(e.v);
    fa[x] = y;
  }
  printf("%lld\n", tot - maxv);
}
