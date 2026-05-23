#include <bits/stdc++.h>
using namespace std;
vector<int> e[100001], w[100001], sv[100001];
int dis[100001], diss[100001], dl[100001], fr[100001], ff[100001], nt[100001],
    rr[100001], vis[100001], rk[100001];
int ed, n, m, dd, x, y, z;
inline bool cmp(int x, int y) {
  if (rk[x] != rk[y])
    return rk[x] < rk[y];
  else
    return diss[x] < diss[y];
}
inline void bfs1() {
  for (int i = (1); i <= (n - 1); i++) dis[i] = 1000000000;
  int s = 1, t = 1;
  vis[0] = 1;
  for (; s <= t; s++) {
    int ss = dl[s], sz = e[ss].size() - 1;
    for (int i = (0); i <= (sz); i++) {
      int tt = e[ss][i];
      if (dis[ss] + 1 < dis[tt]) {
        dis[tt] = dis[ss] + 1;
        vis[tt] = 1, dl[++t] = tt;
      }
    }
  }
}
inline void bfs2() {
  for (int i = (0); i <= (n - 2); i++) diss[i] = 1000000000;
  for (int i = (0); i <= (n - 1); i++) vis[i] = 0;
  int s = 1, t = 1;
  vis[n - 1] = 1;
  dl[1] = n - 1;
  for (; s <= t; s++) {
    int ss = dl[s], sz = e[ss].size() - 1;
    for (int i = (0); i <= (sz); i++) {
      int tt = e[ss][i];
      if (!w[ss][i] && diss[ss] + 1 < diss[tt]) {
        diss[tt] = diss[ss] + 1;
        nt[tt] = ss;
        vis[tt] = 1, dl[++t] = tt;
      }
    }
  }
}
void prf(int x) {
  if (x) prf(fr[x]);
  printf("%d ", x);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (m); i++) {
    scanf("%d%d%d", &x, &y, &z);
    e[x].push_back(y);
    w[x].push_back(z);
    e[y].push_back(x);
    w[y].push_back(z);
  }
  bfs1();
  bfs2();
  ed = n - 1;
  for (int i = (0); i <= (n - 1); i++)
    if (dis[i] != 1000000000) {
      sv[dis[i]].push_back(i);
      if (dis[i] > dd) dd = dis[i];
    }
  for (int i = (1); i <= (dd); i++) {
    int nm = sv[i].size() - 1;
    int lsm = sv[i - 1].size();
    for (int j = (0); j <= (nm); j++) {
      x = sv[i][j];
      rk[x] = lsm * 10;
      int sz = e[x].size() - 1;
      for (int ii = (0); ii <= (sz); ii++) {
        int frm = e[x][ii];
        if (dis[frm] + 1 == dis[x]) {
          int ww = w[x][ii] * lsm + rk[frm];
          if (ww < rk[x]) rk[x] = ww, fr[x] = frm, ff[x] = w[x][ii];
        }
      }
      rr[j] = x;
    }
    sort(rr, rr + nm + 1, cmp);
    for (int j = (0); j <= (nm); j++) rk[rr[j]] = j;
  }
  for (int i = (0); i <= (n - 2); i++)
    if (vis[i]) {
      if (dis[i] == dis[ed] && rk[i] == rk[ed] && diss[i] < diss[ed]) ed = i;
      if (dis[i] == dis[ed] && rk[i] < rk[ed]) ed = i;
      if (dis[i] < dis[ed]) ed = i;
    }
  for (x = ed; x; x = fr[x]) printf("%d", ff[x]);
  if (!ed) printf("0");
  printf("\n%d\n", dis[ed] + diss[ed] + 1);
  prf(ed);
  for (x = nt[ed]; x; x = nt[x]) printf("%d ", x);
}
