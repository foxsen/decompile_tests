#include <bits/stdc++.h>
using namespace std;
void getre() {
  int x = 0;
  printf("%d\n", 1 / x);
}
void gettle() {
  int res = 1;
  while (1) res <<= 1;
  printf("%d\n", res);
}
template <typename T, typename S>
inline bool upmin(T &a, const S &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T, typename S>
inline bool upmax(T &a, const S &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename N, typename PN>
inline N flo(N a, PN b) {
  return a >= 0 ? a / b : -((-a - 1) / b) - 1;
}
template <typename N, typename PN>
inline N cei(N a, PN b) {
  return a > 0 ? (a - 1) / b + 1 : -(-a / b);
}
template <typename N>
N gcd(N a, N b) {
  return b ? gcd(b, a % b) : a;
}
template <typename N>
inline int sgn(N a) {
  return a > 0 ? 1 : (a < 0 ? -1 : 0);
}
inline void gn(long long &x) {
  int sg = 1;
  char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-')
    ;
  c == '-' ? (sg = -1, x = 0) : (x = c - '0');
  while ((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= sg;
}
inline void gn(int &x) {
  long long t;
  gn(t);
  x = t;
}
inline void gn(unsigned long long &x) {
  long long t;
  gn(t);
  x = t;
}
inline void gn(double &x) {
  double t;
  scanf("%lf", &t);
  x = t;
}
inline void gn(long double &x) {
  double t;
  scanf("%lf", &t);
  x = t;
}
inline void gs(char *s) { scanf("%s", s); }
inline void gc(char &c) {
  while ((c = getchar()) > 126 || c < 33)
    ;
}
inline void pc(char c) { putchar(c); }
inline long long sqr(long long a) { return a * a; }
inline double sqrf(double a) { return a * a; }
const int inf = 0x3f3f3f3f;
const double pi = 3.14159265358979323846264338327950288L;
const double eps = 1e-6;
const int mo = 1e9 + 7;
int qp(int a, long long b) {
  int n = 1;
  do {
    if (b & 1) n = 1ll * n * a % mo;
    a = 1ll * a * a % mo;
  } while (b >>= 1);
  return n;
}
int memo[777][10];
int memo2[777][10];
int fac[4444];
int ifac[4444];
char s[777];
int po[11][777];
int invpo[11][777];
int n;
int main() {
  for (int d = (0), _ed = (11); d < _ed; d++) {
    po[d][0] = 1;
    for (int i = (1), _ed = (777); i < _ed; i++)
      po[d][i] = 1ll * po[d][i - 1] * d % mo;
    for (int i = (0), _ed = (777); i < _ed; i++)
      invpo[d][i] = qp(po[d][i], mo - 2);
  }
  gs(s + 1);
  n = strlen(s + 1);
  fac[0] = 1;
  for (int i = (1), _ed = (4444); i < _ed; i++)
    fac[i] = 1ll * fac[i - 1] * i % mo;
  for (int i = (0), _ed = (4444); i < _ed; i++) ifac[i] = qp(fac[i], mo - 2);
  for (int d = (0), _ed = (10); d < _ed; d++)
    for (int a = (0), _ed = (n + 1); a < _ed; a++)
      for (int b = 0; b + a <= n; b++) {
        (((memo[a + b][d]) = ((memo[a + b][d]) +
                              (1ll * ifac[a] * ifac[b] % mo * invpo[d][a + b] %
                               mo * po[9 - d][b] % mo * po[10][b] % mo *
                               (po[10][a]) % mo * invpo[9][1] % mo * d % mo)) %
                             mo) < 0
             ? (memo[a + b][d]) += mo
             : (memo[a + b][d]));
        (((memo2[a + b][d]) = ((memo2[a + b][d]) +
                               (1ll * ifac[a] * ifac[b] % mo * invpo[d][a + b] %
                                mo * po[9 - d][b] % mo * po[10][b] % mo * (-1) %
                                mo * invpo[9][1] % mo * d % mo)) %
                              mo) < 0
             ? (memo2[a + b][d]) += mo
             : (memo2[a + b][d]));
      }
  int tot = 0;
  for (int t = 1; t <= n; t++) {
    int nex = s[t] - '0';
    if (t != n) nex--;
    for (int da = 0; da <= nex; da++) {
      int num[10] = {0};
      for (int j = 1; j <= t - 1; j++) num[s[j] - '0']++;
      num[da]++;
      for (int d = 1; d <= 9; d++) {
        int L = n - t;
        int p = num[d];
        int q = 0;
        for (int tt = d + 1; tt <= 9; tt++) q += num[tt];
        for (int ab = 0; ab <= L; ab++) {
          int temp = (1ll * memo[ab][d] * po[10][p] + memo2[ab][d]) % mo;
          (((temp) = 1ll * (temp) * (po[d][L]) % mo) < 0 ? (temp) += mo
                                                         : (temp));
          (((temp) = 1ll * (temp) * (fac[L]) % mo) < 0 ? (temp) += mo : (temp));
          (((temp) = 1ll * (temp) * (ifac[L - ab]) % mo) < 0 ? (temp) += mo
                                                             : (temp));
          (((temp) = 1ll * (temp) * (po[10][q]) % mo) < 0 ? (temp) += mo
                                                          : (temp));
          (((tot) = ((tot) + (temp)) % mo) < 0 ? (tot) += mo : (tot));
        }
      }
    }
  }
  printf("%d\n", tot);
  return 0;
}
