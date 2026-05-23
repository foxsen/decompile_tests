#include <bits/stdc++.h>
using namespace std;
int N, K, NR = 1, a[100100], g[100100], root[100100], Q, lst;
vector<int> c[100100];
struct range {
  int l, r, sum;
} r[4400400];
int u(int i, int rs, int re, int p, int d) {
  int n = ++NR;
  r[n] = r[i];
  if (rs == re - 1)
    r[n].sum += d;
  else {
    int m = (rs + re) / 2;
    if (p < m)
      r[n].l = u(r[n].l, rs, m, p, d);
    else
      r[n].r = u(r[n].r, m, re, p, d);
    r[n].sum = r[r[n].l].sum + r[r[n].r].sum;
  }
  return n;
}
int q(int i, int rs, int re, int qs, int qe) {
  if (rs == qs && re == qe) return r[i].sum;
  int m = (rs + re) / 2, n = 0;
  if (qs < m && r[i].l) n += q(r[i].l, rs, m, qs, min(m, qe));
  if (qe > m && r[i].r) n += q(r[i].r, m, re, max(qs, m), qe);
  return n;
}
int main() {
  scanf("%d %d", &N, &K);
  for (int i = (1); i < (N + 1); i++) {
    scanf("%d", &a[i]);
    c[a[i]].push_back(i);
  }
  for (int i = (1); i < (100100); i++) {
    for (int j = 0; j + K < ((int)c[i].size()); j++) {
      g[c[i][j]] = c[i][j + K];
    }
  }
  root[N + 1] = 1;
  for (int i = N; i >= 1; i--) {
    root[i] = u(root[i + 1], 1, N + 1, i, 1);
    if (g[i]) root[i] = u(root[i], 1, N + 1, g[i], -1);
  }
  scanf("%d", &Q);
  for (int z = (0); z < (Q); z++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x = (x + lst) % N + 1, y = (y + lst) % N + 1;
    if (x > y) swap(x, y);
    lst = q(root[x], 1, N + 1, x, y + 1);
    printf("%d\n", lst);
  }
  return 0;
}
