#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const double pi = 3.141592653589793;
const long long inf = 1e18 + 5;
const int MOD = 1e9 + 7;
const int maxn = 2e5 + 5;
const int mxn = 1e5 + 5;
const int mx = 1000;
int a[maxn], b[maxn];
int main() {
  ios_base::sync_with_stdio(cin.tie(0) && 0);
  ;
  int n, m;
  cin >> n >> m;
  int x, k, y;
  cin >> x >> k >> y;
  for (int i = 1; i < n + 1; i++) cin >> a[i];
  for (int i = 1; i < m + 1; i++) cin >> b[i];
  bool change = (x > y * k);
  long long cost = 0;
  int l = 0, r = 0, p = 0;
  while (p < m + 1) {
    if (l > n && p == m) return cout << -1 << '\n', 0;
    while (l <= n && a[l] != b[p]) l++;
    r = l, p++;
    while (r <= n && a[r] != b[p]) r++;
    bool fl = 0;
    for (int i = l + 1; i < r; i++) {
      if (a[i] > a[l] && a[i] > a[r]) {
        fl = 1;
        break;
      }
    }
    int len = (r - l - 1);
    if (len < k && fl) return cout << -1 << '\n', 0;
    if (fl) {
      if (change)
        cost += 1ll * x + 1ll * (len - k) * y;
      else
        cost += 1ll * (len / k) * x + 1ll * (len % k) * y;
    } else {
      cost += min(1ll * (len / k) * x + 1ll * (len % k) * y, 1ll * len * y);
    }
    l = r;
  }
  cout << cost << '\n';
  return 0;
}
