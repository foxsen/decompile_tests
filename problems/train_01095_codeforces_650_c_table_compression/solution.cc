#include <bits/stdc++.h>
using namespace std;
struct yts {
  int x, t, l, ne;
} e[4000010];
struct yts2 {
  int x, t, ne;
} E[4000010];
struct PP {
  int x, id;
};
vector<PP> vec1[1000010], vec2[1000010];
int v[2000010], V[2000010], scc[2000010], dfn[2000010], low[2000010],
    st[2000010], q[2000010], du[2000010], f[2000010], ID[2000010];
int n, m, rnum, num, dfs_cnt, scc_cnt, top, cnt;
bool cmp(PP a, PP b) { return a.x < b.x; }
int go(int x, int y) { return (x - 1) * m + y; }
void reput(int x, int y) {
  rnum++;
  E[rnum].x = x;
  E[rnum].t = y;
  du[y]++;
  E[rnum].ne = V[x];
  V[x] = rnum;
}
void put(int x, int y, int l) {
  num++;
  e[num].x = x;
  e[num].t = y;
  e[num].l = l;
  e[num].ne = v[x];
  v[x] = num;
}
void tarjan(int x) {
  dfn[x] = low[x] = ++dfs_cnt;
  st[++top] = x;
  for (int i = v[x]; i; i = e[i].ne) {
    int y = e[i].t;
    if (!dfn[y]) {
      tarjan(y);
      low[x] = min(low[x], low[y]);
    } else if (!scc[y])
      low[x] = min(low[x], dfn[y]);
  }
  if (dfn[x] == low[x]) {
    int y;
    scc_cnt++;
    do {
      y = st[top--];
      scc[y] = scc_cnt;
    } while (y != x);
  }
}
void rebuild() {
  for (int x = 1; x <= cnt; x++)
    for (int i = v[x]; i; i = e[i].ne) {
      int y = e[i].t;
      if (scc[x] != scc[y]) reput(scc[x], scc[y]);
    }
}
void tp() {
  int h = 0, w = 1;
  for (int i = 1; i <= scc_cnt; i++)
    if (du[i] == 0) q[++w] = i;
  while (h != w) {
    int x = q[++h];
    f[x]++;
    for (int i = V[x]; i; i = E[i].ne) {
      int y = E[i].t;
      f[y] = max(f[y], f[x]);
      du[y]--;
      if (du[y] == 0) q[++w] = y;
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int x;
      scanf("%d", &x);
      vec1[i].push_back((PP){x, j});
      vec2[j].push_back((PP){x, i});
    }
  cnt = 0;
  for (int i = 1; i <= n; i++) {
    sort(vec1[i].begin(), vec1[i].end(), cmp);
    int now = -1;
    for (int j = 0; j < m; j++) {
      if (vec1[i][j].x != now) {
        now = vec1[i][j].x;
        cnt++;
        if (j) put(cnt - 1, cnt, 1);
      }
      ID[go(i, vec1[i][j].id)] = cnt;
    }
  }
  for (int i = 1; i <= m; i++) {
    sort(vec2[i].begin(), vec2[i].end(), cmp);
    int now = -1;
    for (int j = 0; j < n; j++) {
      if (vec2[i][j].x != now) {
        now = vec2[i][j].x;
        cnt++;
        if (j) put(cnt - 1, cnt, 1);
      }
      int y = ID[go(vec2[i][j].id, i)];
      put(cnt, y, 0);
      put(y, cnt, 0);
    }
  }
  for (int i = 1; i <= cnt; i++)
    if (!dfn[i]) tarjan(i);
  rebuild();
  tp();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%d ", f[scc[ID[go(i, j)]]]);
    printf("\n");
  }
  return 0;
}
