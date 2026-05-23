#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, max_r = -1, cnt = 0, max_c = -1, min_r = 100000, min_c = 100000;
  cin >> n >> m;
  char x;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> x;
      if (x == 'B') {
        cnt++;
        max_c = max(max_c, j);
        min_c = min(min_c, j);
        max_r = max(max_r, i);
        min_r = min(min_r, i);
      }
    }
  }
  if (max_r == -1) {
    cout << 1 << endl;
    return 0;
  }
  int c, r, len = 0;
  c = max_c - min_c + 1;
  r = max_r - min_r + 1;
  len = max(c, r);
  if (cnt == 0)
    cout << 1 << endl;
  else if (len > n || len > m)
    cout << -1 << endl;
  else
    cout << abs(len * len - cnt) << endl;
}
