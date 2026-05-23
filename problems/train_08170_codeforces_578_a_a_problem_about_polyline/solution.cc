#include <bits/stdc++.h>
using namespace std;
void _r(const int& x) { scanf("%d", &x); }
void _r(const long long& x) { scanf("%I64d", &x); }
void _r(const char* x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(const T& head, const U&... tail) {
  _r(head);
  R(tail...);
}
void _w(const char x) { putchar(x); }
void _w(const char* x) { printf("%s", x); }
void _w(const int x) { printf("%d", x); }
void _w(const long long x) { printf("%I64d", x); }
void _w(const double x) { printf("%.12f", x); }
void W() {}
template <class T, class... U>
void W(const T& head, const U&... tail) {
  _w(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
const long long mod = 1e9 + 7;
long long fp1(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    b >>= 1;
    a *= a;
  }
  return ans;
}
long long fp2(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return ans;
}
long long Read() {
  long long res = 0, flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    res = res * 10 + ch - '0';
    ch = getchar();
  }
  return res * flag;
}
const int N = 2e5 + 5;
int main() {
  int a, b;
  while (~scanf("%d %d", &a, &b)) {
    if (a < b)
      W("-1");
    else if (a == b)
      W((double)1.0 * a);
    else {
      double y;
      if ((a / b) & 1) {
        y = b * 1.0 / (a + b) * (a / b + 1);
      } else {
        y = b * 1.0 / (a + b) * (a / b);
      }
      W((double)b / y);
    }
  }
  return 0;
}
