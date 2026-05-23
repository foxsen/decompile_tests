#include <bits/stdc++.h>
using namespace std;
int s[55][55];
long long poww[100];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  poww[0] = 1;
  for (int i = 1; i <= 80; i++) poww[i] = (poww[i - 1] * 2);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> s[i][j];
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int o = 0, z = 0;
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == 1)
        o++;
      else
        z++;
    }
    ans += poww[o] - 1;
    ans += poww[z] - 1;
  }
  for (int i = 1; i <= m; i++) {
    int o = 0, z = 0;
    for (int j = 1; j <= n; j++) {
      if (s[j][i] == 1)
        o++;
      else
        z++;
    }
    ans += poww[o] - 1;
    ans += poww[z] - 1;
  }
  cout << ans - n * m << endl;
}
