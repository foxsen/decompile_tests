#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chmin(T &x, const T &y) {
  if (x > y) x = y;
}
template <typename T>
void chmax(T &x, const T &y) {
  if (x < y) x = y;
}
char readc() {
  char c;
  while (isspace((c = getchar())))
    ;
  return c;
}
int read() {
  char c;
  while ((c = getchar()) < '-')
    ;
  if (c == '-') {
    int x = (c = getchar()) - '0';
    while ((c = getchar()) >= '0') x = x * 10 + c - '0';
    return -x;
  }
  int x = c - '0';
  while ((c = getchar()) >= '0') x = x * 10 + c - '0';
  return x;
}
const int N = 1000 + 5, INF = 1e9 + 10;
int n, mx[N], fr[N], a[N], b[N], a0[N], b0[N], q[N];
vector<int> lk[N];
bool one(int p) {
  int t = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == INF) {
      for (auto j : lk[i]) {
        if (p > a[j]) {
          if (mx[j]) {
            a[j] = INF;
            return 1;
          }
          fr[j] = 0;
          mx[j] = min(INF, b[j] + p);
          q[++t] = j;
        }
      }
    }
  }
  for (int h = 1; h <= t; ++h) {
    int x = q[h];
    for (auto y : lk[x])
      if (y != fr[x]) {
        int d = mx[x];
        if (d > a[y]) {
          if (mx[y]) {
            for (int i = y; i; i = fr[i]) a[i] = INF;
            for (int i = x; i; i = fr[i]) a[i] = INF;
            return 1;
          }
          mx[y] = min(INF, d + b[y]);
          fr[y] = x;
          q[++t] = y;
        } else if (a[y] == INF && fr[x]) {
          for (int i = x; i; i = fr[i]) a[i] = INF;
          return 1;
        }
      }
  }
  return 0;
}
bool check(int p0) {
  for (int i = 2; i <= n; ++i) a[i] = a0[i];
  for (int i = 2; i <= n; ++i) b[i] = b0[i];
  a[1] = INF;
  b[1] = 0;
  while (1) {
    bool ok = 1;
    int p = p0;
    for (int i = 2; i <= n; ++i) {
      ok &= a[i] == INF;
      if (a[i] == INF) p = min(INF, p + b[i]);
    }
    if (ok) break;
    for (int i = 1; i <= n; ++i) {
      mx[i] = fr[i] = 0;
    }
    if (!one(p)) return 0;
  }
  return 1;
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int m;
    cin >> n >> m;
    for (int i = 2; i <= n; ++i) scanf("%d", a0 + i);
    for (int i = 2; i <= n; ++i) scanf("%d", b0 + i);
    for (int i = 1; i <= n; ++i) lk[i].clear();
    while (m--) {
      int u, v;
      scanf("%d%d", &u, &v);
      lk[u].push_back(v);
      lk[v].push_back(u);
    }
    int l = 0, r = 1e9 + 5;
    while (l + 1 != r) {
      int mid = (l + r) / 2;
      if (check(mid))
        r = mid;
      else
        l = mid;
    }
    cout << r << endl;
  }
}
