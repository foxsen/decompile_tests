#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int n;
struct node {
  int v, w;
  node() {}
  node(int _v, int _w) : v(_v), w(_w) {}
};
vector<node> ve[110];
int ans;
bool flag;
void dfs(int fa, int u) {
  if (u == 1 && fa != -1) flag = true;
  if (flag) return;
  for (int i = 0; i < ve[u].size(); i++) {
    if (flag) return;
    int v = ve[u][i].v;
    int w = ve[u][i].w;
    if (v == fa) continue;
    if (w < 0) ans += (-w);
    dfs(u, v);
  }
}
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < 110; i++) ve[i].clear();
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int t1, t2, t3;
      scanf("%d%d%d", &t1, &t2, &t3);
      sum += t3;
      ve[t1].push_back(node(t2, t3));
      ve[t2].push_back(node(t1, -t3));
    }
    ans = 0;
    flag = false;
    dfs(-1, 1);
    printf("%d\n", min(ans, sum - ans));
  }
  return 0;
}
