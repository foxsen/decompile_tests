#include <bits/stdc++.h>
using namespace std;
int n, m, d[int(1e5 + 5)], a[int(1e5 + 5)];
bool ok(int days) {
  vector<int> when(m + 1, 0x3f3f3f3f3f3f3f3fLL);
  for (int i = 1, __R = days; i <= __R; i++)
    if (d[i]) when[d[i]] = i;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      Q;
  for (int i = 1, __R = m; i <= __R; i++) {
    if (when[i] == int(0x3f3f3f3f3f3f3f3fLL)) return false;
    Q.emplace(when[i], i);
  }
  int last = 0, fdays = 0;
  while (!Q.empty()) {
    int w = Q.top().first, i = Q.top().second;
    Q.pop();
    fdays += (w - last - 1) - a[i];
    if (fdays < 0) return false;
    last = w;
  }
  return true;
}
int find(int l, int r) {
  if (r < l) return -1;
  int m = (l + r) >> 1;
  if (!ok(m)) return find(m + 1, r);
  int tmp = find(l, m - 1);
  return tmp < 0 ? m : tmp;
}
int main() {
  std::ios::sync_with_stdio(false);
  scanf("%d%d", &(n), &(m));
  for (int i = 1, __R = n; i <= __R; i++) scanf("%d", &(d[i]));
  for (int i = 1, __R = m; i <= __R; i++) scanf("%d", &(a[i]));
  printf("%d\n", find(0, n));
  return 0;
}
