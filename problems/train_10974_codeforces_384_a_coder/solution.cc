#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int cnt = 0;
  vector<vector<char> > a(n, vector<char>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j % 2 == 0 and i % 2 == 0)
        a[i][j] = 'C', cnt++;
      else if (j % 2 != 0 and i % 2 != 0)
        a[i][j] = 'C', cnt++;
      else
        a[i][j] = '.';
    }
  }
  cout << cnt << '\n';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j];
    }
    cout << '\n';
  }
  return 0;
}
