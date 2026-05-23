#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int n, m;
bool vis[300010];
vector<int> ans;
int main() {
  int t;
  cin >> t;
  while (t--) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i < 3 * n + 1; i++) {
      vis[i] = false;
    }
    ans.clear();
    bool findans = false;
    for (int j = 0; j < m; j++) {
      int u, v;
      scanf("%d %d", &u, &v);
      if (findans) continue;
      if (!vis[u] && !vis[v]) {
        ans.push_back(j + 1);
        vis[u] = true;
        vis[v] = true;
        if (ans.size() == n) {
          findans = true;
          printf("Matching\n");
          for (auto item : ans) {
            printf("%d ", item);
          }
          printf("\n");
        }
      }
    }
    if (!findans) {
      printf("IndSet\n");
      int cnt = 0;
      for (int i = 1; i < 3 * n + 1; i++) {
        if (vis[i] == false) {
          printf("%d ", i);
          cnt++;
          if (cnt == n) break;
        }
      }
      printf("\n");
    }
  }
  return 0;
}
