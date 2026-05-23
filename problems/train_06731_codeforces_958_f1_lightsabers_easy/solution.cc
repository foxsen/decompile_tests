#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, s, k, h, d, f;
int main() {
  cin >> n >> m;
  int a[n], b[m];
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= m; i++) {
    cin >> b[i];
    s = s + b[i];
  }
  for (i = 1; i < n - s + 2; i++) {
    for (j = i + s - 1; j <= n; j++) {
      int l[m + 1];
      for (f = 1; f < m + 1; f++) {
        l[f] = 0;
      }
      for (k = i; k <= j; k++) {
        l[a[k]]++;
      }
      h = 0;
      for (d = 1; d <= m; d++) {
        if (b[d] == l[d]) h++;
      }
      if (h == m) {
        cout << "YES";
        return 0;
      }
    }
  }
  cout << "NO";
}
