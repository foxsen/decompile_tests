#include <bits/stdc++.h>
const long long MAXN = 1e5;
const long long INF = 0x3f3f3f3f3f3f3f;
long long n, m;
long long d[MAXN << 1 | 1], h[MAXN << 1 | 1];
inline long long read() {
  register long long x = 0, v = 1;
  register char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') v = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * v;
}
namespace ST {
long long A[MAXN << 1 | 1], B[MAXN << 1 | 1];
long long max[19][MAXN << 1 | 1], min[19][MAXN << 1 | 1], lg[MAXN << 1 | 1];
inline long long MAX(long long x, long long y) { return A[x] > A[y] ? x : y; }
inline long long MIN(long long x, long long y) { return B[x] < B[y] ? x : y; }
void get_ST() {
  A[0] = -INF;
  B[0] = INF;
  for (long long i = 2; i <= n << 1; ++i) lg[i] = lg[i >> 1] + 1;
  for (long long i = 1, s = 0; i <= n << 1; ++i) {
    s += d[i];
    A[i] = s + h[i];
    B[i] = s - h[i];
    max[0][i] = i;
    min[0][i] = i;
  }
  for (long long i = 1; i <= lg[n << 1]; ++i) {
    for (long long j = 1; j + (1 << i) - 1 <= n << 1; ++j) {
      max[i][j] = MAX(max[i - 1][j], max[i - 1][j + (1 << i - 1)]);
      min[i][j] = MIN(min[i - 1][j], min[i - 1][j + (1 << i - 1)]);
    }
  }
}
inline long long pmax(long long l, long long r) {
  if (l > r) return 0;
  long long len = lg[r - l + 1];
  return MAX(max[len][l], max[len][r - (1 << len) + 1]);
}
inline long long pmin(long long l, long long r) {
  if (l > r) return 0;
  long long len = lg[r - l + 1];
  return MIN(min[len][l], min[len][r - (1 << len) + 1]);
}
}  // namespace ST
using namespace ST;
long long calc(long long l, long long r) {
  long long x = pmax(l, r), y = pmin(l, r);
  if (x != y) return A[x] - B[y];
  long long tx = MAX(pmax(l, x - 1), pmax(x + 1, r)),
            ty = MIN(pmin(l, y - 1), pmin(y + 1, r));
  return std::max(A[x] - B[ty], A[tx] - B[y]);
}
signed main() {
  n = read();
  m = read();
  for (long long i = 1; i <= n; ++i) {
    d[i % n + 1] = d[i % n + 1 + n] = read();
  }
  for (long long i = 1; i <= n; ++i) {
    h[i] = h[i + n] = read() << 1;
  }
  get_ST();
  while (m--) {
    long long l = read(), r = read();
    if (l <= r)
      printf("%lld\n", calc(r + 1, l + n - 1));
    else
      printf("%lld\n", calc(r + 1, l - 1));
  }
  return 0;
}
