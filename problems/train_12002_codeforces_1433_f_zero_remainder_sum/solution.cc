#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
const long long int inf = 9e18;
const long double pi = 2 * acos(0.0);
using namespace std;
long long int power(long long int a, long long int n) {
  if (n == 0) {
    return 1;
  }
  long long int p = power(a, n / 2);
  p = (p * p);
  if (n % 2 == 1) {
    p = (p * a);
  }
  return p;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
const int N = 1e6 + 5;
vector<long long int> sieve(N, 0);
void si() {
  sieve[1] = 1;
  for (int i = 2; i < N; i++) {
    if (sieve[i] == 0) {
      sieve[i] = 1;
      for (int j = 2 * i; j < N; j += i) {
        sieve[j] = i;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<long long int> > a(n, vector<long long int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  long long int dp[n + 1][m + 1][m / 2 + 1][k];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int i1 = 0; i1 <= m / 2; i1++) {
        for (int j1 = 0; j1 < k; j1++) {
          dp[i][j][i1][j1] = 0;
        }
      }
    }
  }
  dp[0][0][1][a[0][0] % k] = a[0][0];
  vector<long long int> v(k, 0);
  for (int i = 0; i < n; i++) {
    vector<long long int> v1(k, 0);
    for (int j = 0; j < m; j++) {
      for (int i1 = 0; i1 <= m / 2; i1++) {
        for (int j1 = 0; j1 < k; j1++) {
          if (j == 0) {
            if (i != 0) {
              if (i1 <= j + 1) {
                if (i1 == 0) {
                  dp[i][j][i1][j1] = max(dp[i][j][i1][j1], v[j1]);
                } else {
                  if (v[(j1 - a[i][j] + 100 * k) % k] != 0) {
                    dp[i][j][i1][j1] =
                        max(dp[i][j][i1][j1],
                            v[(j1 - a[i][j] + 100 * k) % k] + a[i][j]);
                  } else {
                    if (a[i][j] % k == j1) {
                      dp[i][j][i1][j1] = a[i][j];
                    }
                  }
                }
              }
            }
          } else {
            if (i1 <= j + 1) {
              if (i1 == 0) {
                dp[i][j][i1][j1] = dp[i][j - 1][i1][j1];
              } else {
                if ((i1 - 1 == 0) ||
                    (dp[i][j - 1][i1 - 1][(j1 - a[i][j] + 100 * k) % k] != 0)) {
                  if ((dp[i][j - 1][i1 - 1][(j1 - a[i][j] + 100 * k) % k] !=
                       0)) {
                    dp[i][j][i1][j1] =
                        max(dp[i][j][i1][j1],
                            dp[i][j - 1][i1 - 1][(j1 - a[i][j] + 100 * k) % k] +
                                a[i][j]);
                  } else {
                    if (a[i][j] % k == j1) {
                      dp[i][j][i1][j1] = a[i][j];
                    }
                  }
                }
                if (dp[i][j - 1][i1][j1] != 0) {
                  dp[i][j][i1][j1] =
                      max(dp[i][j][i1][j1], dp[i][j - 1][i1][j1]);
                }
              }
            }
            if (j == m - 1) {
              v1[j1] = max(v1[j1], dp[i][j][i1][j1]);
            }
          }
        }
      }
    }
    for (int j = 0; j < k; j++) {
      v[j] = v1[j];
    }
  }
  long long int ans = 0;
  for (int i = 0; i <= m / 2; i++) {
    ans = max(ans, dp[n - 1][m - 1][i][0]);
  }
  cout << ans << "\n";
  return 0;
}
