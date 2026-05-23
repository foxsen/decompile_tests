#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 18) + 10;
int n, m, a[N], b[20], sz, vis[N], q[20];
void ins(int x) {
  int y = x;
  for (int i = 18; ~i; i--)
    if (x >> i & 1)
      if (!b[i]) {
        b[i] = x, q[++sz] = y;
        return;
      } else
        x ^= b[i];
}
void dfs(int now, int k) {
  printf("%d ", now);
  vis[now] = 1;
  if (k == (1 << m) - 1) exit(0);
  for (int i = (1); i <= (sz); i++)
    if (!vis[q[i] ^ now]) dfs(now ^ q[i], k + 1);
  vis[now] = 0;
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  int j = 1;
  for (int i = (0); i <= (18); i++) {
    for (; j <= n && a[j] < (1 << i); j++) ins(a[j]);
    if (sz == i) m = i;
  }
  memset(b, 0, sizeof(b)), sz = 0;
  for (int i = (1); i <= (n); i++)
    if (a[i] < (1 << m)) ins(a[i]);
  printf("%d\n", m);
  dfs(0, 0);
  return 0;
}
