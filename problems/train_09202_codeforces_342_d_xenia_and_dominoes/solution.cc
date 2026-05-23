#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
const long long mod = 1e9 + 7;
long long f[maxn][8], g[maxn][8];
char a[3][maxn];
int n;
int lst[3], now[3];
long long work() {
  memset(f, 0, sizeof(f));
  f[0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 8; j++) {
      if (!f[i][j]) continue;
      int t = j;
      for (int k = 2; k >= 0; k--) lst[k] = t % 2, t /= 2;
      for (int k = 0; k < 8; k++) {
        int t = k;
        for (int l = 2; l >= 0; l--) now[l] = t % 2, t /= 2;
        bool flag = true;
        for (int l = 0; l <= 2; l++) {
          if (now[l] && a[l][i + 1] == 'X') flag = false;
          if (now[l] == lst[l] && a[l][i + 1] == '.') flag = false;
          if (lst[l] && a[l][i + 1] == 'X') flag = false;
        }
        if (flag) (f[i + 1][k] += f[i][j]) %= mod;
      }
      if (a[0][i + 1] == '.' && a[1][i + 1] == '.' && lst[0] == 0 &&
          lst[1] == 0) {
        now[0] = now[1] = 0;
        if (a[2][i + 1] == 'X' && lst[2] == 1) continue;
        if (a[2][i + 1] == 'X')
          now[2] = 0;
        else
          now[2] = 1 - lst[2];
        t = 0;
        for (int k = 0; k <= 2; k++) t = t * 2 + now[k];
        (f[i + 1][t] += f[i][j]) %= mod;
      }
      if (a[1][i + 1] == '.' && a[2][i + 1] == '.' && lst[1] == 0 &&
          lst[2] == 0) {
        now[1] = now[2] = 0;
        if (a[0][i + 1] == 'X' && lst[0] == 1) continue;
        if (a[0][i + 1] == 'X')
          now[0] = 0;
        else
          now[0] = 1 - lst[0];
        t = 0;
        for (int k = 0; k <= 2; k++) t = t * 2 + now[k];
        (f[i + 1][t] += f[i][j]) %= mod;
      }
    }
  return f[n][0];
}
char in[3][maxn];
void copy() {
  for (int i = 0; i < 3; i++)
    for (int j = 1; j <= n; j++) a[i][j] = in[i][j];
}
void give(int x, int y) { a[x][y] = 'X'; }
bool check(int x, int y) {
  if (x < 0 || x >= 3 || y <= 0 || y > n) return false;
  if (in[x][y] == 'X') return false;
  return true;
}
int canx[3][2] = {0}, cany[3][2] = {0};
bool ok[7][3];
int sign[7];
int main() {
  std::ios::sync_with_stdio(false);
  cany[0][0] = -1, cany[0][1] = -2;
  cany[1][0] = 1, cany[1][1] = 2;
  canx[2][0] = 1, canx[2][1] = 2;
  ok[0][0] = true, ok[1][1] = true, ok[2][2] = true;
  ok[3][0] = ok[3][1] = true;
  ok[4][0] = ok[4][2] = true;
  ok[5][1] = ok[5][2] = true;
  ok[6][1] = ok[6][2] = ok[6][3] = true;
  sign[0] = sign[1] = sign[2] = sign[6] = 1, sign[3] = sign[4] = sign[5] = -1;
  int x, sn;
  cin >> n;
  for (int i = 0; i < 3; i++)
    for (int j = 1; j <= n; j++) {
      cin >> in[i][j];
      if (in[i][j] == 'O') sn = j, x = i;
    }
  in[0][0] = in[1][0] = in[2][0] = 'X';
  if (x == 2) {
    for (int i = 1; i <= n; i++) swap(in[0][i], in[2][i]);
    x = 0;
  }
  in[x][sn] = 'X';
  long long ans = 0;
  for (int _ = 0; _ <= 6; _++) {
    bool flag = true;
    for (int i = 0; i <= 2; i++) {
      if (!ok[_][i]) continue;
      for (int j = 0; j < 2; j++)
        if (!check(x + canx[i][j], sn + cany[i][j])) flag = false;
    }
    if (flag) {
      copy();
      for (int i = 0; i <= 2; i++) {
        if (!ok[_][i]) continue;
        for (int j = 0; j < 2; j++)
          give(x + canx[i][j], sn + cany[i][j]),
              give(x + canx[i][j], sn + cany[i][j]);
      }
      ans += work() * sign[_];
    }
  }
  ans %= mod;
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}
