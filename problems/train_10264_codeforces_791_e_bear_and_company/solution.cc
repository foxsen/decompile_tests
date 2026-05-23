#include <bits/stdc++.h>
using namespace std;
const int N = 80;
const int M = 1010;
const int INF = 0x3f3f3f3f;
const int mod = 1000000007;
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return ans;
}
long long qpow(long long a, long long b, long long c) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % c;
    a = a * a % c;
    b /= 2;
  }
  return ans;
}
int dp[N][N][N][2];
int pos[N][3], num[N][3];
int v, k, x, n;
char s[N];
int len(int x, int i, int j, int k) {
  return x - min(num[x][0], i) - min(num[x][1], j) - min(num[x][2], k);
}
int main() {
  scanf("%d%s", &n, s + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) num[i][j] = num[i - 1][j];
    if (s[i] == 'V') {
      v++;
      num[i][0]++;
      pos[v][0] = i;
    } else if (s[i] == 'K') {
      k++;
      num[i][1]++;
      pos[k][1] = i;
    } else {
      x++;
      num[i][2]++;
      pos[x][2] = i;
    }
  }
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0][0][0] = 0;
  for (int i = 0; i <= v; i++)
    for (int j = 0; j <= k; j++)
      for (int l = 0; l <= x; l++) {
        int m = min(dp[i][j][l][0], dp[i][j][l][1]);
        dp[i + 1][j][l][1] =
            min(dp[i + 1][j][l][1], m + len(pos[i + 1][0], i + 1, j, l));
        dp[i][j + 1][l][0] =
            min(dp[i][j + 1][l][0],
                dp[i][j][l][0] + len(pos[j + 1][1], i, j + 1, l));
        dp[i][j][l + 1][0] =
            min(dp[i][j][l + 1][0], m + len(pos[l + 1][2], i, j, l + 1));
      }
  printf("%d\n", min(dp[v][k][x][0], dp[v][k][x][1]));
}
