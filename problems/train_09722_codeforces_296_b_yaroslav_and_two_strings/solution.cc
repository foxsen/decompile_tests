#include <bits/stdc++.h>
using namespace std;
const int32_t Accepted = 0;
template <typename T>
void in(T& x) {
  static char ch;
  static bool neg;
  for (ch = neg = 0; ch < '0' || '9' < ch; neg |= ch == '-', ch = getchar())
    ;
  for (x = 0; '0' <= ch && ch <= '9'; (x *= 10) += ch - '0', ch = getchar())
    ;
  x = neg ? -x : x;
}
template <typename T, typename... Types>
void in(T& x, Types&... oth) {
  static char ch;
  static bool neg;
  for (ch = neg = 0; ch < '0' || '9' < ch; neg |= ch == '-', ch = getchar())
    ;
  for (x = 0; '0' <= ch && ch <= '9'; (x *= 10) += ch - '0', ch = getchar())
    ;
  x = neg ? -x : x;
  in(oth...);
}
template <typename T>
T _pow_mod(T a, T b, T mod) {
  T base = a, res = 1;
  while (b) {
    if (b & 1) res = (res * base) % mod;
    base = (base * base) % mod;
    b >>= 1;
  }
  return res;
}
template <typename T>
T _pow(T a, T b) {
  T base = a, res = 1;
  while (b) {
    if (b & 1) res = (res * base);
    base = (base * base);
    b >>= 1;
  }
  return res;
}
template <typename T>
void out(T x) {
  char s[65];
  int32_t cnt = 0;
  if (x > 0)
    while (x > 0) s[cnt++] = (x - (x / 10 * 10)) + '0', x /= 10;
  else if (x < 0) {
    while (x < 0) s[cnt++] = (x / 10 * 10) - x + '0', x /= 10;
    s[cnt++] = '-';
  }
  if (cnt == 0)
    putchar('0');
  else
    for (int32_t i = cnt - 1; ~i; i--) putchar(s[i]);
}
template <typename T>
void print(T x) {
  out(x);
  putchar('\n');
}
template <typename T, typename... types>
void print(T x, types... oth) {
  out(x);
  putchar(' ');
  print(oth...);
}
constexpr int maxn = 1e5 + 10;
constexpr int mod = 1e9 + 7;
long long dp[maxn][2][2];
char a[maxn], b[maxn];
int32_t main() {
  int n;
  in(n);
  scanf("%s%s", a + 1, b + 1);
  for (int i = 1; i <= n; i++) {
    if (isdigit(a[i])) a[i] -= '0';
    if (isdigit(b[i])) b[i] -= '0';
  }
  dp[0][0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= 1; j++)
      for (int k = 0; k <= 1; k++) {
        if (a[i] == '?' && b[i] == '?') {
          dp[i][j | 1][k] += 45 * dp[i - 1][j][k];
          dp[i][j | 1][k] %= mod;
          dp[i][j][k | 1] += 45 * dp[i - 1][j][k];
          dp[i][j][k | 1] %= mod;
          dp[i][j][k] += 10 * dp[i - 1][j][k];
          dp[i][j][k] %= mod;
        } else if (a[i] == '?') {
          dp[i][j | 1][k] += (9 - b[i]) * dp[i - 1][j][k];
          dp[i][j | 1][k] %= mod;
          dp[i][j][k | 1] += b[i] * dp[i - 1][j][k];
          dp[i][j][k | 1] %= mod;
          dp[i][j][k] += dp[i - 1][j][k];
          dp[i][j][k] %= mod;
        } else if (b[i] == '?') {
          dp[i][j | 1][k] += a[i] * dp[i - 1][j][k];
          dp[i][j | 1][k] %= mod;
          dp[i][j][k | 1] += (9 - a[i]) * dp[i - 1][j][k];
          dp[i][j][k | 1] %= mod;
          dp[i][j][k] += dp[i - 1][j][k];
          dp[i][j][k] %= mod;
        } else {
          if (a[i] > b[i])
            dp[i][j | 1][k] += dp[i - 1][j][k], dp[i][j][k] %= mod;
          else if (a[i] < b[i])
            dp[i][j][k | 1] += dp[i - 1][j][k], dp[i][j][k] %= mod;
          else
            dp[i][j][k] += dp[i - 1][j][k], dp[i][j][k] %= mod;
        }
      }
  print(dp[n][1][1]);
  return Accepted;
}
