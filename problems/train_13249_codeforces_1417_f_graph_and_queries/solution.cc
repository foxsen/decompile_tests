#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using LD = long double;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using PLD = pair<LD, LD>;
using VI = vector<int>;
using VLL = vector<LL>;
using VLD = vector<LD>;
using VPII = vector<PII>;
using VPLL = vector<PLL>;
using VPLD = vector<PLD>;
using VVI = vector<VI>;
const int inf = 1e9 + 7;
const int MOD = 998244353;
const LL INF = 1e18 + 7;
const long double PI = acos(-1);
const LD EPS = 1e-9;
namespace input {
template <class T>
istream& operator>>(istream& st, vector<T>& container) {
  for (auto& u : container) st >> u;
  return st;
}
template <class T, size_t N>
istream& operator>>(istream& st, array<T, N>& container) {
  for (auto& u : container) st >> u;
  return st;
}
template <class T, class U>
istream& operator>>(istream& st, pair<T, U>& p) {
  st >> p.first >> p.second;
  return st;
}
void re() {}
template <typename T, typename... TArgs>
void re(T& x, TArgs&... rest) {
  cin >> x;
  re(rest...);
}
}  // namespace input
using namespace input;
namespace output {
template <class T>
ostream& operator<<(ostream& st, const vector<T>& container) {
  for (auto& u : container) st << u << ' ';
  return st;
}
template <class T, size_t N>
ostream& operator<<(ostream& st, const array<T, N>& container) {
  for (auto& u : container) st << u << ' ';
  return st;
}
template <class T, class U>
ostream& operator<<(ostream& st, pair<T, U> p) {
  st << p.first << ' ' << p.second;
  return st;
}
void pr() {}
template <typename T>
void pr(const T& x) {
  cout << x;
}
template <typename T, typename... TArgs>
void pr(const T& x, const TArgs&... rest) {
  cout << x << ' ';
  pr(rest...);
}
template <typename... TArgs>
void prln(const TArgs&... args) {
  pr(args...);
  cout << '\n';
}
}  // namespace output
using namespace output;
namespace pairs {
template <class T, class U, class V>
pair<T, U> operator*(pair<T, U> p, V val) {
  return {p.first * val, p.second * val};
}
template <class T, class U, class V>
pair<T, U> operator/(pair<T, U> p, V val) {
  return {p.first / val, p.second / val};
}
template <class T, class U>
pair<T, U> operator-(pair<T, U> a, pair<T, U> b) {
  return {a.first - b.first, a.second - b.second};
}
template <class T, class U>
pair<T, U> operator+(pair<T, U> a, pair<T, U> b) {
  return {a.first + b.first, a.second + b.second};
}
}  // namespace pairs
using namespace pairs;
namespace triples {
template <class T1, class T2, class T3>
struct triple {
  T1 x;
  T2 y;
  T3 z;
  triple() : x(T1()), y(T2()), z(T3()){};
  triple(T1 _x, T2 _y, T3 _z) : x(_x), y(_y), z(_z) {}
};
template <class T1, class T2, class T3>
bool operator<(const triple<T1, T2, T3>& t1, const triple<T1, T2, T3>& t2) {
  if (t1.x != t2.x) return t1.x < t2.x;
  if (t1.y != t2.y)
    return t1.y < t2.y;
  else
    return t1.z < t2.z;
}
template <class T1, class T2, class T3>
bool operator>(const triple<T1, T2, T3>& t1, const triple<T1, T2, T3>& t2) {
  if (t1.x != t2.x) return t1.x > t2.x;
  if (t1.y != t2.y)
    return t1.y > t2.y;
  else
    return t1.z > t2.z;
}
template <class T1, class T2, class T3>
bool operator==(const triple<T1, T2, T3>& t1, const triple<T1, T2, T3>& t2) {
  return (t1.x == t2.x && t1.y == t2.y && t1.z == t2.z);
}
template <class T1, class T2, class T3>
inline istream& operator>>(istream& os, triple<T1, T2, T3>& t) {
  return os >> t.x >> t.y >> t.y;
}
template <class T1, class T2, class T3>
ostream& operator<<(ostream& os, const triple<T1, T2, T3>& t) {
  return os << t.x << " " << t.y << " " << t.z;
}
template <class T1, class T2, class T3>
triple<T1, T2, T3> operator+(triple<T1, T2, T3> a, triple<T1, T2, T3> b) {
  return {a.x + b.x, a.y + b.y, a.z + b.z};
}
template <class T1, class T2, class T3>
triple<T1, T2, T3> operator-(triple<T1, T2, T3> a, triple<T1, T2, T3> b) {
  return {a.x - b.x, a.y - b.y, a.z - b.z};
}
template <class T1, class T2, class T3, class T4>
triple<T1, T2, T3> operator*(triple<T1, T2, T3> a, T4 val) {
  return {a.x * val, a.y * val, a.z * val};
}
template <class T1, class T2, class T3, class T4>
triple<T1, T2, T3> operator/(triple<T1, T2, T3> a, T4 val) {
  return {a.x / val, a.y / val, a.z / val};
}
using TRII = triple<int, int, int>;
using TRLL = triple<LL, LL, LL>;
using TRLD = triple<LD, LD, LD>;
using VTRII = vector<TRII>;
using VTRLL = vector<TRLL>;
using VTRLD = vector<TRLD>;
}  // namespace triples
using namespace triples;
namespace geo {
template <class T>
T dotProduct(pair<T, T> a, pair<T, T> b) {
  return a.first * b.first + a.second * b.second;
}
template <class T>
T crossProduct(pair<T, T> a, pair<T, T> b) {
  return a.first * b.second - a.second * b.first;
}
template <class T>
T lengthPow(pair<T, T> a) {
  return a.first * 1ll * a.first + a.second * 1ll * a.second;
}
template <class T>
LD length(pair<T, T> a) {
  return sqrt(lengthPow(a));
}
template <class T>
T dotProduct(triple<T, T, T> a, triple<T, T, T> b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}
template <class T>
T crossProduct(triple<T, T, T> a, triple<T, T, T> b) {
  return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}
template <class T>
T lengthPow(triple<T, T, T> a) {
  return a.x * 1ll * a.x + a.y * 1ll * a.y + a.z * 1ll * a.z;
}
template <class T>
LD length(triple<T, T, T> a) {
  return sqrt(lengthPow(a));
}
}  // namespace geo
using namespace geo;
template <class T>
T invGeneral(T a, T b) {
  a %= b;
  if (a == 0) return b == 1 ? 0 : -1;
  T x = invGeneral(b, a);
  return x == -1 ? -1 : ((1 - (LL)b * x) / a + b) % b;
}
template <class T>
struct modular {
  T val;
  explicit operator T() const { return val; }
  modular() { val = 0; }
  modular(const LL& v) {
    val = (-MOD <= v && v <= MOD) ? v : v % MOD;
    if (val < 0) val += MOD;
  }
  friend ostream& operator<<(ostream& os, const modular& a) {
    return os << a.val;
  }
  friend void pr(const modular& a) { pr(a.val); }
  friend void re(modular& a) {
    LL x;
    re(x);
    a = modular(x);
  }
  friend bool operator==(const modular& a, const modular& b) {
    return a.val == b.val;
  }
  friend bool operator!=(const modular& a, const modular& b) {
    return !(a == b);
  }
  friend bool operator<(const modular& a, const modular& b) {
    return a.val < b.val;
  }
  modular operator-() const { return modular(-val); }
  modular& operator+=(const modular& m) {
    if ((val += m.val) >= MOD) val -= MOD;
    return *this;
  }
  modular& operator-=(const modular& m) {
    if ((val -= m.val) < 0) val += MOD;
    return *this;
  }
  modular& operator*=(const modular& m) {
    val = (LL)val * m.val % MOD;
    return *this;
  }
  friend modular pow(modular a, LL p) {
    modular ans = 1;
    for (; p; p /= 2, a *= a)
      if (p & 1) ans *= a;
    return ans;
  }
  friend modular inv(const modular& a) {
    auto i = invGeneral(a.val, MOD);
    assert(i != -1);
    return i;
  }
  modular& operator/=(const modular& m) { return (*this) *= inv(m); }
  friend modular operator+(modular a, const modular& b) { return a += b; }
  friend modular operator-(modular a, const modular& b) { return a -= b; }
  friend modular operator*(modular a, const modular& b) { return a *= b; }
  friend modular operator/(modular a, const modular& b) { return a /= b; }
};
using MI = modular<int>;
using PMI = pair<MI, MI>;
using VMI = vector<MI>;
using VPMI = vector<PMI>;
namespace debug {
template <typename _T>
inline void _debug(const char* s, _T x) {
  cerr << s << " = " << x << "\n";
}
template <typename _T, typename... args>
void _debug(const char* s, _T x, args... a) {
  while (*s != ',') cerr << *s++;
  cerr << " = " << x << ',';
  _debug(s + 1, a...);
}
}  // namespace debug
using namespace debug;
template <class T>
bool setMax(T& v, T newV) {
  if (v < newV) {
    v = newV;
    return true;
  }
  return false;
}
template <class T>
bool setMin(T& v, T newV) {
  if (v > newV) {
    v = newV;
    return true;
  }
  return false;
}
const int N = 5e5 + 7;
namespace DSU {
int tab[N];
int sz[N];
VI members[N];
void init(int n) {
  for (int i = (0); (1) > 0 ? i < (n) : i >= (n); i += (1)) {
    sz[i] = 1;
    tab[i] = i;
    members[i] = {i};
  }
}
int Find(int a) {
  if (tab[a] != a) tab[a] = Find(tab[a]);
  return tab[a];
}
void Union(int a, int b) {
  a = Find(a);
  b = Find(b);
  if (a == b) return;
  if (sz[a] < sz[b]) swap(a, b);
  tab[b] = a;
  sz[a] += sz[b];
  members[a].insert(members[a].end(), begin((members[b])), end((members[b])));
}
}  // namespace DSU
int val[N];
bool validEdge[N];
bool ok[N];
VI ids[N];
PII queries[N];
int setID[N];
set<int, greater<int>> sety[2 * N];
void solve() {
  int n, m, q;
  re(n, m, q);
  VPII kra;
  VI edgeQue;
  DSU::init(n);
  for (int i = (0); (1) > 0 ? i < (n) : i >= (n); i += (1)) {
    re(val[i]);
  }
  for (int i = (0); (1) > 0 ? i < (m) : i >= (m); i += (1)) validEdge[i] = 1;
  for (int i = (0); (1) > 0 ? i < (m) : i >= (m); i += (1)) {
    int a, b;
    re(a, b);
    --a, --b;
    kra.push_back({a, b});
  }
  for (int i = (0); (1) > 0 ? i < (q) : i >= (q); i += (1)) {
    int t, a;
    re(t, a);
    --a;
    queries[i] = {t, a};
    if (t == 2) {
      validEdge[a] = false;
      edgeQue.push_back(a);
    }
  }
  reverse(begin((edgeQue)), end((edgeQue)));
  for (int i = (0); (1) > 0 ? i < (m) : i >= (m); i += (1)) {
    if (not validEdge[i]) continue;
    DSU::Union(kra[i].first, kra[i].second);
  }
  for (const auto& edgeID : edgeQue) {
    auto a = DSU::Find(kra[edgeID].first);
    auto b = DSU::Find(kra[edgeID].second);
    if (a == b) continue;
    if (DSU::sz[a] > DSU::sz[b]) swap(a, b);
    ids[edgeID] = DSU::members[a];
    DSU::Union(a, b);
  }
  int cnt = 0;
  map<int, int> iddd;
  for (int i = (0); (1) > 0 ? i < (n) : i >= (n); i += (1)) {
    int a = DSU::Find(i);
    if (iddd.count(a) == 0) iddd[a] = ++cnt;
    setID[i] = iddd[a];
    sety[setID[i]].insert(val[i]);
  }
  for (int i = (0); (1) > 0 ? i < (q) : i >= (q); i += (1)) {
    auto [t, a] = queries[i];
    if (t == 1) {
      auto& set = sety[setID[a]];
      if (set.empty()) {
        prln(0);
        continue;
      }
      prln(*set.begin());
      set.erase(set.begin());
    } else {
      ++cnt;
      auto& setOld = sety[setID[kra[a].first]];
      auto& setNew = sety[cnt];
      for (auto u : ids[a]) {
        setID[u] = cnt;
        if (setOld.erase(val[u])) setNew.insert(val[u]);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cout << fixed << setprecision(13);
  int t = 1;
  for (int i = 1; i <= t; ++i) {
    solve();
  }
  return 0;
}
