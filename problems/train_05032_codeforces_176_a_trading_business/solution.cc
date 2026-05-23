#include <bits/stdc++.h>
int x4[4] = {0, 0, -1, 1};
int y4[4] = {-1, 1, 0, 0};
int x8[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y8[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
using namespace std;
int n, m, k;
char dummy[15];
int a[15][105], b[15][105], c[15][105];
int ans = 0;
bool f(pair<int, int> x, pair<int, int> y) { return x.second > y.second; }
void coba(int from, int to) {
  int res = 0;
  int cur = 0;
  int cap = 0;
  pair<int, int> profit[105];
  for (int i = 0; i < m; i++) profit[i] = make_pair(i, b[to][i] - a[from][i]);
  sort(profit, profit + m, f);
  for (int i = 0; i < m; i++) {
    if (cap == k) break;
    if (profit[i].second <= 0) continue;
    cur = profit[i].first;
    if (cap + c[from][cur] <= k) {
      cap += c[from][cur];
      res += profit[i].second * c[from][cur];
    } else {
      res += profit[i].second * (k - cap);
      cap = k;
    }
  }
  ans = max(res, ans);
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    scanf("%s", dummy);
    for (int j = 0; j < m; j++) scanf("%d %d %d", &a[i][j], &b[i][j], &c[i][j]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      coba(i, j);
      coba(j, i);
    }
  }
  printf("%d\n", ans);
  return 0;
}
