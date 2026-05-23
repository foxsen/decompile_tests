#include <bits/stdc++.h>
using namespace std;
template <class T, class IT>
inline void PRINT(IT i1, IT i2) {
  cout << '[';
  copy(i1, i2, ostream_iterator<T>(cout, ", "));
  cout << "]\n";
}
char field[155][155];
int l[155];
int r[155];
int total_weed;
int main() {
  int n, m;
  cin >> n >> m;
  total_weed = 0;
  for (int i = 0; i < (int)(n); ++i) {
    char buf[155];
    cin >> buf;
    int l_ = 155 + 1;
    int r_ = -1;
    for (int j = 0; j < (int)(m); ++j) {
      field[i][j] = buf[j];
      if (field[i][j] == 'W') {
        l_ = min(l_, j);
        r_ = max(r_, j);
        ++total_weed;
      }
      if (r_ >= 0) {
        l[i] = l_;
        r[i] = r_;
      } else {
        l[i] = -1;
        r[i] = -1;
      }
    }
  }
  int row = 0;
  int col = 0;
  bool dir_right = true;
  int harvested_weed = 0;
  int moves_performed = 0;
  while (harvested_weed < total_weed) {
    if (dir_right) {
      int border = col;
      if (r[row] >= 0) border = max(border, r[row]);
      if (row + 1 < n && r[row + 1] >= 0) border = max(border, r[row + 1]);
      if (col != border) {
        ++col;
        if (field[row][col] == 'W') ++harvested_weed;
      } else {
        ++row;
        dir_right = !dir_right;
        if (field[row][col] == 'W') ++harvested_weed;
      }
    } else {
      int border = col;
      if (l[row] >= 0) border = min(border, l[row]);
      if (row + 1 < n && l[row + 1] >= 0) border = min(border, l[row + 1]);
      if (col != border) {
        --col;
        if (field[row][col] == 'W') ++harvested_weed;
      } else {
        ++row;
        dir_right = !dir_right;
        if (field[row][col] == 'W') ++harvested_weed;
      }
    }
    ++moves_performed;
  }
  cout << moves_performed;
  return 0;
}
