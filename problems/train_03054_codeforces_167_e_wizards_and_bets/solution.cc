#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 100005;
long long read() {
  long long x = 0, flag = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') flag = -1;
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return x * flag;
}
long long n, m, mod, tot, f[605], in[605], out[605];
long long a[605][605], t[605][605];
bool vis[605];
vector<long long> fr, to;
struct edge {
  long long v, next;
} e[MAXN];
void dfs(long long u) {
  vis[u] = 1;
  if (!out[u]) t[u][u] = 1;
  for (long long i = f[u]; i; i = e[i].next) {
    long long v = e[i].v;
    if (!vis[v]) dfs(v);
    for (long long i = 0; i < to.size(); i++)
      t[u][to[i]] = (t[u][to[i]] + t[v][to[i]]) % mod;
  }
}
long long qkpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
void gauss(long long n) {
  long long mark = 1;
  for (long long i = 1; i <= n; i++) {
    long long r = i;
    for (; r <= n; r++)
      if (a[r][i]) break;
    if (i ^ r) mark = -mark;
    swap(a[r], a[i]);
    for (long long j = i + 1; j <= n; j++) {
      long long tmp = a[j][i] * qkpow(a[i][i], mod - 2) % mod;
      for (long long k = i; k <= n; k++)
        a[j][k] = (a[j][k] - a[i][k] * tmp % mod + mod) % mod;
    }
  }
  long long ans = mark;
  for (long long i = 1; i <= n; i++) ans = ans * a[i][i] % mod;
  printf("%lld\n", (ans % mod + mod) % mod);
}
int main() {
  n = read();
  m = read();
  mod = read();
  for (long long i = 1; i <= m; i++) {
    long long u = read(), v = read();
    e[++tot] = edge{v, f[u]}, f[u] = tot;
    in[v]++;
    out[u]++;
  }
  for (long long i = 1; i <= n; i++) {
    if (!in[i]) fr.push_back(i);
    if (!out[i]) to.push_back(i);
  }
  for (long long i = 1; i <= n; i++)
    if (!in[i]) dfs(i);
  for (long long i = 0; i < fr.size(); i++)
    for (long long j = 0; j < to.size(); j++) a[i + 1][j + 1] = t[fr[i]][to[j]];
  gauss(fr.size());
}
