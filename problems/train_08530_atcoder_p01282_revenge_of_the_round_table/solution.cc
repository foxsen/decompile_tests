#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

long long gcd(long long a, long long b) {
  if (b == 0) { return a; }
  return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
  return a / gcd(a, b) * b;
}
//a x + b y = gcd(a, b)
long long extgcd(long long a, long long b, long long &x, long long &y) {
  long long g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}

long long invMod(long long a, long long mod) {
  long long x, y;
  if (extgcd(a, mod, x, y) == 1) { return (x + mod) % mod; }
  return 0;
}


int n, k;
const int MOD = 1000003;
ll dp1[2][1010][1010];
ll dp1sum[2][1010][1010];
ll dp2[1010];
ll dp3[1010];

int main() {
  while (scanf("%d %d", &n, &k), n|k)  {
    int rest = k >= n ? 2 : 0;
    k = min(k, n - 1);
    MEMSET(dp1, 0);
    MEMSET(dp1sum, 0);
    MEMSET(dp2, 0);
    MEMSET(dp3, 0);
    dp1[0][1][1] = 1;
    FOREQ(i, 2, n) {
      FOREQ(j, 1, k) {
        dp1[0][i][j] = (dp1[0][i][j] + dp1[0][i - 1][j - 1]) % MOD;
        dp1[1][i][j] = (dp1[1][i][j] + dp1[1][i - 1][j - 1]) % MOD;
        dp1[0][i][1] = (dp1[0][i][1] + dp1[1][i - 1][j]) % MOD;
        dp1[1][i][1] = (dp1[1][i][1] + dp1[0][i - 1][j]) % MOD;
      }
    }
    FOREQ(i, 1, n) {
      FOREQ(j, 1, n) {
        dp1sum[0][i][j] = (dp1sum[0][i][j - 1] + dp1[0][i][j]) % MOD;
        dp1sum[1][i][j] = (dp1sum[1][i][j - 1] + dp1[1][i][j]) % MOD;
      }
    }
    FOREQ(i, 1, n) {
      FOREQ(j, 1, k) {
        dp2[i] = (dp2[i] + dp1[1][i][j]) % MOD;
      }
      FOREQ(p, 1, k) {
        if (i - p <= 0) { break; }
        dp2[i] = (dp2[i] + dp1sum[1][i - p][k - p]) % MOD;
      }
      dp2[i] = (dp2[i] * 2) % MOD;
    }
    FOREQ(i, 1, n) {
      int lsum = 0;
      FOR(d, 2, i) {
        if (i % d != 0) { continue; }
        lsum = (lsum + dp3[d]) % MOD;
      }
      dp3[i] = (dp2[i] - lsum + MOD) % MOD;
    }
    ll ans = rest;
    FOREQ(i, 2, n) {
      if (n % i != 0) { continue; }
      ans = (ans + dp3[i] * invMod(i, MOD)) % MOD;
    }
    printf("%lld\n", ans);
  }
}