#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 * 3 + 2, oo = INT_MAX, mod = 1e9 + 7;
void debug() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug(T...);
}
int n;
string s;
long long dp[N][4];
long long solve(int indx, int cur) {
  if (indx == n) {
    return (cur == 3);
  }
  long long &res = dp[indx][cur];
  if (~res) return res;
  res = (solve(indx + 1, cur) % mod * (s[indx] == '?' ? 3 : 1) % mod) % mod;
  if (cur == 3) return res;
  if (s[indx] - 'a' == cur || s[indx] == '?')
    res = (res + solve(indx + 1, cur + 1)) % mod;
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<vector<char>> v(h, vector<char>(w));
  vector<vector<int>> col(w, vector<int>(h, 0)), row(h, vector<int>(w, 0));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> v[i][j];
    }
  }
  for (int y = w - 1; y >= 0; --y) {
    for (int i = h - 2; i >= 0; --i) {
      if (v[i][y] == v[i + 1][y] and v[i][y] == '.')
        col[y][i] = col[y][i + 1] + 1;
      else
        col[y][i] = col[y][i + 1];
    }
  }
  for (int i = h - 1; i >= 0; --i) {
    for (int y = w - 2; y >= 0; --y) {
      if (v[i][y] == v[i][y + 1] and v[i][y] == '.')
        row[i][y] = row[i][y + 1] + 1;
      else
        row[i][y] = row[i][y + 1];
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int r1, c1, r2, c2, c = 0;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--, r2--, c1--, c2--;
    for (int i = c1; i <= c2; ++i) {
      if (col[i][r1] > col[i][r2]) c += col[i][r1] - col[i][r2];
    }
    for (int i = r1; i <= r2; ++i) {
      if (row[i][c1] > row[i][c2]) c += row[i][c1] - row[i][c2];
    }
    cout << c << '\n';
  }
  return 0;
}
