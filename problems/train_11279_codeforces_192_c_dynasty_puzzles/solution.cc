#include <bits/stdc++.h>
using namespace std;
istream &in = cin;
int n, len;
char s[100];
int dp[30][30];
int main() {
  in >> n;
  memset(dp, 0, sizeof(dp));
  for (int k = 1; k <= n; ++k) {
    scanf("%s", s);
    len = strlen(s);
    int h = s[0] - 'a', t = s[len - 1] - 'a';
    for (int i = 0; i < 26; ++i)
      if (dp[i][h] > 0) dp[i][t] = max(dp[i][t], dp[i][h] + len);
    dp[h][t] = max(dp[h][t], len);
  }
  int ret = 0;
  for (int i = 0; i < 26; ++i) ret = max(ret, dp[i][i]);
  cout << ret << endl;
  return 0;
}
