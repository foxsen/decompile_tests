#include <bits/stdc++.h>
using namespace std;
int n;
int a[100];
bool vis[100];
bool dfs(int v, int now, int u) {
  if (v == n) return true;
  if (a[v] - 1 == now) {
    if (u != 1)
      return dfs(v + 1, 0, 0);
    else
      return false;
  }
  int la = -1;
  for (int i = 0; i < n; i++)
    if (!vis[i] && a[v] >= a[i] + now && a[i] != la) {
      la = a[i];
      vis[i] = true;
      if (dfs(v, now + a[i], u + 1)) return true;
      vis[i] = false;
    }
  return false;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    vis[i] = false;
  }
  sort(a, a + n);
  if (a[n - 1] != n) {
    printf("NO\n");
    return 0;
  }
  if (dfs(0, 0, 0))
    printf("YES\n");
  else
    printf("NO");
  scanf("%d");
}
