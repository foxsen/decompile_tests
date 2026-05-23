#include <bits/stdc++.h>
const long double eps = 0.00000001;
const long long MOD = 1e9 + 7;
const double PI = 3.141592653589793238463;
using namespace std;
long long ans, k;
int n, m;
long long a[25][25];
map<pair<pair<int, int>, long long>, long long> cnt;
int half;
bool isOK(int x, int y) {
  if (x >= 1 && x <= n && y >= 1 && y <= m) return true;
  return false;
}
void dfs(int x, int y, long long res) {
  res ^= a[x][y];
  if (x + y == half) {
    cnt[{{x, y}, res}]++;
    return;
  }
  if (isOK(x + 1, y)) dfs(x + 1, y, res);
  if (isOK(x, y + 1)) dfs(x, y + 1, res);
}
void back_dfs(int x, int y, long long res) {
  if (x + y == half) {
    ans += cnt[{{x, y}, (res ^ k)}];
    return;
  }
  res ^= a[x][y];
  if (isOK(x - 1, y)) back_dfs(x - 1, y, res);
  if (isOK(x, y - 1)) back_dfs(x, y - 1, res);
}
int main() {
  fflush(stdin);
  cout << fixed, cout.precision(18);
  ios_base::sync_with_stdio(false);
  int i, j;
  cin >> n >> m >> k;
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j) cin >> a[i][j];
  half = (m + n) / 2 + 1;
  dfs(1, 1, 0ll);
  back_dfs(n, m, 0ll);
  cout << ans;
}
