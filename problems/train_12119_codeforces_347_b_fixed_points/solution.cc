#include <bits/stdc++.h>
using namespace std;
int mas[100003], a, n, j;
int main() {
  cin >> n;
  int k = 0;
  int d = 0;
  for (int i = 0; i < n; i++) {
    cin >> mas[i];
  }
  for (int i = 0; i < n; i++) {
    if (mas[i] == i) {
      k++;
    } else {
      if (mas[mas[i]] == i && mas[i] < n && mas[i] >= 0) {
        d = 2;
      } else if (mas[i] < n && mas[i] >= 0) {
        if (d < 1) d = 1;
      }
    }
  }
  cout << d + k;
  return 0;
}
