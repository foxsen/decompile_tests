#include <bits/stdc++.h>
using namespace std;
const int MaxN = 200000 + 5;
const int MaxA = 200000 + 5;
int N;
int A[MaxN], U[MaxN], V[MaxN];
bool not_prime[MaxA];
int prs[MaxA], cntp, mu[MaxA];
int par[MaxA], siz[MaxA];
bool vis[MaxA];
long long f[MaxA], g[MaxA];
vector<int> E[MaxA];
void Linear_sieve(int n) {
  not_prime[1] = true;
  mu[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (not_prime[i] == false) {
      prs[++cntp] = i;
      mu[i] = -1;
    }
    for (int j = 1; j <= cntp; ++j) {
      int k = i * prs[j];
      if (k > n) break;
      not_prime[k] = true;
      if (i % prs[j] == 0) break;
      mu[k] = -mu[i];
    }
  }
}
inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
void init() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
  for (int i = 1; i < N; ++i) scanf("%d %d", &U[i], &V[i]);
  Linear_sieve(200000);
}
int Find(int x) { return x == par[x] ? x : Find(par[x]); }
inline void Merge(int u, int v) {
  int p = Find(u), q = Find(v);
  if (siz[p] < siz[q]) swap(p, q);
  par[q] = p;
  siz[p] += siz[q];
}
void solve() {
  for (int i = 1; i < N; ++i) {
    int u = U[i], v = V[i];
    int n = gcd(A[u], A[v]);
    for (int d = 1; d * d <= n; ++d) {
      if (n % d != 0) continue;
      E[d].push_back(i);
      if (d * d != n) E[n / d].push_back(i);
    }
  }
  for (int i = 1; i <= 200000; ++i) par[i] = i, siz[i] = 1;
  for (int i = 1; i <= 200000; ++i) {
    for (int e : E[i]) {
      int u = U[e], v = V[e];
      Merge(u, v);
    }
    for (int e : E[i]) {
      int p = Find(U[e]);
      if (vis[p] == true) continue;
      vis[p] = true;
      f[i] += 1LL * siz[p] * (siz[p] - 1) / 2;
    }
    for (int e : E[i]) {
      int u = U[e], v = V[e];
      par[u] = u, siz[u] = 1;
      par[v] = v, siz[v] = 1;
      vis[u] = false, vis[v] = false;
    }
  }
  for (int n = 1; n <= 200000; ++n)
    for (int d = 1; n * d <= 200000; ++d) g[n] += mu[d] * f[n * d];
  for (int i = 1; i <= N; ++i) g[A[i]]++;
  for (int i = 1; i <= 200000; ++i)
    if (g[i] != 0) printf("%d %lld\n", i, g[i]);
}
int main() {
  init();
  solve();
  return 0;
}
