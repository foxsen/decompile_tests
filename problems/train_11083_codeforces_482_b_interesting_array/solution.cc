#include <bits/stdc++.h>
using namespace std;
const long long base = 1331;
const long long N = 1e5 + 1;
template <typename T>
inline void Cin(T& x) {
  char c = getchar();
  x = 0;
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
}
template <typename T, typename... Args>
inline void Cin(T& a, Args&... args) {
  Cin(a);
  Cin(args...);
}
long long s[N][31], n, m, a[N], l[N], r[N], q[N], res, ST[4 * N];
void build(long long id, long long l, long long r) {
  if (l == r) {
    ST[id] = a[l];
    return;
  }
  long long mid = (l + r) / 2;
  build(id * 2, l, mid);
  build(id * 2 + 1, mid + 1, r);
  ST[id] = ST[id * 2] & ST[id * 2 + 1];
}
void get(long long id, long long l, long long r, long long L, long long R) {
  if (L > r || R < l) {
    return;
  }
  if (L <= l && r <= R) {
    res = res & ST[id];
    return;
  }
  long long mid = (l + r) / 2;
  get(id * 2, l, mid, L, R);
  get(id * 2 + 1, mid + 1, r, L, R);
}
void read(void) {
  cin >> n >> m;
  for (long long i = 1; i <= (long long)(m); ++i) {
    cin >> l[i] >> r[i] >> q[i];
    for (long long j = 0; j < (long long)(31); ++j) {
      if (q[i] >> j & 1 == 1) {
        s[l[i]][j]++;
        s[r[i] + 1][j]--;
      }
    }
  }
  for (long long i = 1; i <= (long long)(n); ++i) {
    for (long long j = 0; j < (long long)(31); ++j) {
      s[i][j] += s[i - 1][j];
      if (s[i][j] > 0) a[i] += (1 << j);
    }
  }
  build(1, 1, n);
  for (long long i = 1; i <= (long long)(m); ++i) {
    res = a[l[i]];
    get(1, 1, n, l[i], r[i]);
    if (res != q[i]) {
      cout << "NO";
      return;
    }
  }
  cout << "YES" << '\n';
  for (long long i = 1; i <= (long long)(n); ++i) cout << a[i] << ' ';
}
signed main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  read();
}
