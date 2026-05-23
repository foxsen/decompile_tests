#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const long long MX = 2e5 + 10;
const long long nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0};
template <class T>
using V = vector<T>;
template <class T>
bool ckmin(T& a, const T& b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
long long cdiv(long long a, long long b) {
  return a / b + ((a ^ b) > 0 && a % b);
}
constexpr long long log2(long long x) { return 31 - __builtin_clz(x); }
void IO() {}
long long N;
vector<long long> adj[MX];
bool swaped[MX];
vector<long long> a(MX, -1);
long long ans = 0;
void dfs(long long u, long long p) {
  for (auto v : adj[u])
    if (v != p) dfs(v, u);
  if (a[u] == u) {
    ans += 2;
    swap(a[u], a[p]);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  IO();
  cin >> N;
  for (long long i = (1); i < (N + 1); ++i) swaped[i] = false, a[i] = i;
  for (long long i = (0); i < (N - 1); ++i) {
    long long u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 1);
  if (a[1] == 1) {
    for (auto v : adj[1]) {
      swap(a[1], a[v]);
      break;
    }
  }
  cout << ans << "\n";
  for (long long i = (1); i < (N + 1); ++i) cout << a[i] << ' ';
  cout << "\n";
  return 0;
}
