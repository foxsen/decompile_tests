#include <bits/stdc++.h>
using namespace std;
istream &in = cin;
ostream &out = cout;
namespace fft {
struct cd {
  cd(double real = 0, double imag = 0) : real(real), imag(imag) {}
  cd &operator+=(cd const &rhs) {
    real += rhs.real;
    imag += rhs.imag;
    return *this;
  }
  cd &operator-=(cd const &rhs) {
    real -= rhs.real;
    imag -= rhs.imag;
    return *this;
  }
  cd &operator*=(cd const &rhs) {
    double r = real * rhs.real - imag * rhs.imag;
    imag = real * rhs.imag + imag * rhs.real;
    real = r;
    return *this;
  }
  bool operator==(cd const &rhs) {
    return real == rhs.real && imag == rhs.imag;
  }
  double real, imag;
};
long double real(cd const &r) { return r.real; }
map<int, vector<int>> revbits;
map<pair<int, bool>, vector<cd>> w_pow_cache;
double const pi = acos(-1.);
void fft_impl(vector<cd> &v, bool invert) {
  int n = v.size();
  cd *p = &v[0];
  vector<int> &rev = revbits[n];
  if (rev.empty()) {
    int logn = 0;
    while ((1 << logn) < n) ++logn;
    rev.resize(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < logn; ++j)
        if (i & (1 << j)) rev[i] |= 1 << (logn - 1 - j);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i < rev[i]) swap(p[i], p[rev[i]]);
  }
  vector<cd> w_pow(n);
  for (int len = 2; len <= n; len <<= 1) {
    int len2 = len >> 1;
    double ang = (invert ? -1 : 1) * 2 * pi / len;
    cd w(cos(ang), sin(ang));
    w_pow[0] = cd(1, 0);
    for (int i = 1; i < len2; ++i) {
      w_pow[i] = w_pow[i - 1];
      w_pow[i] *= w;
    }
    for (int i = 0; i < n; i += len) {
      int idx = 0;
      cd *pu = p + i, *pv = p + i + len2, *pu_end = p + i + len2;
      for (; pu != pu_end; ++pu, ++pv, ++idx) {
        cd t = *pv;
        t *= w_pow[idx];
        *pv = *pu;
        *pv -= t;
        *pu += t;
      }
    }
  }
}
vector<double> fft(vector<double> const &p, vector<double> const &q) {
  int n = 1;
  for (; n < p.size() + q.size(); n <<= 1)
    ;
  vector<cd> a(n), b(n);
  for (int i = 0; i < p.size(); ++i) a[i] = cd(p[i]);
  for (int i = 0; i < q.size(); ++i) b[i] = cd(q[i]);
  fft_impl(a, false);
  fft_impl(b, false);
  for (int i = 0; i < n; ++i) a[i] *= b[i];
  fft_impl(a, true);
  vector<double> res(n);
  for (int i = 0; i < n; ++i) {
    res[i] = (real(a[i]) / n);
  }
  return res;
}
}  // namespace fft
vector<double> my[449], bc;
int st[449], en[449], jig[449], ct[449];
char str[200005], bstr[200005];
long long fir[3][200005];
int cal(int p, int q, int lst) {
  int ans = 0;
  for (; (p + 62) <= lst; p += 63, q += 63) {
    ans += __builtin_popcountll(fir[0][p] ^ fir[1][q]);
  }
  for (; p <= lst; p++, q++) {
    ans += str[p] != bstr[q];
  }
  return ans;
}
void pecal(char bs[], int bol, int n) {
  for (int i = 0; i < n; i++) {
    if ((i + 62) >= n) continue;
    int cnt = 0;
    for (int j = i; cnt < 63; j++, cnt++)
      if (bs[j] == '1') fir[bol][i] = fir[bol][i] | (1LL << cnt);
  }
}
int main() {
  vector<double> vc;
  int p1, p2, q, cnt = 0, r, v, w, Q, ans = 0, gt, f, j, i, k;
  ;
  scanf("%s%s", str, bstr);
  int n = strlen(str);
  int sz = 7000;
  int m = strlen(bstr);
  pecal(str, 0, n);
  pecal(bstr, 1, m);
  bc.resize(m);
  for (int j = 0; j < m; j++) {
    if (bstr[j] == '0') {
      bc[m - j - 1] = -1;
    } else {
      bc[m - j - 1] = 1;
    }
  }
  for (int i = 0; i < n; i += sz) {
    vc.clear();
    int rng = min(i + sz, n);
    vc.resize(rng);
    st[cnt] = i;
    for (j = i; j < rng; j++) {
      if (str[j] == '0')
        vc[j] = -1;
      else
        vc[j] = 1;
    }
    en[cnt] = j - 1;
    jig[cnt] = j - i;
    my[cnt] = fft::fft(vc, bc);
    ct[cnt] = my[cnt].size();
    cnt++;
  }
  scanf("%d", &Q);
  while (Q--) {
    scanf("%d%d%d", &p1, &p2, &q);
    swap(p2, q);
    p2 = p1 + p2 - 1;
    v = p1 / sz;
    w = p2 / sz;
    if (v == w) {
      ans = 0;
      ans = cal(p1, q, p2);
      printf("%d\n", ans);
      continue;
    }
    r = m - q - 1 + p1;
    ans = 0;
    gt = en[v] - p1 + 1;
    ;
    ans += cal(p1, q, en[v]);
    for (int j = v + 1; j < w; j++) {
      gt += jig[j];
      double f;
      if (ct[j] > r)
        f = my[j][r];
      else
        f = 0;
      ans += (int)(((jig[j] - f) / 2) + .5);
    }
    ans += cal(p1 + gt, q + gt, p2);
    printf("%d\n", ans);
  }
  return 0;
}
