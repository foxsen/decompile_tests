#include <bits/stdc++.h>
using namespace std;
const int N = 1000005, M = 1000005;
const long long MOD = 1e9 + 7;
const double eps = 1e-9;
int n, len[2], dp[N], sum[N], mod = 998244353;
char a[N], l[N], r[N];
vector<int> z[2];
string s[2];
vector<int> ZAlgorithm(string &s) {
  int n = s.size();
  vector<int> z(n);
  int l = 0, r = 0;
  for (int i = 0; i < n; i++) {
    if (i > r) {
      l = i, r = i;
      while (r < n && s[r - i] == s[r]) r++;
      r--;
      z[i] = r - l + 1;
    } else {
      if (r - i + 1 > z[i - l])
        z[i] = z[i - l];
      else {
        l = i;
        while (r < n && s[r - i] == s[r]) r++;
        r--;
        z[i] = r - l + 1;
      }
    }
  }
  return z;
}
int cmp(int idx, int i, int j) {
  int ln = j - i + 1;
  if (ln != len[idx]) return (ln < len[idx] ? -1 : +1);
  int at = z[idx][len[idx] + 1 + i];
  if (at == ln) return 0;
  return a[i + at] < s[idx][at] ? -1 : +1;
}
int main() {
  scanf("%s%s%s", a, l, r);
  n = strlen(a);
  s[0] = string(l) + "#" + string(a);
  s[1] = string(r) + "#" + string(a);
  len[0] = strlen(l);
  len[1] = strlen(r);
  z[0] = ZAlgorithm(s[0]);
  z[1] = ZAlgorithm(s[1]);
  dp[n] = 1;
  sum[n] = 1;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == '0') {
      dp[i] = (l[0] == '0' ? dp[i + 1] : 0);
      sum[i] = (sum[i + 1] + dp[i]) % mod;
      continue;
    }
    int L = -1, R = -1;
    int l = i, r = n - 1, m;
    while (l <= r) {
      m = (l + r) / 2;
      if (cmp(0, i, m) >= 0) {
        L = m;
        r = m - 1;
      } else
        l = m + 1;
    }
    l = i, r = n - 1;
    while (l <= r) {
      m = (l + r) / 2;
      if (cmp(1, i, m) <= 0) {
        R = m;
        l = m + 1;
      } else
        r = m - 1;
    }
    R = min(R, n - 1);
    L = min(L, n - 1);
    if (L <= R) dp[i] = (sum[L + 1] - sum[R + 2] + mod) % mod;
    sum[i] = (sum[i + 1] + dp[i]) % mod;
  }
  printf("%d\n", dp[0]);
  return 0;
}
