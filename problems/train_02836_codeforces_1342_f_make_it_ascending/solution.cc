#include <bits/stdc++.h>
template <typename int_t>
inline int_t lowbit(int_t x) {
  return x & -x;
}
inline int h_bit(unsigned long long x) {
  return int(sizeof(unsigned long long) * 8 - __builtin_clzll(x));
}
unsigned long long pow2(unsigned long long x) {
  return x == lowbit(x) ? x : 1ull << h_bit(x);
}
template <typename T>
int get_bit(T a, int i) {
  return a >> i & 1;
}
template <typename T>
T get_mid(T l, T r) {
  assert(l <= r);
  return l + (r - l >> 1);
}
using std::to_string;
std::string to_string(const std::string &s) { return '"' + s + '"'; }
std::string to_string(const char *s) { return to_string((std::string)s); }
std::string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
std::string to_string(const std::pair<A, B> &p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <size_t N>
std::string to_string(const std::bitset<N> &bs) {
  return bs.to_string();
}
template <typename A>
std::string to_string(const A &v) {
  bool first = true;
  std::string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { std::cerr << std::endl; }
template <typename Head, typename... Tail>
void debug_out(const Head &H, const Tail &...T) {
  std::cerr << " " << to_string(H);
  debug_out(T...);
}
struct fast_ios {
  fast_ios() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
  };
} fast_ios_;
template <typename T>
std::istream &operator>>(std::istream &stream, std::vector<T> &vec) {
  for (auto &x : vec) stream >> x;
  return stream;
}
template <typename T, typename U>
std::istream &operator>>(std::istream &in, std::pair<T, U> &p) {
  in >> p.first >> p.second;
  return in;
}
void scan() {}
template <class T, class... Args>
void scan(T &a, Args &...rest) {
  std::cin >> a;
  scan(rest...);
}
template <typename T>
std::ostream &operator<<(std::ostream &stream, const std::vector<T> &vec) {
  bool first = true;
  for (const T &t : vec) {
    if (first)
      first = false;
    else
      std::cout << ' ';
    std::cout << t;
  }
  return stream;
}
template <typename T, typename U>
std::ostream &operator<<(std::ostream &out, const std::pair<T, U> &p) {
  out << p.first << ' ' << p.second;
  return out;
}
template <typename T>
void print(const std::vector<std::vector<T>> &t) {
  for (const auto &row : t) {
    std::cout << row << '\n';
  }
}
template <typename T>
void print(const T &t) {
  std::cout << t << ' ';
}
template <typename T, typename... Args>
void print(const T &t, const Args &...rest) {
  print(t);
  print(rest...);
}
template <typename T>
void println(const T &t) {
  std::cout << t << '\n';
}
template <typename T, typename... Args>
void println(const T &t, const Args &...rest) {
  print(t);
  println(rest...);
}
template <typename A, typename B>
bool chkmin(A &a, const B &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
template <typename A, typename B>
bool chkmax(A &a, const B &b) {
  if (b > a) {
    a = b;
    return true;
  }
  return false;
}
using ll = long long;
using ull = unsigned long long;
using vl = std::vector<ll>;
using vb = std::vector<bool>;
using vi = std::vector<int>;
using pii = std::pair<int, int>;
using pli = std::pair<ll, int>;
using pll = std::pair<ll, ll>;
using vpii = std::vector<pii>;
template <typename T>
using vv = std::vector<std::vector<T>>;
template <typename T, typename U = std::less<T>>
using pq = std::priority_queue<T, std::vector<T>, U>;
template <typename T, typename U>
T ceil(T x, U y) {
  assert(y > 0);
  if (x > 0) x += y - 1;
  return x / y;
}
template <typename T, typename U>
T floor(T x, U y) {
  assert(y > 0);
  if (x < 0) x -= y - 1;
  return x / y;
}
using namespace std;
int dp[16][15][1 << 15];
pii pre[16][15][1 << 15];
class FMakeItAscending {
 public:
  static void solve(int, int) {
    int T;
    scan(T);
    for (int _iter_212 = 0, _num_212 = T; _iter_212 < _num_212; ++_iter_212) {
      int n;
      scan(n);
      vi a(n);
      scan(a);
      const int tot = 1 << n, all = tot - 1;
      for (std::common_type<decltype(1), decltype(n)>::type i = 1; i <= n; ++i)
        for (std::common_type<decltype(0), decltype(n)>::type j = 0; j < n; ++j)
          for (std::common_type<decltype(0), decltype(tot)>::type s = 0;
               s < tot; ++s)
            dp[i][j][s] = 0;
      vi sum(tot);
      for (std::common_type<decltype(0), decltype(tot)>::type i = 0; i < tot;
           ++i)
        for (std::common_type<decltype(0), decltype(n)>::type j = 0; j < n; ++j)
          if (get_bit(i, j)) sum[i] += a[j];
      for (std::common_type<decltype(1), decltype(tot)>::type s = 1; s < tot;
           ++s) {
        int i = __builtin_ctz(s);
        dp[1][i][s] = sum[s];
        pre[1][i][s] = {0, -1};
      }
      vpii ans;
      for (std::common_type<decltype(1), decltype(n)>::type i = 1; i < n; ++i) {
        for (std::common_type<decltype(0), decltype(n - 1)>::type j = 0;
             j < n - 1; ++j)
          for (std::common_type<decltype(1), decltype(1 << n)>::type s = 1;
               s < 1 << n; ++s)
            if (dp[i][j][s]) {
              for (int u = all xor s, t = u; t > 0 && h_bit(t) - 1 > j;
                   t = t - 1 & u) {
                if (sum[t] <= dp[i][j][s]) continue;
                for (std::common_type<decltype(j + 1), decltype(n)>::type k =
                         j + 1;
                     k < n; ++k)
                  if (get_bit(t, k)) {
                    auto &tar = dp[i + 1][k][s | t];
                    if (tar == 0 or tar > sum[t]) {
                      tar = sum[t];
                      pre[i + 1][k][s | t] = {s, j};
                    }
                    break;
                  }
              }
            }
        bool flag = false;
        for (std::common_type<decltype(0), decltype(n)>::type j = 0; j < n;
             ++j) {
          if (dp[i + 1][j][all]) {
            flag = true;
            break;
          }
        }
        if (!flag) {
          for (std::common_type<decltype(0), decltype(n)>::type j = 0; j < n;
               ++j)
            if (dp[i][j][all]) {
              int s = all;
              for (std::common_type<decltype(1), decltype(i)>::type k = i;
                   k >= 1; k--) {
                auto [ps, pj] = pre[k][j][s];
                int t = s ^ ps;
                for (std::common_type<decltype(0), decltype(n)>::type l = 0;
                     l < n; ++l)
                  if (get_bit(t, l) && l != j) ans.emplace_back(l, j);
                s = ps;
                j = pj;
              }
              break;
            }
          break;
        }
      }
      println((int)(ans).size());
      vb removed(n);
      auto get_index = [&](int i) {
        int res = 0;
        for (std::common_type<decltype(0), decltype(i)>::type j = 0; j < i; ++j)
          if (!removed[j]) ++res;
        return res + 1;
      };
      for (const auto &p : ans) {
        println(get_index(p.first), get_index(p.second));
        removed[p.first] = true;
      }
    }
  }
};
int main() {
  FMakeItAscending solver;
  solver.solve(0, 0);
  return 0;
}
