#include <bits/stdc++.h>
using namespace std;
long long f[80], d[80];
pair<long long, int> p1[80][2], p2[80][2];
int T, n;
inline void init(long long v, int n, int id) {
  if (n == 1) {
    p1[0][id] = make_pair(1, 0);
    p2[0][id] = make_pair(1, 0);
    p1[1][id] = make_pair(v, v != 1);
    p2[1][id] = make_pair(v, v != 2);
    return;
  }
  if (v > f[n - 1])
    init(v - f[n - 1], n - 1, id);
  else
    init(v, n - 1, id);
  p1[n][id].first = p2[n][id].first = v;
  if (v > f[n - 1])
    p1[n][id].second = p1[n - 2][id].second + 1;
  else
    p1[n][id].second = min(p2[n - 1][id].second + 2, p1[n - 1][id].second);
  if (v > f[n - 1])
    p2[n][id].second = p2[n - 2][id].second;
  else
    p2[n][id].second =
        d[n - 2] + 1 + min(p2[n - 1][id].second, p1[n - 1][id].second);
}
inline int query(long long a, long long b, int n) {
  if (a > b) swap(a, b);
  if (a == b) return 0;
  if (n == 0) return 0;
  if (n == 1) return a != b;
  if (a == 1) {
    if (b == p1[n][0].first) return p1[n][0].second;
    if (b == p1[n][1].first) return p1[n][1].second;
  }
  if (b == f[n]) {
    if (a == p2[n][0].first) return p2[n][0].second;
    if (a == p2[n][1].first) return p2[n][1].second;
  }
  int ret = 0x3f3f3f3f;
  if (a > f[n - 1] && b > f[n - 1])
    ret = query(a - f[n - 1], b - f[n - 1], n - 2);
  else if (b > f[n - 1])
    ret = query(1, b - f[n - 1], n - 2) +
          min(query(1, a, n - 1), query(a, f[n - 1], n - 1)) + 1;
  else
    ret = min(min(query(a, f[n - 1], n - 1) + query(1, b, n - 1),
                  query(a, 1, n - 1) + query(b, f[n - 1], n - 1)) +
                  2,
              query(a, b, n - 1));
  return ret;
}
int main() {
  f[0] = 1;
  f[1] = 2;
  for (int i = 2; i <= 77; i++) f[i] = f[i - 1] + f[i - 2];
  d[0] = 0;
  d[1] = 1;
  for (int i = 2; i <= 77; i++) d[i] = d[i - 2] + 1;
  scanf("%d%d", &T, &n);
  if (n > 77) n = 78;
  while (T--) {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    init(x, n, 0);
    init(y, n, 1);
    printf("%d\n", query(x, y, n));
  }
  return 0;
}
