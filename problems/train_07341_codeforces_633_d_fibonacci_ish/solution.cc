#include <bits/stdc++.h>
using namespace std;
int a[1003], ans[1003];
queue<int> q;
map<int, int> m;
int main() {
  int n, ans = 0, x, y;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), ++m[a[i]];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      if (a[i] == a[j] && a[i] == 0) {
        ans = max(ans, m[0]);
        continue;
      }
      int k = 0;
      x = a[i], y = a[j], --m[a[i]], --m[a[j]], q.push(a[i]), q.push(a[j]);
      while (m[x + y]) --m[x + y], q.push(x + y), y = x + y, x = y - x, ++k;
      ans = max(ans, k + 2);
      while (!q.empty()) ++m[q.front()], q.pop();
    }
  printf("%d", ans);
  return 0;
}
