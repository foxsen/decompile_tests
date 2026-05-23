#include <bits/stdc++.h>
template< typename T >
T mod_pow(T x, T n, const T &p) {
  if(x < 0) return 0;
  T ret = 1;
  while(n > 0) {
    if(n & 1) (ret *= x) %= p;
    (x *= x) %= p;
    n >>= 1;
  }
  return ret;
}
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<int, int>;
const double eps = 1e-8;
const ll MOD = 1000000007;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;
template<typename T1, typename T2>
bool chmax(T1 &a, const T2 &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template<typename T1, typename T2>
bool chmin(T1 &a, const T2 &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}
template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for(int i=0;i<((int)(v.size()));++i) {
    if (i) os << " ";
    os << v[i];
  }
  return os;
}
const int ma = 2001;
int n = 0;
ll a[ma];
ll b[ma];
ll res[ma];
void mul(ll a[ma], ll b[ma]) {
  for(int i=0;i<(n);++i) {
    for(int j=0;j<(n);++j) {
      if(i - j < 0) break;
      res[i] += a[i-j] * b[j] % MOD;
      res[i] %= MOD;
    }
  }
  for(int i=0;i<(n);++i) {
    a[i] = res[i];
  }
  memset(res, 0, sizeof(res));
}
bool solve() {
  ll d, x;
  cin >> n >> d >> x;
  if (n == 0) return false;
  n++;
  for(int i=0;i<(min(x, (ll)n));++i) a[i] = 1;
  b[0] = 1;
  while (d) {
    if (d & 1) {
      mul(b, a);
    }
    mul(a, a);
    d >>= 1;
  }
  cout << b[n - 1] << endl;
  return true;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  do {
    for(int i=0;i<(n);++i) {
      memset(a, 0, sizeof(a));
      memset(b, 0, sizeof(b));
    }
  } while(solve());
}

