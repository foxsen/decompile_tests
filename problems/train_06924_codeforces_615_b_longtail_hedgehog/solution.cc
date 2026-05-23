#include <bits/stdc++.h>
using namespace std;
vector<int> G[100001];
long long L[100001];
long long ans = 0;
int dfs(int a) {
  if (L[a] != 0) return L[a];
  int resp = 0;
  for (int x : G[a]) {
    if (a > x) {
      resp = max(dfs(x), resp);
    }
  }
  return L[a] = resp + 1;
}
int main() {
  int n, m, aux, t, a, b;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, (long long)dfs(i) * (long long)G[i].size());
  }
  cout << ans << endl;
  return 0;
}
