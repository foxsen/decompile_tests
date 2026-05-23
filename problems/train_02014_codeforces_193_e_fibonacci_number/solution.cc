#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const int prime = 9241;
long long modulo = (long long)1e13;
long long multiply(long long a, long long b) {
  long long res = 0, v = a;
  while (b) {
    if (b & 1ll) res = res + v;
    if (res >= modulo) res -= modulo;
    v = v + v;
    if (v >= modulo) v -= modulo;
    b >>= 1;
  }
  return res % modulo;
}
struct matr2 {
  long long a, b, c, d;
  matr2() {}
  matr2(long long A, long long B, long long C, long long D)
      : a(A % modulo), b(B % modulo), c(C % modulo), d(D % modulo) {}
};
inline matr2 operator*(const matr2 &A, const matr2 &B) {
  return matr2(multiply(B.a, A.a) + multiply(A.b, B.c),
               multiply(B.b, A.a) + multiply(A.b, B.d),
               multiply(A.c, B.a) + multiply(A.d, B.c),
               multiply(A.c, B.b) + multiply(A.d, B.d));
}
inline matr2 pow(const matr2 &a, long long p) {
  matr2 z = a;
  matr2 res = matr2(1ll, 0ll, 0ll, 1ll);
  while (p) {
    if (p & 1ll) res = res * z;
    z = z * z;
    p >>= 1;
  }
  return res;
}
int m1 = 1953125, m2 = 8192;
long long t1, t2;
int fibsm1[8000005];
int fibsm2[200005];
matr2 mm;
int pos1[10], pos2[10];
int cnt1, cnt2;
long long gcd(long long a, long long b) {
  while (a > 0ll && b > 0ll)
    if (a > b)
      a %= b;
    else
      b %= a;
  return a + b;
}
int main() {
  long long f;
  cin >> f;
  int fm1 = (int)(f % (long long)m1), fm2 = (int)(f % (long long)m2);
  fibsm1[0] = 0ll, fibsm2[0] = 0ll, fibsm1[1] = 1ll, fibsm2[1] = 1ll;
  for (int i = 2;; i++) {
    fibsm1[i] = fibsm1[i - 1] + fibsm1[i - 2];
    if (fibsm1[i] >= m1) fibsm1[i] -= m1;
    if (fibsm1[i - 1] == 0ll && fibsm1[i] == 1ll) {
      t1 = i - 1;
      break;
    }
  }
  for (int i = 2;; i++) {
    fibsm2[i] = fibsm2[i - 1] + fibsm2[i - 2];
    if (fibsm2[i] >= m2) fibsm2[i] -= m2;
    if (fibsm2[i - 1] == 0ll && fibsm2[i] == 1ll) {
      t2 = i - 1;
      break;
    }
  }
  cnt1 = cnt2 = 0;
  for (int i = 0; i < t1; i++)
    if (fm1 == fibsm1[i]) pos1[cnt1++] = i;
  for (int i = 0; i < t2; i++)
    if (fm2 == fibsm2[i]) pos2[cnt2++] = i;
  matr2 zm;
  long long ans = (long long)1e18, t12 = t1 * t2;
  long long diff = t1 * t2 / gcd(t1, t2);
  mm = pow(matr2(0ll, 1ll, 1ll, 1ll), diff);
  for (int i = 0; i < cnt1; i++)
    for (int j = 0; j < cnt2; j++) {
      long long s = -1ll;
      for (long long x = 0; x * t1 <= diff; x++)
        if ((t1 * x + pos1[i] - pos2[j]) % t2 == 0ll) {
          s = x * t1 + pos1[i];
          zm = pow(matr2(0ll, 1ll, 1ll, 1ll), s + 1);
          for (long long it = s; it <= (long long)1.5e13; it += diff) {
            if (zm.a == f) {
              ans = min(ans, it);
              break;
            }
            zm = zm * mm;
          }
        }
    }
  if (ans >= (long long)1e18)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
