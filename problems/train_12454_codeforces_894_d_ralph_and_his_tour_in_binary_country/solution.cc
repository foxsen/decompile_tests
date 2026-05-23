#include <bits/stdc++.h>
namespace fastIO {
bool IOerror = 0;
inline char nc() {
  static char buf[10000000], *p1 = buf + 10000000, *pend = buf + 10000000;
  if (p1 == pend) {
    p1 = buf;
    pend = buf + fread(buf, 1, 10000000, stdin);
    if (pend == p1) {
      IOerror = 1;
      return -1;
    }
  }
  return *p1++;
}
inline bool blank(char ch) {
  return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
inline void read(int &x) {
  char ch;
  while (blank(ch = nc()))
    ;
  if (IOerror) return;
  for (x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0')
    ;
}
};  // namespace fastIO
using namespace fastIO;
using namespace std;
const int N = 1E6 + 7;
vector<long long> pre[N], dis[N];
int t[N];
long long query(int s, long long h) {
  if (h <= 0) return 0;
  int p = upper_bound(begin(dis[s]), end(dis[s]), h) - begin(dis[s]);
  return p * h - pre[s][p - 1];
}
int main() {
  int n, m;
  read(n), read(m);
  for (int i = 2; i <= n; i++) read(t[i]);
  for (int i = n; i >= 1; i--) {
    vector<long long> tmp[2];
    tmp[0].emplace_back(0);
    for (int c = 0; c < 2; c++) {
      int x = 2 * i + c;
      if (x > n) continue;
      for (long long it : dis[x]) {
        tmp[c].emplace_back(it + t[x]);
      }
    }
    dis[i].resize(tmp[0].size() + tmp[1].size());
    merge(begin(tmp[0]), end(tmp[0]), begin(tmp[1]), end(tmp[1]),
          begin(dis[i]));
    int tot = dis[i].size();
    pre[i].resize(tot);
    for (int j = 1; j < tot; j++) pre[i][j] = pre[i][j - 1] + dis[i][j];
  }
  while (m--) {
    int a, h;
    long long ans = 0;
    read(a), read(h);
    ans += query(a, h);
    while (a > 1) {
      int b = a;
      a >>= 1;
      h -= t[b];
      if (h <= 0) break;
      ans += h;
      int x = 2 * a == b ? 2 * a + 1 : 2 * a;
      if (x <= n) ans += query(x, h - t[x]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
