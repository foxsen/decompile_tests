#include <bits/stdc++.h>
using namespace std;
int n;
int rt;
int vl[100020];
int par[100020];
vector<int> sn[100020];
int dep[100020];
int mx[100020], mn[100020];
double ex[100020];
map<int, int> mp;
int me[100020];
void dfs(int v) {
  int i, u;
  if (sn[v].size() == 0) {
    mx[v] = vl[v];
    mn[v] = vl[v];
    return;
  }
  u = sn[v][0];
  dep[u] = dep[v] + 1;
  dfs(u);
  mn[v] = mn[u];
  u = sn[v][1];
  dep[u] = dep[v] + 1;
  dfs(u);
  mx[v] = mx[u];
}
int dfs2(int v, double s, double br) {
  int i, u;
  if (sn[v].size() == 0) {
    ex[v] = s / br;
    return v;
  }
  u = sn[v][0];
  i = dfs2(u, s + mn[sn[v][1]], br + 1);
  mp[vl[v]] = i;
  u = sn[v][1];
  return dfs2(u, s + mx[sn[v][0]], br + 1);
}
int main() {
  int i, j, k, q;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d %d", &j, &k);
    if (j == -1) {
      rt = i;
      par[i] = j;
    } else {
      par[i] = j;
      sn[j].push_back(i);
    }
    vl[i] = k;
  }
  i = 0;
  int mi = 1;
  for (j = 1; j <= n; j++) {
    if (vl[j] > vl[mi]) mi = j;
    if (sn[j].size() > 0) {
      if (vl[sn[j][0]] > vl[sn[j][1]]) swap(sn[j][0], sn[j][1]);
    }
  }
  dfs(rt);
  dfs2(rt, 0, 0);
  mp[2000000000] = mi;
  scanf("%d", &q);
  for (i = 1; i <= q; i++) {
    scanf("%d", &k);
    printf("%.11lf\n", ex[mp.lower_bound(k)->second]);
  }
  return 0;
}
