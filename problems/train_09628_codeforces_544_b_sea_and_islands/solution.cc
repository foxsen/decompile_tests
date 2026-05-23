#include <bits/stdc++.h>
using namespace std;
char a[150][150];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  if ((n * n + 1) / 2 < k)
    printf("NO\n");
  else {
    printf("YES\n");
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (k != 0) {
          if (a[i - 1][j] != 'L' && a[i][j - 1] != 'L') {
            a[i][j] = 'L';
            k--;
          } else
            a[i][j] = 'S';
        } else
          a[i][j] = 'S';
      }
      a[i][n + 1] = '\n';
    }
    for (int i = 1; i <= n; i++) printf("%s", a[i] + 1);
  }
}
