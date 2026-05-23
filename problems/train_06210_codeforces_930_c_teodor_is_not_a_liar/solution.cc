#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
inline long long getint() {
  long long _x = 0, _tmp = 1;
  char _tc = getchar();
  while ((_tc < '0' || _tc > '9') && _tc != '-') _tc = getchar();
  if (_tc == '-') _tc = getchar(), _tmp = -1;
  while (_tc >= '0' && _tc <= '9') _x *= 10, _x += (_tc - '0'), _tc = getchar();
  return _x * _tmp;
}
inline long long add(long long _x, long long _y,
                     long long _mod = 1000000007LL) {
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
inline long long sub(long long _x, long long _y,
                     long long _mod = 1000000007LL) {
  _x -= _y;
  return _x < 0 ? _x + _mod : _x;
}
inline long long mul(long long _x, long long _y,
                     long long _mod = 1000000007LL) {
  _x *= _y;
  return _x >= _mod ? _x % _mod : _x;
}
long long mypow(long long _a, long long _x, long long _mod) {
  if (_x == 0) return 1LL;
  long long _ret = mypow(mul(_a, _a, _mod), _x >> 1, _mod);
  if (_x & 1) _ret = mul(_ret, _a, _mod);
  return _ret;
}
long long mymul(long long _a, long long _x, long long _mod) {
  if (_x == 0) return 0LL;
  long long _ret = mymul(add(_a, _a, _mod), _x >> 1, _mod);
  if (_x & 1) _ret = add(_ret, _a, _mod);
  return _ret;
}
inline bool equal(double _x, double _y) {
  return _x > _y - 1e-9 && _x < _y + 1e-9;
}
void sleep(double sec = 1021) {
  clock_t s = clock();
  while (clock() - s < CLOCKS_PER_SEC * sec)
    ;
}
int __ = 1, _cs;
void build() {}
int BIT[101010];
int lb(int x) { return x & (-x); }
void reset() {
  for (int i = 0; i < 101010; i++) BIT[i] = 0;
}
void modify(int x, int v) {
  for (int i = x; i < 101010; i += lb(i)) BIT[i] = max(BIT[i], v);
}
int query(int x) {
  int ret = 0;
  for (int i = x; i; i -= lb(i)) ret = max(ret, BIT[i]);
  return ret;
}
int n, m, a[101010];
void init() {
  n = getint();
  m = getint();
  while (n--) {
    int li = getint();
    int ri = getint();
    a[li]++;
    a[ri + 1]--;
  }
  n = m;
  for (int i = 1; i <= n; i++) a[i] += a[i - 1];
  for (int i = 1; i <= n; i++) a[i]++;
}
int dpl[101010], ans;
void solve() {
  for (int i = 1; i <= n; i++) {
    int ret = query(a[i]);
    dpl[i] = ret + 1;
    modify(a[i], ret + 1);
  }
  reset();
  ans = dpl[n];
  for (int i = n; i >= 1; i--) {
    int ret = query(a[i]);
    int dpr = ret + 1;
    ans = max(ans, dpr + dpl[i - 1]);
    modify(a[i], ret + 1);
  }
  printf("%d\n", ans);
}
int main() {
  build();
  while (__--) {
    init();
    solve();
  }
}
