#include <bits/stdc++.h>
using namespace std;
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v);
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
template <typename A, typename B>
istream &operator>>(istream &cin, pair<A, B> &p) {
  cin >> p.first;
  return cin >> p.second;
}
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
void usaco(string filename) {
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
}
const long double pi = 3.14159265358979323846;
const long long mod = 1000000007;
long long n, m, k, q, l, r, x, y, z;
const long long template_array_size = 1e6 + 3280;
long long a[template_array_size];
long long b[template_array_size];
long long c[template_array_size];
string second, t;
long long ans = 0;
long long fact[1005];
void solve(int tc = 0) {
  long long p;
  cin >> n >> x >> p;
  fact[0] = fact[1] = 1;
  for (long long i = 2; i <= n; i++) {
    fact[i] = (i * fact[i - 1]) % mod;
  }
  long long l = 0, r = n;
  long long le = x - 1, gr = n - x;
  long long ans = 1;
  long long cnt = n;
  while (l < r) {
    long long m = (l + r) / 2;
    if (m == p) {
      l = m + 1;
    } else if (p > m) {
      ans = (ans * le) % mod;
      --le;
      l = m + 1;
    } else {
      ans = (ans * gr) % mod;
      --gr;
      r = m;
    }
    --cnt;
  }
  if (cnt > 0) ans = (ans * fact[cnt]) % mod;
  cout << ans << '\n';
}
int main() {
  { ios_base::sync_with_stdio(false); }
  { cin.tie(NULL); }
  int tc = 1;
  for (int t = 0; t < tc; t++) solve(t);
}
