#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
namespace Dup4 {
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar()) f ^= (c == '-');
  for (; isdigit(c); c = getchar()) x = x * 10 + (c - '0');
  return x * (f ? 1 : -1);
}
template <typename T>
inline void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar()) f ^= (c == '-');
  for (; isdigit(c); c = getchar()) x = x * 10 + (c - '0');
  x *= f ? 1 : -1;
}
template <typename T>
inline void out(T x) {
  if (!x) {
    putchar(48);
    return;
  }
  if (x < 0) x = -x, putchar('-');
  int bit[20], i, p = 0;
  for (; x; x /= 10) bit[++p] = x % 10;
  for (i = p; i; --i) putchar(bit[i] + 48);
}
template <typename T>
inline void output(T x) {
  out(x), putchar('\n');
}
template <typename T>
inline T gcd(T a, T b) {
  while (b ^= a ^= b ^= a %= b)
    ;
  return a;
}
const double PI = acos(-1.0);
const double EI = exp(1.0);
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const long long INFLL = 0x3f3f3f3f3f3f3f3fll;
}  // namespace Dup4
using namespace Dup4;
namespace FastIO {
bool IOerror = false;
inline char NC() {
  static char buf[10000005], *p1 = buf + 10000005, *pend = buf + 10000005;
  if (p1 == pend) {
    p1 = buf;
    pend = buf + fread(buf, 1, 10000005, stdin);
    if (pend == p1) {
      IOerror = true;
      return -1;
    }
  }
  return *p1++;
}
inline bool blank(char ch) {
  return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
inline void __read(char &x) {
  char ch;
  while (blank(ch = NC()))
    ;
  if (IOerror) {
    x = -1;
    return;
  }
  x = ch;
}
template <typename T>
inline void __read(T &x) {
  char ch;
  while (blank(ch = NC()))
    ;
  if (IOerror) {
    x = -1;
    return;
  }
  bool flag = false;
  if (ch == '-') {
    flag = true;
    ch = NC();
  }
  if (!isdigit(ch))
    while (!isdigit(ch = NC()))
      ;
  for (x = ch - '0'; isdigit(ch = NC()); x = x * 10 + ch - '0')
    ;
  if (flag) x *= -1;
}
}  // namespace FastIO
using namespace FastIO;
const int maxn = (int)5e3 + 10;
const int Maxn = (int)1e6 + 10;
const int MOD = (int)1e9 + 7;
string s;
inline void Solve() {
  int len = s.size(), ans = 0;
  for (int i = 0; i < len; i++) {
    int l = 0, mid = 0;
    for (int j = i; j < len; j++) {
      if (s[j] == '(')
        l++;
      else if (s[j] == ')')
        l--;
      else
        l--, mid++;
      if (!l) ans++;
      if (l < 0 && mid) l += 2, mid--;
      if (l < 0 && !mid) break;
    }
  }
  output(ans);
}
inline void Run() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  while (cin >> s) Solve();
}
int main() {
  Run();
  return 0;
}
