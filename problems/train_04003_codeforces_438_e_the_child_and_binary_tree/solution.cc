#include <bits/stdc++.h>
namespace CTL {
using namespace std;
struct MultiplicativeInverseOfPolynomial {
  static long long pow(long long a, long long b, long long c) {
    long long r = 1;
    for (; b; b& 1 ? r = r * a % c : 0, b >>= 1, a = a * a % c)
      ;
    return r;
  }
  static void ntt(vector<long long>& a, int n, int s, vector<int>& rev,
                  long long p, long long g) {
    g = s == 1 ? g : pow(g, p - 2, p);
    vector<long long> wm;
    for (int i = 0; 1 << i <= n; ++i) wm.push_back(pow(g, (p - 1) >> i, p));
    for (int i = 0; i < n; ++i)
      if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int i = 1, m = 1 << i; 1 << i <= n; ++i, m = 1 << i) {
      vector<long long> wmk(1, 1);
      for (int k = 1; k < (m >> 1); ++k) wmk.push_back(wmk.back() * wm[i] % p);
      for (int j = 0; j < n; j += m)
        for (int k = 0; k < (m >> 1); ++k) {
          long long u = a[j + k], v = wmk[k] * a[j + k + (m >> 1)] % p;
          a[j + k] = u + v;
          a[j + k + (m >> 1)] = u - v + p;
          if (a[j + k] >= p) a[j + k] -= p;
          if (a[j + k + (m >> 1)] >= p) a[j + k + (m >> 1)] -= p;
        }
    }
  }
  static vector<long long> run(vector<long long> a,
                               long long p = 15 * (1 << 27) + 1,
                               long long g = 22) {
    int l = ceil(log2(a.size()) + 1e-8), n = 1 << l, tn = a.size();
    a.resize(2 * n);
    vector<int> rev(2 * n);
    vector<long long> b(2 * n), c = b;
    b[0] = pow(a[0], p - 2, p);
    for (int i = 1, m = 2; i <= l; ++i, m <<= 1) {
      copy(a.begin(), a.begin() + m, c.begin());
      for (int j = 0; j < 2 * m; ++j)
        rev[j] = (rev[j >> 1] >> 1) | ((j & 1) << i);
      ntt(b, 2 * m, 1, rev, p, g);
      ntt(c, 2 * m, 1, rev, p, g);
      for (int j = 0; j < 2 * m; ++j) {
        long long t = 2 - b[j] * c[j] % p;
        b[j] = b[j] * (t < 0 ? t + p : t) % p;
      }
      ntt(b, 2 * m, -1, rev, p, g);
      for (int j = m; j < 2 * m; ++j) b[j] = 0;
      for (int j = 0, k = pow(2 * m, p - 2, p); j < m; ++j) b[j] = b[j] * k % p;
    }
    return b.resize(tn), b;
  }
};
}  // namespace CTL
namespace CTL {
using namespace std;
struct SquareRootOfPolynomial {
  static long long pow(long long a, long long b, long long c) {
    long long r = 1;
    for (; b; b& 1 ? r = r * a % c : 0, b >>= 1, a = a * a % c)
      ;
    return r;
  }
  static void ntt(vector<long long>& a, int n, int s, vector<int>& rev,
                  long long p, long long g) {
    g = s == 1 ? g : pow(g, p - 2, p);
    vector<long long> wm;
    for (int i = 0; 1 << i <= n; ++i) wm.push_back(pow(g, (p - 1) >> i, p));
    for (int i = 0; i < n; ++i)
      if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int i = 1, m = 1 << i; 1 << i <= n; ++i, m = 1 << i) {
      vector<long long> wmk(1, 1);
      for (int k = 1; k < (m >> 1); ++k) wmk.push_back(wmk.back() * wm[i] % p);
      for (int j = 0; j < n; j += m)
        for (int k = 0; k < (m >> 1); ++k) {
          long long u = a[j + k], v = wmk[k] * a[j + k + (m >> 1)] % p;
          a[j + k] = u + v;
          a[j + k + (m >> 1)] = u - v + p;
          if (a[j + k] >= p) a[j + k] -= p;
          if (a[j + k + (m >> 1)] >= p) a[j + k + (m >> 1)] -= p;
        }
    }
  }
  static void inv(vector<long long>& a, int n, vector<long long>& b,
                  long long p, long long g) {
    vector<int> rev(2 * n);
    vector<long long> c(2 * n);
    b[0] = pow(a[0], p - 2, p);
    fill(b.begin() + 1, b.begin() + 2 * n, 0);
    for (int i = 1, m = 2; (1 << i) <= n; ++i, m <<= 1) {
      copy(a.begin(), a.begin() + m, c.begin());
      for (int j = 0; j < 2 * m; ++j)
        rev[j] = (rev[j >> 1] >> 1) | ((j & 1) << i);
      ntt(b, 2 * m, 1, rev, p, g);
      ntt(c, 2 * m, 1, rev, p, g);
      for (int j = 0; j < 2 * m; ++j) {
        long long t = 2 - b[j] * c[j] % p;
        b[j] = b[j] * (t < 0 ? t + p : t) % p;
      }
      ntt(b, 2 * m, -1, rev, p, g);
      for (int j = m; j < 2 * m; ++j) b[j] = 0;
      for (int j = 0, k = pow(2 * m, p - 2, p); j < m; ++j) b[j] = b[j] * k % p;
    }
  }
  static vector<long long> run(vector<long long> a,
                               long long p = 15 * (1 << 27) + 1,
                               long long g = 22, long long r = 1) {
    int l = ceil(log2(a.size()) + 1e-8), n = 1 << l, tn = a.size();
    a.resize(2 * n);
    long long t = pow(2, p - 2, p);
    vector<int> rev(2 * n);
    vector<long long> b(2 * n), c = b, d = c, e = d;
    b[0] = r;
    for (int i = 1, m = 2; i <= l; ++i, m <<= 1) {
      copy(a.begin(), a.begin() + m, c.begin());
      for (int j = 0; j < 2 * m; ++j)
        rev[j] = (rev[j >> 1] >> 1) | ((j & 1) << i);
      inv(b, m, d, p, g);
      ntt(d, 2 * m, 1, rev, p, g);
      ntt(c, 2 * m, 1, rev, p, g);
      for (int j = 0; j < 2 * m; ++j) e[j] = d[j] * c[j] % p;
      ntt(e, 2 * m, -1, rev, p, g);
      for (int j = 0, k = pow(2 * m, p - 2, p); j < m; ++j) {
        b[j] = t * b[j] % p + t * e[j] % p * k % p;
        if (b[j] >= p) b[j] -= p;
      }
    }
    return b.resize(tn), b;
  }
};
}  // namespace CTL
long long p = 998244353, g = 3;
using namespace std;
int main() {
  int n, m;
  scanf("%d", &n), scanf("%d", &m);
  vector<long long> c(m + 1);
  for (int i = 1; i <= n; ++i) {
    int t;
    scanf("%d", &t);
    if (t > m) continue;
    c[t] = p - 4;
  }
  ++c[0];
  c[0] %= p;
  c = CTL::SquareRootOfPolynomial::run(c, p, g);
  ++c[0];
  c[0] %= p;
  c = CTL::MultiplicativeInverseOfPolynomial::run(c, p, g);
  for (int i = 1; i <= m; ++i) {
    long long v = c[i];
    v = v * 2 % p;
    printf("%d\n", int(v));
  }
  return 0;
}
