#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, max, count = 0, flag = 0;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> m;
  int b[m];
  for (j = 0; j < m; j++) {
    cin >> b[j];
    for (i = 0; i < n; i++) {
      if (b[j] % a[i] == 0) {
        if (flag == 0) {
          max = b[j] / a[i];
          count++;
          flag = 1;
        } else if (b[j] / a[i] == max) {
          count++;
        } else if (b[j] / a[i] > max) {
          max = b[j] / a[i];
          count = 1;
        }
      }
    }
  }
  cout << count;
  return 0;
}
