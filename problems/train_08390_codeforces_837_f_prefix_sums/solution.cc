#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f, Inf = 0x7fffffff;
const long long INF = 0x7fffffffffffffff;
const double eps = 1e-10;
unsigned int seed = 19260817;
const unsigned int _RAND_MAX_ = 4294967295u;
__inline__ __attribute__((always_inline)) unsigned int Rand() {
  return seed = seed * 998244353u + 1000000007u;
}
template <typename _Tp>
_Tp gcd(const _Tp &a, const _Tp &b) {
  return (!b) ? a : gcd(b, a % b);
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) _Tp abs(const _Tp &a) {
  return a > 0 ? a : -a;
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) _Tp max(const _Tp &a, const _Tp &b) {
  return a < b ? b : a;
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) _Tp min(const _Tp &a, const _Tp &b) {
  return a < b ? a : b;
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) void chmax(_Tp &a, const _Tp &b) {
  (a < b) && (a = b);
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) void chmin(_Tp &a, const _Tp &b) {
  (a > b) && (a = b);
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) bool _cmp(const _Tp &a,
                                                    const _Tp &b) {
  return abs(a - b) <= eps;
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) void read(_Tp &x) {
  register char ch(getchar());
  bool f(false);
  while (ch < 48 || ch > 57) f |= ch == 45, ch = getchar();
  x = ch & 15, ch = getchar();
  while (ch >= 48 && ch <= 57)
    x = (((x << 2) + x) << 1) + (ch & 15), ch = getchar();
  if (f) x = -x;
}
template <typename _Tp, typename... Args>
__inline__ __attribute__((always_inline)) void read(_Tp &t, Args &...args) {
  read(t);
  read(args...);
}
__inline__ __attribute__((always_inline)) int read_str(char *s) {
  register char ch(getchar());
  while (ch == ' ' || ch == '\r' || ch == '\n') ch = getchar();
  register char *tar = s;
  *tar = ch, ch = getchar();
  while (ch != ' ' && ch != '\r' && ch != '\n' && ch != EOF)
    *(++tar) = ch, ch = getchar();
  return tar - s + 1;
}
const int N = 200005;
struct matrix {
  long long a[3][3];
  __inline__ __attribute__((always_inline)) matrix() {
    memset(a, 0, sizeof(a));
  }
  __inline__ __attribute__((always_inline)) matrix operator*(
      const matrix &o) const {
    matrix c;
    for (int i = 0; i < 3; ++i) {
      for (int k = 0; k < 3; ++k) {
        for (int j = 0; j < 3; ++j) {
          c.a[i][j] += a[i][k] * o.a[k][j];
        }
      }
    }
    return c;
  }
  void print() {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        printf("%lld ", a[i][j]);
      }
      printf("\n");
    }
  }
} f, pw[33];
struct vec {
  long long a[3];
  __inline__ __attribute__((always_inline)) vec() { memset(a, 0, sizeof(a)); }
  __inline__ __attribute__((always_inline)) vec operator*(
      const matrix &o) const {
    vec c;
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        if ((double)c.a[j] + (double)a[k] * o.a[k][j] > 5e18) {
          c.a[j] = INF;
          break;
        }
        c.a[j] += a[k] * o.a[k][j];
      }
    }
    return c;
  }
  __inline__ __attribute__((always_inline)) void print() {
    printf("%lld %lld %lld\n", a[0], a[1], a[2]);
  }
};
long long a[N];
vec cs;
long long k;
bool check(int x) {
  vec tmp = cs;
  for (int i = 30; i >= 0; --i) {
    if ((x >> i) & 1) {
      tmp = tmp * pw[i];
    }
  }
  return tmp.a[0] >= k || tmp.a[1] >= k || tmp.a[2] >= k;
}
int main() {
  int n;
  read(n, k);
  for (int i = 1; i <= n; ++i) read(a[i]);
  int pos = 0;
  while (pos < n && a[pos + 1] == 0) ++pos;
  int m = 0;
  for (int i = pos + 1; i <= n; ++i) {
    a[++m] = a[i];
  }
  n = m;
  for (int i = 1; i <= n; ++i) {
    if (a[i] >= k) {
      printf("0\n");
      return 0;
    }
  }
  if (n > 3) {
    for (int T = 1;; ++T) {
      for (int i = 1; i <= n; ++i) {
        a[i] = a[i - 1] + a[i];
        if (a[i] >= k) {
          printf("%d\n", T);
          return 0;
        }
      }
    }
  }
  if (n == 2) {
    printf("%lld\n", (k - a[2] + a[1] - 1) / a[1]);
    return 0;
  }
  cs.a[0] = a[1], cs.a[1] = a[2], cs.a[2] = a[3];
  f.a[0][0] = f.a[0][1] = f.a[0][2] = f.a[1][1] = f.a[1][2] = f.a[2][2] = 1;
  pw[0] = f;
  for (int i = 1; i <= 30; ++i) pw[i] = pw[i - 1] * pw[i - 1];
  int l = 1, r = 1414213562;
  while (l < r) {
    int mid = ((long long)l + r) >> 1ll;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", l);
  return 0;
}
