#include <bits/stdc++.h>
using namespace std;
int read() {
  char c = getchar();
  int x = 0;
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + (c - '0'), c = getchar();
  return x;
}
void MOD(int &x) {
  if (x >= 998244353) x -= 998244353;
}
int m;
int l, nxt[1000010], head[1000010], to[1000010];
void add(int x, int y) {
  l++;
  nxt[l] = head[x];
  head[x] = l;
  to[l] = y;
}
int low[1000010], f[1000010], d[1000010];
void dfs(int x) {
  low[x] = (1 << 30);
  bool fl = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    int c = to[i];
    d[c] = d[x] + 1;
    dfs(c);
    if (low[c] - d[x] <= m) {
      f[x] += f[c];
      f[c] = 0;
    }
    low[x] = min(low[x], low[c]);
    fl = 0;
  }
  if (fl) low[x] = d[x], f[x] = 1;
}
int getans(int x) {
  int ans = 0;
  for (int i = head[x]; i; i = nxt[i]) {
    int c = to[i];
    ans = max(ans, getans(c));
  }
  return ans + f[x];
}
int main() {
  int n;
  n = read();
  m = read();
  for (int i = 2; i <= n; i++) add(read(), i);
  dfs(1);
  printf("%d\n", getans(1));
}
