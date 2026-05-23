#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long MOD = 1000000007;
long double EPS = 1e-9;
long long binpow(long long b, long long p, long long mod) {
  long long ans = 1;
  b %= mod;
  for (; p; p >>= 1) {
    if (p & 1) ans = ans * b % mod;
    b = b * b % mod;
  }
  return ans;
}
void pre() {}
namespace GetPrimitve {
vector<long long> Divisors;
vector<long long> Divisor(long long x) {
  vector<long long> ans;
  for (long long i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      ans.emplace_back(i);
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) ans.emplace_back(x);
  return ans;
}
bool check(int prim, int p, vector<long long>& divs) {
  for (auto v : divs) {
    if (binpow(prim, (p - 1) / v, p) == 1) return 0;
  }
  return 1;
}
int getRoot(int p) {
  int ans = 2;
  vector<long long> divs = Divisor(p - 1);
  while (!check(ans, p, divs)) ans++;
  return ans;
}
};  // namespace GetPrimitve
namespace POLYMUL {
using polybase = long long;
const long long NTTMOD = 998244353, PRIMITIVE_ROOT = 3;
const long long MAXB = 1 << 21;
long long modInv(long long a) {
  return a <= 1
             ? a
             : (long long)(NTTMOD - NTTMOD / a) * modInv(NTTMOD % a) % NTTMOD;
}
void NTT(polybase P[], long long n, long long oper) {
  for (int i = 1, j = 0; i < n - 1; i++) {
    for (int s = n; j ^= s >>= 1, ~j & s;)
      ;
    if (i < j) swap(P[i], P[j]);
  }
  for (int d = 0; (1 << d) < n; d++) {
    int m = 1 << d, m2 = m * 2;
    long long unit_p0 = binpow(PRIMITIVE_ROOT, (NTTMOD - 1) / m2, NTTMOD);
    if (oper < 0) unit_p0 = modInv(unit_p0);
    for (int i = 0; i < n; i += m2) {
      long long unit = 1;
      for (int j = 0; j < m; j++) {
        polybase &P1 = P[i + j + m], &P2 = P[i + j];
        polybase t = unit * P1 % NTTMOD;
        P1 = (P2 - t + NTTMOD) % NTTMOD;
        P2 = (P2 + t) % NTTMOD;
        unit = unit * unit_p0 % NTTMOD;
      }
    }
  }
}
vector<polybase> mul(const vector<polybase>& a, const vector<polybase>& b) {
  vector<polybase> ret(max(0LL, (long long)a.size() + (long long)b.size() - 1),
                       0);
  static polybase A[MAXB], B[MAXB], C[MAXB];
  int len = 1;
  while (len < (long long)ret.size()) len <<= 1;
  for (int i = 0; i < len; i++) A[i] = i < (int)a.size() ? a[i] : 0;
  for (int i = 0; i < len; i++) B[i] = i < (int)b.size() ? b[i] : 0;
  NTT(A, len, 1);
  NTT(B, len, 1);
  for (long long i = 0; i < len; i++) C[i] = (polybase)A[i] * B[i] % NTTMOD;
  NTT(C, len, -1);
  for (long long i = 0, inv = modInv(len); i < (long long)ret.size(); i++)
    ret[i] = (long long)C[i] * inv % NTTMOD;
  return ret;
}
vector<long long> binpow(vector<long long> b, long long p) {
  vector<long long> ans = vector<long long>(1, 1);
  for (; p; p >>= 1) {
    if (p & 1) ans = mul(ans, b);
    b = mul(b, b);
  }
  return ans;
}
vector<long long> calc(vector<long long>& arr, int l, int r) {
  if (l == r) {
    return vector<long long>(arr[l] + 1, 1);
  }
  int mid = (l + r) >> 1;
  vector<long long> x = calc(arr, l, mid), y = calc(arr, mid + 1, r);
  return mul(x, y);
}
}  // namespace POLYMUL
using namespace POLYMUL;
void solve() {
  long long n;
  cin >> n;
  map<int, int> freq;
  for (long long i = 0; i < (n); ++i) {
    int x;
    cin >> x;
    freq[x]++;
  }
  vector<long long> vals;
  for (auto v : freq) {
    vals.emplace_back(v.second);
  }
  sort((vals).begin(), (vals).end());
  vector<long long> pp = calc(vals, 0, vals.size() - 1);
  cout << pp[n / 2] << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  pre();
  long long _t = 1;
  for (long long i = 1; i <= _t; i++) {
    solve();
  }
}
