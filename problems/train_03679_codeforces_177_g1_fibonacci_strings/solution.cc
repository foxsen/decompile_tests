#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-const-variable"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const int MOD = 1e9 + 7;
const int MAXN = 2000005;
struct Matrix {
  int num[4][4];
  int n, m;
  Matrix(int nn, int mm) {
    n = nn;
    m = mm;
    memset(num, 0, sizeof(num));
  }
  Matrix(int nn) {
    n = m = nn;
    memset(num, 0, sizeof(num));
    for (int i = 0; i < nn; i++) num[i][i] = 1;
  }
  Matrix operator*(const Matrix y) const {
    Matrix x = *this, ans(x.n, y.m);
    if (x.m != y.n) return ans;
    for (int i = 0; i < x.n; i++) {
      for (int j = 0; j < y.m; j++) {
        for (int k = 0; k < x.m; k++) {
          ans.num[i][j] =
              (ans.num[i][j] + 1LL * x.num[i][k] * y.num[k][j] % MOD) % MOD;
        }
      }
    }
    return ans;
  }
};
Matrix binpow(Matrix x, long long y) {
  Matrix r(x.n);
  while (y) {
    if (y & 1) r = r * x;
    x = x * x;
    y >>= 1;
  }
  return r;
}
long long binpow(long long x, long long y, int m) {
  long long r = 1 % m;
  while (y) {
    if (y & 1) r = r * x % m;
    x = x * x % m;
    y >>= 1;
  }
  return r;
}
int nxt[MAXN];
char s[MAXN], s1[MAXN], s2[MAXN];
char *t1 = s1, *t2 = s2;
int kmp(char *s1, char *s2, int *nxt) {
  int n = strlen(s1), m = strlen(s2);
  nxt[0] = -1;
  for (int i = 1, k = -1; i <= m; i++) {
    while (~k && s2[k] != s2[i - 1]) k = nxt[k];
    nxt[i] = ++k;
  }
  int cnt = 0;
  for (int i = 1, k = 0; i <= n; i++) {
    while (~k && s2[k] != s1[i - 1]) k = nxt[k];
    if (m == ++k) cnt++;
  }
  return cnt;
}
void solve() {
  long long kk;
  int m;
  scanf("%lld %d", &kk, &m);
  kk--;
  for (int i = 1; i <= m; i++) {
    scanf("%s", s);
    int len = strlen(s);
    t1[0] = 'a';
    t1[1] = 0;
    t2[0] = 'b';
    t2[1] = 0;
    int l1 = 1, l2 = 1;
    long long k = kk;
    while (l1 < len && k--) {
      for (int j = 0; j <= l1; j++) t2[l2 + j] = t1[j];
      for (int j = 0; j < l2; j++) t1[j] = t2[j];
      t1[l2] = 0;
      swap(l1, l2);
      l2 += l1;
    }
    if (l1 < len) {
      printf("0\n");
    } else {
      int x1 = kmp(t1, s, nxt);
      int x2 = kmp(t2, s, nxt);
      for (int i = 0; i < len - 1; i++) t1[i] = t1[l1 - len + i + 1];
      for (int i = 0; i < len - 1; i++) t1[len - 1 + i] = t2[i];
      for (int i = 0; i < len - 1; i++) t2[i] = t2[l2 - len + i + 1];
      for (int i = 0; i < len - 1; i++) t2[len - 1 + i] = t1[len - 1 + i];
      t1[2 * len - 2] = t2[2 * len - 2] = 0;
      int ba = kmp(t1, s, nxt);
      int ca = kmp(t2, s, nxt);
      int a = 1LL * (ba + ca) % MOD * binpow(2, MOD - 2, MOD) % MOD;
      int b = 1LL * (ba - ca + MOD) % MOD * binpow(2, MOD - 2, MOD) % MOD;
      Matrix x(4, 4);
      x.num[1][0] = x.num[0][1] = x.num[1][1] = x.num[2][2] = 1;
      x.num[2][1] = a;
      x.num[3][1] = b;
      x.num[3][3] = MOD - 1;
      x = binpow(x, k);
      Matrix y(1, 4);
      y.num[0][0] = x1;
      y.num[0][1] = x2;
      y.num[0][2] = 1;
      y.num[0][3] = MOD - 1;
      printf("%d\n", (y * x).num[0][0]);
    }
  }
}
int main() {
  int T = 1, cas = 1;
  (void)(cas);
  while (T--) {
    solve();
  }
  return 0;
}
