#include <bits/stdc++.h>
using namespace std;
const int N = 5003;
const int inf = 1000000007;
int n, a[N], f[N][N], s[N][N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i <= n + 1; i++)
    for (int j = 0; j <= n + 1; j++) f[i][j] = inf;
  for (int i = 0; i <= n + 1; i++)
    for (int j = 0; j <= n + 1; j++) s[i][j] = inf;
  a[0] = 0;
  a[n + 1] = 0;
  s[0][0] = 0;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) {
      if (f[i][j] < inf) {
        if (i + 2 <= n) {
          f[i + 2][j + 1] = min(f[i + 2][j + 1],
                                f[i][j] + min(a[i + 1], a[i] - 1) -
                                    min(min(a[i + 1], a[i] - 1), a[i + 2] - 1) +
                                    a[i + 3] - min(a[i + 3], a[i + 2] - 1));
        }
        s[i + 1][j] = min(s[i + 1][j], f[i][j]);
      }
      if (s[i][j] < inf) {
        f[i + 1][j + 1] = min(f[i + 1][j + 1],
                              s[i][j] + a[i + 2] - min(a[i + 2], a[i + 1] - 1) +
                                  a[i] - min(a[i], a[i + 1] - 1));
        s[i + 1][j] = min(s[i + 1][j], s[i][j]);
      }
    }
  for (int i = 1; i <= (n + 1) / 2; i++) printf("%d ", s[n + 1][i]);
  printf("\n");
}
