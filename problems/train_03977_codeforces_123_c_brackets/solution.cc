#include <bits/stdc++.h>
using namespace std;
const int inv = 1000000000;
const int minv = -inv;
const long long llinv = numeric_limits<long long>::max() - 10ll;
const int max_m = 110;
const int max_n = 110;
const int max_l = max_m + max_n - 1;
int m, n;
long long k;
int p[max_m][max_n];
int dstp[max_m + max_n - 1];
int atp[max_m + max_n - 1];
pair<int, int> Q[max_m + max_n - 1];
char f[max_m + max_n - 1];
long long dp[max_l + 1][max_l + 1];
int l;
bool valid(int i, int j) {
  int ub = min(i, l - i);
  return (j % 2 == i % 2 and 0 <= j and j <= ub);
}
long long currct;
bool enough() {
  l = m + n - 1;
  dp[0][0] = 1ll;
  for (int i = 1; i <= l; ++i)
    for (int j = i % 2; j <= min(i, l - i); j += 2) {
      long long s1 =
          ((f[i - 1] != ')' and valid(i - 1, j - 1)) ? dp[i - 1][j - 1] : 0ll);
      long long s2 =
          ((f[i - 1] != '(' and valid(i - 1, j + 1)) ? dp[i - 1][j + 1] : 0ll);
      if (llinv - s1 < s2)
        dp[i][j] = llinv;
      else
        dp[i][j] = s1 + s2;
    }
  currct = dp[l][0];
  return (currct >= k);
}
int main() {
  scanf("%d", &m);
  scanf("%d", &n);
  cin >> k;
  for (int d = 0; d < m + n - 1; ++d) dstp[d] = inv;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j) {
      scanf("%d", &p[i][j]);
      --p[i][j];
      dstp[i + j] = min(dstp[i + j], p[i][j]);
    }
  for (int d = 0; d < m + n - 1; ++d) Q[d] = pair<int, int>(dstp[d], d);
  sort(Q, Q + m + n - 1);
  for (int d = 0; d < m + n - 1; ++d) {
    atp[d] = Q[d].second;
  }
  fill(f, f + m + n - 1, '-');
  for (int i = 0; i < m + n - 1; ++i) {
    f[atp[i]] = '(';
    if (not enough()) {
      f[atp[i]] = ')';
      k -= currct;
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) printf("%c", f[i + j]);
    printf("\n");
  }
  return 0;
}
