#include <bits/stdc++.h>
using namespace std;
int dis[105], n, d;
int cost[105][105];
int input[105];
int x[105], y[105];
int judge[105];
int abss(int x) {
  if (x < 0)
    return -x;
  else
    return x;
}
void solve() {
  fill(dis, dis + n + 1, 100000000);
  memset(judge, 0, sizeof(judge));
  int x;
  dis[1] = 0;
  while (true) {
    x = -1;
    for (int i = 1; i <= n; i++) {
      if (judge[i] == 0 && (x == -1 || dis[i] < dis[x])) x = i;
    }
    if (x == -1) break;
    judge[x] = 1;
    for (int i = 1; i <= n; i++) {
      dis[i] = min(dis[i], dis[x] + cost[x][i]);
    }
  }
  return;
}
int main() {
  while (scanf("%d%d", &n, &d) != EOF) {
    memset(input, 0, sizeof(input));
    memset(cost, 0, sizeof(cost));
    for (int i = 2; i <= n - 1; i++) scanf("%d", &input[i]);
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &x[i], &y[i]);
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == j) continue;
        cost[i][j] = d * (abss(x[i] - x[j]) + abss(y[i] - y[j])) - input[j];
      }
    }
    solve();
    printf("%d\n", dis[n]);
  }
  return 0;
}
