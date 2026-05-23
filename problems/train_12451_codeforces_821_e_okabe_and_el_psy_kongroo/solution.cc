#include <bits/stdc++.h>
using namespace std;
const long long base = 1e9 + 7;
long long n, k;
struct line {
  long long a, b, y;
} a[101];
struct matrix {
  long long val[16][16];
  matrix() { memset(val, 0, sizeof(val)); }
};
struct matran {
  long long val[16];
  matran() { memset(val, 0, sizeof(val)); }
};
matrix res, tmp, A;
matran cur;
inline matrix operator*(const matrix &x, const matrix &y) {
  for (int i = 0; i <= 15; i++) {
    for (int j = 0; j <= 15; j++) {
      tmp.val[i][j] = 0;
      for (int p = 0; p <= 15; p++) {
        tmp.val[i][j] =
            (tmp.val[i][j] + (x.val[i][p] * y.val[p][j]) % base) % base;
      }
    }
  }
  return tmp;
}
inline matran operator*(const matrix &x, const matran &y) {
  for (int i = 0; i <= 15; i++) {
    cur.val[i] = 0;
    for (int j = 0; j <= 15; j++) {
      cur.val[i] = (cur.val[i] + (x.val[i][j] * y.val[j]) % base) % base;
    }
  }
  return cur;
}
inline void pw(long long p) {
  if (p == 1) {
    res = A;
    return;
  }
  for (int i = 0; i <= 15; i++) res.val[i][i] = 1;
  for (; p; p /= 2, A = A * A) {
    if (p & 1) res = res * A;
  }
}
matran B, ans;
matrix duc;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].a >> a[i].b >> a[i].y;
  }
  B.val[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 15; j++) {
      if (j > a[i].y) B.val[j] = 0;
    }
    if (a[i].a >= k) break;
    for (int p = 0; p <= 15; p++) {
      for (int q = 0; q <= 15; q++) {
        A.val[p][q] = 0;
      }
    }
    for (int j = a[i].y; j >= 0; j--) {
      if (j + 1 <= a[i].y) A.val[j][j + 1] = 1;
      A.val[j][j] = 1;
      if (j - 1 >= 0) A.val[j][j - 1] = 1;
    }
    memset(res.val, 0, sizeof(res.val));
    if (a[i].b >= k)
      pw(k - a[i].a);
    else
      pw(a[i].b - a[i].a);
    B = res * B;
  }
  cout << B.val[0];
}
