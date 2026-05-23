#include <bits/stdc++.h>
using namespace std;
pair<int, int> p[4010];
int a[4010][4010];
int pre[4010], b[4010];
int main() {
  int i, j, k, m, n, res, ans;
  scanf("%d", &n);
  int cnt = 0;
  p[cnt++] = make_pair(0, 0);
  for (i = 1; i <= n; i++) scanf("%d", b + i), p[cnt++] = make_pair(b[i], i);
  sort(p, p + cnt);
  int rnt = 0;
  for (i = 1; i <= n; i++) {
    if (p[i].first == p[i - 1].first)
      pre[p[i].second] = p[i - 1].second;
    else
      pre[p[i].second] = 0;
  }
  for (i = 1; i < n; i++) {
    for (j = i + 1; j <= n; j++) {
      k = pre[j];
      if (k > i)
        a[i][j] = a[i][k];
      else if (k < i && k)
        a[i][j] = a[k][i] + 1;
      else if (k == 0)
        a[i][j] = 2;
      else if (k == i) {
        k = pre[i];
        if (k)
          a[i][j] = a[k][i] + 1;
        else
          a[i][j] = 2;
      }
    }
  }
  ans = 0;
  for (i = 1; i < n; i++)
    for (j = i + 1; j <= n; j++) ans = max(ans, a[i][j]);
  if (ans == 0) ans = 1;
  printf("%d\n", ans);
  return 0;
}
