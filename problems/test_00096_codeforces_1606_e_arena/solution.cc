#include <bits/stdc++.h>
using namespace std;
int n, x;
int f[505][505], C[505][505], pw[505][505];
void add(int &a, int b) {
  a += b;
  if (a >= 998244353) a -= 998244353;
}
void init() {
  for (int i = 0; i <= 500; i++) C[0][i] = 1;
  for (int i = 1; i <= 500; i++)
    for (int j = i; j <= 500; j++)
      C[i][j] = (C[i - 1][j - 1] + C[i][j - 1]) % 998244353;
  for (int i = 1; i <= 500; i++) {
    pw[i][0] = 1;
    for (int j = 1; j <= 500; j++)
      pw[i][j] = (1ll * pw[i][j - 1] * i) % 998244353;
  }
}
void solve() {
  cin >> n >> x;
  init();
  for (int i = 0; i <= 0; i++) f[n][i] = 1;
  for (int i = n; i > 1; i--)
    for (int j = 0; j <= x; j++) {
      if (!f[i][j]) continue;
      for (int k = 0; k <= i; k++) {
        int h = min(x, j + i - 1);
        add(f[k][h], 1ll * C[i - k][i] * pw[h - j][i - k] % 998244353 *
                         f[i][j] % 998244353);
      }
    }
  int res = 0;
  for (int i = 0; i <= x; i++) add(res, f[0][i]);
  cout << res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T = 1;
  for (int i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
