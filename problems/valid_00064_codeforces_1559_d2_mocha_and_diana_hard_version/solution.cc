#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int n, m1, m2, fa[N], fa2[N];
int as, pa, pb, a[N], b[N];
pair<int, int> t[N];
int find(int x) {
  if (fa[x] == x) return x;
  return fa[x] = find(fa[x]);
}
int find2(int x) {
  if (fa2[x] == x) return x;
  return fa2[x] = find2(fa2[x]);
}
int main() {
  scanf("%d%d%d", &n, &m1, &m2);
  for (int i = 1; i <= n; i++) fa[i] = i, fa2[i] = i;
  for (int i = 1; i <= m1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    fa[find(a)] = find(b);
  }
  for (int i = 1; i <= m2; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    fa2[find2(a)] = find2(b);
  }
  for (int i = 2; i <= n; i++) {
    int fi = find(1), fv = find(i), fi2 = find2(1), fv2 = find2(i);
    if (fi == fv || fi2 == fv2) continue;
    fa[fv] = fi, fa2[fv2] = fi2;
    t[++as] = {1, i};
  }
  for (int i = 2; i <= n; i++) {
    int fi = find(1), fv = find(i), fi2 = find2(1), fv2 = find2(i);
    if (fi != fv) a[++pa] = i, fa[fv] = fi;
    if (fi2 != fv2) b[++pb] = i, fa2[fv2] = fi2;
  }
  printf("%d\n", as + min(pa, pb));
  for (int i = 1; i <= as; i++) printf("%d %d\n", t[i].first, t[i].second);
  for (int i = 1; i <= min(pa, pb); i++) printf("%d %d\n", a[i], b[i]);
  return 0;
}
