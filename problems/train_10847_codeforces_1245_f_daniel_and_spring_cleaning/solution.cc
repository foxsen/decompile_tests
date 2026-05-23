#include <bits/stdc++.h>
using namespace std;
long long dp[40][2][2];
int digA[40], digB[40];
long long dfs(int pos, bool limA, bool limB) {
  if (!pos) return 1;
  long long &val = dp[pos][limA][limB];
  if (val != -1) return val;
  int mxA = limA ? digA[pos] : 1;
  int mxB = limB ? digB[pos] : 1;
  val = 0;
  for (int i = 0; i <= mxA; i++) {
    for (int j = 0; j <= mxB; j++) {
      if (i == 1 && j == 1) continue;
      val += dfs(pos - 1, limA && i == mxA, limB && j == mxB);
    }
  }
  return val;
}
long long solve(int a, int b) {
  if (a < 0 || b < 0) return 0;
  memset(dp, -1, sizeof(dp));
  if (a < b) swap(a, b);
  int cnt = 0;
  while (a > 0) {
    digA[++cnt] = a & 1;
    a >>= 1;
  }
  for (int i = 0; i < cnt; i++) {
    digB[i + 1] = b & 1;
    b >>= 1;
  }
  return dfs(cnt, true, true);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long l, r;
    scanf("%lld%lld", &l, &r);
    long long ans = solve(r, r) - (solve(r, l - 1)) * 2 + solve(l - 1, l - 1);
    printf("%lld\n", ans);
  }
  return 0;
}
