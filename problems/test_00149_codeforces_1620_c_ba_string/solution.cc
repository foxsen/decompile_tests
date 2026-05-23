#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
constexpr long long SZ = 1e5 + 7;
constexpr long long inf = 1e18;
constexpr long long mod = 1e9 + 7;
constexpr long long MOD = 998244353;
constexpr long double PI = 3.141592653589793238462;
void __print(long long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << x; }
void __print(const char *x) { cerr << x; }
void __print(const string &x) { cerr << x; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  long long f = 0;
  cerr << '{';
  for (auto &i : x) {
    cerr << (f++ ? ", " : "");
    __print(i);
  }
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) {
    cerr << ", ";
  }
  _print(v...);
}
template <class T>
bool amin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool amax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T1, typename T2>
istream &operator>>(istream &istream, pair<T1, T2> &p) {
  return (istream >> p.first >> p.second);
}
template <typename T>
istream &operator>>(istream &istream, vector<T> &v) {
  for (auto &it : v) {
    cin >> it;
  }
  return istream;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) {
  return (ostream << p.first << " " << p.second);
}
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c) {
  for (auto &it : c) {
    cout << it << " ";
  }
  return ostream;
}
long long tc_cnt = 1;
long long modpow(long long a, long long b, long long m = mod) {
  a = a & m;
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % m;
    }
    b = b >> 1;
    a = (a * a) % m;
  }
  return ans;
}
long long modinv(long long a, long long m = mod) { return modpow(a, m - 2); }
long long modadd(long long a, long long b, long long m = mod) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long modsub(long long a, long long b, long long m = mod) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long modmul(long long a, long long b, long long m = mod) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long moddiv(long long a, long long b, long long m = mod) {
  a = a % m;
  b = b % m;
  return (modmul(a, modinv(b, m), m) + m) % m;
}
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
const long long dx[8] = {0, 1, -1, 0, -1, -1, 1, 1};
const long long dy[8] = {1, 0, 0, -1, 1, -1, -1, 1};
long long mul(long long a, long long b) {
  long long ans = 0;
  while (b) {
    if (b & 1) {
      ans += a;
    }
    b = b >> 1;
    a += a;
    if (a > inf) {
      a = inf;
    }
    if (ans > inf) {
      ans = inf;
    }
  }
  return ans;
}
void oreo() {
  long long n, k, x;
  cin >> n >> k >> x;
  x--;
  string s;
  cin >> s;
  vector<long long> cnt;
  long long c = 0;
  for (long long i = 0; i < n; ++i) {
    if (s[i] == 'a') {
      cnt.push_back(c);
      c = 0;
    } else {
      c++;
    }
  }
  cnt.push_back(c);
  ;
  vector<long long> m((long long)cnt.size());
  m[(long long)m.size() - 1] = 1;
  for (long long i = (long long)cnt.size() - 2; i >= 0; --i) {
    m[i] = mul(m[i + 1], k * cnt[i + 1] + 1);
  };
  vector<long long> ans((long long)cnt.size());
  for (long long i = 0; i < (long long)cnt.size(); ++i) {
    ans[i] = x / m[i];
    x %= m[i];
  };
  for (long long i = 0; i < (long long)cnt.size(); ++i) {
    for (long long j = 0; j < ans[i]; ++j) {
      cout << 'b';
    }
    if (i + 1 != (long long)cnt.size()) {
      cout << 'a';
    }
  }
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) oreo();
  return 0;
}
