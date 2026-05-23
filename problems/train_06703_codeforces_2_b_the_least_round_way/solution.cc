#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2>& p) {
  out << "{" << p.first << ", " << p.second << "} ";
  return out;
}
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& arr) {
  for (auto& i : arr) in >> i;
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T>& arr) {
  for (auto i : arr) out << i << " ";
  out << endl;
  return out;
}
const int INF = 1e9;
void stuff() {
  ios::sync_with_stdio(false);
  cin.tie();
  cout.tie();
}
const int MAXN = 1001;
int f[1001][1001][2];
char g[1001][1001][2];
int n;
int i, j, k, x = 0;
void print(int x, int y) {
  if (x == 1 && y == 1) return;
  if (g[x][y][k])
    print(x - 1, y), cout << 'D';
  else
    print(x, y - 1), cout << 'R';
}
int main() {
  cin >> n;
  for (i = 2; i <= n; ++i)
    f[0][i][0] = f[0][i][1] = f[i][0][0] = f[i][0][1] = 999999999;
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j) {
      cin >> k;
      if (!k)
        x = i;
      else {
        for (; !(k & 1); k >>= 1) ++f[i][j][0];
        for (; !(k % 5); k /= 5) ++f[i][j][1];
      }
      for (k = 0; k < 2; ++k)
        if ((g[i][j][k] = f[i - 1][j][k] < f[i][j - 1][k]))
          f[i][j][k] += f[i - 1][j][k];
        else
          f[i][j][k] += f[i][j - 1][k];
    }
  k = f[n][n][1] < f[n][n][0];
  if (x && f[n][n][k] > 1) {
    cout << 1 << endl;
    for (i = 2; i <= x; ++i) cout << 'D';
    for (i = 2; i <= n; ++i) cout << 'R';
    for (i = x + 1; i <= n; ++i) cout << 'D';
  } else
    cout << f[n][n][k] << endl, print(n, n);
}
