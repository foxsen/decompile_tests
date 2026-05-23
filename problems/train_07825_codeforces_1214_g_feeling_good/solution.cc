#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
template <int n, class... T>
typename std::enable_if<(n >= sizeof...(T))>::type __output_tuple(
    std::ostream &, std::tuple<T...> const &) {}
template <int n, class... T>
typename std::enable_if<(n < sizeof...(T))>::type __output_tuple(
    std::ostream &os, std::tuple<T...> const &t) {
  os << (n == 0 ? "" : ", ") << std::get<n>(t);
  __output_tuple<n + 1>(os, t);
}
template <class... T>
std::ostream &operator<<(std::ostream &os, std::tuple<T...> const &t) {
  os << "(";
  __output_tuple<0>(os, t);
  os << ")";
  return os;
}
template <class T, class U>
std::ostream &operator<<(std::ostream &os, std::pair<T, U> const &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, const std::stack<T> &a) {
  os << "{";
  for (auto tmp = a; tmp.size(); tmp.pop())
    os << (a.size() == tmp.size() ? "" : ", ") << tmp.top();
  os << "}";
  return os;
}
template <class T, class Container, class Compare>
std::ostream &operator<<(std::ostream &os,
                         std::priority_queue<T, Container, Compare> a) {
  os << "{ (top) ";
  while (a.size()) os << a.top() << (a.size() == 1 ? "" : ", "), a.pop();
  os << " }";
  return os;
}
template <class T, class Container>
std::ostream &operator<<(std::ostream &os, std::queue<T, Container> a) {
  os << "{ ";
  while (a.size()) os << a.front() << (a.size() == 1 ? "" : ", "), a.pop();
  os << " }";
  return os;
}
template <
    class T,
    class = typename std::iterator_traits<decltype(begin(T()))>::value_type,
    class = typename std::enable_if<!std::is_same<T, std::string>::value>::type>
std::ostream &operator<<(std::ostream &os, const T &a) {
  for (auto ite = begin(a); ite != end(a); ++ite)
    os << (ite == begin(a) ? "" : " ") << *ite;
  return os;
}
template <int N>
struct BitSet {
  static constexpr int logmsbll(ull x) {
    int h = 0;
    x = x & 0xFFFFFFFF00000000 ? (h += 32, x) & 0xFFFFFFFF00000000 : x;
    x = x & 0xFFFF0000FFFF0000 ? (h += 16, x) & 0xFFFF0000FFFF0000 : x;
    x = x & 0xFF00FF00FF00FF00 ? (h += 8, x) & 0xFF00FF00FF00FF00 : x;
    x = x & 0xF0F0F0F0F0F0F0F0 ? (h += 4, x) & 0xF0F0F0F0F0F0F0F0 : x;
    x = x & 0xCCCCCCCCCCCCCCCC ? (h += 2, x) & 0xCCCCCCCCCCCCCCCC : x;
    x = x & 0xAAAAAAAAAAAAAAAA ? (h += 1, x) & 0xAAAAAAAAAAAAAAAA : x;
    return h;
  }
  static constexpr int popcountll(ull x) {
    if (x == 0) return 0;
    return __builtin_popcountll(x);
    x = (x & 0x5555555555555555) + ((x & 0xAAAAAAAAAAAAAAAA) >> 1);
    x = (x & 0x3333333333333333) + ((x & 0xCCCCCCCCCCCCCCCC) >> 2);
    x = (x & 0x0F0F0F0F0F0F0F0F) + ((x & 0xF0F0F0F0F0F0F0F0) >> 4);
    x = (x & 0x00FF00FF00FF00FF) + ((x & 0xFF00FF00FF00FF00) >> 8);
    x = (x & 0x0000FFFF0000FFFF) + ((x & 0xFFFF0000FFFF0000) >> 16);
    x = (x & 0x00000000FFFFFFFF) + ((x & 0xFFFFFFFF00000000) >> 32);
    return x;
  }
  static ull mr(int l, int r) {
    assert(0 <= l and l <= r and r <= 63);
    if (r == 63) {
      if (l == 0) return -1;
      return ull(-1) ^ ((1ull << (l)) - 1);
    }
    if (l == 0) return ((1ull << (r + 1)) - 1);
    return ((1ull << (r + 1)) - 1) ^ ((1ull << (l)) - 1);
  }
  static constexpr int SZ = (N + 63) / 64;
  unsigned long long x[SZ];
  int stand = 0;
  BitSet &operator|=(BitSet b) {
    stand = -1;
    for (int i = 0; i < SZ; i++) x[i] |= b.x[i];
    return *this;
  }
  BitSet &operator&=(BitSet b) {
    stand = -1;
    for (int i = 0; i < SZ; i++) x[i] &= b.x[i];
    return *this;
  }
  BitSet operator|(BitSet b) const {
    auto c = *this;
    c |= b;
    return c;
  }
  BitSet operator&(BitSet b) const {
    auto c = *this;
    c &= b;
    return c;
  }
  BitSet operator~() const {
    auto c = *this;
    c.flipAll();
    return c;
  }
  bool operator==(BitSet b) const {
    for (int i = 0; i < SZ; i++)
      if (x[i] != b.x[i]) return 0;
    return 1;
  }
  bool operator!=(BitSet b) const { return !(*this == b); }
  int getStand() {
    if (stand == -1) {
      stand = 0;
      for (int i = 0; i < SZ; i++) stand += popcountll(x[i]);
    }
    return stand;
  }
  bool get(int i) const {
    assert(0 <= i and i < SZ * 64);
    return (x[i / 64] >> (i % 64)) & 1;
  }
  void set(int i) {
    assert(0 <= i and i < SZ * 64);
    x[i / 64] |= 1ull << (i % 64);
  }
  int next(int n = 0) const {
    if (n >= N) return -1;
    if (n < 0) n = 0;
    ull z = x[n / 64] & mr(n % 64, 63);
    if (z) {
      return n / 64 * 64 + logmsbll(z);
    }
    for (int i = n / 64 + 1; i < SZ; i++)
      if (x[i]) {
        return i * 64 + logmsbll(x[i]);
      }
    return -1;
  }
  void flip(int l, int r) {
    assert(0 <= l && l <= r && r < N);
    int lg = l / 64;
    int rg = r / 64;
    stand = -1;
    if (lg == rg) {
      x[lg] ^= mr(l % 64, r % 64);
    } else {
      x[lg] ^= mr(l % 64, 63);
      x[rg] ^= mr(0, r % 64);
      for (int g = lg + 1; g < rg; g++) {
        x[g] ^= -1;
      }
    }
  }
  void flipAll() {
    if (stand != -1) stand = N - stand;
    for (int i = 0; i < SZ; i++) x[i] = ~x[i];
  }
  friend ostream &operator<<(ostream &os, BitSet bs) {
    for (int i = 0; i < BitSet::SZ - 1; i++)
      for (int j = 0; j < 64; j++)
        os << (((bs.x[i] >> j) & 1) == 1 ? '1' : '0');
    for (int j = 0; j < 64; j++)
      os << (((bs.x[SZ - 1] >> j) & 1) == 1 ? '1' : '0');
    return os;
  }
};
int n, m, q;
BitSet<2000> bs[2000];
int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);
  cin >> n >> m >> q;
  vector<tuple<int, int, int, int>> data(n);
  set<int> valid;
  set<pair<int, int>> rnk;
  vector<int> cnt(n, 0);
  for (int i = 0; i < n; i++) rnk.emplace(0, i);
  auto upd = [&](int x, int y) -> void {
    if (cnt[x] == 0) return;
    valid.erase(x);
    int x1 = x, x2 = y;
    int y1 = (bs[x] & ~bs[y]).next();
    int y2 = (~bs[x] & bs[y]).next();
    if (y1 != -1 and y2 != -1) {
      valid.insert(x);
      data[x] = make_tuple(x1, y1, x2, y2);
    }
  };
  for (int i = 0; i < q; i++) {
    int a, l, r;
    cin >> a >> l >> r;
    a--, l--, r--;
    assert(rnk.size() == n);
    auto ite = rnk.find(make_pair(cnt[a], a));
    valid.erase(a);
    if (ite != rnk.begin()) {
      int prv = prev(ite)->second;
      valid.erase(prv);
      if (next(ite) != rnk.end()) {
        int nxt = next(ite)->second;
        rnk.erase(ite);
        upd(prv, nxt);
      } else {
        rnk.erase(ite);
      }
    } else {
      rnk.erase(ite);
    }
    bs[a].flip(l, r);
    int st = bs[a].getStand();
    cnt[a] = st;
    auto p = make_pair(st, a);
    ite = rnk.insert(p).first;
    {
      if (ite != rnk.begin()) {
        upd(prev(ite)->second, a);
      }
    }
    {
      if (next(ite) != rnk.end()) {
        upd(a, next(ite)->second);
      }
    }
    if (valid.size()) {
      auto ans = data[*valid.begin()];
      int x1, y1, x2, y2;
      tie(x1, y1, x2, y2) = ans;
      if (x1 > x2) swap(x1, x2);
      if (y1 > y2) swap(y1, y2);
      assert(bs[x1].get(y1) == bs[x2].get(y2));
      assert(bs[x1].get(y2) == bs[x1].get(y2));
      assert(bs[x1].get(y1) != bs[x1].get(y2));
      cout << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
  return 0;
}
