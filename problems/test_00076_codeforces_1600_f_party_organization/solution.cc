#include <bits/stdc++.h>
using namespace std;
const int mxN = 1000006, mod = 1e9 + 7, LOG = 23;
int n, m, u, v;
bool veze[55][55];
bool check(int i1, int i2, int i3, int i4, int i5) {
  if (veze[i1][i2] && veze[i1][i3] && veze[i1][i4] && veze[i1][i5]) {
    if (veze[i2][i3] && veze[i2][i4] && veze[i2][i5]) {
      if (veze[i3][i4] && veze[i3][i5]) {
        if (veze[i4][i5]) {
          return 1;
        }
      }
    }
  }
  if (!veze[i1][i2] && !veze[i1][i3] && !veze[i1][i4] && !veze[i1][i5]) {
    if (!veze[i2][i3] && !veze[i2][i4] && !veze[i2][i5]) {
      if (!veze[i3][i4] && !veze[i3][i5]) {
        if (!veze[i4][i5]) {
          return 1;
        }
      }
    }
  }
  return 0;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    if (u <= 50 && v <= 50) {
      veze[u][v] = 1;
      veze[v][u] = 1;
    }
  }
  int kr = min(n, 50);
  for (int i = 1; i <= kr; i++) {
    for (int j = i + 1; j <= kr; j++) {
      for (int z = j + 1; z <= kr; z++) {
        for (int k = z + 1; k <= kr; k++) {
          for (int p = k + 1; p <= kr; p++) {
            if (check(i, j, z, k, p)) {
              cout << i << " " << j << " " << z << " " << k << " " << p << '\n';
              return 0;
            }
          }
        }
      }
    }
  }
  cout << -1 << '\n';
  return 0;
}
