#include <bits/stdc++.h>
using namespace std;
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c)) v.emplace_back(x);
  return move(v);
}
template <typename T, typename... Args>
inline string arrStr(T arr, int n) {
  stringstream s;
  s << "[";
  for (int i = 0; i < n - 1; i++) s << arr[i] << ",";
  s << arr[n - 1] << "]";
  return s.str();
}
inline void __evars_begin(int line) { cerr << "#" << line << ": "; }
template <typename T>
inline void __evars_out_var(vector<T> val) {
  cerr << arrStr(val, val.size());
}
template <typename T>
inline void __evars_out_var(T* val) {
  cerr << arrStr(val, 10);
}
template <typename T>
inline void __evars_out_var(T val) {
  cerr << val;
}
inline void __evars(vector<string>::iterator it) { cerr << endl; }
template <typename T, typename... Args>
inline void __evars(vector<string>::iterator it, T a, Args... args) {
  cerr << it->substr((*it)[0] == ' ', it->length()) << "=";
  __evars_out_var(a);
  cerr << "; ";
  __evars(++it, args...);
}
const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
          d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return ((a * b) / gcd(a, b)); }
long long modpower(long long base, long long power, long long mod) {
  if (base == 0 || base == 1) return base;
  long long res = 1;
  while (power) {
    if (power % 2) {
      res = (res * base) % mod;
      power--;
    }
    base = (base * base) % mod;
    power /= 2;
  }
  return (res + mod) % mod;
}
long long const INF = 1LL << 60LL;
double const pi = 3.14159265358979323846264338327950;
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0, _n = (n); i < _n; i++) cin >> v[i];
  long long dp[n + 1][n + 1];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    dp[i][i] = v[i];
  }
  for (int k = 2; k <= n; k++) {
    for (int i = 0; i + k <= n; i++) {
      int j = i + k - 1;
      dp[i][j] = dp[i][j - 1] ^ dp[i + 1][j];
    }
  }
  for (int k = 2; k <= n; k++) {
    for (int i = 0; i + k <= n; i++) {
      int j = i + k - 1;
      dp[i][j] = max(dp[i][j], max(dp[i][j - 1], dp[i + 1][j]));
    }
  }
  long long q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    long long l, r;
    cin >> l >> r;
    cout << dp[l - 1][r - 1] << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(2);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
