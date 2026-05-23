#include <bits/stdc++.h>
using namespace std;
struct edges {
  int w;
  int p;
  int idx;
  edges(int _w, int _p, int _idx) {
    w = _w;
    p = _p;
    idx = _idx;
  }
};
bool cmp(edges a, edges b) {
  if (a.w == b.w) return a.p > b.p;
  return a.w < b.w;
}
vector<edges> rec;
pair<int, int> ans[100055];
int vis[100055];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    rec.push_back(edges(x, y, i));
  }
  sort(rec.begin(), rec.end(), cmp);
  bool flag = true;
  memset(vis, 0, sizeof(vis));
  int to = 3, from = 2, inc = 2;
  for (int i = 0; i < m; i++) {
    if (rec[i].p == 1) {
      ans[rec[i].idx] = make_pair(1, inc);
      vis[1] = vis[inc] = 1;
      inc++;
    } else {
      ans[rec[i].idx] = make_pair(from, to);
      if ((vis[to] == 0) || (vis[from] == 0)) flag = false;
      from++;
      if (from == to) {
        to++;
        from = 2;
      }
    }
  }
  if (!flag) {
    printf("-1\n");
    return 0;
  }
  for (int i = 0; i < m; i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
