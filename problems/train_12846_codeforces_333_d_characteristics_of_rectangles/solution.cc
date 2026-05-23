#include <bits/stdc++.h>
using namespace std;
int fastMax(int x, int y) { return (((y - x) >> (32 - 1)) & (x ^ y)) ^ y; }
int fastMin(int x, int y) { return (((y - x) >> (32 - 1)) & (x ^ y)) ^ x; }
const int N = 50010;
const int M = 1e6 + 5;
int res[1010][1010];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &res[i][j]);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n - 1; i++) {
    for (int j = i + 1; j <= n; ++j) {
      int m1 = -0x3f3f3f3f, m2 = -0x3f3f3f3f;
      for (int k = 1; k <= m; ++k) {
        int x = res[i][k], y = res[j][k];
        x = fastMin(x, y);
        if (x > m1)
          m2 = m1, m1 = x;
        else if (x > m2)
          m2 = x;
      }
      ans = fastMax(ans, m2);
    }
  }
  cout << ans << endl;
}
