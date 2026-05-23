#include <bits/stdc++.h>
using namespace std;
long long int INF = 1e9 + 5;
long long int mod = 998244353;
int main() {
  long long int m, n, i, j;
  cin >> n >> m;
  vector<long long int> days(m + 1, 0), ans(n + 1, 0);
  vector<set<pair<long long int, long long int>>> tasks(n + 1);
  long long int x, y, c;
  for (i = 1; i <= m; i++) {
    cin >> x >> y >> c;
    ans[y] = m + 1;
    days[i] = c;
    for (j = x; j < y; j++) {
      tasks[j].insert({y, i});
    }
  }
  for (i = 1; i <= n; i++) {
    if (ans[i] == 0 && tasks[i].size()) {
      auto it = tasks[i].begin();
      while (it != tasks[i].end() && !(days[it->second])) it++;
      if (it != tasks[i].end()) {
        days[it->second]--;
        ans[i] = it->second;
      }
    }
  }
  for (i = 1; i <= m; i++) {
    if (days[i]) {
      cout << -1;
      return 0;
    }
  }
  for (i = 1; i <= n; i++) cout << ans[i] << " ";
}
