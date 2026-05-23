#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000009;
const unsigned int M = 1000000007;
const long long INFLL = (long long)INF * (long long)INF;
const long double EPS = 10e-9;
template <typename T>
void ckmin(T &a, const T &b) {
  a = min(a, b);
}
template <typename T>
void ckmax(T &a, const T &b) {
  a = max(a, b);
}
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
namespace __input {
template <class T1, class T2>
void re(pair<T1, T2> &p);
template <class T>
void re(vector<T> &a);
template <class T, size_t SZ>
void re(array<T, SZ> &a);
template <class T>
void re(T &x) {
  cin >> x;
}
void re(double &x) {
  string t;
  re(t);
  x = stod(t);
}
template <class Arg, class... Args>
void re(Arg &first, Args &...rest) {
  re(first);
  re(rest...);
}
template <class T1, class T2>
void re(pair<T1, T2> &p) {
  re(p.f, p.s);
}
template <class T>
void re(vector<T> &a) {
  for (int i = 0; i < int((a).size()); i++) re(a[i]);
}
template <class T, size_t SZ>
void re(array<T, SZ> &a) {
  for (int i = 0; i < SZ; i++) re(a[i]);
}
}  // namespace __input
using namespace __input;
namespace __output {
template <typename T>
struct is_outputtable {
  template <typename C>
  static constexpr decltype(declval<ostream &>() << declval<const C &>(),
                            bool())
  test(int) {
    return true;
  }
  template <typename C>
  static constexpr bool test(...) {
    return false;
  }
  static constexpr bool value = test<T>(int());
};
template <
    class T, typename V = decltype(declval<const T &>().begin()),
    typename second = typename enable_if<!is_outputtable<T>::value, bool>::type>
void pr(const T &x);
template <class T,
          typename V = decltype(declval<ostream &>() << declval<const T &>())>
void pr(const T &x) {
  cout << x;
}
template <class T1, class T2>
void pr(const pair<T1, T2> &x);
template <class Arg, class... Args>
void pr(const Arg &first, const Args &...rest) {
  pr(first);
  pr(rest...);
}
template <class T, bool pretty = true>
void prContain(const T &x) {
  if (pretty) pr("{");
  bool fst = 1;
  for (const auto &a : x) pr(!fst ? pretty ? ", " : " " : "", a), fst = 0;
  if (pretty) pr("}");
}
template <class T>
void pc(const T &x) {
  prContain<T, false>(x);
  pr("\n");
}
template <class T1, class T2>
void pr(const pair<T1, T2> &x) {
  pr("{", x.f, ", ", x.s, "}");
}
template <class T, typename V, typename second>
void pr(const T &x) {
  prContain(x);
}
void ps() { pr("\n"); }
template <class Arg>
void ps(const Arg &first) {
  pr(first);
  ps();
}
template <class Arg, class... Args>
void ps(const Arg &first, const Args &...rest) {
  pr(first, " ");
  ps(rest...);
}
}  // namespace __output
using namespace __output;
namespace __io {
void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(15);
}
}  // namespace __io
using namespace __io;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
void solve() {
  long long n, m;
  re(n, m);
  vector<long long> a(n), p(m);
  re(a, p);
  sort(p.begin(), p.end());
  long long i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        if (binary_search(p.begin(), p.end(), j + 1))
          swap(a[j], a[j + 1]);
        else {
          ps("NO");
          return;
        }
      }
    }
  }
  ps("YES");
}
int32_t main() {
  setIO();
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
