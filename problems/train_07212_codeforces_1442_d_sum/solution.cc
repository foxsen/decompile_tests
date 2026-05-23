#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void rd(T &x) {
  int fl = 1;
  x = 0;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') fl = -fl;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= fl;
}
template <class T>
inline void wr(T x) {
  if (x < 0) x = -x, putchar('-');
  if (x < 10) {
    putchar(x + '0');
    return;
  }
  int tmp[30] = {0}, cnt = 0;
  while (x) tmp[cnt++] = x % 10, x /= 10;
  for (register int i = cnt - 1; i >= 0; --i) putchar(tmp[i] + '0');
}
const int N = 3e3 + 5;
int n, k;
long long ans, t[N], s[N];
vector<long long> a[N], f;
inline void solve(int l, int r) {
  if (l == r) {
    long long sum = 0;
    for (register int i = 0; i < k && i < t[l]; ++i)
      sum += a[l][i], ans = max(ans, f[k - i - 1] + sum);
    return;
  }
  vector<long long> tmp = f;
  for (register int i = l; i <= ((l + r) >> 1); ++i)
    for (register int j = k; j >= t[i]; --j)
      f[j] = max(f[j - t[i]] + s[i], f[j]);
  solve(((l + r) >> 1) + 1, r);
  f = tmp;
  for (register int i = ((l + r) >> 1) + 1; i <= r; ++i)
    for (register int j = k; j >= t[i]; --j)
      f[j] = max(f[j - t[i]] + s[i], f[j]);
  solve(l, ((l + r) >> 1));
}
int main() {
  rd(n);
  rd(k);
  f.resize(k + 10);
  for (register int i = 1; i <= n; ++i) {
    rd(t[i]);
    long long x;
    for (register int j = 1; j <= t[i]; ++j)
      rd(x), a[i].push_back(x), s[i] += x;
  }
  solve(1, n);
  wr(ans);
  puts("");
  return 0;
}
