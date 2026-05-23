#include <bits/stdc++.h>
using namespace std;
struct comp {
  double a, b;
  comp() {}
  comp(double x) : a(x), b(0) {}
  comp(double x, double y) : a(x), b(y) {}
};
inline comp operator+(comp a, comp b) { return comp(a.a + b.a, a.b + b.b); }
inline comp operator-(comp a, comp b) { return comp(a.a - b.a, a.b - b.b); }
inline comp operator*(comp a, comp b) {
  return comp(a.a * b.a - a.b * b.b, a.a * b.b + a.b * b.a);
}
ostream& operator<<(ostream& a, comp b) {
  a << "(" << b.a << "," << b.b << ")";
  return a;
}
int K;
comp w[2][1234567];
comp qp(comp a, long long b) {
  comp x = 1;
  while (b) {
    if (b & 1) x = x * a;
    a = a * a;
    b >>= 1;
  }
  return x;
}
long long qp(long long a, long long b, int MOD) {
  long long x = 1;
  a %= MOD;
  while (b) {
    if (b & 1) x = x * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return x;
}
const double pi = acos(-1);
int rev[1234567];
void init(int s) {
  for (K = 1; K < s; K <<= 1)
    ;
  {
    double t = pi * 2 / K;
    for (int i = 0; i <= K; ++i) w[0][i] = comp(cos(t * i), sin(t * i));
  }
  for (int i = 0; i <= K; ++i) w[1][i] = w[0][K - i];
  for (int i = 0; i < K; ++i) {
    int t = 0, x = i;
    for (int j = 1; j < K; j <<= 1) t = t * 2 + (x & 1), x >>= 1;
    rev[i] = t;
  }
}
void fft(comp* x, int k) {
  for (int i = 0; i < K; ++i)
    if (i < rev[i]) swap(x[i], x[rev[i]]);
  for (int i = 2; i <= K; i <<= 1)
    for (int j = 0; j < K; j += i)
      for (int s = 0; s < (i >> 1); ++s) {
        comp t = x[j + s + (i >> 1)] * w[k][K / i * s];
        x[j + s + (i >> 1)] = x[j + s] - t;
        x[j + s] = x[j + s] + t;
      }
  if (k) return;
  double sK = sqrt(K);
  for (int i = 0; i < K; ++i) x[i].a /= sK, x[i].b /= sK;
}
int a0_[1234567], b0_[1234567], a1_[1234567], b1_[1234567];
long long x0_[1234567], x1_[1234567];
comp a0[1234567], b0[1234567], a1[1234567], b1[1234567], x0[1234567],
    x1[1234567], x2[1234567];
comp ps[1234567];
template <class T>
void comb_fft0(T* a, T* b, comp* aa, comp* bb) {
  for (int i = 0; i < K; ++i) ps[i].a = a[i], ps[i].b = b[i];
  fft(ps, 0);
  for (int i = 0; i < K; ++i) {
    comp pr = ps[i ? (K - i) : i];
    pr.b = -pr.b;
    aa[i] = (ps[i] + pr) * 0.5;
    bb[i] = (ps[i] - pr) * 0.5;
    swap(bb[i].a, bb[i].b);
    bb[i].b = -bb[i].b;
  }
}
template <class T>
void comb_fft1(comp* aa, comp* bb, T* a, T* b) {
  for (int i = 0; i < K; ++i) {
    comp t = bb[i];
    t.b *= -1;
    swap(t.a, t.b);
    ps[i] = aa[i] + t;
  }
  fft(ps, 1);
  for (int i = 0; i < K; ++i) a[i] = llround(ps[i].a), b[i] = llround(ps[i].b);
}
vector<int> conv(const vector<int>& a, const vector<int>& b, int p) {
  if (a.size() && b.size())
    ;
  else
    return vector<int>();
  init(a.size() + b.size() + 2);
  for (int i = 0; i < K; ++i) a0_[i] = a1_[i] = b0_[i] = b1_[i] = 0;
  for (int i = 0; i < (int)a.size(); ++i) {
    int t = (a[i] % p + p) % p;
    a0_[i] = t % 32768, a1_[i] = t / 32768;
  }
  for (int i = 0; i < (int)b.size(); ++i) {
    int t = (b[i] % p + p) % p;
    b0_[i] = t % 32768, b1_[i] = t / 32768;
  }
  comb_fft0(a0_, a1_, a0, a1);
  comb_fft0(b0_, b1_, b0, b1);
  for (int i = 0; i < K; ++i)
    x0[i] = a0[i] * b0[i], x1[i] = a0[i] * b1[i] + a1[i] * b0[i],
    x2[i] = a1[i] * b1[i];
  comb_fft1(x0, x1, x0_, x1_);
  fft(x2, 1);
  vector<int> c;
  for (int i = 0; i < int(a.size() + b.size() - 1); ++i) {
    long long s = x0_[i] % p + x1_[i] % p * 32768 +
                  llround(x2[i].a) % p * 32768 % p * 32768;
    s = (s % p + p) % p;
    c.push_back(s);
  }
  return c;
}
int n, m, k, a[1234567], s[1234567];
long long su = 0;
const int MOD = 1e9 + 7;
int cm[1234567];
long long calc_z(int p) {
  memset(cm, 0, sizeof cm);
  long long aa = 0;
  for (int i = 0; i <= n; ++i) {
    aa += cm[(s[i] - p + k) % k];
    cm[s[i]]++;
  }
  aa %= MOD;
  aa = aa * m % MOD;
  vector<int> ss(k + 1), sb(k + 1);
  for (int i = 1; i <= n; ++i) ss[s[i]]++;
  for (int i = 0; i < n; ++i) sb[(s[n] - s[i] + k) % k]++;
  ss = conv(ss, sb, MOD);
  vector<int> oo(k + 1);
  for (int i = 0; i < ss.size(); ++i) (oo[i % k] += ss[i]) %= MOD;
  for (int u = 2; u <= m; ++u) {
    aa += oo[((p - s[n] * (long long)(u - 2)) % k + k) % k] *
          (long long)(m - u + 1) % MOD;
  }
  return aa;
}
long long calc_pre(int su) {
  vector<int> ss(k + 1);
  for (int i = 1; i <= n; ++i) {
    ss[s[i]]++;
  }
  long long aa = 0;
  for (int u = 0; u < m; ++u) {
    aa += ss[((su - s[n] * (long long)u) % k + k) % k];
    aa %= MOD;
  }
  return aa % MOD;
}
long long calc_suf(int su) {
  vector<int> ss(k + 1);
  for (int i = 0; i < n; ++i) {
    ss[(s[n] - s[i] + k) % k]++;
  }
  long long aa = 0;
  for (int u = 0; u < m; ++u) {
    aa += ss[((su - s[n] * (long long)u) % k + k) % k];
    aa %= MOD;
  }
  return aa % MOD;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) s[i] = (s[i - 1] + a[i]) % k;
  su = s[n] * (long long)m % k;
  long long ans = calc_z(0);
  ans += calc_z(su) - calc_pre(su) - calc_suf(su) + 1;
  ans %= MOD;
  ans = (ans % MOD + MOD) % MOD;
  cout << ans << "\n";
}
