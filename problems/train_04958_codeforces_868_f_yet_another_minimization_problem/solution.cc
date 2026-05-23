#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  int f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 - '0' + c, c = getchar();
  x *= f;
}
const int N = 1e5 + 10;
int buc[N], L, R, a[N];
long long ans;
void update(int c, int d) { ans += d * buc[c] * (long long)(buc[c] - 1) / 2; }
long long cal(int l, int r) {
  while (L < l) update(a[L], -1), buc[a[L]]--, update(a[L], 1), L++;
  while (L > l) L--, update(a[L], -1), buc[a[L]]++, update(a[L], 1);
  while (R < r) R++, update(a[R], -1), buc[a[R]]++, update(a[R], 1);
  while (R > r) update(a[R], -1), buc[a[R]]--, update(a[R], 1), R--;
  return ans;
}
long long dp[22][N];
int cur;
void solve(int lb, int rb, int l, int r) {
  if (lb > rb || l > r) return;
  int mid = l + r >> 1;
  int d = 0;
  long long res = 1e18;
  for (int i = lb; i <= rb; ++i) {
    long long tmp = cal(i + 1, mid);
    if (res > dp[cur - 1][i] + tmp) res = dp[cur - 1][i] + tmp, d = i;
  }
  dp[cur][mid] = res;
  solve(lb, d, l, mid - 1), solve(d, rb, mid + 1, r);
}
int main() {
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  int n, m;
  read(n), read(m);
  for (int i = 1; i <= n; ++i) read(a[i]);
  buc[a[1]]++, L = R = 1;
  for (cur = 1; cur <= m; ++cur) solve(0, n - 1, 1, n);
  printf("%lld", dp[m][n]);
  return 0;
}
