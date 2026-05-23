#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005ll;
double PI = acos(-1);
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};
template <typename T>
int SIZE(T(&t)) {
  return t.size();
}
template <typename T, size_t N>
int SIZE(T (&t)[N]) {
  return N;
}
string to_string(char t) { return "'" + string({t}) + "'"; }
string to_string(bool t) { return t ? "true" : "false"; }
string to_string(const string &t, int x1 = 0, int x2 = 1e9) {
  string ret = "";
  for (int i = min(x1, SIZE(t)), _i = min(x2, SIZE(t) - 1); i <= _i; ++i) {
    ret += t[i];
  }
  return '"' + ret + '"';
}
string to_string(const char *t) {
  string ret(t);
  return to_string(ret);
}
template <size_t N>
string to_string(const bitset<N> &t, int x1 = 0, int x2 = 1e9) {
  string ret = "";
  for (int i = min(x1, SIZE(t)); i <= min(x2, SIZE(t) - 1); ++i) {
    ret += t[i] + '0';
  }
  return to_string(ret);
}
template <typename T, typename... Coords>
string to_string(const T(&t), int x1 = 0, int x2 = 1e9, Coords... C);
template <typename T, typename S>
string to_string(const pair<T, S> &t) {
  return "(" + to_string(t.first) + ", " + to_string(t.second) + ")";
}
template <typename T, typename... Coords>
string to_string(const T(&t), int x1, int x2, Coords... C) {
  string ret = "[";
  x1 = min(x1, SIZE(t));
  auto e = begin(t);
  advance(e, x1);
  for (int i = x1, _i = min(x2, SIZE(t) - 1); i <= _i; ++i) {
    ret += to_string(*e, C...) + (i != _i ? ", " : "");
    e = next(e);
  }
  return ret + "]";
}
template <int Index, typename... Ts>
struct print_tuple {
  string operator()(const tuple<Ts...> &t) {
    string ret = print_tuple<Index - 1, Ts...>{}(t);
    ret += (Index ? ", " : "");
    return ret + to_string(get<Index>(t));
  }
};
template <typename... Ts>
struct print_tuple<0, Ts...> {
  string operator()(const tuple<Ts...> &t) { return to_string(get<0>(t)); }
};
template <typename... Ts>
string to_string(const tuple<Ts...> &t) {
  const auto Size = tuple_size<tuple<Ts...>>::value;
  return print_tuple<Size - 1, Ts...>{}(t);
}
void dbgr() { ; }
template <typename Heads, typename... Tails>
void dbgr(Heads H, Tails... T) {
  cout << to_string(H) << " | ";
  dbgr(T...);
}
void dbgs() { ; }
template <typename Heads, typename... Tails>
void dbgs(Heads H, Tails... T) {
  cout << H << " ";
  dbgs(T...);
}
const int MOD = 1000000007;
template <typename T_vector>
void output_vector(const T_vector &v, bool line_break = false,
                   bool add_one = false, int start = -1, int end = -1) {
  if (start < 0) start = 0;
  if (end < 0) end = int(v.size());
  for (int i = start; i < end; i++) {
    cout << v[i] + (add_one ? 1 : 0)
         << (line_break    ? '\n'
             : i < end - 1 ? ' '
                           : '\n');
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int(i) = (0); (i) < (n); ++(i)) cin >> s[i];
  vector<vector<int>> a(n, vector<int>(m, INF));
  for (int(i) = (0); (i) < (n); ++(i)) {
    int t = INF;
    for (int(k) = (0); (k) < (2); ++(k)) {
      for (int(j) = (0); (j) < (m); ++(j)) {
        if (s[i][j] == '1')
          t = 0;
        else
          t++;
        a[i][j] = min(a[i][j], t);
      }
    }
    for (int(k) = (0); (k) < (2); ++(k)) {
      for (int(j) = (m - 1); (j) >= (0); --(j)) {
        if (s[i][j] == '1')
          t = 0;
        else
          t++;
        a[i][j] = min(a[i][j], t);
      }
    }
  }
  int ans = INF;
  for (int(i) = (0); (i) < (m); ++(i)) {
    int t = 0;
    for (int(j) = (0); (j) < (n); ++(j)) t = min(t + a[j][i], INF);
    ans = min(ans, t);
  }
  if (ans == INF)
    cout << -1 << '\n';
  else
    cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
