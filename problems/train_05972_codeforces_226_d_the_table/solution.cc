#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int> > a(n, vector<int>(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> a[i][j];
  vector<int> czyR(n, 0), czyK(m, 0);
  vector<int> sR(n, 0), sK(m, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      sR[i] += a[i][j];
      sK[j] += a[i][j];
    }
  }
  while (true) {
    int nr = -1;
    for (int i = 0; i < n; ++i)
      if (sR[i] < 0) nr = i;
    if (nr != -1) {
      czyR[nr] ^= 1;
      sR[nr] *= -1;
      for (int i = 0; i < m; ++i) {
        sK[i] -= a[nr][i];
        a[nr][i] *= -1;
        sK[i] += a[nr][i];
      }
      continue;
    }
    for (int i = 0; i < m; ++i)
      if (sK[i] < 0) nr = i;
    if (nr != -1) {
      czyK[nr] ^= 1;
      sK[nr] *= -1;
      for (int i = 0; i < n; ++i) {
        sR[i] -= a[i][nr];
        a[i][nr] *= -1;
        sR[i] += a[i][nr];
      }
      continue;
    }
    break;
  }
  int x = 0;
  for (int i = 0; i < n; ++i) x += czyR[i];
  cout << x << " ";
  for (int i = 0; i < n; ++i)
    if (czyR[i] == 1) cout << i + 1 << " ";
  cout << endl;
  int y = 0;
  for (int i = 0; i < m; ++i) y += czyK[i];
  cout << y << " ";
  for (int i = 0; i < m; ++i)
    if (czyK[i] == 1) cout << i + 1 << " ";
  return 0;
}
