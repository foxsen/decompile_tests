#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;
const int MOD = 1000000007;
int n, m;
vector<string> C;
vector<vector<char> > M;
vector<ll> DPh, DPv;
vector<bool> Hor;
char read_value(int x, int y) {
  int v = 0;
  char result = '_';
  for (int i = 4 * x + 1; i < 4 * x + 4; ++i) {
    for (int j = 4 * y + 1; j < 4 * y + 4; ++j) {
      if (C[i][j] == 'O') {
        v++;
      }
    }
  }
  if (v == 2 || v == 3) {
    result = (C[4 * x + 1][4 * y + 1] == '.') ? 'v' : 'h';
  } else if (v == 6) {
    result = (C[4 * x + 1][4 * y + 2] == '.') ? 'v' : 'h';
  }
  return result;
}
ll solv(int x, int y) {
  if (x > m - 2 || y > n) return 0;
  if (y == n) return 1;
  ll result = 0;
  if (DPv[y] > -1) {
    return DPv[y];
  }
  DPv[y] = 0;
  if (M[y][x] != 'v' && M[y][x + 1] != 'v') {
    DPv[y] += solv(x, y + 1);
  }
  if (y < n - 1 && M[y][x] != 'h' && M[y][x + 1] != 'h' && M[y + 1][x] != 'h' &&
      M[y + 1][x + 1] != 'h') {
    DPv[y] += solv(x, y + 2);
  }
  DPv[y] %= MOD;
  return DPv[y];
}
ll sol(int x) {
  if (x > m) return 0;
  if (x == m) return 1;
  ll result = 0;
  if (DPh[x] > -1) {
    return DPh[x];
  }
  DPh[x] = 0;
  if (n % 2 == 0 && !Hor[x]) {
    DPh[x] = sol(x + 1);
  }
  DPv.clear();
  DPv.resize(n, -1);
  ll s_2 = solv(x, 0);
  if (n % 2 == 0 && x < m - 1 && !Hor[x] && !Hor[x + 1]) {
    s_2 -= 1;
  }
  DPh[x] += s_2 * sol(x + 2);
  DPh[x] %= MOD;
  return DPh[x];
}
int main() {
  ios::sync_with_stdio(false);
  cout.precision(20);
  cin.tie(NULL);
  while (cin >> n) {
    cin >> m;
    C.resize(4 * n + 1);
    M.clear();
    M.resize(n, vector<char>(m, '_'));
    for (int i = 0; i < 4 * n + 1; ++i) {
      cin >> C[i];
    }
    Hor.clear();
    Hor.resize(m, false);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        M[i][j] = read_value(i, j);
        if (M[i][j] == 'h') {
          Hor[j] = true;
        }
      }
    }
    DPh.clear();
    DPh.resize(m, -1);
    cout << sol(0) << endl;
  }
  return 0;
}
