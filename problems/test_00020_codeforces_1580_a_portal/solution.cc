#include <bits/stdc++.h>
using namespace std;
int T;
int n, m;
int mp[410][410], s[410][410], mx[410], p[410];
int sum(int i, int j, int k) { return s[j - 1][k] - s[i][k]; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        char c;
        cin >> c;
        if (c == '0')
          mp[i][j] = 0;
        else
          mp[i][j] = 1;
      }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + mp[i][j];
    int ans = 5000000;
    for (int i = 1; i <= n; i++)
      for (int j = i + 4; j <= n; j++) {
        for (int k = m; k >= 1; k--) {
          p[k] = 2 * sum(i, j, k - 1) - sum(i, j, k) -
                 sum(i - 1, i + 1, k - 1) - sum(j - 1, j + 1, k - 1) + j - i +
                 2 * k - 3;
          if (k == m)
            mx[k] = p[k];
          else
            mx[k] = min(mx[k + 1], p[k]);
        }
        for (int l = 1; l <= m - 3; l++) {
          int tmp = mx[l + 3] - (s[j - 1][l] - s[i][l]) + j - 1 - i -
                    (s[j - 1][l] - s[i][l] - s[j - 1][l - 1] + s[i][l - 1]) -
                    l + (s[i][l] - s[i - 1][l]) - l + (s[j][l] - s[j - 1][l]);
          ans = min(ans, tmp);
        }
      }
    cout << ans << endl;
  }
  return 0;
}
