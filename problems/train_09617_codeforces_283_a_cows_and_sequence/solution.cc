#include <bits/stdc++.h>
using namespace std;
inline int min(const int &x, const int &y) { return x < y ? x : y; }
inline long long min(const long long &x, const long long &y) {
  return x < y ? x : y;
}
inline double min(const double &x, const double &y) { return x < y ? x : y; }
inline int max(const int &x, const int &y) { return x > y ? x : y; }
inline long long max(const long long &x, const long long &y) {
  return x > y ? x : y;
}
inline double max(const double &x, const double &y) { return x > y ? x : y; }
template <class T>
inline void _updmin(T &x, const T &y) {
  if (x > y) x = y;
}
template <class T>
inline void _updmax(T &x, const T &y) {
  if (x < y) x = y;
}
template <class T>
inline T _lowbit(const T &x) {
  return (x ^ (x - 1)) & x;
}
template <class T>
inline int _bitsize(const T &x) {
  return (x == 0) ? 0 : (1 + _bitsize(x & (x - 1)));
}
const double _pi = acos(-1.0);
const double _eps = 1e-5;
template <class T>
inline T _sqr(const T &x) {
  return x * x;
}
template <class T>
inline T _gcd(const T &x, const T &y) {
  if (x < 0) return _gcd(-x, y);
  if (y < 0) return _gcd(x, -y);
  return (y == 0) ? x : _gcd(y, x % y);
}
template <class T>
inline T _lcm(const T &x, const T &y) {
  if (x < 0) return _lcm(-x, y);
  if (y < 0) return _lcm(x, -y);
  return x * (y / _gcd(x, y));
}
template <class T>
inline T _euc(const T &a, const T &b, T &x, T &y) {
  if (a < 0) {
    T d = _euc(-a, b, x, y);
    x = -x;
    return d;
  }
  if (b < 0) {
    T d = _euc(a, -b, x, y);
    y = -y;
    return d;
  }
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    T d = _euc(b, a % b, x, y);
    T t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
  }
}
template <class T>
inline vector<pair<T, int> > _fac(T n) {
  vector<pair<T, int> > ret;
  for (T i = 2; n > 1;) {
    if (n % i == 0) {
      int cnt = 0;
      for (; n % i == 0; cnt++, n /= i)
        ;
      ret.push_back(make_pair(i, cnt));
    }
    i++;
    if (i > n / i) i = n;
  }
  if (n > 1) ret.push_back(make_pair(n, 1));
  return ret;
}
template <class T>
inline int _prm(const T &x) {
  if (x <= 1) return 0;
  for (T i = 2; sqr(i) <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
template <class T>
inline T _phi(T x) {
  vector<pair<T, int> > f = _fac(x);
  T ret = x;
  for (int i = 0; i < ((int)(f.size())); i++)
    ret = ret / f[i].first * (f[i].first - 1);
  return ret;
}
template <class T>
inline T _inv(T a, T b) {
  T x, y;
  _euc(a, b, x, y);
  if (x == 0) x = 1;
  return x;
}
template <class T>
inline T _cmod(T x, T m) {
  return (x % m + m) % m;
}
template <class T>
inline T _mmod(T x, T y, T m) {
  return (
      T)((((long long)x) * ((long long)y) % ((long long)m) + ((long long)m)) %
         ((long long)m));
}
template <class T>
inline T _pmod(T x, T y, T m) {
  if (y == 0)
    return 1 % m;
  else if ((y & 1) == 0) {
    T z = _pmod(x, y >> 1, m);
    return _mmod(z, z, m);
  } else
    return _mmod(_pmod(x, y ^ 1, m), x, m);
}
const int _MTRXSIZE = 40;
template <class T>
inline void _shwMTRX(int n, T A[_MTRXSIZE][_MTRXSIZE]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << A[i][j] << " ";
    cout << endl;
  }
}
template <class T>
inline void _stdMTRX(int n, T A[_MTRXSIZE][_MTRXSIZE]) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) A[i][j] = (i == j) ? 1 : 0;
}
template <class T>
inline void _addMTRX(int n, T C[_MTRXSIZE][_MTRXSIZE],
                     T A[_MTRXSIZE][_MTRXSIZE], T B[_MTRXSIZE][_MTRXSIZE]) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) C[i][j] = A[i][j] + B[i][j];
}
template <class T>
inline void _subMTRX(int n, T C[_MTRXSIZE][_MTRXSIZE],
                     T A[_MTRXSIZE][_MTRXSIZE], T B[_MTRXSIZE][_MTRXSIZE]) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) C[i][j] = A[i][j] - B[i][j];
}
template <class T>
inline void _mulMTRX(int n, T C[_MTRXSIZE][_MTRXSIZE],
                     T _A[_MTRXSIZE][_MTRXSIZE], T _B[_MTRXSIZE][_MTRXSIZE]) {
  T A[_MTRXSIZE][_MTRXSIZE], B[_MTRXSIZE][_MTRXSIZE];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      A[i][j] = _A[i][j];
      B[i][j] = _B[i][j];
      C[i][j] = 0;
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++) C[i][j] += A[i][k] * B[k][j];
}
template <class T>
inline void _addModMTRX(int n, T m, T C[_MTRXSIZE][_MTRXSIZE],
                        T A[_MTRXSIZE][_MTRXSIZE], T B[_MTRXSIZE][_MTRXSIZE]) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) C[i][j] = _cmod(A[i][j] + B[i][j], m);
}
template <class T>
inline void _subModMTRX(int n, T m, T C[_MTRXSIZE][_MTRXSIZE],
                        T A[_MTRXSIZE][_MTRXSIZE], T B[_MTRXSIZE][_MTRXSIZE]) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) C[i][j] = _cmod(A[i][j] - B[i][j], m);
}
template <class T>
inline void _mulModMTRX(int n, T m, T C[_MTRXSIZE][_MTRXSIZE],
                        T _A[_MTRXSIZE][_MTRXSIZE],
                        T _B[_MTRXSIZE][_MTRXSIZE]) {
  T A[_MTRXSIZE][_MTRXSIZE], B[_MTRXSIZE][_MTRXSIZE];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      A[i][j] = _A[i][j];
      B[i][j] = _B[i][j];
      C[i][j] = 0;
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        C[i][j] = (C[i][j] + _mmod(A[i][k], B[k][j], m)) % m;
}
template <class T>
inline void _powModMTRX(int n, T y, T m, T C[_MTRXSIZE][_MTRXSIZE],
                        T X[_MTRXSIZE][_MTRXSIZE]) {
  T R[_MTRXSIZE][_MTRXSIZE];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) R[i][j] = X[i][j];
  _stdMTRX(n, C);
  if (y > 0)
    for (T i = 1;; i <<= 1) {
      if (y & i) _mulModMTRX(n, m, C, C, R);
      _mulModMTRX(n, m, R, R, R);
      if (i > (y >> 1)) break;
    }
}
template <class T>
struct _frct {
  T a, b;
  _frct(T a = 0, T b = 1);
  string toString();
};
template <class T>
_frct<T>::_frct(T a, T b) {
  T d = _gcd(a, b);
  a /= d;
  b /= d;
  if (b < 0) a = -a, b = -b;
  this->a = a;
  this->b = b;
}
template <class T>
string _frct<T>::toString() {
  ostringstream tout;
  tout << a << "/" << b;
  return tout.str();
}
template <class T>
_frct<T> operator+(_frct<T> p, _frct<T> q) {
  return _frct<T>(p.a * q.b + q.a * p.b, p.b * q.b);
}
template <class T>
_frct<T> operator-(_frct<T> p, _frct<T> q) {
  return _frct<T>(p.a * q.b - q.a * p.b, p.b * q.b);
}
template <class T>
_frct<T> operator*(_frct<T> p, _frct<T> q) {
  return _frct<T>(p.a * q.a, p.b * q.b);
}
template <class T>
_frct<T> operator/(_frct<T> p, _frct<T> q) {
  return _frct<T>(p.a * q.b, p.b * q.a);
}
int n, m;
double sum;
double opt[1100000];
int main() {
  while (scanf("%d", &n) != EOF) {
    sum = 0.0;
    m = 1;
    memset(opt, 0, sizeof(opt));
    for (int i = 0; i < n; i++) {
      int x, y, t;
      scanf("%d", &t);
      switch (t) {
        case 1:
          scanf("%d%d", &x, &y);
          opt[x] += (double)y;
          sum += ((double)x) * ((double)y);
          break;
        case 2:
          scanf("%d", &x);
          opt[m] -= (double)x;
          opt[++m] = (double)x;
          sum += ((double)x);
          break;
        case 3:
          sum -= opt[m];
          opt[m - 1] += opt[m];
          opt[m] = 0.0;
          m--;
          break;
      }
      printf("%.8f\n", sum / m);
    }
  }
  return 0;
}
