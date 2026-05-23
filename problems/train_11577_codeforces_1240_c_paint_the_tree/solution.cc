#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long n, top, k, a[N], f[N][2], head[N];
struct node {
  long long too, Next, zh;
} edge[N * 2];
void add(long long a, long long b, long long c) {
  edge[++top].too = b;
  edge[top].zh = c;
  edge[top].Next = head[a];
  head[a] = top;
}
inline long long read() {
  long long ret = 0, f = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    ret = ret * 10 + c - 48;
    c = getchar();
  }
  if (f) return -ret;
  return ret;
}
bool cmp(long long x, long long y) { return x > y; }
void dfs(long long u, long long fa) {
  long long res = 0, gs = 0;
  for (long long i = head[u]; i; i = edge[i].Next) {
    long long v = edge[i].too, w = edge[i].zh;
    if (v == fa) continue;
    dfs(v, u);
  }
  for (long long i = head[u]; i; i = edge[i].Next) {
    long long v = edge[i].too, w = edge[i].zh;
    if (v == fa) continue;
    res += f[v][0];
    a[++gs] = f[v][1] + w - f[v][0];
  }
  sort(a + 1, a + gs + 1, cmp);
  for (long long i = 1; i <= min(k, gs); i++)
    if (a[i] > 0) res += a[i];
  f[u][0] = f[u][1] = res;
  if (k <= gs && a[k] > 0) f[u][1] -= a[k];
}
signed main() {
  long long T = read();
  while (T--) {
    top = 0;
    n = read();
    k = read();
    for (long long i = 1; i <= n; i++) head[i] = 0;
    for (long long i = 1; i < n; i++) {
      long long x = read(), y = read(), z = read();
      add(x, y, z);
      add(y, x, z);
    }
    dfs(1, 0);
    printf("%lld\n", f[1][0]);
  }
  return 0;
}
