#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long c1, c2;
long long cache[52][52][2][201];
long long cache1[52][52][2][201];
long long mod = 1e9 + 7;
long long fact[300005];
long long inv(long long x) {
  long long r, y;
  for (r = 1, y = mod - 2; y > 0; x = (x * x) % mod, y /= 2)
    if (y % 2 == 1) r = r * x % mod;
  return r;
}
long long nCr(long long n, long long m) {
  return fact[n] * inv(fact[m]) % mod * inv(fact[n - m]) % mod;
}
long long dp(long long lt1, long long lt2, long long side, long long tk) {
  if (tk > 200) return 1e18;
  if (lt1 + lt2 == 0 && side) return tk;
  long long &ans = cache[lt1][lt2][side][tk];
  if (ans != -1) return ans;
  ans = 1e18;
  if (side == 1) {
    long long has1 = c1 - lt1;
    long long has2 = c2 - lt2;
    if (has1 == 0 && k >= 100)
      ans = dp(lt1, lt2 + 1, 0, tk + 1);
    else if (has2 == 0 && k >= 50)
      ans = dp(lt1 + 1, lt2, 0, tk + 1);
    else if (k >= 100)
      ans = min(dp(lt1 + 1, lt2, 0, tk + 1), dp(lt1, lt2 + 1, 0, tk + 1));
  } else {
    for (long long tk1 = 0; tk1 <= lt1; tk1++) {
      for (long long tk2 = lt2; tk2 >= 0; tk2--)
        if (!(tk1 == 0 && tk2 == 0) && 50 * tk1 + 100 * tk2 <= k)
          ans = min(ans, dp(lt1 - tk1, lt2 - tk2, 1, tk + 1));
    }
  }
  return ans;
}
long long path(long long lt1, long long lt2, long long side, long long left) {
  if (left < 0) return 0;
  if (lt1 + lt2 == 0 && left == 0) return 1;
  long long &ans1 = cache1[lt1][lt2][side][left];
  if (ans1 != -1) return ans1;
  ans1 = 0;
  long long ans = 1e18;
  if (side == 1) {
    long long has1 = c1 - lt1;
    long long has2 = c2 - lt2;
    for (long long i = 0; i <= has1; i++)
      for (long long j = 0; j <= has2; j++)
        if (i + j != 0 && i + j != has1 + has2 && i * 50 + j * 100 <= k) {
          long long ct = (nCr(has1, i) * nCr(has2, j)) % mod;
          ans1 += ct * path(lt1 + i, lt2 + j, 0, left - 1);
          if (ans1 >= mod) ans1 %= mod;
        }
  } else {
    for (long long tk1 = lt1; tk1 >= 0; tk1--) {
      for (long long tk2 = lt2; tk2 >= 0; tk2--)
        if (!(tk1 == 0 && tk2 == 0) && 50 * tk1 + 100 * tk2 <= k) {
          long long ct = (nCr(lt1, tk1) * nCr(lt2, tk2)) % mod;
          ans1 += (ct * path(lt1 - tk1, lt2 - tk2, 1, left - 1)) % mod;
        }
    }
  }
  ans1 %= mod;
  return ans1;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  fact[0] = 1;
  for (long long i = 1; i < 300005; i++) fact[i] = (i * fact[i - 1]) % mod;
  cin >> n >> k;
  for (long long i = 0; i < n; i++) {
    long long a;
    cin >> a;
    if (a == 50)
      c1++;
    else
      c2++;
  }
  memset(cache, -1, sizeof(cache));
  if (dp(c1, c2, 0, 0) > 1e15) return cout << "-1\n0", 0;
  long long ans = dp(c1, c2, 0, 0);
  cout << ans << '\n';
  memset(cache1, -1, sizeof(cache1));
  cout << path(c1, c2, 0, ans) << '\n';
}
