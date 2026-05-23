#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
pair<int, int> q[100000 + 5];
long long act[100000 + 5];
int pw[100000 + 5], inv[100000 + 5],
    top = 0, n, m, a[100000 + 5], Ans[100000 + 5], s[100000 + 5], p[100000 + 5];
vector<pair<int, int> > v[100000 + 5];
inline int Calc(int l, int r) {
  return 1LL * (s[r] - s[l - 1] + 1000000007) * inv[l] % 1000000007;
}
inline void add(long long& x, long long y) { x = min(x + y, (long long)4e18); }
inline void pow(long long& x, int t) {
  for (int i = 1; i <= t && x < (long long)4e18; ++i)
    x = min((long long)4e18, x * 2);
}
int main() {
  n = read();
  m = read();
  pw[0] = inv[0] = 1;
  for (int i = 1; i <= n; ++i)
    a[i] = read(), pw[i] = 2 * pw[i - 1] % 1000000007,
    inv[i] = 1LL * inv[i - 1] * (1000000007 + 1) / 2 % 1000000007,
    s[i] = (s[i - 1] + (a[i] + 2LL * 1000000007) * pw[i]) % 1000000007;
  for (int i = 1; i <= m; ++i) {
    int l = read(), r = read();
    v[r].push_back(make_pair(l, i));
  }
  for (int i = 1; i <= n; ++i) {
    long long x = a[i];
    int l = i, r = i;
    for (; top && x >= 0; --top) {
      l = q[top].first;
      if (x > 0) pow(x, q[top].second - q[top].first + 1);
      add(x, act[top]);
    }
    q[++top] = make_pair(l, r);
    p[top] = (p[top - 1] + Calc(l, r)) % 1000000007;
    act[top] = x;
    for (int j = 0; j < v[i].size(); ++j) {
      int pos =
          upper_bound(q + 1, q + top + 1, make_pair(v[i][j].first, n + 1)) - q -
          1;
      int ans = (1LL * p[top] - p[pos] +
                 Calc(v[i][j].first + 1, q[pos].second) + 1000000007) %
                1000000007;
      Ans[v[i][j].second] =
          (2LL * ans + a[v[i][j].first] + 2 * 1000000007) % 1000000007;
    }
  }
  for (int i = 1; i <= m; ++i) printf("%d\n", Ans[i]);
  return 0;
}
