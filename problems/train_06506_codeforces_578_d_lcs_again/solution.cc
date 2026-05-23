#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[100111];
long long dp[100111][8];
bool input() {
  if (cin >> n >> m) {
    string str;
    cin >> str;
    for (int i = (int)(1), _t = (int)(n); i <= _t; i++) s[i] = str[i - 1] - 'a';
    return true;
  } else {
    return false;
  }
}
int get_bit(int x, int v) { return (x >> v) & 1; }
void solve() {
  memset((dp), 0, sizeof(dp));
  for (int i = (int)(0), _t = (int)(m - 1); i <= _t; i++) {
    int state = 1;
    if (i == s[1]) state |= 2;
    if (i == s[1] || i == s[2]) state |= 4;
    dp[1][state]++;
  }
  for (int i = (int)(2), _t = (int)(n); i <= _t; i++) {
    for (int j = (int)(0), _t = (int)(7); j <= _t; j++) {
      int d[4] = {i - 3 + get_bit(j, 0), i - 2 + get_bit(j, 1),
                  i - 2 + get_bit(j, 2)};
      for (int k = (int)(0), _t = (int)(m - 1); k <= _t; k++) {
        int d2[4] = {};
        for (int l = (int)(1), _t = (int)(3); l <= _t; l++) {
          if (s[i - 2 + l] == k)
            d2[l] = d[l - 1] + 1;
          else
            d2[l] = max(d2[l - 1], d[l]);
        }
        if (d2[1] >= i - 2 && min(d2[2], d2[3]) >= i - 1)
          dp[i][(d2[1] - (i - 2)) | ((d2[2] - (i - 1)) << 1) |
                ((d2[3] - (i - 1)) << 2)] += dp[i - 1][j];
      }
    }
  }
  cout << (dp[n][0] + dp[n][1] + dp[n][4] + dp[n][5]) << endl;
}
int main() {
  ios ::sync_with_stdio(false);
  while (input()) solve();
  return 0;
}
