#include <bits/stdc++.h>
using namespace std;
#pragma optimize("Ofast")
queue<unsigned long long> q;
unsigned long long color[1000005];
unsigned long long head[1000005], T, n, m, cnt, cnt1, cnt2, ans;
inline unsigned long long read() {
  unsigned long long x = 0, neg = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') neg = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * neg;
}
struct node {
  unsigned long long to, next;
} edge[1000005];
inline void add(register unsigned long long u, register unsigned long long v) {
  edge[++cnt] = (node){v, head[u]};
  head[u] = cnt;
}
inline unsigned long long fpow(register unsigned long long x,
                               register unsigned long long y) {
  unsigned long long p = 1;
  while (y) {
    if (y & 1) p = p * x % 998244353;
    y >>= 1;
    x = x * x % 998244353;
  }
  return p;
}
inline void bfs() {
  while (!q.empty()) {
    unsigned long long u = q.front();
    q.pop();
    for (register unsigned long long i = head[u]; i; i = edge[i].next) {
      unsigned long long v = edge[i].to;
      if (color[v] == -1) {
        color[v] = 3 - color[u];
        if (color[v] == 1)
          ++cnt1;
        else
          ++cnt2;
        q.push(v);
      } else if (color[v] != 3 - color[u]) {
        ans = 0;
        break;
      }
    }
  }
}
signed main() {
  T = read();
  while (T--) {
    n = read(), m = read();
    ans = 1;
    for (unsigned long long i = 0; i <= n; ++i) color[i] = -1;
    for (unsigned long long i = 0; i <= n; ++i) head[i] = 0;
    for (unsigned long long i = 1; i <= m * 2; ++i)
      edge[i].next = 0, edge[i].to = 0;
    for (register unsigned long long i = 1; i <= m; ++i) {
      unsigned long long a = read(), b = read();
      add(a, b);
      add(b, a);
    }
    for (register unsigned long long i = 1; i <= n; i++) {
      if (~color[i]) continue;
      cnt1 = 1;
      cnt2 = 0;
      color[i] = 1;
      q.push(i);
      bfs();
      if (!ans) break;
      ans =
          (((fpow(2, cnt1) + fpow(2, cnt2)) % 998244353) * (ans % 998244353)) %
          998244353;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
