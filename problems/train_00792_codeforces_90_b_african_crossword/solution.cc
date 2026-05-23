#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[150][150];
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int s[150][150];
  memset(s, 0, sizeof(s));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c = a[i][j];
      for (int b = 0; b < m; b++) {
        if (b != j) {
          if (c == a[i][b]) {
            s[i][b] = 1;
          }
        }
      }
      for (int b = 0; b < n; b++) {
        if (b != i) {
          if (c == a[b][j]) {
            s[b][j] = 1;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (s[i][j] != 1) {
        cout << a[i][j];
      }
    }
  cout << endl;
  return 0;
}
