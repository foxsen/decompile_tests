#include <bits/stdc++.h>
using namespace std;
const int MAXC = 60;
int R, C;
int sum[MAXC][MAXC];
int getSum(int x1, int y1, int x2, int y2) {
  return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}
int test(int a, int b) {
  int ans = R * C;
  for (int i = (int)(1); i <= (int)(R); ++i)
    for (int j = (int)(1); j <= (int)(C); ++j)
      if (i + a - 1 <= R && j + b - 1 <= C)
        ans = min(ans, getSum(i, j, i + a - 1, j + b - 1));
  return ans;
}
int main() {
  cin >> R >> C;
  for (int i = (int)(1); i <= (int)(R); ++i)
    for (int j = (int)(1); j <= (int)(C); ++j) {
      int x;
      cin >> x;
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + x;
    }
  int a, b;
  cin >> a >> b;
  cout << min(test(a, b), test(b, a)) << endl;
  return 0;
}
