#include <bits/stdc++.h>
using namespace std;
unsigned long long n, sum, size[80010];
vector<unsigned long long> G[80010];
unsigned long long cal(unsigned long long x) { return x * (x - 1) / 2; }
void dfs(unsigned long long u, unsigned long long fa) {
  size[u] = 1;
  unsigned long long ans1 = 0, ans2 = 0;
  for (unsigned long long i = 0; i < G[u].size(); i++) {
    unsigned long long v = G[u][i];
    if (v == fa) {
      continue;
    }
    dfs(v, u);
    size[u] += size[v];
    ans1 -= cal(size[v]);
  }
  ans1 += cal(size[u]);
  ans2 += size[u] * (n - size[u]);
  sum += ans1 * ans1 + ans1 * ans2 * 2;
}
signed main() {
  cin >> n;
  for (unsigned long long i = 1; i < n; i++) {
    unsigned long long a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(1, 0);
  cout << cal(n) * cal(n) - sum;
  return 0;
}
