#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
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
const long long MOD = 1e9 + 7, di = 998244353, N = 2e6 + 1;
bool IsQuery = false;
long long q = 1, a[N], n;
map<int, vector<int>> edge;
map<int, bool> occ;
bool odd, even;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void solve() {
  long long n, m, b, MOD, ans = 0;
  cin >> n >> m >> b >> MOD;
  for (int i = 0; i < n; i++) cin >> a[i];
  long long dp[m + 1][b + 1];
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < m; k++) {
      for (int j = 0; j <= b; j++) {
        if (dp[k][j] && j + a[i] <= b) {
          dp[k + 1][j + a[i]] = (dp[k + 1][j + a[i]] + dp[k][j]) % MOD;
        };
      }
    }
  }
  for (int i = 0; i <= b; i++) ans = (ans + dp[m][i]) % MOD;
  cout << ans;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (IsQuery) cin >> q;
  for (int i = 0; i < q; i++) {
    solve();
    cout << "\n";
  }
  return 0;
}
