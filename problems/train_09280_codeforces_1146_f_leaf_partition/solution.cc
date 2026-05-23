#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
vector<int> v[200010];
int d[200010], d1[200010];
int rid_put(int a, int b) {
  int sol = 1;
  for (long long i = 1; i <= b; i <<= 1) {
    if (b & i) sol = (1LL * sol * a) % mod;
    a = (1LL * a * a) % mod;
  }
  return sol;
}
void dfs(int nod) {
  int p = 1, p1 = 1;
  for (int i = 0; i < v[nod].size(); i++) {
    int vec = v[nod][i];
    dfs(vec);
    p = (1LL * p * d[vec]) % mod;
    p1 = (1LL * p1 * ((d[vec] + d1[vec]) % mod)) % mod;
  }
  int s = 0;
  for (int i = 0; i < v[nod].size(); i++) {
    int vec = v[nod][i];
    int a = (1LL * p * rid_put(d[vec], mod - 2)) % mod;
    a = (1LL * a * d1[vec]) % mod;
    s = (s + a) % mod;
  }
  if (v[nod].size() == 0) {
    d[nod] = d1[nod] = 1;
    return;
  }
  d[nod] = (p1 - s + mod) % mod;
  d1[nod] = (p1 - p + mod) % mod;
}
int main() {
  int n, x;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    scanf("%d", &x);
    v[x].push_back(i);
  }
  dfs(1);
  printf("%d", d[1]);
  return 0;
}
