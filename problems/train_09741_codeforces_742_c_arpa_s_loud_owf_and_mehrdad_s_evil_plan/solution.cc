#include <bits/stdc++.h>
using namespace std;
long long crush[110];
bool vis[110];
long long gaba, src;
void dfs(long long n, long long cn = 0) {
  if (crush[n] == src) {
    gaba = cn + 1;
    return;
  }
  vis[n] = 1;
  if (vis[crush[n]] == 0) {
    dfs(crush[n], cn + 1);
  }
}
long long gcd(long long a, long long b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
int main() {
  long long cs, t, i, j, k, x, y, z, ans, q, n, m;
  scanf("%lld", &n);
  for (i = 1; i <= n; i++) {
    scanf("%lld", &x);
    crush[i] = x;
  }
  ans = 0;
  for (i = 1; i <= n; i++) {
    gaba = -1;
    src = i;
    memset(vis, 0, sizeof(vis));
    dfs(i);
    if (gaba == -1) {
      ans = -1;
      break;
    } else if (ans == 0) {
      if (gaba % 2 == 0) gaba /= 2;
      ans = gaba;
    } else {
      if (gaba % 2 == 0) gaba /= 2;
      ans = lcm(ans, gaba);
    }
  }
  cout << ans << endl;
  return 0;
}
