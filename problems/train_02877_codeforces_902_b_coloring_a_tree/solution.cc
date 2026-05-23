#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
int n, c[N + 10], ans;
vector<int> g[N + 10];
void dfs(int x, int C) {
  int flag = C;
  if (C != c[x]) {
    ans++;
    flag = c[x];
  }
  for (int i = 0; i < (int)g[x].size(); i++) {
    int y = g[x][i];
    dfs(y, flag);
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int fa;
    cin >> fa;
    g[fa].push_back(i);
  }
  for (int i = 1; i <= n; i++) cin >> c[i];
  dfs(1, 0);
  cout << ans << endl;
  return 0;
}
