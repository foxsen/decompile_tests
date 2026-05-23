#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, m, i, j, a[1001], b[1001], c[1001], mi = 0, ma = 0;
  cin >> n >> m;
  for (i = 0; i < m; i++) cin >> a[i], b[i] = c[i] = a[i];
  sort(b, b + m);
  sort(c, c + m, greater<int>());
  i = 0, j = n;
  while (j) {
    ma += c[0];
    c[0]--;
    sort(c, c + m, greater<int>());
    j--;
  }
  i = 0, j = n;
  while (j) {
    while (b[i] && j) {
      mi += b[i];
      b[i]--;
      j--;
    }
    i++;
  }
  cout << ma << " " << mi << '\n';
  return 0;
}
