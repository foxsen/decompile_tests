#include <bits/stdc++.h>
using namespace std;
int color[200010], Max[200010];
pair<int, int> p[200010];
int main() {
  int n, q;
  memset(color, -1, sizeof(color));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    p[i] = make_pair(1, a);
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int opt, x, y;
    scanf("%d", &opt);
    if (opt == 1) {
      scanf("%d%d", &x, &y);
      p[x] = make_pair(i, y);
    } else {
      scanf("%d", &x);
      color[i] = x;
    }
  }
  Max[q + 1] = -1;
  for (int i = q; i > 0; i--) {
    Max[i] = max(Max[i + 1], color[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (i > 1) printf(" ");
    printf("%d", max(p[i].second, Max[p[i].first]));
  }
  return 0;
}
