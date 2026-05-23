#include <bits/stdc++.h>
using namespace std;
const int maxn = 112345;
const int inf = 0x3f3f3f3f;
int n, a[maxn], dist[maxn][8], d[8][8], c[8][1 << 8], mask[maxn];
char s[maxn];
inline void bfs(int col) {
  queue<int> que;
  dist[n + col + 1][col] = 0;
  que.push(n + col + 1);
  for (int i = 1; i <= n; ++i)
    if (col == a[i]) {
      dist[i][col] = 0;
      que.push(i);
    }
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    if (u <= n) {
      if (u > 1 && dist[u - 1][col] == inf) {
        dist[u - 1][col] = dist[u][col] + 1;
        que.push(u - 1);
        if (dist[n + a[u - 1] + 1][col] == inf) {
          dist[n + a[u - 1] + 1][col] = dist[u][col] + 1;
          que.push(n + a[u - 1] + 1);
        }
      }
      if (u < n && dist[u + 1][col] == inf) {
        dist[u + 1][col] = dist[u][col] + 1;
        que.push(u + 1);
        if (dist[n + a[u + 1] + 1][col] == inf) {
          dist[n + a[u + 1] + 1][col] = dist[u][col] + 1;
          que.push(n + a[u + 1] + 1);
        }
      }
    } else {
      for (int i = 1; i <= n; ++i)
        if (a[i] == u - n - 1 && dist[i][col] == inf) {
          dist[i][col] = dist[u][col] + 1;
          que.push(i);
        }
    }
  }
}
int main() {
  scanf("%d%s", &n, s + 1);
  for (int i = 1; i <= n; ++i) a[i] = s[i] - 'a';
  memset(dist, 0x3f, sizeof dist);
  for (int i = 0; i < 8; ++i) {
    bfs(i);
    for (int j = 0; j < 8; ++j) d[j][i] = dist[n + j + 1][i];
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < 8; ++j)
      if (d[a[i]][j] != dist[i][j]) mask[i] |= 1 << j;
  int mx = 0;
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = max(1, i - 15); j <= i; ++j) {
      int tmp = i - j;
      for (int k = 0; k < 8; ++k) tmp = min(tmp, dist[i][k] + dist[j][k] + 1);
      if (tmp > mx)
        mx = tmp, res = 1;
      else if (tmp == mx)
        ++res;
    }
    int j = i - 16;
    if (j >= 1) ++c[a[j]][mask[j]];
    for (int j = 0; j < 8; ++j)
      for (int k = 0; k < 256; ++k)
        if (c[j][k]) {
          int tmp = inf;
          for (int l = 0; l < 8; ++l)
            tmp = min(tmp, dist[i][l] + d[j][l] + (k >> l & 1) + 1);
          if (tmp > mx)
            mx = tmp, res = c[j][k];
          else if (tmp == mx)
            res += c[j][k];
        }
  }
  return 0 * printf("%d %I64d\n", mx, res);
}
