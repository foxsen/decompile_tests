#include <algorithm>
#include <iostream>

using namespace std;

//  g, f, e, d, c, b, a
int ss[10][7] = {
  { 0, 1, 1, 1, 1, 1, 1 },
  { 0, 0, 0, 0, 1, 1, 0 },
  { 1, 0, 1, 1, 0, 1, 1 },
  { 1, 0, 0, 1, 1, 1, 1 },
  { 1, 1, 0, 0, 1, 1, 0 },
  { 1, 1, 0, 1, 1, 0, 1 },
  { 1, 1, 1, 1, 1, 0, 1 },
  { 0, 1, 0, 0, 1, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 0, 1, 1, 1, 1 }
};

int main() {
  for (;;) {
    int n;
    cin >> n;
    if (n == -1) return 0;
    int d[7];
    fill(d, d+7, 0);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      for (int j = 0; j < 7; j++) {
        cout << (d[j] ^ ss[x][j]);
        d[j] = ss[x][j];
      }
      cout << endl;
    }
  }
}