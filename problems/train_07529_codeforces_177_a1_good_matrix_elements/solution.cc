#include <bits/stdc++.h>
using namespace std;
int a[200][200];
int main() {
  int n;
  cin >> n;
  int res = 0;
  for (register int i = (1); i < (int)(n + 1); i++)
    for (register int j = (1); j < (int)(n + 1); j++) {
      cin >> a[i][j];
      if (i == j || j + i == n + 1 || j == (n + 1) / 2 || i == (n + 1) / 2) {
        res += a[i][j];
      }
    }
  cout << res << endl;
}
