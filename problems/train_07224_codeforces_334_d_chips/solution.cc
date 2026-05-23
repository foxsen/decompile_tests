#include <bits/stdc++.h>
using namespace std;
void read_file(bool outToFile = true) {}
int n, m;
int A[1000 + 9][1000 + 9];
int main() {
  read_file();
  while (scanf("%d%d", &n, &m) != EOF) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) A[i][j] = 1;
    A[0][0] = A[0][n - 1] = A[n - 1][0] = A[n - 1][n - 1] = 0;
    for (int i = 0; i < m; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      x--, y--;
      A[x][0] = A[x][n - 1] = 0;
      A[0][y] = A[n - 1][y] = 0;
    }
    int ans = 0;
    for (int j = 0; j < n; j++) {
      if (!A[0][j]) continue;
      ans++;
      if (n % 2 == 1 && j == n / 2) {
        A[j][0] = A[j][n - 1] = 0;
        continue;
      }
      if (A[0][n - 1 - j]) {
        ans++;
        A[0][n - 1 - j] = 0;
        A[j][0] = A[n - 1 - j][n - 1] = 0;
      } else {
        A[j][0] = A[n - 1 - j][n - 1] = 0;
      }
    }
    for (int i = 0; i < n; i++) {
      if (!A[i][0]) continue;
      ans++;
      A[i][n - 1] = 0;
    }
    for (int i = 0; i < n; i++) {
      if (!A[i][n - 1]) continue;
      ans++;
    }
    printf("%d\n", ans);
  }
}
