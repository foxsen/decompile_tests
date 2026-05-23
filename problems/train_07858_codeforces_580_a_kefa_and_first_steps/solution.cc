#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, f = 0;
  cin >> n;
  int a[n], b[n];
  for (i = 0; i < n; i++) cin >> a[i];
  int m = a[0], c = 1, k = 0;
  for (i = 1; i < n; i++) {
    f = 1;
    if (m < a[i] || m == a[i]) {
      c++;
      m = a[i];
    } else {
      m = a[i];
      c = 1;
    }
    b[k] = c;
    k++;
  }
  if (f) {
    int mx = b[0];
    for (i = 1; i < k; i++) {
      if (mx < b[i]) mx = b[i];
    }
    cout << mx << endl;
  } else
    cout << c << endl;
  return 0;
}
