#include <bits/stdc++.h>
using namespace std;
long long int grid[305][305], result[305][305];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long int i, j, t, n, m, k, l, r, temp, sum, mini, maxi, flag;
  cin >> n;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      cin >> grid[i][j];
      result[i][j] = grid[i][j];
    }
  }
  cin >> k;
  while (k--) {
    sum = 0LL;
    cin >> l >> r;
    cin >> m;
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++)
        result[i][j] = min(grid[i][j], min(grid[i][l] + m + result[r][j],
                                           grid[i][r] + m + grid[l][j]));
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        grid[i][j] = result[i][j];
        sum += result[i][j];
      }
    }
    cout << sum / 2 << " ";
  }
  cout << endl;
  return 0;
}
