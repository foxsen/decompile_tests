#include <bits/stdc++.h>
using namespace std;
int a[100010], vis[100010];
int main() {
  memset(a, 0, sizeof(a));
  memset(vis, 0, sizeof(vis));
  int n = 0;
  map<int, int> nMap;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    nMap[a[i]] = i;
  }
  sort(a + 1, a + n + 1);
  map<int, vector<int>> res;
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      vis[i] = 1;
      ++cnt;
      res[cnt].push_back(i);
      for (int x = nMap[a[i]]; x != i; x = nMap[a[x]]) {
        vis[x] = 1;
        res[cnt].push_back(x);
      }
    }
  }
  printf("%d\n", cnt);
  for (auto re : res) {
    printf("%d ", re.second.size());
    for (auto mem : re.second) {
      printf("%d ", mem);
    }
    printf("\n");
  }
  return 0;
}
