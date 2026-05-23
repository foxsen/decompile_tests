#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int maxn = 100005;
int r[305][305];
int ans[305];
int main() {
  int n;
  scanf("%d", &n);
  int d;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &d);
      r[i][d] = j;
    }
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &d);
    r[0][d] = i;
  }
  int tmp1 = 0, tmp2 = 0;
  for (int i = 0; i <= n; i++) r[i][0] = n + 1;
  for (int i = 1; i <= n; i++) {
    if (r[0][tmp1] > r[0][i])
      tmp2 = tmp1, tmp1 = i;
    else if (r[0][tmp2] > r[0][i])
      tmp2 = i;
    for (int j = 1; j <= n; j++) {
      if (tmp1 != j) {
        if (r[j][ans[j]] > r[j][tmp1]) ans[j] = tmp1;
      } else if (tmp2) {
        if (r[j][ans[j]] > r[j][tmp2]) ans[j] = tmp2;
      }
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  puts("");
  return 0;
}
