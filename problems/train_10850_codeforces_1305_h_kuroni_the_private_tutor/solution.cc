#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class t, class u>
void chmax(t& first, u second) {
  if (first < second) first = second;
}
template <class t, class u>
void chmin(t& first, u second) {
  if (second < first) first = second;
}
template <class t>
using vc = vector<t>;
template <class t>
using vvc = vc<vc<t>>;
using pi = pair<ll, ll>;
using vi = vc<ll>;
template <class t, class u>
ostream& operator<<(ostream& os, const pair<t, u>& p) {
  return os << "{" << p.first << "," << p.second << "}";
}
template <class t>
ostream& operator<<(ostream& os, const vc<t>& v) {
  os << "{";
  for (auto e : v) os << e << ",";
  return os << "}";
}
using uint = unsigned;
using ull = unsigned long long;
template <class t, size_t n>
ostream& operator<<(ostream& os, const array<t, n>& first) {
  return os << vc<t>(first.begin(), first.end());
}
template <ll i, class T>
void print_tuple(ostream&, const T&) {}
template <ll i, class T, class H, class... Args>
void print_tuple(ostream& os, const T& t) {
  if (i) os << ",";
  os << get<i>(t);
  print_tuple<i + 1, T, Args...>(os, t);
}
template <class... Args>
ostream& operator<<(ostream& os, const tuple<Args...>& t) {
  os << "{";
  print_tuple<0, tuple<Args...>, Args...>(os, t);
  return os << "}";
}
template <class t>
void print(t x, ll suc = 1) {
  cout << x;
  if (suc == 1) cout << "\n";
  if (suc == 2) cout << " ";
}
ll read() {
  ll i;
  cin >> i;
  return i;
}
vi readvi(ll n, ll off = 0) {
  vi v(n);
  for (ll i = ll(0); i < ll(n); i++) v[i] = read() + off;
  return v;
}
template <class T>
void print(const vector<T>& v, ll suc = 1) {
  for (ll i = ll(0); i < ll(v.size()); i++)
    print(v[i], i == ll(v.size()) - 1 ? suc : 2);
}
string readString() {
  string s;
  cin >> s;
  return s;
}
template <class T>
T sq(const T& t) {
  return t * t;
}
void yes(bool ex = true) {
  cout << "Yes"
       << "\n";
  if (ex) exit(0);
}
void no(bool ex = true) {
  cout << "No"
       << "\n";
  if (ex) exit(0);
}
void possible(bool ex = true) {
  cout << "Possible"
       << "\n";
  if (ex) exit(0);
}
void impossible(bool ex = true) {
  cout << "Impossible"
       << "\n";
  if (ex) exit(0);
}
constexpr ll ten(ll n) { return n == 0 ? 1 : ten(n - 1) * 10; }
const ll infLL = LLONG_MAX / 3;
const ll inf = infLL;
ll topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
ll topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
ll botbit(signed first) { return first == 0 ? 32 : __builtin_ctz(first); }
ll botbit(ll first) { return first == 0 ? 64 : __builtin_ctzll(first); }
ll popcount(signed t) { return __builtin_popcount(t); }
ll popcount(ll t) { return __builtin_popcountll(t); }
bool ispow2(ll i) { return i && (i & -i) == i; }
ll mask(ll i) { return (ll(1) << i) - 1; }
template <class t>
bool inc(t first, t second, t c) {
  return first <= second && second <= c;
}
template <class t>
void mkuni(vc<t>& v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
ll rand_int(ll l, ll r) {
  static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<ll>(l, r)(gen);
}
template <class t>
ll lwb(const vc<t>& v, const t& first) {
  return lower_bound(v.begin(), v.end(), first) - v.begin();
}
void muri() {
  cout << "-1 -1" << endl;
  exit(0);
}
ll ganbaruzoi(vi first, vi lw, vi up, ll z) {
  for (ll i = ll(0); i < ll(z); i++) chmin(up[i], up[z - 1]);
  for (ll i = ll(0); i < ll(z); i++) chmax(lw[i], lw[0]);
  for (ll i = ll(0); i < ll(z); i++)
    if (lw[i] > up[i]) return -1;
  ll n = ll(first.size());
  ll zorg = z;
  while (z < n && up[z] == inf) z++;
  ll need = 0, sum = 0, lim = 0;
  ll aff = 0;
  for (ll i = ll(n) - 1; i >= ll(0); i--) {
    if (first[i] < lw[i]) {
      need += lw[i] - first[i];
    } else {
      ll u = first[i] - lw[i];
      {
        ll w = min(u, need);
        u -= w;
        need -= w;
        sum += w;
        assert(sum <= lim);
      }
      if (need == 0 && u > up[i] - lw[i]) {
        ll w = min(u - (up[i] - lw[i]), lim - sum);
        assert(w >= 0);
        u -= w;
        sum += w;
        assert(sum <= lim);
      }
      first[i] = lw[i] + u;
      if (first[i] > up[i]) return -1;
    }
    sum += first[i];
    lim += up[i];
    chmin(lim, inf);
    if (i == z) aff = lim - (sum + need);
  }
  if (need > 0) return -1;
  if (up[0] == inf) {
    for (ll i = ll(0); i < ll(z); i++) chmax(first[i], lw[i]);
    ll s = accumulate(first.begin(), first.begin() + zorg, ll(0));
    ll p = s / zorg, q = s % zorg;
    assert(p >= lw[0]);
    for (ll i = ll(zorg); i < ll(z); i++) aff += p - first[i];
    if (q <= aff)
      return p;
    else
      return -1;
  } else {
    assert(lw[0] == up[0]);
    assert(lw[0] == first[0]);
    return first[0];
  }
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  ll n, m;
  cin >> n >> m;
  vi first(m + 1), second(m + 1);
  for (ll i = ll(0); i < ll(n); i++) {
    ll l, r;
    cin >> l >> r;
    first[0]++;
    first[l]--;
    second[l]++;
    second[r]--;
  }
  for (ll i = ll(0); i < ll(m); i++) first[i + 1] += first[i];
  for (ll i = ll(0); i < ll(m); i++) second[i + 1] += second[i];
  first.pop_back();
  second.pop_back();
  vi lw(m, 0), up(m, inf);
  {
    ll q;
    cin >> q;
    for (ll _ = ll(0); _ < ll(q); _++) {
      ll p, s;
      cin >> p >> s;
      p--;
      chmax(lw[p], s);
      chmin(up[p], s);
    }
    for (ll i = ll(0); i < ll(m - 1); i++) chmin(up[i + 1], up[i]);
    for (ll i = ll(m - 1) - 1; i >= ll(0); i--) chmax(lw[i], lw[i + 1]);
  }
  {
    ll t;
    cin >> t;
    for (ll i = ll(0); i < ll(m); i++) t -= first[i];
    if (t < 0) muri();
    for (ll i = ll(0); i < ll(m); i++) {
      ll u = min(t, second[i]);
      first[i] += u;
      t -= u;
    }
    if (t > 0) muri();
    for (ll i = ll(0); i < ll(m - 1); i++) assert(first[i] >= first[i + 1]);
  }
  void(0);
  ll ok = 0, ng = m + 1;
  while (ng - ok > 1) {
    const ll mid = (ok + ng) / 2;
    ll w = ganbaruzoi(first, lw, up, mid);
    if (w != -1)
      ok = mid;
    else
      ng = mid;
  }
  if (ok == 0) muri();
  ll w = ganbaruzoi(first, lw, up, ok);
  cout << ok << " " << w << endl;
}
