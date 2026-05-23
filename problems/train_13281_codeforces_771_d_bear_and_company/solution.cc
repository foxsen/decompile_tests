#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
char s[200];
vector<int> pos[3];
int dp[200][200][200][3];
int main() {
  int n = 0;
  scanf("%d%s", &n, s + 1);
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'V')
      pos[0].push_back(i);
    else if (s[i] == 'K')
      pos[1].push_back(i);
    else
      pos[2].push_back(i);
  }
  for (int s = 1; s <= n; s++) {
    for (int i = 0; i <= pos[0].size() && i <= s; i++) {
      for (int j = 0; j + i <= s && j <= pos[1].size(); j++) {
        int k = s - i - j;
        if (k > pos[2].size()) continue;
        for (int t = 0; t < 3; t++) dp[i][j][k][t] = INF;
        if (i > 0) {
          int v = 0;
          int p = pos[0][i - 1];
          for (int y = 0; y < j; y++)
            if (p < pos[1][y]) v++;
          for (int z = 0; z < k; z++)
            if (p < pos[2][z]) v++;
          for (int t = 0; t < 3; t++)
            dp[i][j][k][0] = min(dp[i - 1][j][k][t], dp[i][j][k][0]);
          dp[i][j][k][0] += v;
        }
        if (j > 0) {
          int v = 0;
          int p = pos[1][j - 1];
          for (int x = 0; x < i; x++)
            if (p < pos[0][x]) v++;
          for (int z = 0; z < k; z++)
            if (p < pos[2][z]) v++;
          for (int t = 1; t < 3; t++)
            dp[i][j][k][1] = min(dp[i][j - 1][k][t], dp[i][j][k][1]);
          dp[i][j][k][1] += v;
        }
        if (k > 0) {
          int v = 0;
          int p = pos[2][k - 1];
          for (int x = 0; x < i; x++)
            if (p < pos[0][x]) v++;
          for (int y = 0; y < j; y++)
            if (p < pos[1][y]) v++;
          for (int t = 0; t < 3; t++)
            dp[i][j][k][2] = min(dp[i][j][k - 1][t], dp[i][j][k][2]);
          dp[i][j][k][2] += v;
        }
      }
    }
  }
  int ans = INF;
  for (int i = 0; i < 3; i++)
    ans = min(ans, dp[pos[0].size()][pos[1].size()][pos[2].size()][i]);
  printf("%d", ans);
}
