#include <bits/stdc++.h>
using namespace std;
const int N = 1100;
int n, d[N][N];
void df(int poz, int step) {
  int nel = (poz + step) % n, nstep = (step + 1) % n;
  if (nel == 0) nel = n;
  if (d[nel][nstep] == -1) {
    d[nel][nstep] = 1;
    df(nel, nstep);
  }
}
int main() {
  int i, j;
  cin >> n;
  for (i = 0; i < N; ++i)
    for (j = 0; j < N; ++j) d[i][j] = -1;
  d[1][1] = 1;
  df(1, 1);
  int ver = 0;
  for (i = 1; i <= n; ++i) {
    int vv = 0;
    for (j = 1; j <= n; ++j)
      if (d[i][j] != -1) vv = 1;
    if (!vv) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
