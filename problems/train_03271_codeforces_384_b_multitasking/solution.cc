#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, i, j;
  cin >> n >> m >> k;
  cout << m * (m - 1) / 2 << endl;
  if (k) {
    for (i = 1; i < m; i++)
      for (j = i + 1; j <= m; j++) cout << j << " " << i << endl;
  } else {
    for (i = 1; i < m; i++)
      for (j = i + 1; j <= m; j++) cout << i << " " << j << endl;
  }
  return 0;
}
