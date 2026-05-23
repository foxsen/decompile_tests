#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int maxN = 1e5 + 10;
int n, m;
void solve() {
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  vector<vector<int>> pre_min(n, vector<int>(m));
  vector<vector<int>> pre_max(n, vector<int>(m));
  vector<vector<int>> suf_min(n, vector<int>(m));
  vector<vector<int>> suf_max(n, vector<int>(m));
  for (int i = 0; i < (int)(n); ++i) {
    for (int j = 0; j < (int)(m); ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < (int)(n); ++i) {
    pre_min[i][0] = pre_max[i][0] = a[i][0];
    for (int j = 1; j <= (int)(m - 1); ++j) {
      pre_min[i][j] = min(pre_min[i][j - 1], a[i][j]);
      pre_max[i][j] = max(pre_max[i][j - 1], a[i][j]);
    }
    suf_min[i][m - 1] = suf_max[i][m - 1] = a[i][m - 1];
    for (int j = (int)(m - 1) - 1; j >= 0; --j) {
      suf_min[i][j] = min(suf_min[i][j + 1], a[i][j]);
      suf_max[i][j] = max(suf_max[i][j + 1], a[i][j]);
    }
  }
  for (int col = 0; col < (int)(m - 1); ++col) {
    vector<int> vec(n);
    iota((vec).begin(), (vec).end(), 0);
    sort((vec).begin(), (vec).end(),
         [&](int i, int j) { return pre_max[i][col] < pre_max[j][col]; });
    vector<int> suf_x(n), suf_y(n);
    suf_x[n - 1] = pre_min[vec[n - 1]][col];
    suf_y[n - 1] = suf_max[vec[n - 1]][col + 1];
    for (int i = (int)(n - 1) - 1; i >= 0; --i) {
      suf_x[i] = min(suf_x[i + 1], pre_min[vec[i]][col]);
      suf_y[i] = max(suf_y[i + 1], suf_max[vec[i]][col + 1]);
    }
    int x = pre_max[vec[0]][col], y = suf_min[vec[0]][col + 1];
    int pos = -1;
    for (int i = 0; i < (int)(n - 1); ++i) {
      if (x < suf_x[i + 1] && y > suf_y[i + 1]) {
        pos = i;
        break;
      }
      x = max(x, pre_max[vec[i + 1]][col]);
      y = min(y, suf_min[vec[i + 1]][col + 1]);
    }
    if (pos != -1) {
      string ans(n, 0);
      for (int i = 0; i < (int)(n); ++i) {
        if (i <= pos) {
          ans[vec[i]] = 'B';
        } else {
          ans[vec[i]] = 'R';
        }
      }
      cout << "YES\n" << ans << " " << col + 1 << "\n";
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
