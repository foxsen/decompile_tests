#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long INF = 1e18;
const long double PI = acos((long double)-1);
const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
          d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};
string to_string(char c) { return string(1, c); }
string to_string(const char* s) { return (string)s; }
string to_string(string s) { return s; }
string to_string(bool b) { return b ? "true" : "false"; }
string to_string(vector<bool> v) {
  string res;
  for (int i = (0); i < ((int)(v).size()); ++i) res += char('0' + v[i]);
  return res;
}
template <size_t SZ>
string to_string(bitset<SZ> b) {
  string res;
  for (int i = (0); i < (SZ); ++i) res += char('0' + b[i]);
  return res;
}
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return 31 - __builtin_clz(x); }
const long long MOD = 1e9 + 7;
const int MX = 1e6 + 1;
int tree[MX + 5];
int sum(int k) {
  int a = 0;
  while (k >= 1) {
    a += tree[k];
    k -= k & -k;
  }
  return a;
}
void add(int k, int x) {
  while (k <= MX) {
    tree[k] += x;
    k += k & -k;
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  long long ans = 1;
  vector<pair<int, int> > qs(MX + 5);
  vector<vector<int> > ver(MX + 5);
  for (int i = (0); i < (n); ++i) {
    int y, l, r;
    cin >> y >> l >> r;
    ++y;
    ++l;
    ++r;
    qs[y] = make_pair(l, r);
    if (l == 1 && r == MX) ++ans;
  }
  for (int i = (0); i < (m); ++i) {
    int x, b, t;
    cin >> x >> b >> t;
    ++x;
    ++b;
    ++t;
    ver[b].push_back(x);
    ver[t + 1].push_back(-x);
    if (b == 1 && t == MX) ++ans;
  }
  for (int y = (1); y < (MX + 1); ++y) {
    for (int& x : ver[y]) {
      if (x > 0)
        add(x, 1);
      else
        add(-x, -1);
    }
    auto& p = qs[y];
    if (p.second != 0) {
      ans += sum(p.second) - sum(p.first - 1);
    }
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
