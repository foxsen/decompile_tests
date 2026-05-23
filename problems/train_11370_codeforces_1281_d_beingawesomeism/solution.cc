#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t, r, c;
  cin >> t;
  while (t--) {
    cin >> r >> c;
    vector<string> v(r);
    for (long long int i(0), ThkMk(r); i < ThkMk; ++i) cin >> v[i];
    vector<vector<bool>> hb(r, vector<bool>(c, false));
    vector<vector<bool>> vb = hb;
    bool edge = false;
    int cnt = 0;
    bool fulledge = false;
    bool edgefulledge = false;
    bool esquina = false;
    for (long long int i(0), ThkMk(r); i < ThkMk; ++i) {
      for (long long int j(0), ThkMk(c); j < ThkMk; ++j) {
        if (v[i][j] == 'A') {
          ++cnt;
          if (i > 0) {
            hb[i][j] = hb[i - 1][j];
          }
          if (i == 0) {
            edge = true;
            if (j == 0 or j == c - 1) esquina = true;
            hb[i][j] = true;
          }
          if (i == r - 1) {
            edge = true;
            if (j == 0 or j == c - 1) esquina = true;
            if (i > 0)
              hb[i][j] = hb[i - 1][j];
            else
              hb[i][j] = true;
            if (hb[i][j]) {
              fulledge = true;
              if (j == 0 or j == c - 1) edgefulledge = true;
            }
          }
          if (j > 0) {
            vb[i][j] = vb[i][j - 1];
          }
          if (j == 0) {
            edge = true;
            if (i == 0 or i == r - 1) esquina = true;
            vb[i][j] = true;
          }
          if (j == c - 1) {
            edge = true;
            if (i == 0 or i == r - 1) esquina = true;
            if (j > 0)
              vb[i][j] = vb[i][j - 1];
            else
              vb[i][j] = true;
            if (vb[i][j]) {
              fulledge = true;
              if (i == 0 or i == r - 1) edgefulledge = true;
            }
          }
        }
      }
    }
    if (cnt == 0) {
      cout << "MORTAL" << '\n';
      continue;
    }
    if (cnt == r * c) {
      cout << "0" << '\n';
      continue;
    }
    if (edgefulledge) {
      cout << "1" << '\n';
      continue;
    }
    if (esquina or fulledge) {
      cout << "2" << '\n';
      continue;
    }
    if (edge) {
      cout << "3" << '\n';
      continue;
    }
    cout << "4" << '\n';
  }
  return 0;
}
