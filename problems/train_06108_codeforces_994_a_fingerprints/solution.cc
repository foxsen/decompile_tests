#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, m, x[100], y[11], z[11], i, j, k = 0;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (i = 0; i < m; i++) {
    cin >> y[i];
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (x[i] == y[j]) {
        z[k] = x[i];
        k++;
      }
    }
  }
  for (i = 0; i < k; i++) {
    cout << z[i] << " ";
  }
  return 0;
}
