#include <bits/stdc++.h>
using namespace std;
int n, q;
char cc[100001];
int nxt[100001][26], nx[26];
int dp[251][251][251];
int st1[251], st2[251], st3[251];
int trans(int k, int d) { return k == -1 ? -1 : nxt[k][d]; }
int better(int a, int b) {
  if (a == -1) {
    return b;
  }
  if (b == -1) {
    return a;
  }
  return min(a, b);
}
void solve() {
  scanf("%d%d%s", &n, &q, cc);
  memset(nx, -1, sizeof(nx));
  int ll = strlen(cc);
  for (int i = ll; i >= 0; i--) {
    if (i < ll) {
      nx[cc[i] - 'a'] = i + 1;
    }
    for (int j = 0; j < 26; j++) {
      nxt[i][j] = nx[j];
    }
  }
  int c1 = 0, c2 = 0, c3 = 0;
  dp[0][0][0] = 0;
  while (q--) {
    char cmd[2], dd[2];
    int id;
    scanf("%s%d", cmd, &id);
    if (cmd[0] == '+') {
      scanf("%s", dd);
      int d = dd[0] - 'a';
      if (id == 1) {
        for (int i = 0; i <= c2; i++) {
          for (int j = 0; j <= c3; j++) {
            dp[c1 + 1][i][j] = trans(dp[c1][i][j], d);
            if (i > 0) {
              int di = st2[i - 1];
              dp[c1 + 1][i][j] =
                  better(dp[c1 + 1][i][j], trans(dp[c1 + 1][i - 1][j], di));
            }
            if (j > 0) {
              int dj = st3[j - 1];
              dp[c1 + 1][i][j] =
                  better(dp[c1 + 1][i][j], trans(dp[c1 + 1][i][j - 1], dj));
            }
          }
        }
        st1[c1++] = d;
      } else if (id == 2) {
        for (int i = 0; i <= c1; i++) {
          for (int j = 0; j <= c3; j++) {
            dp[i][c2 + 1][j] = trans(dp[i][c2][j], d);
            if (i > 0) {
              int di = st1[i - 1];
              dp[i][c2 + 1][j] =
                  better(dp[i][c2 + 1][j], trans(dp[i - 1][c2 + 1][j], di));
            }
            if (j > 0) {
              int dj = st3[j - 1];
              dp[i][c2 + 1][j] =
                  better(dp[i][c2 + 1][j], trans(dp[i][c2 + 1][j - 1], dj));
            }
          }
        }
        st2[c2++] = d;
      } else if (id == 3) {
        for (int i = 0; i <= c1; i++) {
          for (int j = 0; j <= c2; j++) {
            dp[i][j][c3 + 1] = trans(dp[i][j][c3], d);
            if (i > 0) {
              int di = st1[i - 1];
              dp[i][j][c3 + 1] =
                  better(dp[i][j][c3 + 1], trans(dp[i - 1][j][c3 + 1], di));
            }
            if (j > 0) {
              int dj = st2[j - 1];
              dp[i][j][c3 + 1] =
                  better(dp[i][j][c3 + 1], trans(dp[i][j - 1][c3 + 1], dj));
            }
          }
        }
        st3[c3++] = d;
      }
    } else {
      if (id == 1) {
        c1--;
      } else if (id == 2) {
        c2--;
      } else if (id == 3) {
        c3--;
      }
    }
    printf("%s\n", dp[c1][c2][c3] == -1 ? "NO" : "YES");
  }
}
int main() { solve(); }
