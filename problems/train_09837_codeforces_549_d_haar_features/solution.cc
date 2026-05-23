#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 5;
long long a[N][N], b[N][N], c[N][N];
int n, m;
char s[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    for (int j = 1; j <= m; j++) a[i][j] = s[j] == 'W' ? 1 : -1;
  }
  int ans = 0;
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      if (j > 1) c[i][j - 1] += c[i][j];
      b[i][j] += c[i][j];
      if (b[i][j] != a[i][j]) {
        long long add = a[i][j] - b[i][j];
        ans++;
        if (j > 1) c[i][j - 1] += add;
        for (int k = i - 1; k >= 1; k--) c[k][j] += add;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
