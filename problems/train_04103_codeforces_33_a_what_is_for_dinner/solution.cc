#include <bits/stdc++.h>
using namespace std;
int row, col;
int total;
int main() {
  scanf("%d", &col);
  scanf("%d", &row);
  scanf("%d", &total);
  vector<int> vt(row + 10, -1);
  for (int i = 0; i < col; ++i) {
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    vt[x] = (vt[x] == -1 ? y : min(vt[x], y));
  }
  int res = 0;
  for (int i = 1; i <= row; ++i) {
    res += (vt[i] == -1 ? 0 : vt[i]);
  }
  cout << min(total, res) << "\n";
  return 0;
}
