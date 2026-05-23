#include <bits/stdc++.h>
using namespace std;
const int dx44[5] = {0, -1, -1, 1, 1};
const int dy44[5] = {0, -1, 1, -1, 1};
const int dx4[5] = {0, -1, 0, 1, 0};
const int dy4[5] = {0, 0, 1, 0, -1};
const int dx8[9] = {0, -1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[9] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
const int maxn = 2e5 + 50;
const double PI = acos(-1.0);
const long long mod = 1e9 + 7;
long long po(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  } else {
    return gcd(b % a, a);
  }
}
void YES() {
  puts("YES");
  exit(0);
}
void Yes() { puts("Yes"); }
void NO() {
  puts("NO");
  exit(0);
}
void No() { puts("No"); }
void one() {
  puts("-1");
  exit(0);
}
int dp[200010];
int pre[200010];
int suf[200010];
int a[200010];
int search(int b, int e, int val) {
  if (b == e) {
    return b;
  }
  int m = (b + e + 1) >> 1;
  if (dp[m] <= val)
    return search(m, e, val);
  else
    return search(b, m - 1, val);
}
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[i] -= i;
  }
  memset(dp, 63, sizeof dp);
  dp[0] = INT_MIN;
  for (int i = 1; i <= n; i++) {
    pre[i] = 1 + search(0, n, a[i]);
    dp[pre[i]] = min(dp[pre[i]], a[i]);
  }
  memset(dp, 63, sizeof dp);
  dp[0] = INT_MIN;
  for (int i = n; i >= 1; i--) {
    suf[i] = 1 + search(0, n, -a[i]);
    dp[suf[i]] = min(dp[suf[i]], -a[i]);
  }
  memset(dp, 63, sizeof dp);
  dp[0] = INT_MIN;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int opt = search(0, n, a[i] + 1);
    ans = max(ans, suf[i] + opt);
    if (i > 1) {
      dp[pre[i - 1]] = min(dp[pre[i - 1]], a[i - 1]);
    }
  }
  ans = n - ans;
  if (ans > 0) --ans;
  printf("%d\n", ans);
}
int main() {
  solve();
  return 0;
}
