#include <bits/stdc++.h>
using namespace std;
int cell[4][4];
void go() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) cout << cell[i][j] << " ";
    cout << endl;
  }
}
int main() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) cin >> cell[i][j];
  }
  cell[0][0] = (cell[1][2] + cell[2][1]) / 2;
  cell[2][2] = (cell[0][1] + cell[1][0]) / 2;
  cell[1][1] = ((cell[0][0] + cell[0][2]) - cell[2][1]);
  go();
  return 0;
}
