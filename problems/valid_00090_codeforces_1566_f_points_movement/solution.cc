#include <bits/stdc++.h>
using namespace std;
char gc() {
  static char buf[1 << 16], *s, *t;
  if (s == t) {
    t = (s = buf) + fread(buf, 1, 1 << 16, stdin);
    if (s == t) return EOF;
  }
  return *s++;
}
int read() {
  char c;
  int w = 1;
  while ((c = getchar()) > '9' || c < '0')
    if (c == '-') w = -1;
  int ans = c - '0';
  while ((c = getchar()) >= '0' && c <= '9')
    ans = (ans << 1) + (ans << 3) + c - '0';
  return ans * w;
}
char st;
const int xx = 2e5 + 5;
long long n, m;
long long a[xx];
struct node {
  long long l, r;
  bool operator<(const node& w) const { return l < w.l; };
} e[xx], w[xx];
long long vis[xx];
struct no {
  long long x, y;
  bool operator<(const no& w) const { return x < w.x; }
};
long long f[xx][2];
multiset<no> s;
long long mn[xx << 2];
void build(long long k, long long l, long long r) {
  if (l == r) return mn[k] = e[l].r, void();
  long long mid = l + r >> 1;
  build(k << 1, l, mid);
  build(k << 1 | 1, mid + 1, r);
  mn[k] = min(mn[k << 1], mn[k << 1 | 1]);
}
long long ask(long long k, long long l, long long r, long long x, long long y) {
  if (x <= l && r <= y) return mn[k];
  long long mid = l + r >> 1, ans = 2e9 + 1000;
  if (x <= mid) ans = min(ans, ask(k << 1, l, mid, x, y));
  if (mid < y) ans = min(ans, ask(k << 1 | 1, mid + 1, r, x, y));
  return ans;
}
char ed;
signed main() {
  int T = read();
  while (T--) {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    a[++n] = -5e9 - 1000, a[++n] = 5e9 + 1000;
    memset(vis, 0, sizeof(vis[0]) * (m + 1));
    sort(a + 1, a + n + 1);
    s.clear();
    for (int i = 1; i <= m; i++) w[i].l = read(), w[i].r = read();
    sort(w + 1, w + m + 1);
    long long tt = 1;
    for (int i = 1; i <= n; i++) {
      while (tt <= m && w[tt].l <= a[i]) s.insert((no){w[tt].r, tt}), tt++;
      while (s.size() && ((--s.end())->x) >= a[i])
        vis[((--s.end())->y)] = 1, s.erase(--s.end());
    }
    long long oo = 0;
    for (int i = 1; i <= m; i++)
      if (!vis[i]) e[++oo] = w[i];
    m = oo;
    for (int i = 1; i <= n; i++) f[i][0] = f[i][1] = 1e18;
    f[1][0] = f[1][1] = 0;
    if (!m) {
      puts("0");
      continue;
    }
    build(1, 1, m);
    tt = 1;
    for (int i = 1; i < n; i++) {
      long long l = tt, r = tt - 1;
      while (r != m && e[r + 1].l <= a[i + 1]) r++;
      if (l > r) {
        f[i + 1][0] = min(f[i][0], f[i][1]);
        f[i + 1][1] = min(f[i][0], f[i][1]);
        continue;
      }
      long long p = ask(1, 1, m, l, r);
      f[i + 1][0] = (a[i + 1] - p) * 2 + min(f[i][0], f[i][1]);
      f[i + 1][1] = (a[i + 1] - p) + min(f[i][0], f[i][1]);
      for (int j = l; j <= r; j++) {
        long long p;
        if (j != r)
          p = ask(1, 1, m, j + 1, r);
        else
          p = a[i + 1];
        f[i + 1][0] = min(f[i + 1][0], (a[i + 1] - p) * 2 +
                                           min(f[i][0] + e[j].l - a[i],
                                               f[i][1] + (e[j].l - a[i]) * 2));
        f[i + 1][1] = min(f[i + 1][1],
                          (a[i + 1] - p) + min(f[i][0] + e[j].l - a[i],
                                               f[i][1] + (e[j].l - a[i]) * 2));
      }
      tt = r + 1;
    }
    cout << min(f[n][0], f[n][1]) << "\n";
  }
  return 0;
}
