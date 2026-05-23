#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, M = 2e5, mod = 1000000007, inf = 1000000007;
const long long lmod = 1000000007, linf = 1e18 + 77;
const long double eps = 1e-14;
inline void oi(int x) {
  if (x == 0) {
    putchar('0');
    return;
  }
  char c[10];
  int k = 0;
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  while (x) {
    int nx = x / 10;
    c[k++] = x - nx * 10;
    x = nx;
  }
  while (k--) {
    putchar(c[k] + '0');
  }
}
inline void ol(long long x) {
  char c[19];
  int cc = 0;
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  while (x) {
    long long nx = x / 10;
    c[cc++] = x - nx * 10;
    x = nx;
  }
  while (cc--) {
    putchar(c[cc] + '0');
  }
}
inline void gi(int& val) {
  char c;
  do {
    c = getchar();
  } while (c < '0' || c > '9');
  if (c == '-') {
    val = -1;
  } else {
    val = c - '0';
  }
  c = getchar();
  while (c >= '0' && c <= '9') {
    val *= 10;
    val += c - '0';
    c = getchar();
  }
}
inline void gl(long long& val) {
  char c;
  do {
    c = getchar();
  } while (c < '0' || c > '9');
  if (c == '-') {
    val = -1;
  } else {
    val = c - '0';
  }
  c = getchar();
  while (c >= '0' && c <= '9') {
    val *= 10;
    val += c - '0';
    c = getchar();
  }
}
inline void gl(long long& val1, long long& val2) {
  gl(val1);
  gl(val2);
}
inline void gl(long long& val1, long long& val2, long long& val3) {
  gl(val1);
  gl(val2);
  gl(val3);
}
long long len(long long x) {
  int k = 0;
  long long ret = 1;
  while (x) {
    ret *= 2;
    x /= 2;
  }
  return ret - 1;
}
int gb(long long pos, long long l, long long r, long long x) {
  long long mid = (l + r) / 2;
  if (pos == mid) {
    return x % 2;
  } else {
    if (pos < mid) {
      return gb(pos, l, mid - 1, x / 2);
    } else {
      return gb(pos, mid + 1, r, x / 2);
    }
  }
}
int main() {
  long long n, l, r;
  gl(n, l, r);
  if (n < 2) {
    oi(n);
    return 0;
  }
  int ans = 0;
  for (long long i = l; i <= r; i++) {
    ans += gb(i, 1, len(n), n);
  }
  oi(ans);
}
