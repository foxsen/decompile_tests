#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  bool f = false;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = true;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ '0');
    c = getchar();
  }
  return f ? -x : x;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
long long n, k, a[101], b[101][101], ans, cnt1, cnt2;
signed main() {
  n = read();
  k = read();
  for (register long long i = 0; i < n; ++i)
    a[i] = read(), b[i / k][i % k] = a[i];
  for (register long long i = 0; i < k; ++i) {
    cnt1 = cnt2 = 0;
    for (register long long j = 0; j < n / k; ++j)
      b[j][i] == 1 ? ++cnt1 : ++cnt2;
    ans += min(cnt1, cnt2);
  }
  cout << ans;
  return 0;
}
