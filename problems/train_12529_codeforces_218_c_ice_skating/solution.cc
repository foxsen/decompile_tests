#include <bits/stdc++.h>
using namespace std;
vector<int> a[110];
int x[110], y[110];
bool mark[110];
void dfs(int x) {
  mark[x] = true;
  for (int i = 0; i < a[x].size(); i++)
    if (mark[a[x][i]] == false) dfs(a[x][i]);
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (x[i] == x[j] || y[i] == y[j]) a[i].push_back(j);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (mark[i] == false) {
      ans++;
      dfs(i);
    }
  }
  cout << ans - 1 << endl;
  return 0;
}
