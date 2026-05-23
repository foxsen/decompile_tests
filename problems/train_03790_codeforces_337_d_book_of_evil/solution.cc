#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 3;
int n, m, d, p[N], mx[N][2], us[N];
vector<vector<int> > v;
void up(int ind, int ch) {
  if (mx[ind][0] <= ch) {
    mx[ind][1] = mx[ind][0];
    mx[ind][0] = ch;
  } else if (mx[ind][1] < ch) {
    mx[ind][1] = ch;
  }
}
void dfs(int x) {
  us[x] = 1;
  for (auto u : v[x]) {
    if (!us[u]) {
      dfs(u);
      up(x, mx[u][0] + 1);
    }
  }
  if (p[x]) up(x, 0);
}
int ans = 0;
void dfs1(int x, int way) {
  us[x] = 1;
  if (way <= d && mx[x][0] <= d) ans++;
  for (auto u : v[x]) {
    if (!us[u])
      if (mx[u][0] + 1 == mx[x][0])
        dfs1(u, max(way, mx[x][1]) + 1);
      else
        dfs1(u, max(way, mx[x][0]) + 1);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> d;
  v.resize(n);
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    --x;
    p[x] = 1;
  }
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (int i = 0; i < n; i++) mx[i][0] = mx[i][1] = -(int)2e9;
  dfs(0);
  fill(us, us + n, 0);
  int huihuihhuiuuuuuuuuuuuihuiui = -(int)2e9;
  dfs1(0, huihuihhuiuuuuuuuuuuuihuiui);
  cout << ans;
}
