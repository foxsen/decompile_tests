#include <bits/stdc++.h>
using namespace std;
char a[3][3];
int p[3];
int main() {
  int i;
  cin >> a[0] >> a[1] >> a[2];
  int x;
  for (i = 0; i < 3; i++) {
    x = 0;
    switch (a[i][1]) {
      case 's':
        x = 0;
        break;
      case 'm':
        x = 10;
        break;
      case 'p':
        x = 20;
        break;
    }
    p[i] = x + (a[i][0] - '0');
  }
  sort(p, p + 3);
  if (p[0] == p[1] && p[1] == p[2]) {
    cout << 0;
    return 0;
  }
  if (p[2] - p[1] == 1 && p[1] - p[0] == 1) {
    cout << 0;
    return 0;
  }
  if (p[2] / 10 == p[1] / 10 && p[2] - p[1] <= 2) {
    cout << 1;
    return 0;
  }
  if (p[1] / 10 == p[0] / 10 && p[1] - p[0] <= 2) {
    cout << 1;
    return 0;
  }
  cout << 2;
}
