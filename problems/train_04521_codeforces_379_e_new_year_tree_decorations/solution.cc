#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int inf = 1e9 + 7;
const long long linf = 1e18;
int a[13333];
inline int fastmax(int x, int y) { return (((y - x) >> (31)) & (x ^ y)) ^ y; }
int v[333][333];
double ans[333];
const int D = 2500;
int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < k + 1; j++) cin >> v[i][j];
  for (int i = 0; i < k; i++)
    for (int j = 0; j < D + 1; j++) {
      int h, y = 0;
      for (int K = 0; K < n; K++) {
        int ynow = v[K][i] * (D - j) + v[K][i + 1] * j;
        h = fastmax(0, ynow - y);
        y = fastmax(y, ynow);
        ans[K] += h;
        if (j != 0 && j != D) ans[K] += h;
      }
    }
  for (int i = 0; i < n; i++)
    cout << fixed << setprecision(6) << ans[i] / D / 5000 << endl;
  return 0;
}
