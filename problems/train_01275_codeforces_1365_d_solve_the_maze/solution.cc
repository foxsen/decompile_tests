#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 7;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
bool block(string *S, int i, int j, int n, int m) {
  vector<pair<int, int>> A{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  for (auto g : A) {
    int ii = i + g.first;
    int jj = j + g.second;
    if (ii >= 0 && ii < n && jj >= 0 && jj < m) {
      if (S[ii][jj] == 'G') {
        return false;
      }
      if (S[ii][jj] == '.') {
        S[ii][jj] = '#';
      }
    }
  }
  return true;
}
bool ok(string *S, int i, int j, int n, int m) {
  vector<pair<int, int>> A{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  S[i][j] = '0';
  for (auto g : A) {
    int ii = i + g.first;
    int jj = j + g.second;
    if (ii >= 0 && ii < n && jj >= 0 && jj < m) {
      if (S[ii][jj] == '1') {
        S[i][j] = '1';
        return true;
      }
      if (S[ii][jj] == '.' || S[ii][jj] == 'G') {
        if (ok(S, ii, jj, n, m)) {
          S[i][j] = '1';
          return true;
        }
      }
    }
  }
  return false;
}
void solve() {
  int n, m;
  cin >> n >> m;
  string S[n];
  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (S[i][j] == 'B' && !block(S, i, j, n, m)) {
        cout << "No\n";
        return;
      }
    }
  }
  if (S[n - 1][m - 1] == '.') {
    S[n - 1][m - 1] = '1';
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (S[i][j] == 'G' && !ok(S, i, j, n, m)) {
        cout << "No\n";
        return;
      }
    }
  }
  cout << "Yes\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
