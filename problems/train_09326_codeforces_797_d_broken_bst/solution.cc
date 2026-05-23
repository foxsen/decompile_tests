#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int v[N], lson[N], rson[N], used[N], l[N], r[N];
set<int> s;
void dfs(int x) {
  if (~lson[x]) {
    l[lson[x]] = l[x];
    r[lson[x]] = min(r[x], v[x]);
    dfs(lson[x]);
  }
  if (~rson[x]) {
    l[rson[x]] = max(l[x], v[x]);
    r[rson[x]] = r[x];
    dfs(rson[x]);
  }
}
int main() {
  int n, root, ans;
  scanf("%d", &n);
  memset(used, 0, sizeof(used));
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d", &v[i], &lson[i], &rson[i]);
    if (~lson[i]) used[lson[i]] = 1;
    if (~rson[i]) used[rson[i]] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      root = i;
      break;
    }
  }
  l[root] = 0;
  r[root] = 1e9;
  dfs(root);
  ans = 0;
  for (int i = 1; i <= n; i++) {
    if (v[i] >= l[i] && v[i] <= r[i]) s.insert(v[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (!s.count(v[i])) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
