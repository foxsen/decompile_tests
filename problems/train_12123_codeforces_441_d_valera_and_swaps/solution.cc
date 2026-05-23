#include <bits/stdc++.h>
using namespace std;
int n;
int a[3050], p[3050], s[3050], ps[3050], vis[3050];
int m;
void dfs(int i) {
  if (vis[i]) return;
  vis[i] = 1;
  dfs(a[i]);
  return;
}
int main() {
  int i, j, k;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    s[a[i]] = i;
  }
  memcpy(p, a, sizeof(a));
  memcpy(ps, s, sizeof(s));
  int cnt = 0;
  for (i = 1; i <= n; i++) {
    if (p[i] != i) {
      int temp = p[i];
      swap(p[i], p[ps[i]]);
      swap(ps[i], ps[temp]);
      cnt++;
    }
  }
  scanf("%d", &m);
  if (cnt == m)
    printf("0\n");
  else if (cnt < m) {
    printf("%d\n", m - cnt);
    for (i = 1; i <= m - cnt; i++) {
      memset(vis, 0, sizeof(vis));
      dfs(1);
      for (j = 1; j <= n; j++) {
        if (!vis[j]) {
          printf("1 %d ", j);
          swap(a[1], a[j]);
          break;
        }
      }
    }
    printf("\n");
  } else {
    printf("%d\n", cnt - m);
    while (1) {
      for (i = 1; i <= n; i++)
        if (a[i] != i) break;
      for (j = a[i], k = n; j != i; j = a[j]) k = min(k, j);
      printf("%d %d ", i, k);
      swap(a[i], a[k]);
      cnt--;
      if (cnt == m) break;
    }
    printf("\n");
  }
  return 0;
}
