#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &a) {
  T x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  a = x * f;
}
template <typename T>
void write(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x < 10) return (void)putchar(x + '0');
  write(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void writeln(T x) {
  write(x);
  putchar('\n');
}
template <typename T>
void writes(T x) {
  write(x);
  putchar(' ');
}
template <typename T, typename... Args>
void read(T &t, Args &...args) {
  read(t);
  read(args...);
}
template <typename T, typename... Args>
void writes(T t, Args... args) {
  writes(t);
  writes(args...);
}
template <typename T, typename... Args>
void writeln(T t, Args... args) {
  writes(t);
  writes(args...);
  putchar('\n');
}
const long long mod = 998244353;
long long n, head[300005], pnt[300005 << 1], nxt[300005 << 1], E = 0;
long long dp[300005][3];
void add_edge(long long u, long long v) {
  pnt[E] = v;
  nxt[E] = head[u];
  head[u] = E++;
}
void dfs(long long u, long long f) {
  dp[u][0] = 1;
  for (long long i = head[u]; i != -1; i = nxt[i]) {
    long long v = pnt[i];
    if (v == f) continue;
    dfs(v, u);
    dp[u][2] =
        (dp[u][0] * (dp[v][0] + dp[v][1]) + dp[u][1] * (dp[v][0] + dp[v][1]) +
         dp[u][2] * (dp[v][0] + dp[v][2] * 2)) %
        mod;
    dp[u][1] =
        (dp[u][0] * dp[v][2] + dp[u][1] * (dp[v][0] + 2 * dp[v][2])) % mod;
    dp[u][0] = dp[u][0] * (dp[v][0] + dp[v][2]) % mod;
  }
}
signed main() {
  memset(head, -1, sizeof(head));
  read(n);
  for (long long i = 1; i < n; i++) {
    long long u, v;
    read(u, v);
    add_edge(u, v);
    add_edge(v, u);
  }
  dfs(1, 0);
  writeln((dp[1][0] + dp[1][2]) % mod);
  return 0;
}
