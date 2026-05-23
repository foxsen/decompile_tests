#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> arr[i][j];
      }
    }
    int row = 0, col = 0;
    for (int i = 0; i < n; i++) {
      bool flag = true;
      for (int j = 0; j < m; j++) {
        if (arr[i][j] == 1) flag = false;
      }
      if (flag) row++;
    }
    for (int j = 0; j < m; j++) {
      bool flag = true;
      for (int i = 0; i < n; i++) {
        if (arr[i][j] == 1) flag = false;
      }
      if (flag) col++;
    }
    int ans = min(row, col);
    if (ans % 2 == 0) {
      cout << "Vivek" << endl;
    } else
      cout << "Ashish" << endl;
  }
}
