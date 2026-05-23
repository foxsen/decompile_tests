#include <bits/stdc++.h>
struct edge {
  int to;
  edge* next;
} E[6010], *ne = E, *first[3010];
void link(int a, int b) {
  *ne = (edge){b, first[a]};
  first[a] = ne++;
}
int C[3010], cnt;
bool tag[3010];
int dfs1(int i, int f) {
  int t;
  tag[i] = 1;
  for (edge* e = first[i]; e; e = e->next)
    if (e->to != f) {
      if (tag[e->to])
        return C[cnt++] = i, e->to;
      else if ((t = dfs1(e->to, i)) > -1)
        return (C[cnt++] = i) == t ? -1 : t;
      else if (t == -1)
        return tag[i] = 0, -1;
    }
  tag[i] = 0;
  return -2;
}
double dfs2(int i, int f, int d, int l, int r) {
  double s = 1.0 / (d + l) + 1.0 / (d + r) - 1.0 / (d + l + r);
  for (edge* e = first[i]; e; e = e->next)
    e->to != f && (!tag[i] || !tag[e->to]) ? s += dfs2(e->to, i, d + 1, l, r)
                                           : 1;
  if (tag[i] && (f == -1 || !tag[f])) {
    int k = 0;
    while (C[k] != i) k++;
    r = cnt - 2;
    for (int j = (k + 1) % cnt; j != k; j = (j + 1) % cnt, l++, r--)
      s += dfs2(C[j], i, d + 1, l, r);
  }
  return s;
}
int main() {
  int n, a, b;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &a, &b), link(a, b), link(b, a);
  dfs1(0, -1);
  double ans = 0;
  for (int i = 0; i < n; i++) ans += dfs2(i, -1, 1, 0, 0);
  printf("%.12lf\n", ans);
}
