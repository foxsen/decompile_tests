#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
int a[N], n, d, dep[N], y, mx;
vector<int> vec[N];
void dfs(int x, int pa) {
  if (pa == -1)
    dep[x] = 0;
  else {
    if (a[x] == a[pa])
      dep[x] = dep[pa];
    else
      dep[x] = dep[pa] + 1;
  }
  if (dep[x] > mx) {
    mx = dep[x];
    y = x;
  }
  for (int y : vec[x]) {
    if (y == pa) continue;
    dfs(y, x);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--, y--;
    vec[x].push_back(y);
    vec[y].push_back(x);
  }
  mx = -1;
  dfs(0, -1);
  dfs(y, -1);
  printf("%d\n", (mx + 1) / 2);
  return 0;
}
