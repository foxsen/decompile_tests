#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
const int inv2 = 500000004;
vector<int> g[100100];
int f[100100][2];
int n;
void loadtree(void) {
  scanf("%d", &n);
  for (int i = (2), _b = (n); i <= _b; i = i + 1) {
    int u;
    scanf("%d", &u);
    g[u].push_back(i);
  }
  for (int i = (1), _b = (n); i <= _b; i = i + 1)
    sort(g[i].begin(), g[i].end());
}
int allSub(const vector<int> &v) {
  int res = 1;
  for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
    res = 1LL * res * (*it + 1) % mod;
  return (res);
}
int allOddSub(const vector<int> &v) {
  int res = 1;
  for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
    res = 1LL * res * (1 - *it + mod) % mod;
  return (1LL * (allSub(v) - res + mod) % mod * inv2 % mod);
}
void dfs(int u) {
  for (int i = 0, _n = (2); i < _n; i = i + 1) f[u][i] = i;
  int prev[2];
  vector<int> child[2];
  for (__typeof((g[u]).begin()) it = (g[u]).begin(); it != (g[u]).end(); it++) {
    int v = *it;
    dfs(v);
    for (int i = 0, _n = (2); i < _n; i = i + 1) child[i].push_back(f[v][i]);
    for (int i = 0, _n = (2); i < _n; i = i + 1) prev[i] = f[u][i];
    for (int i = 0, _n = (2); i < _n; i = i + 1)
      for (int j = 0, _n = (2); j < _n; j = j + 1)
        f[u][i ^ j] = (f[u][i ^ j] + 1LL * prev[i] * f[v][j]) % mod;
  }
  if (g[u].size() < 2) return;
  for (int i = 0, _n = (2); i < _n; i = i + 1) f[u][i] = 2LL * f[u][i] % mod;
  f[u][0] = (f[u][0] - allOddSub(child[1]) + mod) % mod;
  f[u][1] = (f[u][1] - allSub(child[0]) + mod) % mod;
}
void process(void) {
  dfs(1);
  printf("%d", (f[1][0] + f[1][1]) % mod);
}
int main(void) {
  assert(2LL * inv2 % mod == 1);
  loadtree();
  process();
  return 0;
}
