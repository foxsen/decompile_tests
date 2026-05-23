#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template <class T>
bool set_max(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool set_min(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename T>
string to_string(T v) {
  bool first = true;
  string res = "{";
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
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const int N = 2000 * 2000 + 10;
const int MOD = 1e9 + 7;
const double eps = 1e-6;
vector<int> g[N];
vector<int> vis;
vector<int> a;
vector<ll> dp;
ll sum;
ll ans;
bool dfs(int u, int fa) {
  bool loop = false;
  vis[u] = 1;
  dp[u] = a[u];
  for (int v : g[u]) {
    if (v == fa) continue;
    if (vis[v]) {
      loop = true;
    } else {
      loop |= dfs(v, u);
      set_max(dp[u], dp[v] + a[u]);
    }
  }
  if (loop) {
    sum += a[u];
    return true;
  } else {
    set_max(ans, dp[u]);
    return false;
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vis.assign(n, 0);
  dp.assign(n, 0);
  sum = 0;
  ans = 0;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int s;
  cin >> s;
  s--;
  dfs(s, -1);
  cout << ans + sum << endl;
}
