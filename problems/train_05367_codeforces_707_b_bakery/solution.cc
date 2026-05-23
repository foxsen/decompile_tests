#include <bits/stdc++.h>
using namespace std;
int oo = 1 << 30;
const int MaxN = 1e5;
int ok[MaxN + 5];
int n, m, k, x;
struct zz {
  int u, v, l;
} s[MaxN + 5];
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= m; i++) scanf("%d %d %d", &s[i].u, &s[i].v, &s[i].l);
  for (int i = 1; i <= k; i++) {
    scanf(" %d", &x);
    ok[x] = 1;
  }
  int min = oo;
  for (int i = 1; i <= m; i++) {
    if (ok[s[i].u] && ok[s[i].v]) continue;
    if (!ok[s[i].u] && !ok[s[i].v]) continue;
    if (min > s[i].l) min = s[i].l;
  }
  if (min != oo)
    printf("%d\n", min);
  else
    printf("-1\n");
}
