#include <bits/stdc++.h>
using namespace std;
int main() {
  int A[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) cin >> A[i][j];
  }
  bool v = false;
  for (int i = 0; i < 4; i++) {
    if (A[i][3] == 1) {
      if (A[(i + 1) % 4][0] == 1 || A[(i + 2) % 4][1] == 1 ||
          A[(i + 3) % 4][2] == 1 || A[i][0] + A[i][1] + A[i][2] > 0) {
        v = true;
        break;
      }
    }
  }
  (v) ? cout << "YES\n" : cout << "NO\n";
  return 0;
}
