#include <bits/stdc++.h>
using namespace std;
long long n, x, y;
long long sz[1005][1005];
int main() {
  cin >> n;
  n--;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      sz[i][j] = (i + j) % n + 1;
    }
  }
  for (int i = 0; i < n; i++) {
    sz[i][n] = sz[i][i];
    sz[n][i] = sz[i][i];
    sz[i][i] = 0;
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      cout << sz[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
