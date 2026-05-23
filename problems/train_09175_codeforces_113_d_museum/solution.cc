#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int to, next;
} e[500];
int tot, head[25], n, m, a, b, i, j, num, id[25][25], pos[630][2], d[25], k;
double v[630][630], p[25], ans[25];
inline void add(int u, int v) {
  e[++tot].to = v;
  e[tot].next = head[u];
  head[u] = tot;
}
int main() {
  int uu, vv;
  scanf("%d%d%d%d", &n, &m, &a, &b);
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j) id[i][j] = ++num, pos[num][0] = i, pos[num][1] = j;
  for (i = 1; i <= m; ++i) {
    scanf("%d%d", &uu, &vv);
    add(uu, vv);
    ++d[uu];
    add(vv, uu);
    ++d[vv];
  }
  for (i = 1; i <= n; ++i) scanf("%lf", &p[i]);
  for (i = 1; i <= num; ++i) {
    int u1 = pos[i][0], u2 = pos[i][1];
    v[i][i] = -1;
    if (u1 == u2) continue;
    v[i][i] += p[u1] * p[u2];
    double v1 = (1 - p[u1]) * p[u2] / d[u1], v2 = (1 - p[u2]) * p[u1] / d[u2],
           v3 = (1 - p[u1]) * (1 - p[u2]) / d[u1] / d[u2];
    for (int j = head[u1]; j; j = e[j].next) v[id[e[j].to][u2]][i] = v1;
    for (int j = head[u2]; j; j = e[j].next) v[id[u1][e[j].to]][i] = v2;
    for (int j = head[u1]; j; j = e[j].next)
      for (k = head[u2]; k; k = e[k].next) v[id[e[j].to][e[k].to]][i] = v3;
  }
  v[id[a][b]][num + 1] = -1;
  for (i = 1; i <= num; ++i) {
    int t = -1;
    for (j = i; j <= num; ++j)
      if (t == -1 || fabs(v[j][i]) > fabs(v[t][i])) t = j;
    for (j = 1; j <= num + 1; ++j) swap(v[i][j], v[t][j]);
    for (j = i + 1; j <= num; ++j) {
      double kt = v[j][i] / v[i][i];
      for (k = i; k <= num + 1; ++k) v[j][k] -= kt * v[i][k];
    }
  }
  for (i = num; i >= 1; --i) {
    for (j = i + 1; j <= num + 1; ++j) v[i][num + 1] -= ans[j] * v[i][j];
    ans[i] = v[i][num + 1] / v[i][i];
  }
  for (i = 1; i <= n; ++i) printf("%.10lf ", ans[id[i][i]]);
  return 0;
}
