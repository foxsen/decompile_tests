#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
const long long mod = 998244353;
vector<int> vec[N];
vector<int> ans;
int vis[N];
int main() {
  int t, n, m;
  cin >> t;
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      vec[i].clear();
      vis[i] = 0;
    }
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      vec[v].push_back(u);
    }
    ans.clear();
    for (int i = 1; i <= n; i++) {
      int f = 1;
      for (int j : vec[i]) {
        if (!vis[j]) {
          for (int k : vec[j]) {
            if (!vis[k]) {
              vis[i] = 1;
              ans.push_back(i);
              f = 0;
              break;
            }
          }
        }
        if (!f) break;
      }
    }
    printf("%d\n", ans.size());
    for (int i : ans) {
      printf("%d ", i);
    }
    puts("");
  }
  return 0;
}
