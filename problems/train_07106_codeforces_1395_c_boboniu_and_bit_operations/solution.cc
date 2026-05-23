#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  cin >> n >> m;
  long long int a[n], b[m];
  vector<long long int> x[n];
  for (long long int i = 0; i < n; i++) cin >> a[i];
  for (long long int i = 0; i < m; i++) cin >> b[i];
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) x[i].push_back(a[i] & b[j]);
  }
  for (long long int k = 0; k < 512; k++) {
    long long int oh = 0;
    for (long long int i = 0; i < n; i++) {
      long long int ok = 0;
      for (long long int j = 0; j < m; j++) {
        if ((k | x[i][j]) == k) {
          ok = 1;
          break;
        }
      }
      if (ok == 0) {
        oh = 1;
        break;
      }
    }
    if (oh == 0) {
      cout << k << endl;
      break;
    }
  }
  return 0;
}
