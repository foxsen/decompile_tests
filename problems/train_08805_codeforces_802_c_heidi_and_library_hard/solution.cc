#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
template <typename T>
inline void read(T &x) {
  int ch = getchar();
  x = 0;
  bool f = false;
  double d = 1;
  for (; ch != '-' && (ch < '0' || ch > '9'); ch = getchar())
    ;
  if (ch == '-') {
    f = true;
    ch = getchar();
  }
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  if (ch == '.')
    for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar())
      x += (ch - '0') * (d *= 0.1);
  if (f) x = -x;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  if (a < b) return a = b, 1;
  return 0;
}
template <typename T>
inline bool chkmin(T &a, const T &b) {
  if (a > b) return a = b, 1;
  return 0;
}
const int K = 81, N = 170, M = N << 4, INF = 0x3f3f3f3f;
int n, k, S, T, a[K], c[K], head[N], to[M], nxt[M], cap[M], w[M], tmp[K];
inline void add(int a, int b, int c, int d) {
  static int cnt = 1;
  to[++cnt] = b;
  nxt[cnt] = head[a];
  head[a] = cnt;
  cap[cnt] = c;
  w[cnt] = d;
  to[++cnt] = a;
  nxt[cnt] = head[b];
  head[b] = cnt;
  cap[cnt] = 0;
  w[cnt] = -d;
}
int dis[N], inc[N], q[N], f, r, pre[N], ans;
bool inq[N];
inline void AMOD(int &x) {
  ++x;
  if (x >= N) x = 0;
}
inline bool spfa() {
  memset(inq, 0, sizeof inq);
  memset(dis, 0x3f, sizeof dis);
  f = r = 0;
  q[r++] = S;
  inc[S] = INF;
  dis[S] = 0;
  inq[S] = true;
  while (f != r) {
    int u = q[f];
    AMOD(f);
    inq[u] = false;
    for (register int i = head[u]; i; i = nxt[i])
      if (cap[i] && chkmin(dis[to[i]], dis[u] + w[i])) {
        inc[to[i]] = min(inc[u], cap[i]);
        pre[to[i]] = i;
        if (!inq[to[i]]) {
          inq[to[i]] = true;
          q[r] = to[i];
          AMOD(r);
        }
      }
  }
  return dis[T] < INF;
}
int main() {
  read(n);
  read(k);
  for (register int i = 1; i <= n; ++i) read(a[i]);
  for (register int i = 1; i <= n; ++i) read(c[i]);
  T = 1 + (S = n << 1 | 1);
  for (register int i = 1; i <= n; ++i) {
    add(S, i, 1, c[a[i]]);
    add(i, i + n, 1, 0);
    add(i + n, T, 1, 0);
    if (i < n) add(i, i + 1, k - 1, 0);
    if (tmp[a[i]]) add(i - 1, tmp[a[i]] + n, 1, -c[a[i]]);
    tmp[a[i]] = i;
  }
  while (spfa()) {
    ans += inc[T] * dis[T];
    for (register int u = T; u; u = to[pre[u] ^ 1]) {
      cap[pre[u]] -= inc[T];
      cap[pre[u] ^ 1] += inc[T];
    }
  }
  printf("%d", ans);
}
