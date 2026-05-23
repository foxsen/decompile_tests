#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return '"' + s + '"'; }
string to_string(char s) { return string(1, s); }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A>
string to_string(A);
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool f = 1;
  string r = "{";
  for (const auto& x : v) {
    if (!f) r += ", ";
    f = 0;
    r += to_string(x);
  }
  return r + "}";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int inf = 1e9;
const long long INF = 1e18;
const int mod = 1e9 + 7;
const int bit32 = log2(inf) + 3;
const int bit64 = log2(INF) + 3;
inline int add(long long a, long long b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}
inline int sub(long long a, long long b) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}
inline int mul(long long a, long long b) {
  a %= mod;
  b %= mod;
  return (int)((long long)a * b % mod);
}
inline int modexpo(long long a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b /= 2;
  }
  return res;
}
inline int divide(long long a, long long b) {
  return mul(a, modexpo(b, mod - 2));
}
inline int inv(long long a) { return modexpo(a, mod - 2); }
clock_t time_p = clock();
void ktj() {
  time_p = clock() - time_p;
  cerr << "Time elapsed : " << (float)(time_p) / CLOCKS_PER_SEC << "\n";
}
void pre() {}
void solve() {
  int n, i, j, k;
  cin >> n;
  vector<int> a(n);
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = bit32 - 1; i >= 0; i--) {
    int set = 0, unset = 0;
    for (j = 0; j < n; j++) {
      set += ((a[j] >> i) & 1);
    }
    if (set & 1) {
      unset = n - set;
      if (set % 4 == 1) {
        cout << "WIN\n";
      } else if (unset & 1) {
        cout << "WIN\n";
      } else {
        cout << "LOSE\n";
      }
      return;
    }
  }
  cout << "DRAW" << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  pre();
  int t = 1, T;
  if (1) cin >> t;
  for (T = 1; T <= t; T++) {
    if (0) cout << "Case #" << T << ": ";
    solve();
  }
  ktj();
}
