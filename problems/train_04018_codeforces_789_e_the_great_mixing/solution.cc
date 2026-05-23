#include <bits/stdc++.h>
using namespace std;
const int C = 1e6, INF = 1e9;
int n, m, mk[2 * C + 5], d[2 * C + 5];
vector<int> a;
queue<int> q;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x;
    scanf("%d", &x);
    x -= n;
    if (mk[x + C] == 0) {
      mk[x + C] = 1;
      a.push_back(x);
    }
  }
  memset(d, -1, sizeof(d));
  q.push(0);
  d[C] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int o : a) {
      int v = u + o;
      if (v < -2000 || v > 2000) continue;
      if (d[v + C] == -1) {
        d[v + C] = d[u + C] + 1;
        q.push(v);
      }
    }
  }
  int sol = INF;
  for (int o : a) {
    if (d[-o + C] == -1) continue;
    sol = min(sol, d[-o + C]);
  }
  if (sol == INF) sol = -1;
  printf("%d\n", sol);
  return 0;
}
