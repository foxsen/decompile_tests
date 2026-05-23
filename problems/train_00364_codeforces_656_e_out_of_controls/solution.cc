#include <bits/stdc++.h>
using namespace std;
int main() {
  int maxn = 999999999;
  int m[105][105];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) m[i][j] = maxn;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> m[i][j];
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        if (m[i][j] > m[i][k] + m[k][j]) m[i][j] = m[i][k] + m[k][j];
      }
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (m[i][j] < maxn) ans = max(ans, m[i][j]);
  printf("%d\n", ans);
  return 0;
}
