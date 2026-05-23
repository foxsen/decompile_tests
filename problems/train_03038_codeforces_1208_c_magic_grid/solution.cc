#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
map<int, int> b;
int arr[maxn][maxn];
int main() {
  int n;
  scanf("%d", &n);
  int cnt = 0;
  for (int i = 1; i <= n / 4; i++) {
    for (int j = 1; j <= n / 4; j++) {
      for (int ii = 1; ii <= 4; ii++) {
        for (int jj = 1; jj <= 4; jj++) {
          arr[(i - 1) * 4 + ii][(j - 1) * 4 + jj] = cnt++;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}
