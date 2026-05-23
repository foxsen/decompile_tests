#include <bits/stdc++.h>
using namespace std;
const int MOD = 119 << 23 | 1;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int)1e9 + 23111992;
const long long LINF = (long long)1e18 + 23111992;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
inline long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long fpow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
template <class T>
inline int chkmin(T& a, const T& val) {
  return val < a ? a = val, 1 : 0;
}
template <class T>
inline int chkmax(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
inline unsigned long long isqrt(unsigned long long k) {
  unsigned long long r = sqrt(k) + 1;
  while (r * r > k) r--;
  return r;
}
inline long long icbrt(long long k) {
  long long r = cbrt(k) + 1;
  while (r * r * r > k) r--;
  return r;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
inline int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }
inline int sign(long double x) { return x < -EPS ? -1 : x > +EPS; }
inline int sign(long double x, long double y) { return sign(x - y); }
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int mrand() { return abs((int)mt()); }
template <const int mod, const int maxf>
struct NTT {
  int rts[maxf + 1];
  int bitrev[maxf];
  int iv[maxf + 1];
  int fpow(int a, int k) {
    if (!k) return 1;
    int res = a, tmp = a;
    k--;
    while (k) {
      if (k & 1) {
        res = (long long)res * tmp % mod;
      }
      tmp = (long long)tmp * tmp % mod;
      k >>= 1;
    }
    return res;
  }
  int prt() {
    vector<int> dvs;
    for (int i = 2; i * i < mod; i++) {
      if ((mod - 1) % i) continue;
      dvs.push_back(i);
      if (i * i != mod - 1) dvs.push_back((mod - 1) / i);
    }
    for (int i = 2; i < mod; i++) {
      int flag = 1;
      for (int j = 0; j < dvs.size(); j++) {
        if (fpow(i, dvs[j]) == 1) {
          flag = 0;
          break;
        }
      }
      if (flag) return i;
    }
    assert(0);
    return -1;
  }
  NTT() {
    int k = 0;
    while ((1 << k) < maxf) k++;
    bitrev[0] = 0;
    for (int i = 1; i < maxf; i++) {
      bitrev[i] = bitrev[i >> 1] >> 1 | ((i & 1) << k - 1);
    }
    int pw = fpow(prt(), (mod - 1) / maxf);
    rts[0] = 1;
    for (int i = 1; i <= maxf; i++) {
      rts[i] = (long long)rts[i - 1] * pw % mod;
    }
    for (int i = 1; i <= maxf; i <<= 1) {
      iv[i] = fpow(i, mod - 2);
    }
  }
  void dft(int a[], int n, int sign) {
    int d = 0;
    while ((1 << d) * n != maxf) d++;
    for (int i = 0; i < n; i++) {
      if (i < (bitrev[i] >> d)) {
        swap(a[i], a[bitrev[i] >> d]);
      }
    }
    for (int len = 2; len <= n; len <<= 1) {
      int delta = maxf / len * sign;
      for (int i = 0; i < n; i += len) {
        int* w = sign > 0 ? rts : rts + maxf;
        for (int k = 0; k + k < len; k++) {
          int &a1 = a[i + k + (len >> 1)], &a2 = a[i + k];
          int t = (long long)*w * a1 % mod;
          a1 = a2 - t;
          a2 = a2 + t;
          a1 += a1 < 0 ? mod : 0;
          a2 -= a2 >= mod ? mod : 0;
          w += delta;
        }
      }
    }
    if (sign < 0) {
      int in = iv[n];
      for (int i = 0; i < n; i++) {
        a[i] = (long long)a[i] * in % mod;
      }
    }
  }
  void multiply(int a[], int b[], int na, int nb, int c[]) {
    static int fa[maxf], fb[maxf];
    int n = na + nb - 1;
    while (n != (n & -n)) n += n & -n;
    for (int i = 0; i < n; i++) fa[i] = fb[i] = 0;
    for (int i = 0; i < na; i++) fa[i] = a[i];
    for (int i = 0; i < nb; i++) fb[i] = b[i];
    dft(fa, n, 1), dft(fb, n, 1);
    for (int i = 0; i < n; i++) fa[i] = (long long)fa[i] * fb[i] % mod;
    dft(fa, n, -1);
    for (int i = 0; i < n; i++) c[i] = fa[i];
  }
  vector<int> multiply(vector<int> a, vector<int> b) {
    static int fa[maxf], fb[maxf], fc[maxf];
    int na = a.size(), nb = b.size();
    for (int i = 0; i < na; i++) fa[i] = a[i];
    for (int i = 0; i < nb; i++) fb[i] = b[i];
    multiply(fa, fb, na, nb, fc);
    int k = na + nb - 1;
    vector<int> res(k);
    for (int i = 0; i < k; i++) res[i] = fc[i];
    return res;
  }
};
NTT<MOD, 1 << 20> ntt;
void solve() {
  int n;
  cin >> n;
  int dep = 0;
  while ((1 << dep + 1) - 1 <= n) dep++;
  dep--;
  function<vector<vector<int> >(int n)> divide = [&](int dep) {
    int k = 1 << dep + 1;
    vector<vector<int> > res(2, vector<int>(k));
    if (!dep) {
      res[0][0] = res[1][1] = 1;
      return res;
    }
    vector<vector<int> > r = divide(dep - 1);
    vector<int> x0 = r[0];
    vector<int> x1 = r[0];
    vector<int> y0 = r[1];
    vector<int> y1 = r[1];
    for (int i = (0); i < (int((x0).size())); ++i) {
      if (i & 1) {
        x0[i] = y0[i] = 0;
      } else {
        x1[i] = y1[i] = 0;
      }
    }
    vector<int> a0 = ntt.multiply(y0, r[0]);
    vector<int> a1 = ntt.multiply(y1, r[1]);
    vector<int> b0 = ntt.multiply(x0, r[1]);
    vector<int> b1 = ntt.multiply(x1, r[0]);
    for (int i = (0); i < (int((a0).size())); ++i) {
      res[0][i] = (a0[i] + a1[i]) % MOD;
      res[1][i] = (b0[i] + b1[i]) % MOD;
    }
    return res;
  };
  auto res = divide(dep);
  int r = n - (1 << dep + 1) + 1;
  cout << (res[0][r] + res[1][r]) % MOD << "\n";
}
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0);
  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }
  if (argc > 2) {
    assert(freopen(argv[2], "wb", stdout));
  }
  solve();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
