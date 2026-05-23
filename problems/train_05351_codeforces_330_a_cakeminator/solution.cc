#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j;
  map<int, int> x, y;
  cin >> n >> m;
  char arr[n][m];
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 'S') {
        x[i]++;
        y[j]++;
      }
    }
  }
  int notification = 0, sum = 0;
  for (i = 0; i < n; i++) {
    if (x[i] == 0) {
      for (j = 0; j < m; j++) {
        arr[i][j] = 'M';
      }
    }
  }
  for (i = 0; i < m; i++) {
    if (y[i] == 0) {
      for (j = 0; j < n; j++) {
        arr[j][i] = 'M';
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (arr[i][j] == 'M') {
        sum++;
      }
    }
  }
  cout << sum << endl;
}
