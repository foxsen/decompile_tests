#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int MAXN = 100010;
int N, c[MAXN], f[MAXN][2];
vector<int> graph[MAXN];
void dfs(int u, int p) {
  f[u][0] = 1;
  f[u][1] = 0;
  for (int i = 0; i < graph[u].size(); ++i) {
    int v = graph[u][i];
    if (v != p) {
      dfs(v, u);
      f[u][1] = (long long)f[u][1] * f[v][0] % MOD;
      f[u][1] = (f[u][1] + (long long)f[u][0] * f[v][1]) % MOD;
      f[u][0] = (long long)f[u][0] * f[v][0] % MOD;
    }
  }
  if (c[u] == 1)
    f[u][1] = f[u][0];
  else
    f[u][0] = (f[u][0] + f[u][1]) % MOD;
}
int main() {
  int v;
  cin >> N;
  for (int u = 0; u < N - 1; ++u) {
    cin >> v;
    graph[u + 1].push_back(v);
    graph[v].push_back(u + 1);
  }
  for (int i = 0; i < N; ++i) cin >> c[i];
  dfs(0, -1);
  cout << f[0][1] << endl;
  return 0;
}
