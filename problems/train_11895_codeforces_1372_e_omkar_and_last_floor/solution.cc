#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
void ckmin(T &a, U b) {
  if (a > b) a = b;
}
template <class T, class U>
void ckmax(T &a, U b) {
  if (a < b) a = b;
}
const int MAXN = 113;
int N, M;
vector<int> pts[MAXN];
int id[MAXN][MAXN];
int dp[MAXN][MAXN];
int32_t main() {
  cout << fixed << setprecision(12);
  cerr << fixed << setprecision(4);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  for (auto i = (0); i < (N); i++) {
    int k;
    cin >> k;
    for (auto j = (1); j < (k + 1); j++) {
      int l, r;
      cin >> l >> r;
      for (auto k = (l); k < (r + 1); k++) {
        id[i][k] = j;
      }
    }
    id[i][0] = 0;
    id[i][M + 1] = k + 1;
  }
  for (auto i = (0); i < (M); i++) {
    for (auto l = (1); l < (M - i + 1); l++) {
      int r = l + i;
      for (auto j = (l); j < (r + 1); j++) {
        int cur = 0;
        int c = 0;
        for (auto k = (0); k < (N); k++) {
          cur = dp[l][j - 1] + dp[j + 1][r];
          if (id[k][j] != id[k][l - 1] && id[k][j] != id[k][r + 1]) c++;
        }
        ckmax(dp[l][r], cur + c * c);
      }
    }
  }
  cout << dp[1][M] << '\n';
  return 0;
}
