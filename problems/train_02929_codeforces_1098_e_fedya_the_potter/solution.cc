#include <bits/stdc++.h>
using std::max;
using std::min;
const int inf = 0x3f3f3f3f, Inf = 0x7fffffff;
const long long INF = 0x3f3f3f3f3f3f3f3f;
__inline__ __attribute__((always_inline)) unsigned int rnd() {
  static unsigned int seed = 416;
  return seed += 0x71dad4bfu, seed ^= seed >> 5, seed += 0xc6f74d88u,
         seed ^= seed << 17, seed += 0x25e6561u, seed ^= seed >> 13;
}
template <typename _Tp>
_Tp gcd(const _Tp &a, const _Tp &b) {
  return (!b) ? a : gcd(b, a % b);
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) _Tp abs(const _Tp &a) {
  return a >= 0 ? a : -a;
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) void chmax(_Tp &a, const _Tp &b) {
  (a < b) && (a = b);
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) void chmin(_Tp &a, const _Tp &b) {
  (b < a) && (a = b);
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) void read(_Tp &x) {
  char ch(getchar());
  bool f(false);
  while (!isdigit(ch)) f |= ch == 45, ch = getchar();
  x = ch & 15, ch = getchar();
  while (isdigit(ch)) x = (((x << 2) + x) << 1) + (ch & 15), ch = getchar();
  f && (x = -x);
}
template <typename _Tp, typename... Args>
__inline__ __attribute__((always_inline)) void read(_Tp &t, Args &...args) {
  read(t);
  read(args...);
}
template <typename _Tp, typename... Args>
__inline__ __attribute__((always_inline)) _Tp min(const _Tp &a, const _Tp &b,
                                                  const Args &...args) {
  return a < b ? min(a, args...) : min(b, args...);
}
template <typename _Tp, typename... Args>
__inline__ __attribute__((always_inline)) _Tp max(const _Tp &a, const _Tp &b,
                                                  const Args &...args) {
  return a < b ? max(b, args...) : max(a, args...);
}
__inline__ __attribute__((always_inline)) int read_str(char *s) {
  char ch(getchar());
  while (ch == ' ' || ch == '\r' || ch == '\n') ch = getchar();
  char *tar = s;
  *tar = ch, ch = getchar();
  while (ch != ' ' && ch != '\r' && ch != '\n' && ch != EOF)
    *(++tar) = ch, ch = getchar();
  return tar - s + 1;
}
const int N = 50005;
const int MAXN = 100005;
int a[N];
int g[N][21], Log2[N];
__inline__ __attribute__((always_inline)) int query(int l, int r) {
  int k = Log2[r - l + 1];
  return gcd(g[l][k], g[r - (1 << k) + 1][k]);
}
__inline__ __attribute__((always_inline)) long long s(long long x) {
  return 1ll * x * (x + 1) >> 1;
}
long long f(long long n, long long a, long long b, long long c) {
  if (!a) return (n + 1) * (b / c);
  if (a < 0 || b < 0 || a >= c || b >= c) {
    long long A = a % c, B = b % c;
    (A < 0) && (A += c), (B < 0) && (B += c);
    return f(n, A, B, c) + ((a - A) / c) * s(n) + ((b - B) / c) * (n + 1);
  }
  long long m = (a * n + b) / c;
  return n * m - f(m - 1, c, c - b - 1, a);
}
long long cnt[MAXN];
long long val[MAXN];
long long calc(long long mid) {
  long long ans = 0, sum = 0, qwq = 0;
  int pos = 100000;
  for (int i = 100000; i >= 1; --i) {
    if (!cnt[i]) continue;
    int l = 1;
    while (l <= cnt[i]) {
      while (sum + 1ll * l * i > mid && pos > i) {
        sum -= cnt[pos] * pos;
        qwq -= cnt[pos];
        --pos;
      }
      if (pos > i || (pos == i && 1ll * l * i <= mid)) {
        long long r = min((mid - sum) / i, (long long)cnt[i]);
        ans += +s(r) - s(l - 1) + 1ll * (r - l + 1) * qwq;
        if (cnt[pos + 1]) ans += f(r - l, -i, mid - sum - 1ll * i * l, pos + 1);
        l = r + 1;
      } else {
        long long tmp = mid / i;
        if (l >= tmp)
          ans += (cnt[i] - l + 1) * tmp;
        else {
          chmin(tmp, cnt[i]);
          ans += s(tmp) - s(l - 1);
          ans += (cnt[i] - tmp) * tmp;
        }
        l = cnt[i] + 1;
      }
    }
    sum += cnt[i] * i;
    qwq += cnt[i];
  }
  return ans;
}
int main() {
  for (int i = 2; i < N; ++i) Log2[i] = Log2[i >> 1] + 1;
  int n;
  read(n);
  for (int i = 1; i <= n; ++i) read(a[i]);
  for (int i = n; i >= 1; --i) {
    g[i][0] = a[i];
    for (int j = 1; j <= 20 && i + (1 << (j - 1)) <= n; ++j)
      g[i][j] = gcd(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
  }
  for (int i = 1; i <= n; ++i) {
    int cur = i;
    while (cur <= n) {
      int l = cur, r = n;
      int tmp = query(i, cur);
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (query(i, mid) == tmp)
          l = mid;
        else
          r = mid - 1;
      }
      cnt[tmp] += l - cur + 1;
      cur = l + 1;
    }
  }
  long long cnt = ((s(n) * (s(n) + 1) / 2) + 1) / 2;
  long long l = 1, r = 1e18;
  while (l < r) {
    long long mid = (l + r) >> 1;
    if (calc(mid) >= cnt)
      r = mid;
    else
      l = mid + 1;
  }
  printf("%lld\n", l);
  return 0;
}
