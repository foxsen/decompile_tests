#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const long long INFL = LLONG_MAX;
const long double pi = acos(-1);
long long M;
long long H[10];
long long A[10];
long long X[10];
long long Y[10];
long long P[10];
long long Q[10];
long long tmp[10];
long long gcd(long long a, long long b) {
  while (b != 0) {
    long long tmp = a % b;
    a = b;
    b = tmp;
  }
  return a;
}
pair<long long, long long> euclid(long long a, long long b) {
  if (a == 0) {
    assert(b == 1);
    return make_pair(0, 1);
  }
  if (b == 0) {
    assert(a == 1);
    return make_pair(1, 1);
  }
  long long aa = b;
  long long bb = a % b;
  long long p, q;
  pair<long long, long long> rec = euclid(aa, bb);
  long long pp = rec.first;
  long long qq = rec.second;
  p = qq;
  q = pp - (a / b) * qq;
  assert(p * a + q * b == 1);
  return make_pair(p, q);
}
long long inv(long long a, long long mod) {
  a %= mod;
  pair<long long, long long> res = euclid(a, mod);
  long long p = res.first;
  long long q = res.second;
  return p;
}
int main() {
  ios_base::sync_with_stdio(0);
  cout.precision(15);
  cout << fixed;
  cout.tie(0);
  cin.tie(0);
  cin >> M;
  for (int(i) = 1, j123 = 2; (i) <= j123; (i)++)
    cin >> H[i] >> A[i] >> X[i] >> Y[i];
  for (int(i) = 1, j123 = 2; (i) <= j123; (i)++) tmp[i] = H[i];
  for (int(day) = 1, j123 = M + 10; (day) <= j123; (day)++) {
    for (int(i) = 1, j123 = 2; (i) <= j123; (i)++)
      tmp[i] = (X[i] * tmp[i] + Y[i]) % M;
    if (tmp[1] == A[1] && tmp[2] == A[2]) {
      cout << day << '\n';
      return 0;
    }
    for (int(i) = 1, j123 = 2; (i) <= j123; (i)++)
      if (tmp[i] == A[i] && P[i] == 0) {
        P[i] = day;
      }
  }
  for (int(i) = 1, j123 = 2; (i) <= j123; (i)++) tmp[i] = A[i];
  for (int(day) = 1, j123 = M + 10; (day) <= j123; (day)++) {
    for (int(i) = 1, j123 = 2; (i) <= j123; (i)++)
      tmp[i] = (X[i] * tmp[i] + Y[i]) % M;
    for (int(i) = 1, j123 = 2; (i) <= j123; (i)++)
      if (tmp[i] == A[i] && Q[i] == 0) {
        Q[i] = day;
      }
  }
  for (int(i) = 1, j123 = 2; (i) <= j123; (i)++) {
    if (P[i] == 0 || Q[i] == 0) {
      cout << -1 << '\n';
      return 0;
    }
  }
  long long g = gcd(Q[1], Q[2]);
  if ((P[1] - P[2]) % g != 0) {
    cout << -1 << '\n';
    return 0;
  }
  long long kk2 = inv(Q[2] / g, Q[1] / g);
  long long k2 = ((P[1] - P[2]) / g) * kk2;
  long long k1 = (P[2] - P[1] + k2 * Q[2]) / Q[1];
  assert(P[1] + k1 * Q[1] == P[2] + k2 * Q[2]);
  while (k1 < 0 || k2 < 0) {
    k1 += Q[2] / g;
    k2 += Q[1] / g;
  }
  while (k1 - Q[2] / g >= 0 && k2 - Q[1] / g >= 0) {
    k1 -= Q[2] / g;
    k2 -= Q[1] / g;
  }
  assert(P[1] + k1 * Q[1] == P[2] + k2 * Q[2]);
  cout << P[1] + k1 * Q[1] << '\n';
}
