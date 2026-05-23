#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:268435456")
using namespace std;
int a[100001][2], b[100001][3], pairi = 1, ans[100001], cc;
pair<int, int> pairs[200001];
set<pair<int, int> > set1;
int main() {
  int n, m;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &a[i][0], &a[i][1]);
    pairs[pairi++] = pair<int, int>(a[i][0], i);
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d", &b[i][0], &b[i][1], &b[i][2]);
    pairs[pairi++] = pair<int, int>(b[i][0], -i);
  }
  sort(pairs + 1, pairs + 1 + n + m);
  for (int i = 1; i <= n + m; i++)
    if (pairs[i].second < 0)
      set1.insert(pair<int, int>(b[-pairs[i].second][1], -pairs[i].second));
    else {
      set<pair<int, int> >::iterator it =
          set1.lower_bound(pair<int, int>(a[pairs[i].second][1], -1));
      if (it == set1.end()) {
        printf("NO\n");
        cc = 1;
        break;
      } else {
        ans[pairs[i].second] = it->second;
        --b[it->second][2];
        if (b[it->second][2] == 0) set1.erase(it);
      }
    }
  if (!cc) {
    printf("YES\n");
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  }
  return 0;
}
