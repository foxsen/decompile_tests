#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, j, sum = 0, c, t = 0;
  cin >> n >> k;
  int a[505][505] = {0};
  c = n * (k - 1);
  for (i = 1; i <= n; i++) {
    for (j = 1; j < k; j++) {
      t++, a[i][j] = t;
    }
    for (j = k; j <= n; j++) {
      c++, a[i][j] = c;
      if (j == k) sum += a[i][j];
    }
  }
  cout << sum << endl;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) cout << a[i][j] << " ";
    cout << endl;
  }
  return 0;
}
