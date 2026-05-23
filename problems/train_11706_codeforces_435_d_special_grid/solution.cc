#include <bits/stdc++.h>
using namespace std;
int mat[405][405];
int n, m;
string s;
int hangr[405][405], hangl[405][405];
int lieu[405][405];
void Init() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) mat[i][j + 1] = s[j] - '0';
  }
  for (int i = 1; i <= n; i++) {
    int last = 0;
    for (int j = 1; j <= m; j++) {
      if (mat[i][j]) last = j;
      hangl[i][j] = last;
    }
    last = m + 1;
    for (int j = m; j >= 1; j--) {
      if (mat[i][j]) last = j;
      hangr[i][j] = last;
    }
  }
  for (int j = 1; j <= m; j++) {
    int last = 0;
    for (int i = 1; i <= n; i++) {
      if (mat[i][j]) last = i;
      lieu[i][j] = last;
    }
  }
}
void solve() {
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (mat[i][j]) continue;
      for (int l = 1; i + l <= n && j + l <= m; l++) {
        if (mat[i + l][j + l]) break;
        if (hangl[i + l][j + l] < j && lieu[i + l][j] < i) ans++;
      }
      for (int l = 1; i + l <= n && j - l > 0; l++) {
        if (mat[i + l][j - l]) break;
        if (hangr[i + l][j - l] > j && lieu[i + l][j] < i) ans++;
      }
      for (int l = 1; i + l <= n && j - l > 0; l++) {
        if (mat[i + l][j - l]) break;
        if (hangr[i][j - l] > j && lieu[i + l][j - l] < i) ans++;
      }
      for (int l = 1; i + l <= n && j + l <= m; l++) {
        if (mat[i + l][j + l]) break;
        if (hangl[i][j + l] < j && lieu[i + l][j + l] < i) ans++;
      }
      for (int l = 1; j - l > 0 && j + l <= m && i - l > 0; l++) {
        if (mat[i - l][j - l] || mat[i - l][j + l]) break;
        if (hangl[i - l][j + l] < j - l) ans++;
      }
      for (int l = 1; j - l > 0 && j + l <= m && i + l <= n; l++) {
        if (mat[i + l][j - l] || mat[i + l][j + l]) break;
        if (hangl[i + l][j + l] < j - l) ans++;
      }
      for (int l = 1; i - l > 0 && i + l <= n && j + l <= m; l++) {
        if (mat[i - l][j + l] || mat[i + l][j + l]) break;
        if (lieu[i + l][j + l] < i - l) ans++;
      }
      for (int l = 1; i - l > 0 && i + l <= n && j - l > 0; l++) {
        if (mat[i - l][j - l] || mat[i + l][j - l]) break;
        if (lieu[i + l][j - l] < i - l) ans++;
      }
    }
  cout << ans;
}
int main() {
  Init();
  solve();
  return 0;
}
