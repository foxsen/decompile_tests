#include <bits/stdc++.h>
using namespace std;
const int Mod = 1000000007;
int fpow(int a, int b) {
  int ans = 1, t = a;
  while (b) {
    if (b & 1) ans = 1ll * ans * t % Mod;
    t = 1ll * t * t % Mod;
    b >>= 1;
  }
  return ans;
}
int l1[100010], r1[100010];
int l2[100010], r2[100010];
int p[400010], N;
long long f[400010], F[400010];
long long g[400010], G[400010];
long long h[400010], H[400010];
long long calc(long long* a, int l, int r) {
  long long ans = a[r];
  if (l >= 0) ans = (ans - a[l] + Mod) % Mod;
  return ans;
}
int pos1[400010], pos2[400010];
int main() {
  int k, n, m;
  scanf("%d %d %d", &k, &n, &m);
  p[++N] = k;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &l1[i], &r1[i]);
    l1[i]--;
    p[++N] = l1[i];
    p[++N] = r1[i];
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &l2[i], &r2[i]);
    l2[i]--;
    p[++N] = l2[i];
    p[++N] = r2[i];
  }
  sort(p, p + N + 1);
  N = unique(p, p + N + 1) - p - 1;
  memset(pos1, -1, sizeof(pos1));
  memset(pos2, -1, sizeof(pos2));
  for (int i = 1; i <= n; i++) {
    l1[i] = lower_bound(p, p + N + 1, l1[i]) - p;
    r1[i] = lower_bound(p, p + N + 1, r1[i]) - p;
    pos1[r1[i]] = max(pos1[r1[i]], l1[i]);
  }
  for (int i = 1; i <= m; i++) {
    l2[i] = lower_bound(p, p + N + 1, l2[i]) - p;
    r2[i] = lower_bound(p, p + N + 1, r2[i]) - p;
    pos2[r2[i]] = max(pos2[r2[i]], l2[i]);
  }
  for (int i = 1; i <= N; i++) {
    pos1[i] = max(pos1[i], pos1[i - 1]);
    pos2[i] = max(pos2[i], pos2[i - 1]);
  }
  h[0] = H[0] = 1;
  for (int i = 1; i <= N; i++) {
    f[i] = (calc(G, pos1[i], i - 1) + calc(H, pos1[i], i - 1)) % Mod;
    g[i] = (calc(F, pos2[i], i - 1) + calc(H, pos2[i], i - 1)) % Mod;
    h[i] = (h[i - 1] + f[i - 1] + g[i - 1]) *
           (fpow(2, p[i] - p[i - 1]) + Mod - 2) % Mod;
    F[i] = (F[i - 1] + f[i]) % Mod;
    G[i] = (G[i - 1] + g[i]) % Mod;
    H[i] = (H[i - 1] + h[i]) % Mod;
  }
  printf("%lld\n", (f[N] + g[N] + h[N]) % Mod);
  return 0;
}
