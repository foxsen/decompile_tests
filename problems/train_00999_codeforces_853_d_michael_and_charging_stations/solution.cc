#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int MOD2 = 1007681537;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
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
inline long long isqrt(long long k) {
  long long r = sqrt(k) + 1;
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
const int maxn = 1e6 + 5;
int n;
int a[maxn];
vector<int> pos1;
vector<int> pos2;
int mn[maxn << 1];
int sm[maxn << 1];
void upd(int p, int val) {
  p += 1 << 19;
  mn[p] = sm[p] = val;
  while (p > 1) {
    p >>= 1;
    sm[p] = sm[p << 1] + sm[p << 1 | 1];
    mn[p] = min(mn[p << 1], sm[p << 1] + mn[p << 1 | 1]);
  }
}
int check(int mi) {
  for (int i = (0); i < (n); i++) {
    upd(i, -a[i]);
  }
  for (int i = (0); i < (int((pos2).size())); i++) {
    int ix = pos2[i];
    upd(ix, 200);
  }
  int ptr = int((pos2).size()) - 1;
  for (int x = (0); x < (int((pos1).size()) + 1); x++)
    if (mi >= 1000 * x) {
      int y = min(int((pos2).size()), (mi - 1000 * x) / 2000);
      while (ptr >= y) {
        int ix = pos2[ptr];
        upd(ix, -2000);
        ptr--;
      }
      if (x) {
        int ix = pos1[x - 1];
        upd(ix, 100);
      }
      int rm = mi - 1000 * x - 2000 * y;
      if ((!x && a[0] == 1000) || (!y && a[0] == 2000)) {
        upd(0, rm - a[0]);
      } else {
        upd(0, rm + a[0] / 10);
      }
      if (mn[1] >= 0) {
        return 1;
      }
    }
  return 0;
}
void solve() {
  cin >> n;
  for (int i = (0); i < (n); i++) {
    cin >> a[i];
    if (a[i] == 1000) {
      pos1.push_back(i);
    } else {
      pos2.push_back(i);
    }
  }
  int lo = 0, hi = 600000000;
  while (lo < hi) {
    int mi = lo + hi >> 1;
    if (!check(mi)) {
      lo = mi + 1;
    } else {
      hi = mi;
    }
  }
  cout << (lo + hi >> 1) << "\n";
}
int main() {
  int JUDGE_ONLINE = 1;
  if (fopen("in.txt", "r")) {
    JUDGE_ONLINE = 0;
    assert(freopen("in.txt", "r", stdin));
  } else {
    ios_base::sync_with_stdio(0), cin.tie(0);
  }
  solve();
  if (!JUDGE_ONLINE) {
  }
  return 0;
}
