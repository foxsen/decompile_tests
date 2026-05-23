#include <bits/stdc++.h>
using namespace std;
int n;
char m[5005][5005], vis[5005];
bool bfs(int u, int pre) {
  vis[u] = 1;
  for (int i = 1; i <= n; i++)
    if (m[u][i] == '1') {
      if (m[i][pre] - '0') {
        printf("%d %d %d\n", pre, u, i);
        return 1;
      }
      if (!vis[i] && bfs(i, u)) return 1;
    }
  return 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%s", m[i] + 1);
  for (int i = 1; i <= n; i++)
    if (!vis[i] && bfs(i, i)) return 0;
  puts("-1");
  return 0;
}
