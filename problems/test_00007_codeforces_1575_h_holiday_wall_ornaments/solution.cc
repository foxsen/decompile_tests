#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int dp[2][N][N];
char s[N], str[N], ss[N];
int nxt[N][2];
int fail_all;
int get_lcp(int cnt) {
  for (int l = cnt - 1; l >= 1; l--) {
    bool flag = true;
    for (int j = 0; j < l; j++) {
      if (str[l - j] != ss[cnt - j]) {
        flag = false;
        break;
      }
    }
    if (flag) return l;
  }
  return 0;
}
void get_next(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++)
      if (str[i + 1] - '0' == j)
        nxt[i][j] = i + 1;
      else {
        int cnt = 0;
        for (int k = 1; k <= i; k++) {
          ss[++cnt] = str[k];
        }
        ss[++cnt] = '0' + j;
        nxt[i][j] = get_lcp(cnt);
      }
  }
  for (int i = 1; i <= n; i++) ss[i] = str[i];
  fail_all = get_lcp(n);
}
void update(int &x, int y) {
  if (x == -1 || x > y) x = y;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  scanf("%s", str + 1);
  get_next(m);
  memset(dp, -1, sizeof(dp));
  dp[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    int flag = i & 1;
    memset(dp[flag ^ 1], -1, sizeof(dp[flag ^ 1]));
    for (int j = 0; j < m; j++) {
      for (int k = 0; k <= n - m + 1; k++) {
        if (dp[flag][j][k] == -1) continue;
        for (int r = 0; r < 2; r++) {
          int l = nxt[j][r];
          int carry = 0;
          if (l == m) {
            l = fail_all;
            carry++;
          }
          update(dp[flag ^ 1][l][k + carry],
                 dp[flag][j][k] + (s[i + 1] - '0' != r));
        }
      }
    }
  }
  for (int i = 0; i <= n - m + 1; i++) {
    int ans = -1;
    for (int j = 0; j < m; j++)
      if (dp[n & 1][j][i] != -1) {
        update(ans, dp[n & 1][j][i]);
      }
    printf("%d ", ans);
  }
  printf("\n");
  return 0;
}
