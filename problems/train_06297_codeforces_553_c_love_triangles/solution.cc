#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<pair<int, int> > adj[N];
int ass[N];
int ans = 500000004;
void dfs(int s, int as) {
  if (ass[s]) {
    if (ass[s] != as) ans = 0;
    return;
  }
  ass[s] = as;
  for (auto it : adj[s]) {
    if (it.second == 1)
      dfs(it.first, as);
    else
      dfs(it.first, 3 - as);
  }
}
int main() {
  int n, m, i, a, b, c;
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    cin >> a >> b >> c;
    adj[a - 1].push_back({b - 1, c});
    adj[b - 1].push_back({a - 1, c});
  }
  for (i = 0; i < n; i++)
    if (!ass[i]) dfs(i, 1), ans = ans * 2 % 1000000007;
  cout << ans;
}
