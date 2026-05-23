#include <bits/stdc++.h>
using namespace std;
const int N = 1007;
const int M = 114;
const int mod = 1e9 + 9;
int n, m;
int ch[M][4], fa[M], len[N], tot = 1;
void bfs() {
  queue<int> q;
  for (int i = 0, iE = 3; i <= iE; i++)
    if (ch[1][i])
      q.push(ch[1][i]), fa[ch[1][i]] = 1;
    else
      ch[1][i] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    len[u] = max(len[u], len[fa[u]]);
    for (int i = 0, iE = 3; i <= iE; i++) {
      int v = ch[u][i];
      if (v)
        fa[v] = ch[fa[u]][i], q.push(v);
      else
        ch[u][i] = ch[fa[u]][i];
    }
  }
}
int dp[N][M][12];
char s[114];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, iE = m; i <= iE; i++) {
    scanf("%s", s + 1);
    int Len = strlen(s + 1);
    int now = 1;
    for (int j = 1, jE = Len; j <= jE; j++) {
      int opt = (s[j] > 'A') + (s[j] > 'G') + (s[j] > 'C') + (s[j] > 'T');
      if (!ch[now][opt]) ch[now][opt] = ++tot;
      now = ch[now][opt];
    }
    len[now] = max(len[now], Len);
  }
  bfs();
  dp[0][1][0] = 1;
  for (int i = 1, iE = n; i <= iE; i++)
    for (int j = 1, jE = tot; j <= jE; j++)
      for (int k = 0, kE = 10; k <= kE; k++)
        for (int t = 0, tE = 3; t <= tE; t++) {
          if (len[ch[j][t]] >= k + 1)
            (dp[i][ch[j][t]][0] += dp[i - 1][j][k]) %= mod;
          else
            (dp[i][ch[j][t]][k + 1] += dp[i - 1][j][k]) %= mod;
        }
  int ans = 0;
  for (int i = 1, iE = tot; i <= iE; i++) (ans += dp[n][i][0]) %= mod;
  printf("%d\n", ans);
  return 0;
}
