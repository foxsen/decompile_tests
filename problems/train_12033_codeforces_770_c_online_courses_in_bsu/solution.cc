#include <bits/stdc++.h>
const int N = 1e5 + 7;
using namespace std;
vector<int> ans, a[N];
int us[N], need[N];
int x, i, j, k, n, m;
void dfs(int x) {
  us[x] = 1;
  for (int i = 0; i < a[x].size(); ++i)
    if (us[a[x][i]] == 1) {
      cout << -1;
      exit(0);
    } else if (us[a[x][i]] == 2)
      continue;
    else
      dfs(a[x][i]);
  us[x] = 2;
  ans.push_back(x);
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < k; ++i) cin >> need[i], need[i]--;
  for (int i = 0; i < n; ++i) {
    cin >> m;
    for (int j = 0; j < m; ++j) cin >> x, a[i].push_back(x - 1);
  }
  for (int i = 0; i < k; ++i)
    if (!us[need[i]]) dfs(need[i]);
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); ++i) cout << ans[i] + 1 << ' ';
}
