#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e3 + 5;
const long long MOD = 1e9 + 7;
long long n, m, R, x[MAXN], y[MAXN], T[MAXN][MAXN], W[MAXN][MAXN],
    U[MAXN][MAXN], V[MAXN][MAXN];
long long c[MAXN], inve[MAXN], fact[MAXN];
void read_input() {
  cin >> n >> m >> R;
  for (long long i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> c[i];
    T[x[i]][y[i]]++;
  }
}
long long get_cnt(long long l, long long r, long long l2, long long r2) {
  l2 = max(1LL, l2);
  r2 = max(1LL, r2);
  l = min(1000LL, l);
  r = min(1000LL, r);
  if (l < l2 || r < r2) return 0;
  return T[l][r] - T[l][r2 - 1] - T[l2 - 1][r] + T[l2 - 1][r2 - 1];
}
long long add(long long f, long long s) {
  f += s;
  if (f >= MOD) f %= MOD;
  if (f < 0) f += MOD;
  return f;
}
long long subs(long long f, long long s) {
  f -= s;
  if (f >= MOD) f %= MOD;
  if (f < 0) f += MOD;
  return f;
}
long long mul(long long f, long long s) {
  f *= s;
  if (f >= MOD) f %= MOD;
  if (f < 0) f += MOD;
  return f;
}
long long pw(long long f, long long y) {
  long long ans = 1;
  long long temp = f;
  while (y) {
    if (y & 1) {
      ans = mul(temp, ans);
    }
    temp = mul(temp, temp);
    y >>= 1;
  }
  return ans;
}
long long inv(long long f) { return pw(f, MOD - 2); }
long long comb(long long f, long long s) {
  if (f < s) return 0;
  return mul(fact[f], mul(inve[s], inve[f - s]));
}
void solve() {
  fact[0] = 1;
  inve[0] = inv(1);
  for (long long i = 1; i < MAXN; i++) {
    fact[i] = mul(i, fact[i - 1]);
    inve[i] = inv(fact[i]);
  }
  for (long long i = 1; i < MAXN; i++) {
    for (long long j = 1; j < MAXN; j++) {
      T[i][j] += T[i][j - 1] + T[i - 1][j] - T[i - 1][j - 1];
    }
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = i; j < n; j++) {
      long long r = max(x[i], x[j]), l = max(y[i], y[j]), r2 = min(x[i], x[j]),
                l2 = min(y[i], y[j]);
      W[i][j] = get_cnt(r2 + R, l2 + R, r - R, l - R);
      V[i][j] = get_cnt(x[i] + R, y[i] + R, x[i] - R, y[i] - R) - W[i][j];
      U[i][j] = get_cnt(x[j] + R, y[j] + R, x[j] - R, y[j] - R) - W[i][j];
      long long times = 0;
      times = subs(comb(n, m), comb(n - W[i][j], m));
      long long n2 = n - W[i][j];
      times = add(times, add(subs(comb(n2, m), comb(n2 - U[i][j], m)),
                             add(-comb(n2 - V[i][j], m),
                                 comb(n2 - V[i][j] - U[i][j], m))));
      if (i == j)
        ans = add(ans, mul(times, mul(c[i], c[i])));
      else
        ans = add(ans, mul(mul(2, times), mul(c[i], c[j])));
    }
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  read_input();
  solve();
  return 0;
}
