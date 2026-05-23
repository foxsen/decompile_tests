#include <bits/stdc++.h>
using namespace std;
long long INV2 = 500000004;
long long INV6 = 166666668;
long long power(long long a, long long b, long long c) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b & 1) x = (x * y) % c;
    y = (y * y) % c;
    b /= 2;
  }
  return x % c;
}
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int N = 1e5 + 5, M = 15;
long long n, m, dp[N][M][5], aux[M][5], k, x;
vector<int> v[N];
bool vis[N];
void dfs(int node) {
  vis[node] = 1;
  dp[node][0][0] = k - 1;
  dp[node][1][1] = 1;
  dp[node][0][2] = m - k;
  for (auto u : v[node]) {
    if (!vis[u]) {
      dfs(u);
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j <= x; ++j) {
          aux[j][i] = 0;
        }
      }
      for (int i = x; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
          aux[i][0] = (aux[i][0] + (dp[node][i - j][0] *
                                    (dp[u][j][0] + dp[u][j][1] + dp[u][j][2])) %
                                       1000000007) %
                      1000000007;
          aux[i][1] =
              (aux[i][1] + (dp[node][i - j][1] * dp[u][j][0]) % 1000000007) %
              1000000007;
          aux[i][2] =
              (aux[i][2] + (dp[node][i - j][2] * (dp[u][j][0] + dp[u][j][2])) %
                               1000000007) %
              1000000007;
        }
      }
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j <= x; ++j) {
          dp[node][j][i] = aux[j][i];
        }
      }
    }
  }
  return;
}
int main() {
  scanf("%lld%lld", &n, &m);
  for (int i = 0; i < n - 1; ++i) {
    int xx, yy;
    scanf("%d%d", &xx, &yy);
    v[xx].push_back(yy);
    v[yy].push_back(xx);
  }
  scanf("%lld%lld", &k, &x);
  dfs(1);
  long long ans = 0;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j <= x; ++j) {
      ans = (ans + dp[1][j][i]) % 1000000007;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
