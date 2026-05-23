#include <bits/stdc++.h>
using namespace std;
int b[505][505];
int maxR[505];
int n, m, q;
int findmax(int i) {
  int maxi = 0;
  int eyes = 0;
  for (int j = 1; j <= m; j++) {
    if (b[i][j] == 1) {
      eyes++;
    } else {
      maxi = maxi > eyes ? maxi : eyes;
      eyes = 0;
    }
  }
  maxi = maxi > eyes ? maxi : eyes;
  return maxi;
}
int main(int argc, char** argv) {
  int x, y;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> b[i][j];
    }
  }
  int maxi = 0;
  int maxS = 0;
  for (int i = 1; i <= n; i++) {
    maxR[i] = findmax(i);
    if (maxR[i] > maxS) {
      maxS = maxR[i];
      maxi = i;
    }
  }
  for (int i = 0; i < q; i++) {
    cin >> x >> y;
    b[x][y] = 1 - b[x][y];
    maxR[x] = findmax(x);
    if (b[x][y]) {
      if (maxR[x] > maxS) {
        maxS = maxR[x];
        maxi = x;
      }
    } else {
      if (maxi == x) {
        maxS = 0;
        for (int j = 1; j <= n; j++) {
          if (maxR[j] > maxS) {
            maxS = maxR[j];
            maxi = j;
          }
        }
      }
    }
    cout << maxS << endl;
  }
  return 0;
}
