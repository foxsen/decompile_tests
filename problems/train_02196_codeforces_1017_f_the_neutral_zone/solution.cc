#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const double pi = acos(-1.0);
const int maxn = 100000 + 10;
const int mod = 1e9 + 7;
inline char _getchar() {
  static const int BUFSIZE = 100001;
  static char buf[BUFSIZE];
  static char *psta = buf, *pend = buf;
  if (psta >= pend) {
    psta = buf;
    pend = buf + fread(buf, 1, BUFSIZE, stdin);
    if (psta >= pend) return -1;
  }
  return *psta++;
}
inline int read(int &x) {
  x = 0;
  int f = 1;
  char ch = _getchar();
  while ((ch < '0' || ch > '9') && ~ch) {
    if (ch == '-') f = -1;
    ch = _getchar();
  }
  if (ch == -1) return -1;
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = _getchar();
  }
  x *= f;
  return 1;
}
inline int read(long long &x) {
  x = 0;
  int f = 1;
  char ch = _getchar();
  while ((ch < '0' || ch > '9') && ~ch) {
    if (ch == '-') f = -1;
    ch = _getchar();
  }
  if (ch == -1) return -1;
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = _getchar();
  }
  x *= f;
  return 1;
}
inline int read(double &x) {
  char in;
  double Dec = 0.1;
  bool IsN = false, IsD = false;
  in = _getchar();
  if (in == EOF) return -1;
  while (in != '-' && in != '.' && (in < '0' || in > '9')) in = _getchar();
  if (in == '-') {
    IsN = true;
    x = 0;
  } else if (in == '.') {
    IsD = true;
    x = 0;
  } else
    x = in - '0';
  if (!IsD) {
    while (in = _getchar(), in >= '0' && in <= '9') {
      x *= 10;
      x += in - '0';
    }
  }
  if (in != '.') {
    if (IsN) x = -x;
    return 1;
  } else {
    while (in = _getchar(), in >= '0' && in <= '9') {
      x += Dec * (in - '0');
      Dec *= 0.1;
    }
  }
  if (IsN) x = -x;
  return 1;
}
inline int read(float &x) {
  char in;
  double Dec = 0.1;
  bool IsN = false, IsD = false;
  in = _getchar();
  if (in == EOF) return -1;
  while (in != '-' && in != '.' && (in < '0' || in > '9')) in = _getchar();
  if (in == '-') {
    IsN = true;
    x = 0;
  } else if (in == '.') {
    IsD = true;
    x = 0;
  } else
    x = in - '0';
  if (!IsD) {
    while (in = _getchar(), in >= '0' && in <= '9') {
      x *= 10;
      x += in - '0';
    }
  }
  if (in != '.') {
    if (IsN) x = -x;
    return 1;
  } else {
    while (in = _getchar(), in >= '0' && in <= '9') {
      x += Dec * (in - '0');
      Dec *= 0.1;
    }
  }
  if (IsN) x = -x;
  return 1;
}
inline int read(char *x) {
  char *tmp = x;
  char in = _getchar();
  while (in <= ' ' && in != EOF) in = _getchar();
  if (in == -1) return -1;
  while (in > ' ') *(tmp++) = in, in = _getchar();
  *tmp = '\0';
  return 1;
}
typedef unsigned int ui;
int p[17000];
int n, A, B, C, D;
ui f(int x) { return A * x * x * x + B * x * x + C * x + D; }
inline ui Count(int i) {
  ui ans = 0;
  int t = 0;
  long long x = 1;
  while (x * i <= n) x *= i, t++;
  ui pre = 0;
  while (t) {
    ui no = n / x * f(i);
    ans += t * (no - pre);
    pre += no - pre;
    t--;
    x /= i;
  }
  return ans;
}
int main() {
  scanf("%d%d%d%d%d", &n, &A, &B, &C, &D);
  int tot = 0;
  for (int i = 2; i * i <= n; i++) {
    int flag = 0;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        flag = 1;
        break;
      }
    }
    if (!flag) p[tot++] = i;
  }
  ui ans = 0;
  ans += Count(2);
  ans += Count(3);
  for (int i = 5, f = 2; i <= n; i = i + f, f = 6 - f) {
    ans += Count(i);
  }
  for (int i = 5, f = 2; i <= n; i = i + f, f = 6 - f) {
    for (int j = 2; j < tot; j++) {
      if (1LL * i * p[j] > n) break;
      ans -= Count(i * p[j]);
      if (i % p[j] == 0) break;
    }
  }
  printf("%u", ans);
  return 0;
}
