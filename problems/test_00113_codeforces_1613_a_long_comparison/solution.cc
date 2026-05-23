#include <bits/stdc++.h>
using namespace std;
template <typename T, size_t N>
int SIZE(const T (&t)[N]) {
  return N;
}
template <typename T>
int SIZE(const T &t) {
  return t.size();
}
string to_string(const string s, int x1 = 0, int x2 = 1e9) {
  return '"' + ((x1 < s.size()) ? s.substr(x1, x2 - x1 + 1) : "") + '"';
}
string to_string(const char *s) { return to_string((string)s); }
string to_string(const bool b) { return (b ? "true" : "false"); }
string to_string(const char c) { return string({c}); }
template <size_t N>
string to_string(const bitset<N> &b, int x1 = 0, int x2 = 1e9) {
  string t = "";
  for (int __iii__ = min(x1, SIZE(b)), __jjj__ = min(x2, SIZE(b) - 1);
       __iii__ <= __jjj__; ++__iii__) {
    t += b[__iii__] + '0';
  }
  return '"' + t + '"';
}
template <typename A, typename... C>
string to_string(const A(&v), int x1 = 0, int x2 = 1e9, C... coords);
int l_v_l_v_l = 0, t_a_b_s = 0;
template <typename A, typename B>
string to_string(const pair<A, B> &p) {
  l_v_l_v_l++;
  string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
  l_v_l_v_l--;
  return res;
}
template <typename A, typename... C>
string to_string(const A(&v), int x1, int x2, C... coords) {
  int rnk = rank<A>::value;
  string tab(t_a_b_s, ' ');
  string res = "";
  bool first = true;
  if (l_v_l_v_l == 0) res += '\n';
  res += tab + "[";
  x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v));
  auto l = begin(v);
  advance(l, x1);
  auto r = l;
  advance(r, (x2 - x1) + (x2 < SIZE(v)));
  for (auto e = l; e != r; e = next(e)) {
    if (!first) {
      res += ", ";
    }
    first = false;
    l_v_l_v_l++;
    if (e != l) {
      if (rnk > 1) {
        res += '\n';
        t_a_b_s = l_v_l_v_l;
      };
    } else {
      t_a_b_s = 0;
    }
    res += to_string(*e, coords...);
    l_v_l_v_l--;
  }
  res += "]";
  if (l_v_l_v_l == 0) res += '\n';
  return res;
}
void dbgm() { ; }
template <typename Heads, typename... Tails>
void dbgm(Heads H, Tails... T) {
  cerr << to_string(H) << " | ";
  dbgm(T...);
}
double eps = 1e-9;
double PI = acos(-1);
const int MOD = 1000000007;
void solve() {
  string x;
  int p;
  cin >> x >> p;
  string xx;
  int pp;
  cin >> xx >> pp;
  int msz = x.size(), nsz = xx.size();
  int i = x.size() - 1;
  int cnt1 = 0, cnt2 = 0;
  for (; i >= 0; i--) {
    if (x[i] == '0') {
      p++;
      msz--;
      cnt1++;
    } else {
      i++;
      break;
    }
  }
  x.erase(i, cnt1);
  i = xx.size() - 1;
  for (; i >= 0; i--) {
    if (xx[i] == '0') {
      pp++;
      nsz--;
      cnt2++;
    } else {
      i++;
      break;
    }
  }
  xx.erase(i, cnt2);
  int n, m;
  n = p + msz;
  m = pp + nsz;
  cerr << "------------" << '\n'
       << __func__ << ":" << 195 << " ==> "
       << "["
       << "n, m, x, xx, p, pp"
       << "]:  ";
  dbgm(n, m, x, xx, p, pp);
  cerr << '\n';
  if (n > m) {
    cout << ">" << '\n';
    return;
  }
  if (n < m) {
    cout << "<" << '\n';
    return;
  }
  if (n == m) {
    if (x.size() > xx.size()) {
      int diff = x.size() - xx.size();
      for (int i = 0; i < (int)diff; ++i) {
        xx += '0';
      }
    }
    if (x.size() < xx.size()) {
      int diff = xx.size() - x.size();
      for (int i = 0; i < (int)diff; ++i) {
        x += '0';
      }
    }
    int c = stoi(x);
    int d = stoi(xx);
    if (c == d) {
      cout << "=" << '\n';
      return;
    }
    if (c > d) {
      cout << ">" << '\n';
      return;
    }
    if (c < d) {
      cout << "<" << '\n';
      return;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);
  int cases;
  cases = 1;
  cin >> cases;
  for (int i = 1; i <= cases; i++) {
    solve();
  }
}
