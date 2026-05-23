#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
struct node {
  int beau, cost;
  bool operator<(node obj) const { return cost < obj.cost; }
} cc[maxn], dd[maxn];
int Cn, Dn;
int C, D, n;
int main() {
  scanf("%d%d%d", &n, &C, &D);
  for (int i = 0; i < n; i++) {
    int a, b;
    char ope;
    scanf("%d%d %c", &a, &b, &ope);
    if (ope == 'C') {
      cc[Cn].beau = a;
      cc[Cn].cost = b;
      Cn++;
    } else {
      dd[Dn].beau = a;
      dd[Dn].cost = b;
      Dn++;
    }
  }
  sort(cc, cc + Cn);
  sort(dd, dd + Dn);
  int maxc = 0, maxd = 0, maxcd = 0;
  for (int i = 0; i < Cn && cc[i].cost <= C; i++) {
    for (int j = i + 1; j < Cn; j++) {
      if (cc[i].cost + cc[j].cost <= C) {
        maxc = max(maxc, cc[i].beau + cc[j].beau);
      } else {
        break;
      }
    }
  }
  for (int i = 0; i < Dn && dd[i].cost <= D; i++) {
    for (int j = i + 1; j < Dn; j++) {
      if (dd[i].cost + dd[j].cost <= D) {
        maxd = max(maxd, dd[i].beau + dd[j].beau);
      } else {
        break;
      }
    }
  }
  int ma = 0, mb = 0;
  int p = 0;
  while (p < Cn && cc[p].cost <= C) {
    ma = max(ma, cc[p].beau);
    p++;
  }
  p = 0;
  while (p < Dn && dd[p].cost <= D) {
    mb = max(mb, dd[p].beau);
    p++;
  }
  if (!ma || !mb)
    maxcd = 0;
  else
    maxcd = ma + mb;
  printf("%d\n", max(maxc, max(maxd, maxcd)));
  return 0;
}
