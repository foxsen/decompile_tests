#include <bits/stdc++.h>
using namespace std;
const int maxm = 100004;
int n, m, mx[maxm];
pair<int, int> a[maxm], b[maxm], p[maxm];
int an, bn;
int Find1(int x, int y) {
  int l(1), r(an), mid;
  while (l < r) {
    mid = (l + r) >> 1;
    if (a[mid].second >= x)
      r = mid;
    else
      l = mid + 1;
  }
  if (x > a[l].second || y < a[l].first) return 0;
  return l;
}
int Find2(int x, int y) {
  int l(1), r(an), mid;
  while (l < r) {
    mid = (l + r) >> 1;
    if (a[mid + 1].first <= y)
      l = mid + 1;
    else
      r = mid;
  }
  if (x > a[l].second || y < a[l].first) return 0;
  return l;
}
int main() {
  int i, j, k, t, ii, jj, kk, tt;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) scanf("%d%d", &p[i].first, &p[i].second);
  sort(p + 1, p + m + 1);
  a[an = 1] = pair<int, int>(1, 1);
  int x(0);
  for (i = 1; i <= m;) {
    if (p[i].first > x + 1) a[an = 1] = pair<int, int>(a[1].first, n);
    for (j = i; p[j].first == p[i].first; i++)
      ;
    x = p[j].first;
    bn = 0;
    for (t = 0, k = j; k < i; t = p[k++].second)
      if (t + 1 <= p[k].second - 1)
        b[++bn] = pair<int, int>(t + 1, p[k].second - 1);
    if (t + 1 <= n) b[++bn] = pair<int, int>(t + 1, n);
    if (!bn) {
      puts("-1");
      return 0;
    }
    for (k = 1; k <= bn; k++) {
      ii = Find1(b[k].first, b[k].second);
      jj = Find2(b[k].first, b[k].second);
      mx[k] = int(~0U >> 1);
      if (ii) mx[k] = min(mx[k], max(a[ii].first, b[k].first));
      if (jj) mx[k] = min(mx[k], max(a[jj].first, b[k].first));
    }
    an = 0;
    for (k = 1; k <= bn; k++)
      if (mx[k] < int(~0U >> 1)) a[++an] = pair<int, int>(mx[k], b[k].second);
    if (!an) {
      puts("-1");
      return 0;
    }
  }
  if (x < n) a[an = 1] = pair<int, int>(a[1].first, n);
  if (!an || a[an].second < n) {
    puts("-1");
    return 0;
  }
  printf("%d\n", 2 * (n - 1));
  return 0;
}
