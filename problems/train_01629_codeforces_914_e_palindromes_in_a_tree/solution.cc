#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
const int N = 1e6 + 10;
const long long mod = 1e9 + 7;
const long long mod2 = 998244353;
const long long inf = 8e18;
const int LOG = 22;
long long pw(long long a, long long b, long long M) {
  return (!b ? 1
             : (b & 1 ? (a * pw(a * a % M, b / 2, M)) % M
                      : pw(a * a % M, b / 2, M)));
}
char C[N];
long long sum[N], ans[N];
int n, A[N], hide[N], sub[N], mask[N], T[(1 << LOG)];
vector<int> G[N], vec;
void dfs(int v, int P) {
  sub[v] = 1;
  for (auto u : G[v]) {
    if (hide[u] || u == P) continue;
    dfs(u, v);
    sub[v] += sub[u];
  }
}
int find(int v, int P, int _n) {
  for (auto u : G[v]) {
    if (hide[u] || u == P) continue;
    if (sub[u] * 2 > _n) return find(u, v, _n);
  }
  return v;
}
void pre(int v, int P) {
  sum[v] = 0;
  mask[v] = A[v] ^ mask[P];
  T[mask[v]]++;
  for (auto u : G[v]) {
    if (hide[u] || u == P) continue;
    pre(u, v);
  }
}
void clear(int v, int P) {
  sum[v] = 0;
  T[mask[v]]--;
  for (auto u : G[v]) {
    if (hide[u] || u == P) continue;
    clear(u, v);
  }
}
void erase(int v, int P) {
  vec.push_back(v);
  for (auto u : G[v]) {
    if (hide[u] || u == P) continue;
    erase(u, v);
  }
}
void calc(int v, int P) {
  for (auto u : G[v]) {
    if (hide[u] || u == P) continue;
    calc(u, v);
    sum[v] += sum[u];
  }
  ans[v] += sum[v];
}
void dec(int v) {
  dfs(v, 0);
  int _n = sub[v], centroid = find(v, 0, _n);
  pre(centroid, 0);
  hide[centroid] = 1;
  T[mask[centroid]]--;
  sum[centroid] += T[0];
  for (int i = 0; i < LOG; i++) {
    int mask2 = (1 << i);
    sum[centroid] += T[mask2];
  }
  T[mask[centroid]]++;
  for (auto u : G[centroid]) {
    if (hide[u]) continue;
    vec.clear();
    erase(u, 0);
    for (auto x : vec) {
      T[mask[x]]--;
    }
    for (auto x : vec) {
      mask[x] ^= mask[centroid];
      sum[x] += T[mask[x]];
      for (int i = 0; i < LOG; i++) {
        int mask2 = mask[x] ^ (1 << i);
        sum[x] += T[mask2];
      }
      mask[x] ^= mask[centroid];
    }
    for (auto x : vec) {
      T[mask[x]]++;
    }
  }
  calc(centroid, 0);
  ans[centroid] -= sum[centroid] / 2;
  clear(centroid, 0);
  for (auto u : G[centroid]) {
    if (hide[u]) continue;
    dec(u);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  scanf("%s", C);
  for (int i = 0; i < n; i++) {
    A[i + 1] = 1 << (C[i] - 'a');
  }
  dec(1);
  for (int i = 1; i <= n; i++) {
    printf("%lld ", ans[i] + 1);
  }
  return 0;
}
