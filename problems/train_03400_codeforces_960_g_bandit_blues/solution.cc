#include <bits/stdc++.h>
using namespace std;
namespace NTT {
const int EXP = 23;
const unsigned long long EXP_MULT = 119, NTT_MOD = (EXP_MULT << EXP) + 1;
unsigned long long rt[EXP + 1], invrt[EXP + 1];
bool built;
unsigned long long modPow(unsigned long long a, unsigned long long p) {
  return p ? modPow((a) * (a) % NTT_MOD, p >> 1) * (p & 1 ? a : 1) % NTT_MOD
           : 1;
}
unsigned long long invMod(unsigned long long a) {
  return modPow(a, NTT_MOD - 2);
}
unsigned long long findCyclic() {
  vector<long long> multFactors;
  unsigned long long temp = EXP_MULT;
  for (long long i = 2; i * i <= temp; i += 2) {
    if (temp % i == 0) multFactors.push_back(i);
    while (temp % i == 0) temp /= i;
    if (i == 2) i--;
  }
  if (temp > 1) multFactors.push_back(temp);
  for (long long i = 2; i < NTT_MOD; i++) {
    bool works = 1;
    if (modPow(i, NTT_MOD >> 1) == 1) works = 0;
    for (const int factor : multFactors)
      if (modPow(i, NTT_MOD / factor) == 1) works = 0;
    if (works) return i;
  }
}
void buildRT() {
  if (built) return;
  built = 1;
  rt[EXP] = modPow(findCyclic(), EXP_MULT);
  for (int i = (EXP)-1; i >= 0; i--)
    rt[i] = (rt[i + 1]) * (rt[i + 1]) % NTT_MOD;
  for (int i = 0; i < (EXP + 1); i++) invrt[i] = invMod(rt[i]);
}
int rev(int idx, int sz) {
  int tmp = 1, res = 0;
  sz >>= 1;
  while (sz) {
    if (sz & idx) res |= tmp;
    sz >>= 1;
    tmp <<= 1;
  }
  return res;
}
vector<unsigned long long> bitReverseCopy(vector<unsigned long long> val) {
  vector<unsigned long long> res(val.size());
  for (int i = 0; i < (val.size()); i++) res[i] = val[rev(i, val.size())];
  return res;
}
vector<unsigned long long> ntt(vector<unsigned long long> val) {
  buildRT();
  vector<unsigned long long> res = bitReverseCopy(val);
  int n = res.size();
  for (int i = (1); i < (32 - __builtin_clz(n)); i++) {
    int m = 1 << i;
    unsigned long long wm = rt[i];
    for (int k = 0; k < n; k += m) {
      unsigned long long w = 1;
      for (int j = 0; j < (m >> 1); j++) {
        unsigned long long t = w * res[k + j + (m >> 1)] % NTT_MOD;
        unsigned long long u = res[k + j];
        res[k + j] = (u + t) % NTT_MOD;
        res[k + j + (m >> 1)] = (u + NTT_MOD - t) % NTT_MOD;
        w = (w * wm) % NTT_MOD;
      }
    }
  }
  return res;
}
vector<unsigned long long> invntt(vector<unsigned long long> val) {
  swap(rt, invrt);
  vector<unsigned long long> res = ntt(val);
  swap(rt, invrt);
  unsigned long long u = invMod(val.size());
  for (int i = 0; i < (res.size()); i++) res[i] = (res[i] * u) % NTT_MOD;
  return res;
}
vector<unsigned long long> conv(vector<unsigned long long> a,
                                vector<unsigned long long> b) {
  int finalSZ = a.size() + b.size() - 1;
  int neededSZ = 1 << (32 - __builtin_clz(finalSZ - 1));
  a.resize(neededSZ), b.resize(neededSZ);
  a = ntt(a), b = ntt(b);
  for (int i = 0; i < (neededSZ); i++) a[i] = a[i] * b[i] % NTT_MOD;
  a = invntt(a);
  a.resize(finalSZ);
  return a;
}
};  // namespace NTT
using namespace NTT;
struct Polynomial {
  int deg;
  unsigned long long* coefficients;
  Polynomial(int d = 0) {
    deg = d;
    coefficients = new unsigned long long[deg + 1];
    memset(coefficients, 0, (deg + 1) * sizeof(unsigned long long));
  }
  Polynomial operator()(Polynomial p) {
    Polynomial curr;
    curr[0] = 1;
    Polynomial res;
    for (int i = 0; i < (deg + 1); i++) {
      res += curr * coefficients[i];
      curr *= p;
    }
    return res;
  }
  Polynomial operator+(unsigned long long a) {
    Polynomial p(deg);
    for (int i = 0; i < (deg + 1); i++) p[i] = coefficients[i];
    p[0] += a;
    p[0] %= NTT_MOD;
    return p;
  }
  Polynomial operator-(unsigned long long a) {
    Polynomial p(deg);
    for (int i = 0; i < (deg + 1); i++) p[i] = coefficients[i];
    p[0] += NTT_MOD - a;
    p[0] %= NTT_MOD;
    return p;
  }
  Polynomial operator*(unsigned long long mult) {
    Polynomial p(deg);
    for (int i = 0; i < (deg + 1); i++) p[i] = coefficients[i] * mult % NTT_MOD;
    return p;
  }
  Polynomial operator/(unsigned long long div) { return *this * invMod(div); }
  Polynomial operator+(Polynomial b) {
    Polynomial res(max(deg, b.deg));
    for (int i = 0; i < (max(deg, b.deg) + 1); i++)
      res[i] = (((i > deg) ? 0 : coefficients[i]) + ((i > b.deg) ? 0 : b[i])) %
               NTT_MOD;
    return res;
  }
  Polynomial operator-(Polynomial p) { return *this + (p * (NTT_MOD - 1)); }
  Polynomial operator*(Polynomial b) {
    vector<unsigned long long> va, vb;
    for (int i = 0; i < (deg + 1); i++) va.push_back((*this)[i]);
    for (int i = 0; i < (b.deg + 1); i++) vb.push_back(b[i]);
    vector<unsigned long long> vc = NTT::conv(va, vb);
    Polynomial res(vc.size() - 1);
    for (int i = 0; i < (vc.size()); i++) res[i] = vc[i];
    return res;
  }
  void operator+=(unsigned long long a) {
    coefficients[0] += a, coefficients[0] %= NTT_MOD;
  }
  void operator-=(unsigned long long a) { *this += NTT_MOD - a; }
  void operator*=(unsigned long long mult) {
    for (int i = 0; i < (deg + 1); i++)
      coefficients[i] *= mult, coefficients[i] %= NTT_MOD;
  }
  void operator/=(unsigned long long div) { *this *= invMod(div); }
  void operator+=(Polynomial b) { *this = *this + b; }
  void operator-=(Polynomial p) { *this = *this - p; }
  void operator*=(Polynomial b) { *this = *this * b; }
  unsigned long long& operator[](int idx) { return coefficients[idx]; }
};
int N, A, B;
long long C(long long n, long long r) {
  long long res = 1;
  long long div = 1;
  for (int i = 0; i < (r); i++) res = res * (n - i) % NTT_MOD;
  for (int i = (1); i < (r + 1); i++) div = div * i % NTT_MOD;
  return res * invMod(div) % NTT_MOD;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> A >> B;
  if (A + B - 2 > N - 1 || A == 0 || B == 0) {
    cout << 0 << endl;
    return 0;
  }
  queue<Polynomial> q;
  Polynomial strt(0);
  strt[0] = 1;
  q.push(strt);
  for (int i = 0; i < (N - 1); i++) {
    Polynomial mult(1);
    mult[1] = 1;
    mult[0] = i;
    q.push(mult);
  }
  while (q.size() > 1) {
    Polynomial a = q.front();
    q.pop();
    Polynomial b = q.front();
    q.pop();
    q.push(a * b);
  }
  cout << q.front()[A + B - 2] * C(A + B - 2, A - 1) % NTT_MOD << endl;
  return 0;
}
