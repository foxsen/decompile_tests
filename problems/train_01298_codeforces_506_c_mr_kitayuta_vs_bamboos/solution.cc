#include <bits/stdc++.h>
using namespace std;
int a1234;
inline void xxx() {
  for (;;)
    ;
}
inline int rd(int l, int r) { return rand() % (r - l + 1) + l; }
const int mxn = 1e5 + 3;
long long a[mxn], now[mxn];
int n, m, k, hh;
priority_queue<pair<long long, int> > q;
int day[mxn], h[mxn];
inline void ins(int x) { q.push(pair<long long, int>(-(now[x] / a[x]), x)); }
inline bool work(long long x) {
  q = priority_queue<pair<long long, int> >();
  for (int i = 1; i <= n; ++i) now[i] = x, ins(i);
  for (int i = 1; i <= m; ++i) {
    int re = k;
    int x;
    long long y;
    while (re) {
      x = q.top().second, y = -q.top().first;
      q.pop();
      if (y < i)
        return 0;
      else if (y >= m) {
        for (int j = 1; j <= n; ++j) now[j] -= m * a[j], assert(now[j] >= 0);
        re += (m - i) * k;
        for (int j = 1; j <= n; ++j) {
          while (re && now[j] < h[j]) now[j] += hh, --re;
          if (now[j] < h[j]) return 0;
        }
        return 1;
      } else {
        while (now[x] - (y + 1) * a[x] < 0 && re) --re, now[x] += hh;
        ins(x);
      }
    }
  }
  for (int i = 1; i <= n; ++i)
    if (now[i] - m * a[i] < h[i]) return 0;
  return 1;
}
int main() {
  a1234 = scanf("%d%d%d%d", &n, &m, &k, &hh);
  long long l = 0, r = 0, mid;
  for (int i = 1; i <= n; ++i)
    a1234 = scanf("%d%lld", h + i, a + i), l = max(l, a[i]),
    r = max(r, h[i] + m * a[i]);
  while (l < r) {
    mid = (l + r) >> 1;
    if (work(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%lld\n", l);
  return 0;
}
