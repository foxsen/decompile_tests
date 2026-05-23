#include <bits/stdc++.h>
using namespace std;
struct edge {
  int nxt, t, id;
} e[10010 << 1];
int head[10010], edge_cnt;
void add_edge(int x, int y, int z) {
  e[edge_cnt] = (edge){head[x], y, z};
  head[x] = edge_cnt++;
}
int Cnt, Rec, dep[10010], sum[10010], ID[10010];
vector<int> Ans;
bool vis[10010];
void dfs(int x, int f) {
  vis[x] = 1;
  int i;
  for (i = head[x]; ~i; i = e[i].nxt) {
    int to = e[i].t;
    if (vis[to]) {
      if (to != f && dep[to] < dep[x]) {
        if (((dep[x] - dep[to] + 1) & 1) == 1) {
          sum[x]++;
          sum[to]--;
          Cnt++;
          Rec = e[i].id;
        } else {
          sum[x]--;
          sum[to]++;
        }
      }
    } else {
      ID[to] = e[i].id;
      dep[to] = dep[x] + 1;
      dfs(to, x);
      sum[x] += sum[to];
    }
  }
}
int main() {
  int n, m, i;
  scanf("%d%d", &n, &m);
  memset(head, -1, sizeof(head));
  for (i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add_edge(x, y, i);
    add_edge(y, x, i);
  }
  for (i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i, 0);
    }
  }
  if (Cnt == 0) {
    printf("%d\n", m);
    for (i = 1; i <= m; i++) {
      printf("%d%c", i, " \n"[i == m]);
    }
  } else {
    if (Cnt == 1) {
      Ans.push_back(Rec);
    }
    for (i = 1; i <= n; i++) {
      if (sum[i] == Cnt) {
        Ans.push_back(ID[i]);
      }
    }
    sort(Ans.begin(), Ans.end());
    int t = Ans.size();
    printf("%d\n", t);
    for (i = 0; i < t; i++) {
      printf("%d%c", Ans[i], " \n"[i == t - 1]);
    }
  }
  return 0;
}
