#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
vector<int> G[N];
int alice[N], bob[N];
void dfs(int x, int fa, int *d) {
  d[x] = d[fa] + 1;
  for (int i = 0; i < (int)G[x].size(); ++i) {
    if (G[x][i] != fa) {
      dfs(G[x][i], x, d);
    }
  }
}
int main() {
  int n, x;
  cin >> n >> x;
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  alice[0] = bob[0] = -1;
  dfs(1, 0, alice);
  dfs(x, 0, bob);
  int ans = 2;
  for (int i = 1; i <= n; ++i) {
    if (alice[i] > bob[i]) {
      ans = max(ans, alice[i] * 2);
    }
  }
  cout << ans;
  return 0;
}
