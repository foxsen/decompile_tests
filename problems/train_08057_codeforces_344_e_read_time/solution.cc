#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, k;
  long long a[100005], b[100005], l = 0, r = 100000000050LL, x, z, y = r;
  cin >> n >> m;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= m; i++) cin >> b[i];
  while (l <= r) {
    x = l + (r - l) / 2;
    j = 1;
    for (i = 1; i <= n; i++) {
      if (j > m || a[i] - x > b[j]) break;
      z = b[j];
      k = j;
      if (z < a[i]) {
        while (b[j] <= a[i] + (x - (a[i] - z)) / 2) j++;
        while (b[k] <= z + x - (a[i] - z)) k++;
        j = max(j, k);
      } else
        while (b[j] <= a[i] + x) j++;
    }
    if (j <= m)
      l = x + 1;
    else
      r = x - 1, y = min(y, x);
  }
  cout << y;
  return 0;
}
