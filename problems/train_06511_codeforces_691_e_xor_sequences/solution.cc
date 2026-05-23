#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = ((res % p) * (x % p)) % p;
    y = y >> 1;
    x = ((x % p) * (x % p)) % p;
  }
  return res;
}
long long raichu(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = ((res) * (x));
    y = y >> 1;
    x = ((x) * (x));
  }
  return res;
}
bool isprime(long long n) {
  if (n < 2)
    return false;
  else if (n == 2)
    return true;
  else if (n % 2 == 0)
    return false;
  else {
    long long z = sqrt(n);
    for (int i = 0; i < z - 1; i++)
      if (n % (i + 2) == 0) return false;
    return true;
  }
}
long long dp[105][105];
long long solve(int cur, int n, vector<vector<int> > &g) {
  if (n == 0)
    return 1;
  else if (dp[cur][n] != -1)
    return dp[cur][n];
  else {
    long long ans = 0;
    for (auto i : g[cur]) {
      ans += solve(i, n - 1, g);
      ans %= 1000000007;
    }
    dp[cur][n] = ans;
    return ans;
  }
}
vector<vector<long long> > MUL(vector<vector<long long> > &x,
                               vector<vector<long long> > &y, int n) {
  vector<vector<long long> > res(n, vector<long long>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res[i][j] = 0;
      for (int k = 0; k < n; k++) {
        res[i][j] += (x[i][k] * y[k][j]) % 1000000007;
        res[i][j] %= 1000000007;
      }
    }
  }
  return res;
}
vector<vector<long long> > powerM(vector<vector<long long> > x, long long y,
                                  long long p, int n) {
  vector<vector<long long> > res(n, vector<long long>(n, 0));
  for (int i = 0; i < n; i++) res[i][i] = 1;
  while (y > 0) {
    if (y & 1) {
      res = (MUL(res, x, n));
    }
    y = y >> 1;
    x = (MUL(x, x, n));
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tests = 1, Tests;
  Tests = tests;
  while (tests--) {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    k--;
    vector<vector<long long> > g(n, vector<long long>(n, 0LL));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        long long z = A[i] ^ A[j];
        int cnt = 0;
        for (int k = 0; k <= 60; k++) {
          if ((z >> k) & 1LL) cnt++;
        }
        if (cnt % 3 == 0) {
          g[i][j] = 1;
          g[j][i] = 1;
        }
      }
    }
    vector<vector<long long> > ans = powerM(g, k, 1000000007, n);
    long long ANS = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ANS += ans[i][j];
        ANS %= 1000000007;
      }
    }
    cout << ANS;
  }
  return 0;
}
