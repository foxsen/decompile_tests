#include <bits/stdc++.h>
using namespace std;
int n, m;
int h[500], hh[500], newh[500];
vector<pair<int, int> > ans;
int cnt = 20000;
int main() {
  scanf("%d%d", &n, &m);
  memset(h, -1, sizeof(h));
  for (int i = 0, x, y; i < m; i++) {
    scanf("%d", &y);
    for (; y--;) scanf("%d", &x), h[x - 1] = cnt--;
  }
  memcpy(hh, h, sizeof(hh));
  sort(hh, hh + n);
  reverse(hh, hh + n);
  for (int i = 0; i < n; i++) {
    if (h[i] == hh[i]) continue;
    int p1, p2;
    for (int j = i + 1; j < n; j++)
      if (h[j] == hh[i]) {
        p1 = j;
        break;
      }
    for (int j = i; j < n; j++)
      if (h[j] == -1) {
        p2 = j;
        break;
      }
    if (p2 == i) {
      ans.push_back(make_pair(p1, i));
      swap(h[p1], h[i]);
    } else {
      ans.push_back(make_pair(i, p2));
      ans.push_back(make_pair(p1, i));
      h[p2] = h[i];
      h[i] = h[p1];
      h[p1] = -1;
    }
  }
  assert(((int)ans.size()) <= n + n);
  printf("%d\n", ((int)ans.size()));
  for (int i = 0; i < ((int)ans.size()); i++)
    printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
  return 0;
}
