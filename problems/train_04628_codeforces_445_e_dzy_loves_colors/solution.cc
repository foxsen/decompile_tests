#include <bits/stdc++.h>
using namespace std;
const long long A = 100000000000000LL, N = 228228;
long long i, j, n, m, a, l, r, x, t[3][N * 4];
void talk(long long v, long long l, long long r) {
  if (!t[0][v]) return;
  long long mid = (l + r) / 2;
  t[1][v * 2] += t[2][v] * (mid - l + 1),
      t[1][v * 2 + 1] += t[2][v] * (r - mid);
  t[0][v * 2] = t[0][v * 2 + 1] = t[0][v];
  t[2][v * 2] += t[2][v], t[2][v * 2 + 1] += t[2][v], t[2][v] = 0;
}
void modi(long long v, long long l, long long r, long long _l, long long _r,
          long long x) {
  if (_l > _r) return;
  if (l == _l && r == _r && t[0][v]) {
    t[1][v] += labs(t[0][v] - x) * (r - l + 1), t[2][v] += labs(x - t[0][v]),
        t[0][v] = x;
    return;
  }
  talk(v, l, r);
  long long mid = (l + r) / 2;
  modi(v * 2, l, mid, _l, min(_r, mid), x),
      modi(v * 2 + 1, mid + 1, r, max(_l, mid + 1), _r, x);
  if (t[0][v * 2 + 1] == t[0][v * 2])
    t[0][v] = t[0][v * 2];
  else
    t[0][v] = 0;
  t[1][v] = t[1][v * 2] + t[1][v * 2 + 1];
}
long long get(long long v, long long l, long long r, long long _l,
              long long _r) {
  if (_l > _r) return 0;
  if (l == _l && r == _r) return t[1][v];
  talk(v, l, r);
  long long mid = (l + r) / 2;
  return get(v * 2, l, mid, _l, min(_r, mid)) +
         get(v * 2 + 1, mid + 1, r, max(_l, mid + 1), _r);
}
void build(long long v, long long l, long long r) {
  if (l == r) {
    t[0][v] = l;
    return;
  }
  long long mid = (l + r) / 2;
  build(v * 2, l, mid), build(v * 2 + 1, mid + 1, r);
}
int main() {
  cin >> n >> m;
  build(1, 1, n);
  while (m--) {
    scanf("%d%d%d", &a, &l, &r);
    if (a == 1)
      scanf("%d", &x), modi(1, 1, n, l, r, x);
    else
      cout << get(1, 1, n, l, r) << "\n";
  }
}
