#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
template <typename T>
bool mmax(T &m, const T q) {
  if (m < q) {
    m = q;
    return true;
  } else
    return false;
}
template <typename T>
bool mmin(T &m, const T q) {
  if (m > q) {
    m = q;
    return true;
  } else
    return false;
}
void __print(long long first) { cerr << first; }
void __print(long first) { cerr << first; }
void __print(unsigned first) { cerr << first; }
void __print(unsigned long first) { cerr << first; }
void __print(unsigned long long first) { cerr << first; }
void __print(float first) { cerr << first; }
void __print(double first) { cerr << first; }
void __print(long double first) { cerr << first; }
void __print(char first) { cerr << '\'' << first << '\''; }
void __print(const char *first) { cerr << '\"' << first << '\"'; }
void __print(const string &first) { cerr << '\"' << first << '\"'; }
void __print(bool first) { cerr << (first ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &first) {
  cerr << '{';
  __print(first.first);
  cerr << ',';
  __print(first.second);
  cerr << '}';
}
template <typename T>
void __print(const T &first) {
  long long f = 0;
  cerr << '{';
  for (auto &i : first) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
std::mt19937 rng(
    (long long)std::chrono::steady_clock::now().time_since_epoch().count());
const long long N = 1e6 + 6;
vector<long long> g[N];
long long n, s, root, first, a[N];
vector<long long> d;
long long dfs(long long u, long long p) {
  long long ans = a[u];
  for (auto v : g[u]) {
    if (v == p) continue;
    ans += dfs(v, u);
  }
  if (ans == first) {
    ans = 0;
    d.push_back(u);
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(12);
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    long long p, w;
    cin >> p >> w;
    a[i] = w;
    s += w;
    if (p == 0)
      root = i;
    else {
      g[i].push_back(p);
      g[p].push_back(i);
    }
  }
  if (s % 3 != 0) {
    cout << -1;
    return 0;
  }
  first = s / 3;
  dfs(root, 0);
  long long ans1 = -1, ans2 = -1;
  for (auto i : d) {
    if (i != root) {
      if (ans1 == -1)
        ans1 = i;
      else if (ans2 == -1)
        ans2 = i;
    }
  }
  if (ans1 == -1 || ans2 == -1)
    cout << -1;
  else
    cout << ans1 << " " << ans2;
  return 0;
}
