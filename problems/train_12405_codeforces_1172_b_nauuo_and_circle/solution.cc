#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n;
vector<int> E[500005];
long long fac[500005], ans = 1;
void init() {
  fac[0] = fac[1] = 1;
  for (int i = 2; i <= 200000; ++i) {
    fac[i] = fac[i - 1] * i % MOD;
  }
}
void dfs(int u, int fa) {
  int son = 0;
  for (int &v : E[u]) {
    if (v == fa) continue;
    dfs(v, u);
    ++son;
  }
  if (u == 1) {
    (ans *= fac[son]) %= MOD;
    (ans *= n) %= MOD;
  } else {
    (ans *= fac[son + 1]) %= MOD;
  }
}
int main() {
  scanf("%d", &n);
  int u, v;
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &u, &v);
    E[u].push_back(v);
    E[v].push_back(u);
  }
  init();
  dfs(1, 0);
  printf("%I64d\n", ans);
}
