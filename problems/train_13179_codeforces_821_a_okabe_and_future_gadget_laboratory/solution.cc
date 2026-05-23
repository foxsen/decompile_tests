#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  int arr[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] != 1) {
        bool found = 0;
        for (int k = 0; k < n; k++) {
          if (k != j) {
            int s = arr[i][j] - arr[i][k];
            for (int l = 0; l < n; l++) {
              if (arr[l][j] == s) {
                found = 1;
              }
            }
          }
        }
        if (!found) {
          cout << "No" << '\n';
          return 0;
        }
      }
    }
  }
  cout << "Yes" << '\n';
  return 0;
}
