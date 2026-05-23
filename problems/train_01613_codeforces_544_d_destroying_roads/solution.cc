#include <bits/stdc++.h>
using namespace std;
int n, m;
bool inq[3010];
int dis[3010][3010];
vector<int> G[3010];
void SPFA(int s) {
  memset(inq, 0, sizeof inq);
  queue<int> que;
  dis[s][s] = 0;
  inq[s] = true;
  que.push(s);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    inq[u] = false;
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      if (dis[s][v] > dis[s][u] + 1) {
        dis[s][v] = dis[s][u] + 1;
        if (!inq[v]) {
          inq[v] = true;
          que.push(v);
        }
      }
    }
  }
}
int s1, t1, s2, t2;
int l1, l2;
int main() {
  memset(dis, 0x3f, sizeof dis);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) SPFA(i);
  scanf("%d%d%d", &s1, &t1, &l1);
  scanf("%d%d%d", &s2, &t2, &l2);
  if (dis[s1][t1] > l1 || dis[s2][t2] > l2) {
    puts("-1");
    return 0;
  }
  int ans = dis[s1][t1] + dis[s2][t2];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      if (dis[s1][i] + dis[i][j] + dis[j][t1] <= l1 &&
          dis[s2][i] + dis[i][j] + dis[j][t2] <= l2)
        ans = min(
            ans, dis[s1][i] + dis[s2][i] + dis[i][j] + dis[j][t1] + dis[j][t2]);
      if (dis[s1][i] + dis[i][j] + dis[j][t1] <= l1 &&
          dis[s2][j] + dis[j][i] + dis[i][t2] <= l2)
        ans = min(
            ans, dis[s1][i] + dis[i][j] + dis[j][t1] + dis[s2][j] + dis[i][t2]);
    }
  printf("%d\n", m - ans);
  return 0;
}
