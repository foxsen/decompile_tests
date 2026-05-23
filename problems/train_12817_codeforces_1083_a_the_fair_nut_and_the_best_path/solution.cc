#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 300000;
int wis[MAX_N], ps[MAX_N], pes[MAX_N], cis[MAX_N];
vector<pair<int, int> > nbrs[MAX_N];
long long dp0[MAX_N], dp1[MAX_N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", wis + i);
  for (int i = 1; i < n; i++) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    u--, v--;
    nbrs[u].push_back(pair<int, int>(v, c));
    nbrs[v].push_back(pair<int, int>(u, c));
  }
  long long maxd = 0;
  ps[0] = -1, pes[0] = 0;
  for (int u = 0; u >= 0;) {
    vector<pair<int, int> > &nbru = nbrs[u];
    int up = ps[u];
    if (cis[u] == 0) dp0[u] = dp1[u] = wis[u];
    if (cis[u] < nbru.size()) {
      pair<int, int> ve = nbru[cis[u]++];
      int v = ve.first;
      if (v != up) {
        ps[v] = u, pes[v] = ve.second;
        u = v;
      }
    } else {
      maxd = max(maxd, dp0[u] + dp1[u] - wis[u]);
      if (up >= 0 && dp0[u] >= pes[u]) {
        long long du = dp0[u] - pes[u] + wis[up];
        if (dp0[up] < du)
          dp1[up] = dp0[up], dp0[up] = du;
        else if (dp1[up] < du)
          dp1[up] = du;
      }
      u = up;
    }
  }
  printf("%lld\n", maxd);
  return 0;
}
