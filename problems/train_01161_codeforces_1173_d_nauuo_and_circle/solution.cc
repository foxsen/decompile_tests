#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
vector<int> edge[200000];
long long fact[200001];
void init() {
  fact[0] = fact[1] = 1;
  for (int i = (2); i < (200001); ++i) fact[i] = (fact[i - 1] * i) % MOD;
}
long long ans = 1;
void dfs(int par, int ver) {
  (ans *= fact[edge[ver].size()]) %= MOD;
  for (int e : edge[ver])
    if (e != par) {
      dfs(ver, e);
    }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  init();
  int n;
  cin >> n;
  for (int i = (0); i < (n - 1); ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    edge[u].emplace_back(v);
    edge[v].emplace_back(u);
  }
  dfs(-1, 0);
  (ans *= n) %= MOD;
  cout << ans << '\n';
  return 0;
}
