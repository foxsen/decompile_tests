#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long double eps = 1e-7;
const int inf = 1000000010;
const long long INF = 10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 1010, LOG = 20;
long long powmod(long long a, long long b) {
  if (!b) return 1;
  if (b & 1) return a * powmod(a * a % mod, b >> 1) % mod;
  return powmod(a * a % mod, b >> 1);
}
long long n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
long long F[MAXN];
long long I[MAXN];
long long tav[MAXN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  F[0] = 1;
  for (int i = 1; i < MAXN; i++) F[i] = F[i - 1] * i % mod;
  I[MAXN - 1] = powmod(F[MAXN - 1], mod - 2);
  for (int i = MAXN - 1; i; i--) I[i - 1] = I[i] * i % mod;
  tav[0] = 1;
  for (int i = 1; i < MAXN; i++) tav[i] = tav[i - 1] * 2 % mod;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) cin >> A[i];
  sort(A + 1, A + m + 1);
  ans = F[n - m];
  for (int i = 2; i <= m; i++) {
    int len = A[i] - A[i - 1] - 1;
    if (len) ans = (ans * tav[len - 1] % mod) * I[len] % mod;
  }
  ans = ans * I[A[1] - 1] % mod;
  ans = ans * I[n - A[m]] % mod;
  cout << ans << '\n';
  return 0;
}
