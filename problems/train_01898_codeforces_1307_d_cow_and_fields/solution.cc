#include <bits/stdc++.h>
using namespace std;
int dis_s[200005], dis_t[200005];
struct Point {
  int id;
} b[200005];
int a[200005];
vector<int> E[200005];
void bfs(int S, int dis[]) {
  for (int i = 1; i <= 200005; i++) dis[i] = 200005 + 1;
  queue<int> Q;
  Q.push(S);
  dis[S] = 0;
  while (!Q.empty()) {
    int now = Q.front();
    Q.pop();
    for (auto& v : E[now]) {
      if (dis[v] > dis[now] + 1) {
        dis[v] = dis[now] + 1;
        Q.push(v);
      }
    }
  }
}
int num[200005];
bool cmp(Point A, Point B) {
  return dis_t[A.id] - dis_s[A.id] < dis_t[B.id] - dis_s[B.id];
}
int mxt[200005], mxs[200005];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    E[x].push_back(y);
    E[y].push_back(x);
  }
  bfs(1, dis_s);
  bfs(n, dis_t);
  int ans = 0;
  for (int i = 1; i <= k; i++) b[i].id = a[i];
  sort(b + 1, b + k + 1, cmp);
  mxs[k + 1] = 0, mxt[0] = 0;
  for (int i = k; i >= 1; i--) mxs[i] = max(mxs[i + 1], dis_s[b[i].id]);
  for (int i = 1; i <= k; i++) mxt[i] = max(mxt[i - 1], dis_t[b[i].id]);
  for (int i = 1; i <= k; i++) {
    int tmp = 0;
    if (i > 1) {
      tmp = max(tmp, dis_s[b[i].id] + mxt[i - 1] + 1);
    }
    if (i < k) {
      tmp = max(tmp, dis_t[b[i].id] + mxs[i + 1] + 1);
    }
    ans = max(ans, tmp);
  }
  ans = min(ans, dis_s[n]);
  printf("%d\n", ans);
  return 0;
}
