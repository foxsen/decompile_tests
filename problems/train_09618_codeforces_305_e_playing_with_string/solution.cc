#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
char s[maxn];
bool g[maxn];
int sg[maxn];
int ans;
int dfs2(int x) {
  if (x <= 0) return 0;
  if (x == 1) return 1;
  if (sg[x] != -1) return sg[x];
  int i, temp;
  bool judge[101];
  memset(judge, false, sizeof(judge));
  for (i = 1; i <= x; i++) {
    temp = dfs2(i - 2) ^ dfs2(x - i - 1);
    judge[temp] = 1;
  }
  for (i = 0;; i++)
    if (!judge[i]) return sg[x] = i;
}
int dfs(int n) {
  if (n <= 0) return 0;
  if (n == 1) return 1;
  if (~sg[n]) return sg[n];
  bool vis[105];
  memset(vis, 0, sizeof(vis));
  int i;
  for (i = 1; i <= n; i++) vis[dfs(i - 2) ^ dfs(n - i - 1)] = 1;
  for (i = 0;; i++)
    if (!vis[i]) {
      return sg[n] = i;
    }
}
int main() {
  memset(sg, -1, sizeof(sg));
  scanf("%s", s);
  int len = strlen(s), i, j;
  for (i = 1; i < len - 1; i++)
    if (s[i - 1] == s[i + 1]) g[i] = 1;
  for (i = 0; i < len; i++)
    if (g[i]) {
      j = i;
      int c = 0;
      while (g[j]) j++, c++;
      i = j - 1;
      ans ^= dfs(c);
    }
  if (ans) {
    puts("First");
    for (int k = 1; k < len - 1; k++)
      if (g[k]) {
        int x = g[k - 1], y = g[k + 1];
        g[k - 1] = g[k] = g[k + 1] = 0;
        ans = 0;
        for (i = 0; i < len; i++)
          if (g[i]) {
            j = i;
            int c = 0;
            while (g[j]) j++, c++;
            i = j - 1;
            ans ^= dfs(c);
          }
        if (!ans) {
          printf("%d\n", k + 1);
          return 0;
        }
        g[k] = 1;
        g[k - 1] = x;
        g[k + 1] = y;
      }
  } else
    puts("Second");
  return 0;
}
