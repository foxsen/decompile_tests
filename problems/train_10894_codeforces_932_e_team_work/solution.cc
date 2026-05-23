#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
const int MOD = 1000000007;
long long n, k, sol;
int dp[MAXN][MAXN], p[MAXN], l[MAXN];
vector<int> v[MAXN];
long long add(long long a, long long b) {
  a += b;
  if (a >= MOD) return a - MOD;
  return a;
}
long long sub(long long a, long long b) {
  a -= b;
  if (a < 0) return a + MOD;
  return a;
}
long long mul(long long a, long long b) { return a * b % MOD; }
long long pot(long long b, long long e) {
  if (e == 0) return 1;
  if (e & 1) {
    return mul(b, pot(b, e - 1));
  } else {
    long long t = pot(b, e / 2);
    return mul(t, t);
  }
}
void calc_dp() {
  for (int i = 0; i <= k; i++) {
    dp[i][0] = dp[i][i] = 1;
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= k; j++) {
      dp[i][j] = add(dp[i - 1][j], dp[i - 1][j - 1]);
    }
  }
}
int main() {
  cin >> n >> k;
  calc_dp();
  for (int i = 1; i <= k; i++) {
    p[i] = pot(i, k);
  }
  v[0].push_back(0);
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= k; j++) {
      l[i] = add(l[i], mul(dp[i][j], p[j]));
    }
    v[0].push_back(mul(l[i], pot(2, k - i)));
  }
  for (int i = 0; i < k; i++) {
    for (int j = 1; j < v[i].size(); j++) {
      v[i + 1].push_back(sub(v[i][j], v[i][j - 1]));
    }
  }
  long long val = 1;
  for (int i = 1; i <= k; i++) {
    val = mul(val, n + 1 - i);
    val = mul(val, pot(i, MOD - 2));
    sol = add(sol, mul(val, v[i][0]));
  }
  if (n <= k)
    cout << l[n];
  else
    cout << mul(sol, pot(2, n - k));
  return 0;
}
